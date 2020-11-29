#include <ronquido.h>
#include <Arduino.h>

void ronquidoON(int GPIOLed){
  for (int i=0; i<256; i++){
    analogWrite(GPIOLed,i);
    delay(duracionRonquidoPaso);
  }

}
void ronquidoOFF(int GPIOLed){
  for (int i=255; i>=0; i--){
    analogWrite(GPIOLed,i);
    delay(duracionRonquidoPaso);
  }
}

void ronquido(int GPIOLed){
  static unsigned long last=0;
  static bool off = true;
  int duracion = off ? duracionRonquidoOff : duracionRonquidoOn;

  if (millis() < (last + duracion )){
    return;
  }

  if (off){
    ronquidoON(GPIOLed);
    off=false;
  }else{
    ronquidoOFF(GPIOLed);
    off=true;
  }
  last = millis();
}