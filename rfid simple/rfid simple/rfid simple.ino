#include<SPI.h>
#include<MFRC522.h>
MFRC522 rfid(D4,D3);
MFRC522::MIFARE_Key key;
String tag;
void setup(){
  Serial.begin(9600);
  pinMode(D8,OUTPUT);
  SPI.begin();
  rfid.PCD_Init();
}
void loop(){
  if(!rfid.PICC_IsNewCardPresent())
  return;
  if(rfid.PICC_ReadCardSerial()){
    for(byte i=0;i<4;i++){
      tag=rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    if(tag=="25"){
      Serial.println("granted");
      digitalWrite(D8,HIGH);
      delay(1000);
      digitalWrite(D8,LOW);
    }else{
      Serial.println("denied");
      digitalWrite(D8,HIGH);
      delay(200);
      digitalWrite(D8,LOW);
      delay(200);
      digitalWrite(D8,HIGH);
      delay(200);
      digitalWrite(D8,LOW);
    }
    tag="";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
