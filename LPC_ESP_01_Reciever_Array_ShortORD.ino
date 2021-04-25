#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
const char *ssid = "HTR";
const char *password = "87654321";
//ESP8266WebServer server(80);
int Data[6];
int CV1 ;
int CV2 ;
int CV3 ;
int CV4 ;
int CV5 ;
int RF ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{for(int i=0;i<6;i++){
  Data[i]=Serial.parseFloat(); //Write the serial data
}
}
CV1=Data[0];
CV2=Data[1];
CV3=Data[2];
CV4=Data[3];
CV5=Data[4];
RF=Data[5];}
