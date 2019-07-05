#include "FastLED.h"

#define BRIGHTNESS  5
#define LED_TYPE    WS2812B
#define LED_PIN     3
#define NUM_LEDS    256

CRGB leds[NUM_LEDS];

void setup() {
  delay(100); // for safety
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
}
void loop() {
  static uint8_t hue;
  hue=hue+1;
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CHSV(hue, 255, 255);
    hue+=4;
    FastLED.show();
    delay(3);
  }
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CHSV(hue, 255, 255);
    hue+=10;
    FastLED.show();
    delay(3);
  }
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CHSV(hue, 255, 255);
    hue+=30;
    FastLED.show();
    delay(3);
  }
}
