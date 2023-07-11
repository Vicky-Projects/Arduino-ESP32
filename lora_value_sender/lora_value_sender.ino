
#include<DHT.h>
#include<SPI.h>
#include<LoRa.h>

const int ss=5;
const int rst=35;
const int dio0=34;
DHT dht(4,DHT11);
int d,dur;
float h,t;

void humi(float h){
  h=dht.readHumidity();
  Serial.print("humi =");Serial.println(h);
  Serial.print("\n");
  lora(h);
  delay(2000);
  
}
void temp(float t){
  t=dht.readTemperature();
  Serial.print("temp =");Serial.println(t);
  lora(t);
  delay(2000);
  
}
void ultra(int d){
  digitalWrite(17,HIGH);
  delay(2000);
  digitalWrite(17,LOW);
  dur=pulseIn(16,HIGH);
  d=((dur*0.034)/2);
  Serial.print("distance=");Serial.println(d);
  lora(d);
  
  delay(2000);
}

void lora(int a){
  LoRa.beginPacket();
  LoRa.print(a);
  LoRa.endPacket();

  
}
void setup() {
  
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(16,INPUT);
  dht.begin();
  while (!Serial);

  Serial.println("LoRa Sender");
  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(20);
  LoRa.setSyncWord(0xF4);
  Serial.println("LoRa Initializing ok!");
}
 
  

void loop() {
  
  humi(h);
  temp(t);
  ultra(d);
  
  
}












