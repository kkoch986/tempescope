#include <Arduino.h>

//
#if defined ENABLE_LIGHTING
#include <lighting.h>
#include <weather.h>

Weather *weather;
Lighting *lighting;
#endif

void setup() {
  Serial.begin(9600);

#if defined ENABLE_LIGHTING
  weather = new Weather();
  lighting = new Lighting();

  lighting->initialize();
#endif
}

void loop() {

#if defined ENABLE_LIGHTING
  lighting->loop();
#endif
}