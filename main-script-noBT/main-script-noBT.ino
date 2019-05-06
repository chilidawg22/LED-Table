#include <FastLED.h>

const int X = 4;
const int Y = 4;

const int IRMatrix[X][Y] = {{33, 42, 49, 45}, {26, 37, 34, 53}, {22, 41, 38, 25}, {50, 30, 29, 46}};
const int IRs[X*Y] = {22, 25, 26, 29, 30, 33, 34, 37, 38, 41, 42, 45, 46, 49, 50, 53};

CRGB on;
CRGB off;
const int LEDpin = 6;
const int LEDmatrix[X][Y] = {{0, 1, 2, 3}, {7, 6, 5, 4}, {8, 9, 10, 11}, {15, 14, 13, 12}}; //1 LED per square
CRGB leds[X*Y];

void setup() {
  on = CRGB(250, 250, 250);
  off = CRGB (0, 0, 0);

  FastLED.addLeds<WS2811, LEDpin, GRB>(leds, X*Y);
  
  Serial.begin(9600);
  Serial.println("ready");

}

void loop() {
  String out = "";
    for(int x = 0; x <= X-1; x ++){
      for(int y = 0; y <= Y-1; y ++){
        if(!digitalRead(IRMatrix[x][y])){
          leds[LEDmatrix[x][y]] = on;
          out += String(x) + ", " + String(y) + "; ";
        }
        else{
          leds[LEDmatrix[x][y]] = off;
        }
      }
    }
    Serial.println(out);
    FastLED.show();
}
