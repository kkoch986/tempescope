#include <lighting.h>

#define DATA_PIN    NEO_PIXEL_PIN
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    NEO_PIXEL_COUNT

#define BRIGHTNESS          50
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];

// minutes
static const uint8_t dayLengthMin = DAY_LENGTH_MINUTES;
static const float intervalMillis = ((float)(dayLengthMin * 60) / 256) * 1000;
static uint8_t paletteIndex = 0;

const TProgmemPalette16 dayPalette_p PROGMEM =
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

void lighting_test() 
{
  //
  CRGB color = ColorFromPalette(dayPalette_p, paletteIndex, 255, LINEARBLEND);

  // TODO: See how much this affects things...
  // HighNoonSun, DirectSunlight, OvercastSky, ClearBlueSky,
  FastLED.setTemperature(DirectSunlight);

  // 
  fill_solid(leds, NUM_LEDS, color);

  //
  EVERY_N_MILLISECONDS(intervalMillis) {    
    if (paletteIndex < 255) {
      paletteIndex++;
    }

    if (paletteIndex == 255) {
      paletteIndex = 0;
    }

    Serial.print("Index: ");  
    Serial.print(paletteIndex);  
    Serial.println();  
  }
}

void lighting_addLightning(fract8 chanceOfLightning) 
{
  if( random8() < chanceOfLightning) {
    leds[random8(NUM_LEDS)] += CRGB::White;
  }
}

void lighting_setup() {
  // Initial delay for setup
  delay(1000);
  
  // Tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void lighting_loop()
{
  //
  lighting_test();

  //
  FastLED.show();
}
