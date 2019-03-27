#include <FastLED.h>

const int LEDpower = 250;
const int LEDpin = 6;
const int pinMatrix[4][4] = {{22, 23, 24, 25}, {26, 27, 28, 29}, {30, 31, 32, 33}, {34, 35, 36, 37}};
const int numLEDs = 16;
const int LEDmatrix[4][4] = {{0, 7, 8, 15}, {1, 6, 9, 14}, {2, 5, 10, 13}, {3, 4, 11, 12}}; //1 LED per square

CRGB leds[numLEDs];

void setup() {
  FastLED.addLeds<WS2811, LEDpin, GRB>(leds, numLEDs);
  for(int i : pinMatrix){
    pinMode(i, INPUT);
  }
}

void loop() {
    for(int x = 0; x <= 3; x ++){
      for (int y = 0; y <= 3; y ++){
        if(digitalRead(pinMatrix[x][y])) leds[LEDmatrix[x][y]] = CRGB(LEDpower, LEDpower, LEDpower);
     }
   }
   FastLED.show();
}
