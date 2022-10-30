#include <Arduino.h>
#include "SoftwareSerial.h"

#define BLE_RX      PIND0
#define BLE_TX      PIN1

SoftwareSerial BLESerial(BLE_RX , BLE_TX);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
}