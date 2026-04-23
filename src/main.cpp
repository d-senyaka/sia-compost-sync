#include <Arduino.h>
#include <DHT.h>
#include "model.h" // Import your generated TinyML model

#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ4_PIN 34

DHT dht(DHTPIN, DHTTYPE);

// Create an instance of your classifier from model.h
Eloquent::Projects::CompostClassifier classifier;

void setup() {
    Serial.begin(115200);
    dht.begin();
    pinMode(MQ4_PIN, INPUT);
    Serial.println("Sia-Compost-Sync: Edge Inference Mode Active");
}

void loop() {
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

    delay(5000); // Check every 5 seconds
}