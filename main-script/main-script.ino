#include <FastLED.h>

//global size variable
const int X = 4;
const int Y = 4;

//global constants for keeping track index of LED and IR-sensor grid coordinates
const int IRMatrix[X][Y] = {{33, 42, 49, 45}, {26, 37, 34, 53}, {22, 41, 38, 25}, {50, 30, 29, 46}};
const int LEDmatrix[X][Y] = {{0,  , 2, 3}, {7, 6, 5, 4}, {8, 9, 10, 11}, {15, 14, 13, 12}};

const int LEDpin = 6; //global variable containing the number of the pin the LEDs are connected to


//global variables containing default on/ off states for LEDs
CRGB on;
CRGB off;g

CRGB leds[X*Y];

void setup() {
  //define LED on/ off states
  on = CRGB(250, 250, 250);
  off = CRGB (0, 0, 0);

  FastLED.addLeds<WS2811, LEDpin, GRB>(leds, X*Y);  //setup LEDs
}

void loop() {
    for(int x = 0; x <= X-1; x ++){
      for(int y = 0; y <= Y-1; y ++){
        if(!digitalRead(IRMatrix[x][y])){
          leds[LEDmatrix[x][y]] = on;
        }
        else{
          leds[LEDmatrix[x][y]] = off;
        }
      }
    }
    FastLED.show();
}
