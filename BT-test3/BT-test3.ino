#include <SoftwareSerial.h>
#define endMarker   '\n'
#define numChars    32
char receivedChars[numChars];
byte index = 0;
bool newData = false;
String received = "";

SoftwareSerial hc06(4, 2);

void setup() {

  Serial.begin(9600);
  hc06.begin(9600);

}

void loop() {
  if(newData){
    Serial.println(received);
    newData = false;
  }
}

void checkSerial(){
  char rc;
  
  while(hc06.available() > 0 && not newData){
    rc = Serial.read();
    if(rc == endMarker){
      receivedChars[index] = '\0';
      index = 0;
      newData = true;
      received = String(receivedChars);
    }
    else{
      receivedChars[index] = rc;
      index ++;
    }
  }
}
