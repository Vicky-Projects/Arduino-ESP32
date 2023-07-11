#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>


const char* ssid = "Pantech- SF";
const char* password = "elearning@2022";
ESP8266WebServer server(80);
void myfunc(){
  server.send(200,"text/html",webpage());
  delay(1000);
  
}
void myfunc1(){
  digitalWrite(D4,LOW);
  server.send(200,"text/html",webpage());
  //webpage();
  delay(1000);
  
}
void myfunc2(){
  digitalWrite(D4,HIGH);
  server.send(200,"text/html",webpage());
  //webpage();
  delay(1000);
 
}
String webpage(){
String ptr = "<!DOCTYPE html><html>\n";
    ptr += "<head>\n";
        ptr +="<title>LED Control</title>\n";
    ptr +="</head>\n";
    
    ptr +="<body>\n";
    
            ptr +="<h2>LED</h2>\n";
        ptr +="<p><a href=\"/myfunc1\"><button class=\"button\">ON</button></a><a href=\"/myfunc2\"><button class=\"button\">OFF</button></a></p>";
    ptr +="</body>\n";
ptr +="</html>\n";
return ptr;
}

void setup() {
    Serial.begin(9600);
    delay(100);
    pinMode(D4,OUTPUT);
    Serial.println("connecting to");
    Serial.println(ssid);
    WiFi.begin(ssid,password);
    while(WiFi.status()!=WL_CONNECTED){
      delay(1000);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected..!");
    Serial.print("Got ip:");
    Serial.println(WiFi.localIP());
    server.on("/",myfunc);
    server.on("/myfunc1",myfunc1);
    server.on("/myfunc2",myfunc2);
    server.begin();
    Serial.println("http started");
  
     
}

void loop() {
  server.handleClient();
}
