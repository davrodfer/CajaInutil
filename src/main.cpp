#include <Arduino.h>
#include <main.h>

void setup() {
  Serial.begin(SERIALSPEED);
  Serial.println("Setup");
  pinMode(Led, OUTPUT);
  
}

void loop() {
  digitalWrite(Led, LOW);
  delay(200);
  digitalWrite(Led, HIGH);
  delay(200);
}