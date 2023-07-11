int ldr,ir;
unsigned int ldra;
void setup() {
  Serial.begin(9600);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  pinMode(A0,INPUT);
  ldr=0;

}

void loop() {
  ir=digitalRead(D1);
  ldr=digitalRead(D2);
  ldra=analogRead(A0);
  Serial.println(ir);
  Serial.println(ldr);
  Serial.println(ldra);
  Serial.print('\n');
  delay(1000);
  if(ir==0){
    Serial.println("obj detected");
    if(ldr==1){
      Serial.println("place is dark");
      digitalWrite(D3,HIGH);
      delay(1000);
      }else{
        Serial.println("place is bright");
        digitalWrite(D3,LOW);
        delay(1000);
      }
      
  }else{
        Serial.println("obj not detected");
        Serial.println("place is bright");
        digitalWrite(D3,LOW);
        delay(1000);
  
}
}