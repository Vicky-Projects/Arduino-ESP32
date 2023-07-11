byte indx;
char data[50];
int count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    byte c=Serial.read();
    data[indx++]=c;
    if(c=='\r'){
    Serial.println(data);
    count++;
    delay(1000);
    data[50]=0;
  }
  if(count==1){
    Serial.println("hello LPC");
    delay(1000);
    count=0;

  }
}else{
     Serial.println("no data");
      
  }
  
}
