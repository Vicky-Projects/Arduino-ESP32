#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
char data[50];
int num=2023;
int count=0;
byte indx,c;
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  while(c==!'\r'){
  if(Serial.available()>0){
    byte c=Serial.read();
    data[indx++]=c;
    if(c=='\r'){
      Serial.println(data);
      lcd.setCursor(1,0);
      lcd.print(data);
      lcd.clear();
      indx=0;
      delay(2000);
      
      
    }
  }
     
  }
  while(Serial.available()==!"1"){
  Serial.println("ooo\r");
  delay(2000); 
  
  
  
}
}



 

 
