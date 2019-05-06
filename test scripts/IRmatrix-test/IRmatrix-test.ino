const int IRMatrix[4][4] = {{33, 42, 49, 45}, {26, 37, 34, 53}, {22, 41, 38, 25}, {50, 30, 29, 46}};
const int IRs[16] = {22, 25, 26, 29, 30, 33, 34, 37, 38, 41, 42, 45, 46, 49, 50, 53};

String out = "";

void setup() {
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() {
  delay(500);
  out = "";
  //pin();

  matrix();
  
  Serial.println(out);
}

void pin(){
  for(int i : IRs){
    if(!digitalRead(i)){
      out += String(i) + "; ";
    }
  }
}

void matrix(){
    for(int x = 0; x <= 3; x ++){
      for(int y = 0; y <= 3; y ++){
        if(!digitalRead(IRMatrix[x][y])){
          out += String(x) + ", " + String(y) + "; ";
        }
      }
    }
}
