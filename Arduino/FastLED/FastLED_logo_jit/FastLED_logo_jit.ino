#include "FastLED.h"

#define BRIGHTNESS  17
#define LED_TYPE    WS2812B
#define LED_PIN     3
#define NUM_LEDS    256

CRGB leds[NUM_LEDS];

int logo[256];

void setup() {
  logoSetup();
  delay(250); // for safety
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );

  for(int i=0; i<NUM_LEDS; i++){
    if(logo[i] == 1){
      leds[i] = CRGB::White;
      delay(3);
    }else if(logo[i] == 2){
      leds[i] = CRGB::White;
    }else{
      leds[i] = CRGB::Black;
      delay(3);
    }
  }
  FastLED.show();
  delay(1000);
}

void loop() {
  patternA();
  patternA();
  patternA();
  patternB();
  patternB();
  patternB();
  patternC();
  patternC();
  patternC();
  patternD();
  patternD();
  patternD();
  setup();
}

void patternA(){
  static uint8_t hueA;
  static uint8_t hueB;

  hueA+=4;
  
  for(int i=0; i<NUM_LEDS; i++){
    if(logo[i] == 1){
      delay(0);
    }
    else if(logo[i] == 2){
      leds[i] = CHSV(hueA, 255, 255);
      FastLED.show();
      delay(20);
    }else{
      leds[i] = CHSV(hueB, 255, 90);
      hueB+=28;
      FastLED.show();
      delay(3);
    }
  }
}

void patternB(){
  static uint8_t hueA;
  static uint8_t hueB;
  
  hueA+=7;
  
  for(int i=0; i<NUM_LEDS; i++){
    if(logo[i] == 1){
      delay(0);
    }
    else if(logo[i] == 2){
      leds[i] = CHSV(hueA, 255, 255);
      delay(2);
    }else{
      leds[i] = CHSV(hueB, 255, 90);
      hueB+=4;
      delay(3);
    }
  }
  FastLED.show();
}

void patternC(){
  static uint8_t hueA;
  static uint8_t hueB;
  
  hueB+=7;
  
  for(int i=0; i<NUM_LEDS; i++){
    if(logo[i] == 1){
      delay(0);
    }
    else if(logo[i] == 2){
      leds[i] = CHSV(hueA, 255, 255);
      hueA+=4;
      delay(3);
    }else{
      leds[i] = CHSV(hueB, 255, 90);
      delay(2);
    }
  }
  FastLED.show();
}

void patternD(){
  static uint8_t hueA;
  static uint8_t hueB;
  
  hueB+=4;
  
  for(int i=0; i<NUM_LEDS; i++){
    if(logo[i] == 1){
      delay(0);
    }
    else if(logo[i] == 2){
      leds[i] = CHSV(hueA, 255, 255);
      hueA+=28;
      FastLED.show();
      delay(10);
    }else{
      leds[i] = CHSV(hueB, 255, 90);
      FastLED.show();
      delay(2);
    }
  }
}

void logoSetup (){
  //t
  logo[19] = 1;
  logo[27] = 1;
  logo[35] = 1;
  logo[44] = 1;
  for(int i=50; i<60; i++)
    logo[i] = 1;
  logo[76] = 1;
  logo[83] = 1;

  //i
  logo[114] = 1;
  for(int i=116; i<124; i++)
    logo[i] = 1;

  //j
  logo[178] = 1;
  for(int i=180; i<190; i++)
    logo[i] = 1;
  logo[193] = 1;
  logo[220] = 1;
  logo[221] = 1;

  //underline
  int current = 30;
  for(int i=0; i<8; i++){
    if(i%2==0){
      logo[current] = 2;
      current+=3;
    }else{
      logo[current] = 2;
      current+=29;
    }   
  }  
}
