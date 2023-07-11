#include<Wire.h>
#include<LiquidCrystal_I2C.h>

int ldr;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(D5,INPUT);
  pinMode(D6,OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();

}

void loop() {
  ldr=digitalRead(D5);
  lcd.setCursor(2,0);
  lcd.print(ldr);
  if(ldr==1){
    digitalWrite(D6,HIGH);
    lcd.setCursor(3,1);
    lcd.print("room is dark");
  }else{
    digitalWrite(D6,LOW);
    lcd.setCursor(3,1);
    lcd.print("room is brighter");
  }
  

}
