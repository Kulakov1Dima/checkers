#include "Configuration.h"
#include <ESP8266WiFi.h>

int realTimeConnected = 0;
bool status_of_the_indicator = false;

void beginConnected(){
  WiFi.begin( NETWORK_NAME, NETWORK_PASSWORD );
}

void connectedWifi(){
  if(millis() - realTimeConnected > TIME_INTERVAL_CONNECTED_WIFI){
      realTimeConnected = millis();
      digitalWrite(INDICATOR_OF_NETWORK_STATUS, status_of_the_indicator=!status_of_the_indicator);
      matrixON();
    }
    Serial.print(".");
    delay(10);

    if(WiFi.status() != WL_CONNECTED)connectedWifi();
    else{
      Serial.println();
      Serial.print("Connected, IP address: ");
      Serial.println(WiFi.localIP());
    }
}
void checkWifi(){
  if(millis() - realTimeConnected > TIME_INTERVAL_CHECK_WIFI){
      realTimeConnected += TIME_INTERVAL_CHECK_WIFI;
      #ifdef INVERT_INDICATOR_OF_NETWORK_STATUS
      status_of_the_indicator = (WiFi.status() == WL_CONNECTED);
      #endif
      #ifndef INVERT_INDICATOR_OF_NETWORK_STATUS
      status_of_the_indicator = !(WiFi.status() == WL_CONNECTED);
      #endif
      digitalWrite(INDICATOR_OF_NETWORK_STATUS, status_of_the_indicator);
    }
}