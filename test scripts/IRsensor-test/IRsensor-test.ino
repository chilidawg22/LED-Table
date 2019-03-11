const int IRpin1 = 3; 
const int IRpin2 = 9;
const int ledPin = 13; //pin13 built-in led
void setup()
{
  Serial.begin(9600);
  pinMode(IRpin1, INPUT); // set trackingPin as INPUT
  pinMode(IRpin2, INPUT);
  pinMode(ledPin, OUTPUT); //set ledPin as OUTPUT
}
void loop()
{
  boolean IR1 = digitalRead(IRpin1);
  boolean IR2 = digitalRead(IRpin2);

  if (IR1 == LOW) { //if it's detecting something
    Serial.println("IR sensor 1 is detecting something");
    } 
  else if (IR1 == HIGH) {
    Serial.println("IR sensor 1 is not detecting anything");
    }

  if (IR2 == LOW) {
    Serial.println("IR sensor 2 is detecting something");
    }
   else if (IR2 == HIGH) {
     Serial.println("IR sensor 2 is not detecting anything");
    }

   delay(250);
}
