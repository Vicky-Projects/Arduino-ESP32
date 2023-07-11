const int ledpin = 4;
const int buttonpin = 5;
int buttonstate=LOW;
void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(buttonpin,INPUT);

}

void loop() {
  buttonstate=digitalRead(buttonpin);

  if(buttonstate == HIGH)
  {
    digitalWrite(ledpin,HIGH);
    }else{
    digitalWrite(ledpin,LOW);
  }

}
