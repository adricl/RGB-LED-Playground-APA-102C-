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
  
  
  delay( 300 ); 
}

void loop() {
  uint32_t currentTime = millis();
  static int pos = 0;

  for(int i = 0; i < LED_STRIP_COUNT; i++){
    Serial.printf(" %d ", pos);
    leds[i] = array1[pos];
    Serial.printf(" %x ", array1[pos]);
    pos++;
  }
  FastLED.show();
  if (pos >= (sizeof(array1))/sizeof(int)) {
    pos = 0;  
  }
  delay(100);
  Serial.print("Delay\n");
 
}


