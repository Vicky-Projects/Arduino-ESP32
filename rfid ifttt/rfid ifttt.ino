#include<ESP8266WiFi.h>
const char* ssid = "Pantech- SF";
const char* password = "elearning@2022";
const char* servername="https://maker.ifttt.com/trigger/{name}/json/with/key/bLYbrNVWi9lIxjYqTQxgY1";
unsigned long timerdelay=10000;
unsigned long lasttime=0;
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  Serial.println("connecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("connecting to wifi");
  Serial.println(WiFi.localIP());


}

void loop() {
  if((millis()-lasttime)>timerdelay){
    if(WiFi.status()==Wl_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      http.begin(client,servername);
      http.addHeader("content-type":text/html;charset=utf-8);
      String httpRequestData=
    }
  }


}
