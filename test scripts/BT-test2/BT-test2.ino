//#include <SoftwareSerial.h>

//SoftwareSerial hc06(4, 2);


const char endMarker = '\n';
const byte numChars = 32;

char receivedBT[numChars];
String BT;
byte BTindex = 0;
bool newBT = false;

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  //Initialize Bluetooth Serial Port
  Serial1.begin(9600);

  Serial.println("ready");
}

void loop(){
  //parrot();  
  checkBT();
  
  if(newBT){
    Serial.println(BT);
    newBT = false;
  }
  
}

void checkBT(){
  char rc;
  while(Serial1.available() && not newBT){
      rc = Serial1.read();
      if(rc == endMarker){
        receivedBT[BTindex] = '\0';
        BTindex = 0;
        newBT = true;
        BT = String(receivedBT);
      }
      else{
        receivedBT[BTindex] = rc;
        BTindex ++;
      }
  }
}

void parrot(){
   //Write data from HC06 to Serial Monitor
  if (Serial1.available()){
    Serial.write(Serial1.read());
  }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()){
    Serial1.write(Serial.read());
  }  
}
