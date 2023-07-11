#include<MCP3208.h>
float vref=3.3;
float resolution = vref/4095;
MCP3208 adc;

void setup() {
  Serial.begin(115200);
  adc.begin(D5,D7,D6,D8);

}

void loop() {
  float temp1 = adc.readADC(0);
  float temp2 = adc.readADC(1);
  float potential = adc.readADC(2);
  float potential2;
  temp1=(temp1*resolution);
  temp1=temp1*100;
  temp2=(temp2*resolution);
  temp2=temp2*100;
  potential2=(potential*resolution);
  potential2=potential2*100;
  delay(6000);
  Serial.print("temp1:");
  Serial.println(temp1);
  Serial.print("temp2:");
  Serial.println(temp2);
  Serial.print("potential:");
  Serial.println(potential);
  Serial.print("potential to temp:");
  Serial.println(potential2);


}
