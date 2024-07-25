#include <Adafruit_BME280.h>
#include <ArduinoJson.h>
#include "bme_sensor.h"

Adafruit_BME280 bme;

void initBME()
{
  if (!bme.begin(0x76))
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }
}

String getSensorReadings()
{
  JsonDocument doc;
  doc["temperature"] = bme.readTemperature();
  doc["humidity"] = bme.readHumidity();
  doc["pressure"] = bme.readPressure() / 100.0F;
  String jsonString;
  serializeJson(doc, jsonString);
  return jsonString;
}
