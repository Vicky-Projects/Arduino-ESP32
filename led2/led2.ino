#include <dummy.h>


void setup() {
  pinMode(D2,HIGH);
  Serial.begin(9600);  

}

void loop() {
  digitalWrite(D2,HIGH);
  Serial.println("on");
  delay(2000);
  digitalWrite(D2,LOW);
  Serial.println("off");
  delay(2000);


}
