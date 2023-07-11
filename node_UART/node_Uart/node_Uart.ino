
byte indx;
char data[50];
String str="hello\r";
int count=0;
void setup() {
  Serial.begin(9600);
  
  
  }

  

void loop() {
  
  if(count==1){
      Serial.println(str);
      Serial.print('\t');
      delay(2000);
      count=0;
    }
  if(Serial.available()>0){
    byte c=Serial.read();
    data[indx++]=c;
    if(c=='\r'){
    
    Serial.println(data);
    count++;
    delay(1000);
    data[50]=0;  
    }
    
    
     
    
  
    }

}
