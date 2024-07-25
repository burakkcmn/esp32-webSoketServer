#include <Arduino.h>
#include "wifi_config.h"
#include "web_server.h"
#include "bme_sensor.h"
#include "file_system.h"

unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

void setup()
{
  Serial.begin(115200);
  initBME();
  initWiFi();
  initLittleFS();
  initWebSocket();
}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    String sensorReadings = getSensorReadings();
    Serial.print(sensorReadings);
    notifyClients(sensorReadings);
    lastTime = millis();
  }
  cleanupWebSocketClients();
}
