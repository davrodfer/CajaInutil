#include <Arduino.h>
#include <main.h>
#include <ronquido.h>
#include <flashLed.h>
#include <Servo.h>

void setup() {
  Serial.begin(SERIALSPEED);
  Serial.println("Setup");
  pinMode(Led, OUTPUT);

  /*
  Servo servo;
  servo.attach(GPIOServo);
  Serial.println("-- 0 --");
  servo.write(0);
  delay(2000);
  Serial.println("-- 180 --");
  servo.write(180);
  delay(2000);
  servo.detach();
  */
}

void mueveServo2(){
  static unsigned long last=0;
  static bool servoOn = true;
  static Servo servo;
  static int angle = 0;

  last = last > millis() ? millis() : last;

  if ((servoOn) && (angle == anguloParado) && (millis() > (last + 1500 ))){
    servo.detach();
    servoOn = false;
    Serial.print(millis());
    Serial.println(" Esta parado, desconecto");
    // Serial.println(servoOn);
  }

  if (millis() < (last + 4000 )){
    return;
  }

  angle=(angle == anguloParado) ? anguloEncendido : anguloParado;
  Serial.print(millis());Serial.print(" Angle: ");Serial.println(angle);
  servo.attach(GPIOServo);
  servo.write(angle);
  servoOn = true;
  last=millis();
}
/*
void mueveServo(unsigned int duracion, byte paso){
  static unsigned long last=0;
  static int direccion = 1;
  static int angle = 0;
  last = last > millis() ? millis() : last;

  if (millis() < (last + duracion )){
    return;
  }
  if (angle >= 180){ direccion = -1; angle=180; }
  if (angle <=   0){ direccion =  1; angle=0; }
  
  angle+=paso*direccion;
  servo.write(angle);
  last = millis();
}
*/
void loop() {
  ronquido(Led);
  mueveServo2();
  //mueveServo(1000,90);
  //servo.write(0);
}