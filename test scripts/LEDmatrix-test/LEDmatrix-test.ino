#include <FastLED.h>
#define LEDpin     6
#define numLEDs    16

int matrix[4][4] = {{0, 7, 8, 15}, {1, 6, 9, 14}, {2, 5, 10, 13}, {3, 4, 11, 12}}; 

CRGB leds[numLEDs];
String out[];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, LEDpin, GRB>(leds, numLEDs);
}

void cut(String in, char sep){
  int prev = 0;
  int count = 0;
  String med[10];
  
  for(int p = 0; p < in.length(); p ++){
    if(in[p] == sep){
      med[count] = in.substring(prev, p - 1);
      prev = p + 1;
      count ++;
    }
  }

  int c = 0;
  String out[count];
  for(String i : med){
    if(i != NULL){
      out[c] = i;
      c ++;
    }
  }
}

void loop() {
  cut("yo, qo", ',');
  for(String i : cutted){
    Serial.println(i);
  }
}
