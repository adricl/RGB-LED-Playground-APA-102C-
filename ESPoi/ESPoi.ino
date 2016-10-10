#include <Arduino.h>

#include <FastLED.h>

#include "new_graphics.h"

//LED Settings

#define PIN_DATA 4 //D2
#define PIN_CLK 5 //D1
#define BRIGHTNESS  10
#define LED_TYPE    APA102
#define COLOR_ORDER BGR

//LED COUNT
#define LED_STRIP_COUNT 30


CRGB leds[LED_STRIP_COUNT];

void setup() {

  delay( 300 ); // power-up safety delay

  FastLED.addLeds<LED_TYPE, PIN_DATA, PIN_CLK, COLOR_ORDER>(leds, LED_STRIP_COUNT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  delay( 300 ); 
}

void loop() {
  uint32_t currentTime = millis();
  static int slice = 0;
  static int slice_count = (int) ( (sizeof(array1)/sizeof(int))/LED_STRIP_COUNT);
  
  for(int led_num = 0; led_num < LED_STRIP_COUNT; led_num++){
    int pos = led_num * slice_count + slice;
    leds[led_num] = array1[pos];        
  }
  FastLED.delay(20);

  if ( slice >= slice_count){
    slice = 0;
  }
  else {
    slice++; 
  }
}


