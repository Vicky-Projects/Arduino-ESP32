int ldr;
void setup() {
  pinMode(D5,OUTPUT);
  pinMode(D7,INPUT);
  Serial.begin(9600);
}
void loop() {
  ldr=digitalRead(D7);
  Serial.print(ldr);
  if(ldr==1){
    digitalWrite(D5,HIGH);
  }else{
    digitalWrite(D5,LOW);
  }

}
