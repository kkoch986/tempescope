#include <Arduino.h>

//
#if defined ENABLE_LIGHTING
#include <lighting.h>
#endif

/**
 * Just implements a basic "blink" sketch.
 * on the esp32 dev board pin D2 controls the on-board LED.
 */
#define LED_PIN IN_LED_PIN

void setup() {
#if defined ENABLE_LIGHTING
  lighting_setup();
#else   
  pinMode(LED_PIN, OUTPUT);
#endif
}

void loop() {

#if defined ENABLE_LIGHTING
  lighting_loop();
#else 
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
#endif
}