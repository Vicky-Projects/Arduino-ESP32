#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
char data[50];
String str="Hi\r";
byte indx,d;
int count=0;
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
}

void loop() {
 
  Serial.print(str);
  Serial.print('\t');
  delay(2000);
 
  if(Serial.available()>0){
    d=Serial.read();
    data[indx++]=d;
    if(d=='\r'){
      lcd.setCursor(1,0);
      lcd.print(data);
      Serial.println(data);
      count++;
      delay(1000);
      lcd.clear();
      data[50]=0;
    }

}
  

}
