#include <ESP8266HTTPClient.h>
#include "Configuration.h"
#include <WiFiClient.h>

WiFiClient wifiClient;
String dataHost = "";
String* data = &dataHost;
long timeHost = 0;

void polling(){
if(millis() - timeHost > TIME_HOST){
    HTTPClient http;
    http.begin(wifiClient, "http://yandexcheckers.000webhostapp.com/data.txt");
    int httpCode = http.GET();
    *data=http.getString();
    matrixLoop(data);
    timeHost = millis();
}
}
