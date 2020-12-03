#include <flashLed.h>
#include <Arduino.h>

void flashLed(int GPIOLed,int duracion){
  static unsigned long last=0;
  static bool off = true;
  
  last = last > millis() ? millis() : last;

  if (millis() < (last + duracion )){
    return;
  }

  if (off){
    flashLedON(GPIOLed);
    off=false;
  }else{
    flashLedOFF(GPIOLed);
    off=true;
  }
  last = millis();
}

void flashLedON(int GPIOLed){
  digitalWrite(GPIOLed,HIGH);
}
void flashLedOFF(int GPIOLed){
  digitalWrite(GPIOLed,LOW);
}
