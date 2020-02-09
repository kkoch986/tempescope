#include <Arduino.h>

//
#if defined ENABLE_LIGHTING
#include <lighting.h>
#endif

void setup() {
  Serial.begin(9600);
  
#if defined ENABLE_LIGHTING
  lighting_setup();
#endif
}

void loop() {

#if defined ENABLE_LIGHTING
  lighting_loop();
#endif
}