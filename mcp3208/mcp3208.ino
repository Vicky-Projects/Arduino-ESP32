#include<SPI.h>
#include<MCP3208.h>




MCP3208 adc;
ADC_MODE(ADC_VCC)//read esp voltage instead of analog_in a0,leave A0 unconnected


void setup() {
 
  Serial.begin(115200);
  adc.begin(D5,D7,D6,D8);
  SPI.begin();
  

}
void loop() {
  Serial.print("MCP3208 values:");
  for(int i=0;i<=7;i++){
    int val = adc.readADC(i);
    Serial.print(val);
    Serial.print("\t");
  }
  Serial.println("");
  delay(3000);

  }
  


