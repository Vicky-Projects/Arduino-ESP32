void setup() {
  pinMode(D5,INPUT);
  Serial.begin(9600);

}

void loop() {
  int IR=digitalRead(D5);
  Serial.println(IR);
  delay(200);
  if(IR == 0 ){
    Serial.println("motion detected");
     
  }else{
    Serial.println("not");
  }
  }


