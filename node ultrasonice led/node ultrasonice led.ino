int d,dur;
void setup() {
  pinMode(21,OUTPUT);
  pinMode(18,INPUT);
  pinMode(25,OUTPUT);
  Serial.begin(9600);


}

void loop() {
  digitalWrite(21,HIGH);
  delay(2000);
  digitalWrite(21,LOW);
  dur=pulseIn(18,HIGH);
  d=(dur*0.034)/2;
  if(d>10){
    digitalWrite(25,HIGH);
  }else{
    digitalWrite(25,LOW);
  }
  delay(2000);
}