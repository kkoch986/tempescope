#include <lighting.h>

#define DATA_PIN    NEO_PIXEL_PIN
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    NEO_PIXEL_COUNT

#define BRIGHTNESS  50

CRGB leds[NUM_LEDS];

Lighting::Lighting() {
  this->dayLengthMin = DAY_LENGTH_MINUTES;
  this->intervalMillis = ((float)(dayLengthMin * 60) / 256) * 1000;
}

void Lighting::initialize(){
  // Initial delay for setup
  delay(1000);
  
  // Tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void Lighting::loop(){
  //
  render();

  //
  FastLED.show();
}

void Lighting::render() 
{
  //
  CRGB color = ColorFromPalette(dayPalette, this->paletteIndex, 255, LINEARBLEND);

  // TODO: See how much this affects things...
  // HighNoonSun, DirectSunlight, OvercastSky, ClearBlueSky,
  FastLED.setTemperature(DirectSunlight);

  // 
  fill_solid(leds, NUM_LEDS, color);

  //
  EVERY_N_MILLISECONDS(this->intervalMillis) {    
    if (this->paletteIndex < 255) {
      this->paletteIndex++;
    }

    if (this->paletteIndex == 255) {
      this->paletteIndex = 0;
    }

    Serial.print("Index: ");  
    Serial.print(this->paletteIndex);  
    Serial.println();  
  }
}

void Lighting::addLightning(fract8 chanceOfLightning) 
{
  if( random8() < chanceOfLightning) {
    leds[random8(NUM_LEDS)] += CRGB::White;
  }
}
