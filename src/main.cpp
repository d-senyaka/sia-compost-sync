#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4          // DHT11 Data Pin
#define DHTTYPE DHT11
#define MQ4_PIN 34        // MQ4 Analog Pin

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(MQ4_PIN, INPUT);
  
  // Header for our Serial stream (helpful for debugging)
  Serial.println("Temp,Humidity,Methane");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int m = analogRead(MQ4_PIN);

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor_Error,0,0");
  } else {
    // CSV-style output for the Python logger to catch
    Serial.print(t);
    Serial.print(",");
    Serial.print(h);
    Serial.print(",");
    Serial.println(m);
  }

  delay(2000); // 2-second interval for data collection
}