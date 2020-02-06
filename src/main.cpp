#include <Arduino.h>

/**
 * Just implements a basic "blink" sketch.
 * on the esp32 dev board pin D2 controls the on-board LED.
 */
#define LED_PIN IN_LED_PIN

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}