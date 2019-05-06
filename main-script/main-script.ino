#include <FastLED.h>

const int X = 4;
const int Y = 4;

int stage = 0;
int coX = 0;
int coY = 0;
int G = 0;
int B = 0;

bool manual = false;

const char endMarker = '\n';
const byte numChars = 32;

String Ser;
bool newSerial = false;

char receivedBT[numChars];
byte BTindex = 0;

char receivedSerial[numChars];
byte Serialindex = 0;

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
  Serial1.begin(9600);
  Serial.println("ready");

}

void loop() {
  
  checkBT();
  checkSerial();
  
  if(newSerial){
    Serial.println(Ser);
    Serial1.println(Ser);
    newSerial = false;

    switch(stage){
      case 0:
        if(Ser == "manual"){
          manual = true;
          Serial.println("Manual control enabled");
          Serial1.println("Manual control enabled");
        }
        else if(Ser == "IRgrid"){
          manual = false;
          Serial.println("Manual control disabled");
          Serial1.println("Manual control disabled");
        }

        else if(Ser == "GB"){
          stage = 1;
          Serial.println("Green, Blue manual input mode entered");
          Serial1.println("Green, Blue manual input mode entered");
        }
        break;

      case 1:
        coX = Ser.toInt();
        stage = 2;
        Serial.println("X-position set to: " + Ser);
        Serial1.println("X-position set to: " + Ser);
        break;

      case 2:
        coY = Ser.toInt();
        stage = 3;
        Serial.println("Y-position set to: " + Ser);
        Serial1.println("Y-position set to: " + Ser);
        break;

      case 3:
        G = Ser.toInt();
        stage = 4;
        Serial.println("Green intensity value set to: " + Ser);
        Serial1.println("Green intensity value set to: " + Ser);
        break;

      case 4:
        B = Ser.toInt();
        Serial.println("Blue intensity value set to: " + Ser);
        Serial1.println("Blue intensity value set to: " + Ser);
        leds[LEDmatrix[coX][coY]] = CRGB(0, G, B);
        Serial.println("LED light intensity set");
        Serial1.println("LED light intensity set");
        stage = 0;
        break;
    }
    
  }

  if(!manual){
    IRLED();
  }
  FastLED.show();
}

void IRLED(){
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
}

void checkBT(){
  char rc;
  while(Serial1.available() && not newSerial){
      rc = Serial1.read();
      if(rc == endMarker){
        receivedBT[BTindex] = '\0';
        BTindex = 0;
        newSerial = true;
        Ser = String(receivedBT);
      }
      else{
        receivedBT[BTindex] = rc;
        BTindex ++;
      }
  }
}

void checkSerial(){
  char rc;
  while(Serial.available() && not newSerial){
      rc = Serial.read();
      if(rc == endMarker){
        receivedSerial[Serialindex] = '\0';
        Serialindex = 0;
        newSerial = true;
        Ser = String(receivedSerial);
      }
      else{
        receivedSerial[Serialindex] = rc;
        Serialindex ++;
      }
  }
}
