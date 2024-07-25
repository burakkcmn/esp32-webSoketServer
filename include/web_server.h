#ifndef WEB_SERVER_H
#define WEB_SERVER_H

void initWebSocket();
void cleanupWebSocketClients();
void notifyClients(String sensorReadings);

#endif
