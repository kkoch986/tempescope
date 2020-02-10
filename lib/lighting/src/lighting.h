#ifndef lighting_h
#define lighting_h
#include <Arduino.h>
#include <FastLED.h>

//void lighting_setup();

//void lighting_loop();

class Lighting {
  public:
  Lighting();
  void initialize();
  void loop();
  
  private:  
  int pinR, pinG, pinB;
  void render();
  void addLightning(fract8 chanceOfLightning);
};

#endif