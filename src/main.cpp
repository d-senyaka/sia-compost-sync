#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "model.h" // Import your generated TinyML model

#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ4_PIN 34
#define SAMPLE_INTERVAL_MS 5000
#define MQTT_BROKER "broker.hivemq.com"
#define MQTT_PORT 1883
#define DATA_TOPIC "sia/compost/data"
#define COMMAND_TOPIC "sia/compost/commands"
#define MQTT_RECONNECT_INTERVAL_MS 5000

#ifndef WIFI_SSID
#define WIFI_SSID ""
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD ""
#endif

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);
Eloquent::Projects::CompostClassifier classifier;
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
unsigned long lastSampleAtMs = 0;
unsigned long lastMqttReconnectAttemptMs = 0;
volatile bool forceRefreshRequested = false;

void setup_wifi() {
    delay(10);
    if (ssid[0] == '\0' || password[0] == '\0') {
        Serial.println("WiFi credentials are not configured; skipping WiFi setup.");
        return;
    }
    Serial.println("\nConnecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
    Serial.println("\nWiFi connected. IP: "); Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Command received on topic: "); Serial.println(topic);

    String command;
    for (unsigned int i = 0; i < length; i++) {
        command += (char)payload[i];
    }
    command.trim();
    command.toUpperCase();

    if (command == "REFRESH") {
        forceRefreshRequested = true;
        Serial.println("Action: Force refresh scheduled.");
    } else if (command == "RESET") {
        Serial.println("Action: System reset requested.");
        delay(100);
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
    clientId += String((uint32_t)(ESP.getEfuseMac() & 0xFFFFFFFF), HEX);

    if (client.connect(clientId.c_str())) {
        Serial.println("connected");
        client.subscribe(COMMAND_TOPIC);
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
    client.setServer(MQTT_BROKER, MQTT_PORT);
    client.setCallback(callback);
    Serial.println("Sia-Compost-Sync: Edge Inference Mode Active");
}

void loop() {
    if (ssid[0] != '\0' && password[0] != '\0') {
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
    if (!forceRefreshRequested && (unsigned long)(sampleNow - lastSampleAtMs) < SAMPLE_INTERVAL_MS) {
        return;
    }
    forceRefreshRequested = false;
    lastSampleAtMs = sampleNow;

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
