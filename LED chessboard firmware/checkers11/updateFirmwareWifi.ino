#include "Configuration.h"
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

ESP8266WebServer HttpServer(SERVERPORT);
ESP8266HTTPUpdateServer httpUpdater;

void updateFirmware(){
    httpUpdater.setup(&HttpServer, OTAPATH, OTAUSER, OTAPASSWORD);
    HttpServer.on("/", handleRoot);
    HttpServer.begin();
}

void updateServer(){
  HttpServer.handleClient();
}

void handleRoot() {
  HttpServer.send(400, "text/plain", "not found");
}
