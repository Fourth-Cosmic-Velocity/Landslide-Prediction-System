#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
const char *ssid = "E.D.I.T.H";
const char *password = "qwertyas";
//ESP8266WebServer server(80);
WiFiServer server(80);
char  SBIT;
float Data[6];
float CV1 ;
float CV2 ;
float CV3 ;
float CV4 ;
float CV5 ;
float RF ;
void setup() {
//WiFi.begin(ssid, password);  
//WiFi.softAP(ssid,password);
Serial.begin(9600);
Serial.print("Connecting to");
Serial.println(ssid);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
void loop() {

WiFiClient client = server.available();   // Listen for incoming clients
while(true){
if (Serial.available()>0){
  SBIT=Serial.read();
  Serial.print(SBIT);
  if(SBIT ==73){
    //Serial.print("SBIT");
  //Serial.read();
    for(int i=0;i<6;i++){
      Data[i]=Serial.parseFloat();
      //Serial.println(Data[0]);
      //delay(600);
      }//Write the serial data
      break; 
  }
}
}
client.println("CV1= "+String(Data[0]));
client.println("CV2= " +String(Data[1]));
client.println("CV3= "+String(Data[2]));
client.println("CV4= "+String(Data[3]));
client.println("CV5= "+String(Data[4]));
client.println("RF= "+String(Data[5]));
Serial.println();
Serial.println("CV1= "+String(Data[0]));
Serial.println("CV2= "+String(Data[1]));
Serial.println("CV3= "+String(Data[2]));
Serial.println("CV4= "+String(Data[3]));
Serial.println("CV5= "+String(Data[4]));
Serial.println("RF= "+String(Data[5]));

//delay(600);
/*CV1=Data[0];
CV2=Data[1];
CV3=Data[2];
CV4=Data[3];
CV5=Data[4];
RF=Data[5];*/ }
