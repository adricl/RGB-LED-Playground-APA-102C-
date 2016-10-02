#include <Arduino.h>

#include <FastLED.h>

#include "new_graphics.h"

//LED Settings

#define PIN_DATA 4 //D2
#define PIN_CLK 5 //D1
#define BRIGHTNESS  40
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define LED_STRIP_COUNT 30
CRGB leds[LED_STRIP_COUNT];

//SLICES FOR IMAGE
#define NUM_SLICES  150

void setup() {

  delay( 300 ); // power-up safety delay


  Serial.begin(57600);


  FastLED.addLeds<LED_TYPE, PIN_DATA, PIN_CLK, COLOR_ORDER>(leds, LED_STRIP_COUNT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.print("\nINIT\n");
  
  //FastLED.showColor(CRGB::Black);
  
  
  delay( 3000 ); 
}

void loop() {
  uint32_t currentTime = millis();
  static int slice = 0;


  for(int led_num = 0; led_num < LED_STRIP_COUNT; led_num++){

    uint8_t pos = slice * LED_STRIP_COUNT + led_num;
    //Serial.printf("Slice: %d, LED: %d, pos: %d", slice, led_num, pos);   
    leds[led_num] = array1[pos];
    
    //Serial.printf(" %x ", array1[pos]);
    
  }
  //Serial.print("\n");
  FastLED.show();
  FastLED.delay(40);
  if ( slice >= NUM_SLICES){
    slice = 0;
  }
  else {
    slice++; 
  }
}


