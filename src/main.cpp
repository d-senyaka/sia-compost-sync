#include <Arduino.h>
#include <cinttypes>
#include <WiFi.h>
#if !defined(MQTT_USE_TLS) || MQTT_USE_TLS
#include <WiFiClientSecure.h>
#endif
#include <PubSubClient.h>
#include <DHT.h>
#include "model.h" // Import your generated TinyML model

#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ4_PIN 34
#define SAMPLE_INTERVAL_MS 5000
#ifndef WIFI_CONNECT_TIMEOUT_MS
#define WIFI_CONNECT_TIMEOUT_MS 15000UL
#endif
#ifndef MQTT_USE_TLS
#define MQTT_USE_TLS 1
#endif
#define MQTT_BROKER "broker.hivemq.com"
#if MQTT_USE_TLS
#define MQTT_PORT 8883
#else
#define MQTT_PORT 1883
#endif
#define DATA_TOPIC "sia/compost/data"
#define COMMAND_TOPIC_PREFIX "sia/compost/commands/"
#define MQTT_RECONNECT_INTERVAL_MS 5000
#define RESET_DELAY_MS 100  // Brief pause so reset message can flush on Serial

#ifndef WIFI_SSID
#define WIFI_SSID ""
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD ""
#endif

#ifndef COMMAND_TOKEN
#define COMMAND_TOKEN ""
#endif

#if MQTT_USE_TLS
WiFiClientSecure espClient;
#else
WiFiClient espClient;
#endif
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);
Eloquent::Projects::CompostClassifier classifier;
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const char* commandToken = COMMAND_TOKEN;
String deviceId;
unsigned long lastSampleAtMs = 0;
unsigned long lastMqttReconnectAttemptMs = 0;
String commandTopic;
portMUX_TYPE sampleTimestampMux = portMUX_INITIALIZER_UNLOCKED;

String getDeviceId() {
    uint64_t chipId = ESP.getEfuseMac();
    char idBuffer[13];
    snprintf(idBuffer, sizeof(idBuffer), "%012" PRIx64, chipId);
    return String(idBuffer);
}

void setup_wifi() {
    delay(10);
    if (ssid[0] == '\0') {
        Serial.println("WiFi SSID is not configured; skipping WiFi setup.");
        return;
    }
    Serial.println("\nConnecting to WiFi...");
    if (password[0] == '\0') {
        WiFi.begin(ssid);
    } else {
        WiFi.begin(ssid, password);
    }
    unsigned long connectStartedAt = millis();
    while (WiFi.status() != WL_CONNECTED && (millis() - connectStartedAt) < WIFI_CONNECT_TIMEOUT_MS) {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi connected. IP: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nWiFi connection timeout. Continuing in local edge-only mode.");
        WiFi.disconnect(true);
    }
}

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Command received on topic: "); Serial.println(topic);

    String command;
    for (unsigned int i = 0; i < length; i++) {
        command += (char)payload[i];
    }
    command.trim();

    if (commandToken[0] != '\0') {
        String tokenPrefix = String(commandToken) + ":";
        if (!command.startsWith(tokenPrefix)) {
            Serial.println("Action: Unauthorized command rejected (missing/invalid token).");
            return;
        }
        command = command.substring(tokenPrefix.length());
        command.trim();
    }
    command.toUpperCase();

    if (command == "REFRESH") {
        unsigned long refreshTimestamp = millis() - SAMPLE_INTERVAL_MS;
        portENTER_CRITICAL(&sampleTimestampMux);
        lastSampleAtMs = refreshTimestamp;
        portEXIT_CRITICAL(&sampleTimestampMux);
        Serial.println("Action: Force refresh scheduled.");
    } else if (command == "RESET") {
        Serial.println("Action: System reset requested.");
        delay(RESET_DELAY_MS);
        ESP.restart();
    } else {
        Serial.print("Action: Unknown command '");
        Serial.print(command);
        Serial.println("'.");
    }
}

void reconnect() {
    Serial.print("Attempting MQTT connection...");
    String clientId = "SiaCompostClient-";
    clientId += deviceId;

    if (client.connect(clientId.c_str())) {
        Serial.println("connected");
        client.subscribe(commandTopic.c_str());
    } else {
        Serial.print("failed, rc=");
        Serial.println(client.state());
    }
}

void setup() {
    Serial.begin(115200);
    dht.begin();
    pinMode(MQ4_PIN, INPUT);
    setup_wifi();
#if MQTT_USE_TLS
    espClient.setInsecure();
#endif
    client.setServer(MQTT_BROKER, MQTT_PORT);
    client.setCallback(callback);
    deviceId = getDeviceId();
    commandTopic = String(COMMAND_TOPIC_PREFIX) + deviceId;
    Serial.print("Command topic: ");
    Serial.println(commandTopic);
    if (commandToken[0] != '\0') {
        Serial.println("Command token protection: enabled");
    } else {
        Serial.println("Command token protection: disabled (set COMMAND_TOKEN build flag to enable)");
    }
#if MQTT_USE_TLS
    Serial.println("MQTT transport: TLS enabled");
#else
    Serial.println("MQTT transport: plaintext (set MQTT_USE_TLS=1 to enable TLS)");
#endif
    Serial.println("Sia-Compost-Sync: Edge Inference Mode Active");
}

void loop() {
    if (ssid[0] != '\0') {
        if (!client.connected()) {
            unsigned long mqttNow = millis();
            if ((unsigned long)(mqttNow - lastMqttReconnectAttemptMs) >= MQTT_RECONNECT_INTERVAL_MS) {
                lastMqttReconnectAttemptMs = mqttNow;
                reconnect();
            }
        } else {
            client.loop();
        }
    }

    unsigned long sampleNow = millis();
    unsigned long lastSampleSnapshot;
    portENTER_CRITICAL(&sampleTimestampMux);
    lastSampleSnapshot = lastSampleAtMs;
    portEXIT_CRITICAL(&sampleTimestampMux);

    if ((unsigned long)(sampleNow - lastSampleSnapshot) < SAMPLE_INTERVAL_MS) {
        return;
    }
    portENTER_CRITICAL(&sampleTimestampMux);
    lastSampleAtMs = sampleNow;
    portEXIT_CRITICAL(&sampleTimestampMux);

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int m = analogRead(MQ4_PIN);

    if (isnan(h) || isnan(t)) {
        Serial.println("Sensor Error...");
        return;
    }

    // 1. Prepare the input for the model
    // The order MUST match your training features: [Temperature, Humidity, Methane]
    float input[3] = { t, h, (float)m };

    // 2. Predict the state
    String prediction = classifier.predictLabel(input);

    // 3. Output the result
    Serial.print("--- Local Insight ---");
    Serial.print(" | State: ");
    Serial.println(prediction);
    
    // Print raw data too (useful for Phase 4 MQTT sync)
    Serial.printf("Data: T=%.2f, H=%.2f, M=%d\n", t, h, m);

    if (client.connected()) {
        char payload[128];
        snprintf(payload, sizeof(payload),
                 "{\"temp\":%.2f,\"hum\":%.2f,\"methane\":%d,\"status\":\"%s\"}",
                 t, h, m, prediction.c_str());
        client.publish(DATA_TOPIC, payload);
    }
}
