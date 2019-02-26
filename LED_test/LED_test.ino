#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    150

CRGB leds[NUM_LEDS];
bool ons[NUM_LEDS];

void setup() {
  for( int p = 0; p <= NUM_LEDS - 1; p ++){
    ons[p] = true;
  }
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  FollowToEnd();
  //otherFollow();
}

  void FollowToEnd(){
      for( int p = 0; p <= NUM_LEDS - 1; p ++){
    if(ons[p]){
      leds[p] = CRGB(random(125), random(75), random(255));
    }
    else{
      leds[p] = CRGB(0, 0, 0);
    }
    FastLED.show();
    ons[p] = not ons[p];
    delay(50);
  }
  }

  void otherFollow(){
    for(int p = 0; p <= NUM_LEDS - 1; p++){
      leds[p] = CRGB(random(125), random(75), random(255));
      if(p - 5 < 0){
        
      }
      leds[p - 5] = CRGB(0, 0, 0);
      FastLED.show();
      delay(50);
    }
  }
