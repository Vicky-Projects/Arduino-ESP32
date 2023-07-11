
#include<Wire.h>

char data[50];
int count=0;
byte indx,c;
void setup() {
  Serial.begin(9600);

     
  }
  void loop(){
      if(Serial.available()>0){
    byte c=Serial.read();
    data[indx++]=c;
    if(c=='\r'){
      Serial.println(data);
      indx=0;
      delay(2000);
      
      
    }
  }else{
Serial.println("no data rece");
  }
  }
  
 




 

 
