#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<DHT.h>
DHT dht(D5,DHT11);
const char* ssid="Pantech- SF";
const char* password="elearning@2022";

ESP8266WebServer server(80);
float t;
float h;
void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(D5,INPUT);
  dht.begin();
  Serial.println("connectin to");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected...!");
  Serial.print("Got ip:");
  Serial.println(WiFi.localIP());

  server.on("/",myfunc);

  server.begin();
  Serial.println("http started");



}

void loop() {
  server.handleClient();
  
}

void myfunc(){
  //while(true){
  t=(dht.readTemperature());
  h=(dht.readHumidity());
  server.send(200,"text/html",SendHTML(t,h));
  Serial.println("Temperature in C:");  
   Serial.println(t);  
   Serial.println("Humidity in C:");  
   Serial.println(h);  
   delay(1000); 
   
  //}
  
}

String SendHTML(float Temperaturestat,float Humiditystat){
  String ptr="<!DOCTYPE html><html>\n";
    ptr += "<head><meta http-equiv=\"refresh\" content=\"2\">\n";
      ptr += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
      ptr += "<link rel=\"stylesheet\" href=\"style for temp humi icon.css\">\n";
      ptr += "<script src=\"https://kit.fontawesome.com/a514c7f8b1.js\" crossorigin=\"anonymous\">\n";
      ptr += "</script>\n";
      ptr += "<title>ESP8266 with Dht11 Sensor</title>\n";
      ptr += "<style>\n";
      ptr += "h1 {color: red;font-size: 50px;margin: 0px;background-color: black;text-align: center;}\n";
      ptr += "</style>\n";
      ptr += "</head>\n";
      ptr += "<body>\n";
      ptr += "<h1>ESP8266 with dht11</h1>\n";
      ptr += "<br><p style=\"text-align: center; font-size: 20px; font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif; color: rgb(252, 10, 10);\">Temperature:\n";
      ptr += (float)Temperaturestat;
      ptr += "<i class=\"fa-sharp fa-solid fa-thermometer\" style=\"color: coral; font-size: 30px;\"></i></p><br>\n";
      ptr += "<p style=\"text-align: center; font-size: 20px; font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif; color: blue;\">Humidity:\n";
      ptr += (float)Humiditystat;
      ptr +="<i class=\"fas fa-tint\" style=\"color: aqua; font-size: 30px;\"></i></p>\n";
      ptr += "</body>\n";
      ptr += "</html>\n";
      return ptr;

}
