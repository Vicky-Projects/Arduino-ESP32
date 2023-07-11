#include <SPI.h>
#include <LoRa.h>
const int ss=5;
const int rst=35;
const int dio0=34;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");
LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSyncWord(0xF4);
  Serial.println("LoRa Initializing ok!");
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.println("Received packet '");

    // read packet
    while (LoRa.available()) {
      float h= ((float)LoRa.read());
      Serial.print("humi =");Serial.println(h);
      delay(2000);
      
      
      
    }
    while(LoRa.available()){
      float t= ((float)LoRa.read());
      Serial.print("temp =");Serial.println(t);
      delay(2000);
      
            
    }
    while(LoRa.available()){
      float d= ((float)LoRa.read());
      Serial.print("distance=");Serial.println(d);
      delay(2000);
      
    }

    
  }
}