#include <FastLED.h>

#define LED_PIN     4
#define CLK_PIN     5
#define COLOR_ORDER BGR
#define CHIPSET     APA102
#define NUM_LEDS    240

#define BRIGHTNESS  100
#define FRAMES_PER_SECOND 60

bool gReverseDirection = false;


CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, CLK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
  //FastLED.setMaxPowerInVoltsAndMilliamps(5,2000); //For later versions of FastLED
  
}

void loop()
{
  static uint8_t counter = 0;
  static uint8_t counter_mod = 0;
  
  uint8_t value = map(cubicwave8(counter_mod), 0, 255, 100, 255);
  FastLED.showColor(CHSV(0, 255, value));

  
  FastLED.show(); // display this frame

  if((counter % 2) == 0){
    counter_mod++;
  }
  counter++;
  
}

