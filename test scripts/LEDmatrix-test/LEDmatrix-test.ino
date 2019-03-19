#include <FastLED.h>
#define LEDpin     6
#define numLEDs    16

int matrix[4][4] = {{0, 7, 8, 15}, {1, 6, 9, 14}, {2, 5, 10, 13}, {3, 4, 11, 12}}; 

CRGB leds[numLEDs];


void setup() {
  FastLED.addLeds<WS2811, LEDpin, GRB>(leds, numLEDs);
  leds[matrix[0][0]] = CRG
}

void loop() {
  // put your main code here, to run repeatedly:

}
