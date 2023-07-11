#include<SPI.h>
#include<LoRa.h>

const int ss=10;
const int rst=8;
const int dio0=9;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("LoRa Receiver");
  LoRa.setPins(ss,rst,dio0);
  while(!LoRa.begin(433E6)){
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF4);
  Serial.println("LoRa Initializing ok!");

}

void loop() {
  int packetSize = LoRa.parsePacket();
  if(packetSize){
    Serial.print("Received packet");
    while(LoRa.available()){
      String LoRaData=LoRa.readString();
      Serial.print(LoRaData);
    }
    Serial.print("  with RSSI");
    Serial.println(LoRa.packetRssi());
  }

}
