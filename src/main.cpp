#include <Arduino.h>
#include <main.h>
#include <ronquido.h>

void setup() {
  Serial.begin(SERIALSPEED);
  Serial.println("Setup");
  pinMode(Led, OUTPUT);
  
}

void loop() {
  ronquido(Led);
}