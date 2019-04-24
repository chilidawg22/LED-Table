#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    16

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  }


void loop() {
    for(int i = 0 ; i<= NUM_LEDS - 1; i++){

        leds[i] = CRGB(250, 250, 250);
       
      }
    FastLED.show();
    
  }
