#include <Arduino.h>

/**
 * Just implements a basic "blink" sketch.
 * on the esp32 dev board pin D2 controls the on-board LED.
 */
#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}