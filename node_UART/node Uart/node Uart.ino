#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte indx;
char data[50];
String str="hello\r";
int count=0;
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  }

  

void loop() {
  
 
  if(Serial.available()>0){
    byte c=Serial.read();
    data[indx++]=c;
    if(c=='\r'){
    lcd.setCursor(1,0);
    lcd.print(data);
    count++;
    delay(1000);
    lcd.clear();
    data[50]=0;  
    }
    if(count==1);{
      Serial.print(str);
      Serial.print('\t');
      delay(2000);
      count++;
    }
    
     
    
  
    }

}
