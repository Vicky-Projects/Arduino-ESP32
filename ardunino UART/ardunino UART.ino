#include<Arduino.h>

#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
char data1[50];
byte indx,d;
int count=0;
void setup() {
  Serial.begin(115200);
   lcd.init();
  lcd.backlight();
  lcd.clear();

  while(Serial.available()<=0){
  Serial.write("ino:hi\r");
  delay(3000);
   }
  while(d==!'\r'){
  if(Serial.available()>0){
    d=Serial.read();
    data1[indx++]=d;
    if(d=='\r'){
      Serial.println(data1);
      lcd.setCursor(1,0);
      lcd.print(data1);
      Serial.write("1");
      indx=0;
      lcd.clear();
      delay(1000);
    }
  }
}
}






  
 

  


