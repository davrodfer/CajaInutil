#include <ronquido.h>
#include <Arduino.h>

void ronquido(int GPIOLed){
  static unsigned long last=0;
  static bool off = true;
  static int intensidad = 0;
  int duracion = 1;

  last = last > millis() ? millis() : last;

  if (
      (intensidad > RonquidoMinIntensidad) && 
      (intensidad < RonquidoMaxIntensidad)
  ){ //esta en proceso de moverse
    duracion = duracionRonquidoPaso;
  }else if (off){
    duracion = duracionRonquidoOff;
  }else{
    duracion = duracionRonquidoOn;
  }

  if (millis() < (last + duracion )){
    return;
  }

  intensidad += (off ? RonquidoPasoIntensidad : -RonquidoPasoIntensidad);
  intensidad = intensidad > RonquidoMaxIntensidad ? RonquidoMaxIntensidad : intensidad;
  intensidad = intensidad < RonquidoMinIntensidad ? RonquidoMinIntensidad : intensidad;
  analogWrite(GPIOLed,intensidad);
  if (intensidad <= RonquidoMinIntensidad){
    off = true;
  }
  if (intensidad >= RonquidoMaxIntensidad){
    off = false;
  }

  last = millis();
}