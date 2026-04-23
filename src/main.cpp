#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "model.h"

// --- CONFIGURATION ---
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com"; // Public testing broker

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(4, DHT11);
Eloquent::Projects::CompostClassifier classifier;

void setup_wifi() {
    delay(10);
    Serial.println("\nConnecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
    Serial.println("\nWiFi connected. IP: "); Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
    // This is for Phase 4 bidirectional control (receiving commands)
    Serial.print("Command received on topic: "); Serial.println(topic);
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("SiaCompostClient")) {
            Serial.println("connected");
            client.subscribe("sia/compost/commands");
        } else {
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    dht.begin();
}

void loop() {
    if (!client.connected()) reconnect();
    client.loop();

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int m = analogRead(34);

    if (!isnan(h) && !isnan(t)) {
        float input[3] = { t, h, (float)m };
        String prediction = classifier.predictLabel(input);

        // Create a JSON payload
        String payload = "{\"temp\":" + String(t) + 
                         ",\"hum\":" + String(h) + 
                         ",\"methane\":" + String(m) + 
                         ",\"status\":\"" + prediction + "\"}";

        Serial.println("Publishing: " + payload);
        client.publish("sia/compost/data", payload.c_str());
    }

    delay(10000); // Publish every 10 seconds
}