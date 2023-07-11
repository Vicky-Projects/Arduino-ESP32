#include<SPI.h>
#include<LoRa.h>
const int ss=5;
const int rst=35;
const int dio0=34;
int count=0;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("LoRa Sender");

  LoRa.setPins(ss, rst, dio0);
  while(!LoRa.begin(433E6)){
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF4);
  Serial.println("LoRa Initializing OK!");

}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(count);
  LoRa.beginPacket();
  LoRa.print("hello");
  LoRa.print(count);
  LoRa.endPacket();
  count++;
  delay(10000);
}

