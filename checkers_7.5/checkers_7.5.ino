#include "config.h"
#include "wifiHttpSetup.h"
#include "matrix.h"
#include <ArduinoJson.h>

String dataHost = "";
long timeHost =0;

void setup() {
  Serial.begin (9600);
  wifiSetup();
  httpUpdater.setup(&HttpServer, OTAPATH, OTAUSER, OTAPASSWORD);
  HttpServer.on("/", handleRoot);  //Прошивка по воздуху
  HttpServer.on(SUBFOLDERDATA, data);
  HttpServer.begin();
  ledSetup();
}
void loop() {
  if(millis()-timeHost>2500){
  HttpServer.handleClient();
  HTTPClient http;
  http.begin(host);
  int httpCode = http.GET();
  dataHost=httpCode;
  if (httpCode == 200)
  {
    dataHost = http.getString();
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
    DynamicJsonBuffer jsonBuffer(capacity);
    JsonObject& root = jsonBuffer.parseObject(dataHost);
    dataHost = root["command"].as<char*>();
    dataHost.replace(" ", "");
    dataHost.toUpperCase();
    mainMatrix(dataHost);
  }
  timeHost = millis();
}
}

void handleRoot() {
  digitalWrite(indicatorLed, 1);
  HttpServer.send(400, "text/plain", "not found");
}

void data() {
  digitalWrite(indicatorLed, 0);
  HttpServer.send(200, "text/plain", dataHost);
}
