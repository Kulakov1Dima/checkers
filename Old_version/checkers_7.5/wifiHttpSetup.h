#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266HTTPClient.h>

ESP8266WebServer HttpServer(SERVERPORT);
ESP8266HTTPUpdateServer httpUpdater;

void wifiSetup() {
  pinMode(indicatorLed, OUTPUT);
  digitalWrite(indicatorLed, 1);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);//подключение к wifi

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(indicatorLed, 0);
    delay(100);
    digitalWrite(indicatorLed, 1);
    delay(100);
  }
}
