#include <Arduino.h>

//
#if defined ENABLE_LIGHTING
#include <lighting.h>
#endif

void setup() {
#if defined ENABLE_LIGHTING
  lighting_setup();
#endif
}

void loop() {

#if defined ENABLE_LIGHTING
  lighting_loop();
#endif
}