
char data[50];
String str="Hi\r";
byte indx,d;
int count=0;
void setup() {
  Serial.begin(9600);
  
  
}

void loop() {
 
  Serial.println(str);
  Serial.print('\t');
  delay(2000);
 
  if(Serial.available()>0){
    d=Serial.read();
    data[indx++]=d;
    if(d=='\r'){
      
      Serial.println(data);
      count++;
      delay(1000);
      
      data[50]=0;
    }

}
  

}
