#include <Arduino.h>
#include <main.h>
#include <ronquido.h>
#include <flashLed.h>
#include <Servo.h>

Servo servo;
int angle = 10;

void setup() {
  Serial.begin(SERIALSPEED);
  Serial.println("Setup");
  pinMode(Led, OUTPUT);
  servo.attach(GPIOServo);
  Serial.println("-- 0 --");
  servo.write(0);
  delay(2000);
}

void mueveServo(unsigned int duracion, byte paso){
  static unsigned long last=0;
  static int direccion = 1;
  if (millis() < (last + duracion )){
    return;
  }
  if (angle >= 180){ direccion = -1; angle=180; }
  if (angle <=   0){ direccion =  1; angle=0; }
  
  angle+=paso*direccion;
  servo.write(angle);
  last = millis();
}

void loop() {
  ronquido(Led);
  mueveServo(50,5);
}