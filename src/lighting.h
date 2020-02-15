#ifndef lighting_h
#define lighting_h
#include <Arduino.h>
#include <FastLED.h>

// https://github.com/FastLED/FastLED/wiki/Pixel-reference#colors
const TProgmemPalette16 dayPalette PROGMEM =
{
    CRGB::Black,
    CRGB::Goldenrod,
    CRGB::DarkSalmon,
    CRGB::LightYellow,
    CRGB::PaleGoldenrod,
    CRGB::LightGoldenrodYellow,
    CRGB::Cornsilk,
    CRGB::Ivory,
    CRGB::Cornsilk,
    CRGB::LightGoldenrodYellow,
    CRGB::PaleGoldenrod,
    CRGB::LightYellow,
    CRGB::DarkSalmon,
    CRGB::Goldenrod,
    CRGB::Black,
};

class Lighting {
  public:
  Lighting();
  void initialize();
  void loop();
  
  private:  
  void render();
  void addLightning(fract8 chanceOfLightning);

  int dayLengthMin = 30;
  float intervalMillis = ((float)(dayLengthMin * 60) / 256) * 1000;
  int paletteIndex = 0;
};

#endif