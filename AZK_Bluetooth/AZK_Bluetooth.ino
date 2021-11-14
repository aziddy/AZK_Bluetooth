#include <Arduino.h>
#include <ArduinoJson.h>
#include "SPIFFS.h"

/*
 *  START AS WIFI_AP TO CONFIGURE KEYS
 *  OR
 *  START AS BLE KEYBOARD
*/

//For Wifi



void setup() {
  // put your setup code here, to run once:

  wifimake();


}

void loop() {
  // put your main code here, to run repeatedly:
  wifiLoop();

}
