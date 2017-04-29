//Data and data1 are changed in older version.

#include <DHT.h>
#define DHTTYPE DHT22
int data=5;
int clk=3;
int strobe=4;
int data1=2;
DHT dht(data1, DHTTYPE);
float hum,temp;
int temp1,temp2,temp3,hum1,hum2,hum3;
int tempsegment,humsegment;
byte segment[]={63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
void setup()
{
  dht.begin();
  Serial.begin(9600);
  pinMode(strobe,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clk,OUTPUT);
}
void loop()
{
  hum=0;
  temp=0;
  while (hum==0 || temp==0){
    hum = dht.readHumidity();
    temp = dht.readTemperature();
  }
  Serial.print("Humidity:");
  Serial.print(hum);
  Serial.println(" %   ");
  Serial.print("Temperature:");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("***************");
  tempsegment=temp*10;
  temp1=tempsegment%10;
  tempsegment=tempsegment/10;
  temp2=tempsegment%10;
  tempsegment=tempsegment/10;
  temp3=tempsegment%10;
  humsegment=hum*10;
  hum1=humsegment%10;
  humsegment=humsegment/10;
  hum2=humsegment%10;
  humsegment=humsegment/10;
  hum3=humsegment%10;
  digitalWrite(strobe,LOW);
  shiftOut(data,clk,MSBFIRST,0);
  shiftOut(data,clk,MSBFIRST,0);
  shiftOut(data,clk,MSBFIRST,segment[hum1]);
  shiftOut(data,clk,MSBFIRST,segment[hum2]);
  shiftOut(data,clk,MSBFIRST,segment[hum3]);
  shiftOut(data,clk,MSBFIRST,segment[temp1]);
  shiftOut(data,clk,MSBFIRST,segment[temp2]);
  shiftOut(data,clk,MSBFIRST,segment[temp3]);
  delay(200);
  digitalWrite(strobe,HIGH);
  delay(1000);
  }
