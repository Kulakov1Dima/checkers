#include "Configuration.h"
#include <Arduino.h>


void setup(){
    Serial.begin(9600);
    pinMode(INDICATOR_OF_NETWORK_STATUS, OUTPUT);
    beginConnected();
    connectedWifi();
    updateFirmware();
}

void loop(){
    #ifdef CHECK_WIFI
    checkWifi();
    #endif
    updateServer();
    polling();
}
