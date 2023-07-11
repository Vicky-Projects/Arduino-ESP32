#include<Wire.h>
#include<MAX30100_PulseOximeter.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define REPORT_MS 1000
float BPM,SPO2;
uint32_t tsLastReport=0;
PulseOximeter pox;
void onBeatDetected()
{
  Serial.println("Beat Detected!");
}
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  Serial.print("init pulse oxi");
  lcd.print("initializing pulse");

  if(!pox.begin())
  {
    Serial.println("fail");
    lcd.setCursor(1,0);
    lcd.println("failed");
    for(;;);
  }
  else
  {
    lcd.setCursor(1,0);
    lcd.println("success");
    Serial.println("success");
   

  }
   pox.setOnBeatDetectedCallback(onBeatDetected);



}

void loop() {
  pox.update();
  BPM=pox.getHeartRate();
  SPO2=pox.getSpO2();
  if(millis()-tsLastReport>REPORT_MS)
  {
    Serial.print("heart rate:");
    Serial.print(BPM);
    Serial.print("SpO2:");
    Serial.print(SPO2);
    Serial.println("%");

    
    lcd.setCursor(1,0);
    lcd.print(BPM);
    lcd.print("BPM");
    lcd.setCursor(1,1);
    lcd.print(SPO2);
    lcd.print("SPO2");
    tsLastReport=millis();
     }

}
