#include<DHT.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(2,DHT11);
void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
}
void loop() {
  lcd.setCursor(1,0);
  lcd.print("t=");
  lcd.print((dht.readTemperature()));
  lcd.setCursor(1,1);
  lcd.print("h=");
  lcd.print(dht.readHumidity());
  delay(1000);
  lcd.clear();
}
