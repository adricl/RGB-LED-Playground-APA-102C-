#include <FastLED.h>

#include "new_graphics.h"

//LED Settings

#define PIN_DATA 13
#define PIN_CLK 14
#define BRIGHTNESS  64
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

}

void loop() {
  uint32_t currentTime = millis();
  
  //while (millis()< currentTime + 8000) { 

    Serial.print("loop\n");
    for(int pos = NUM_LEDS; pos > 0; pos--){
      Serial.printf("pos %d\n", pos);
      for (int x = 0; x < NUM_SLICES; x++){
        int line = x + ((NUM_LEDS - pos)*NUM_SLICES);
        Serial.printf("Line %d\n", line);
        leds[pos - 1] = array1[line];
      }
        FastLED.show();        
        delayMicroseconds(60); //may need to increase / decrease depending on spin rate
      
      
    }
      
  
  delayMicroseconds(1000);
  Serial.print("Delay\n");
//}
  
}
