int d,dur;
void setup() {
  pinMode(D4,OUTPUT);
  pinMode(D5,INPUT);
  Serial.begin(9600);


}

void loop() {
  digitalWrite(D4,HIGH);
  delay(2000);
  digitalWrite(D4,LOW);
  dur=pulseIn(D5,HIGH);
  d=(dur*0.034)/2;
  Serial.println(d);  
  delay(2000);
}
