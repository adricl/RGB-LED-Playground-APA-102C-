#include <ESP8266WiFi.h>

//LED Settings
#include <FastLED.h>
#define LED_PIN     4
#define CLK_PIN     5
#define COLOR_ORDER BGR
#define CHIPSET     APA102
#define NUM_LEDS    240
CRGB leds[NUM_LEDS];

//WIFI Settings
const char* ssid     = "Your WiFi SSID";
const char* password = "Your WiFi Password";
// const char* host = "utcnist2.colorado.edu";
const char* host = "128.138.141.172";

void setup() {
  Serial.begin(115200);                   // diagnostic channel

  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid, password);
  delay(100);
}


void loop() {

}

