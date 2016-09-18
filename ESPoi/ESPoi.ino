#include <FastLED.h>

#include "new_graphics.h"

//LED Settings

#define PIN_DATA 13
#define PIN_CLK 14
#define BRIGHTNESS  40
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define LED_STRIP_COUNT 240
#define NUM_LEDS 20
CRGB leds[NUM_LEDS];

//SLICES FOR IMAGE
#define NUM_SLICES  150

void setup() {

  delay( 300 ); // power-up safety delay


  Serial.begin(57600);


  FastLED.addLeds<LED_TYPE, PIN_DATA, PIN_CLK, COLOR_ORDER>(leds, LED_STRIP_COUNT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.print("\nINIT\n");
  
  FastLED.showColor(CRGB::Black);
  
  
  delay( 300 ); 
}

void loop() {
  uint32_t currentTime = millis();
  
  //while (millis()< currentTime + 8000) { 
//Slice# + (led# * SLICE_COUNT)

    Serial.print("loop\n");
    for(int slice = 0; slice < NUM_SLICES; slice++){
      FastLED.clear();
      for(int led = 0; led < NUM_LEDS; led++){
        int pos = slice + (led * NUM_SLICES);
        if (pos > 2999){
          Serial.print("Error\n");
        }
        else {
          Serial.printf("Line %d", pos);
          Serial.printf(" 0x%06x\n", array1[pos]);
          //leds[ 220+ led ] = array1[pos];
        }
      }
      FastLED.show();        
      delayMicroseconds(1000); //may need to increase / decrease depending on spin rate
      Serial.printf("Slice %d\n", slice);
    }
  delayMicroseconds(10);
  Serial.print("Delay\n");
//}
 
}
