#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
float vref=3.3;
float resolution = vref/1023;
float temp;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  


}

void loop() {
  lcd.clear();
  temp=analogRead(A0);
  temp=(temp*resolution);
  temp=temp*100;
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(temp);
  Serial.println(temp);
  delay(1000);
  lcd.clear();
 

}
