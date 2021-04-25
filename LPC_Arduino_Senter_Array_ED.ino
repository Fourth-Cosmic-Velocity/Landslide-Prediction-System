#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); //RX,TX
const int C1 = A1;
const int C2 = A2;
const int C3 = A3;
const int C4 = A4;
const int C5 = A5;
const int TB = 2;
float MC= float(5)/1024;
unsigned long ST=0;
unsigned long ET=0;
const long TD = 10;
unsigned long tim;
float HI = 0;
int count = 0;
int M = 1;
float Data[6];

void setup() {
ST = millis();
mySerial.begin(9600);
Serial.begin(9600);
pinMode(C1,INPUT);
pinMode(C2,INPUT);
pinMode(C3,INPUT);
pinMode(C4,INPUT);
pinMode(C5,INPUT);
pinMode(TB,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Data[0]=analogRead(C1)*MC;
Data[1]=analogRead(C2)*MC;
Data[2]=analogRead(C3)*MC;
Data[3]=analogRead(C4)*MC;
Data[4]=analogRead(C5)*MC;
Data[5]=count*0.7/2500000;
HI = pulseIn(2,HIGH);
if(HI < 2000 && HI > 0){
  count++;
  delay(500);}
  
  ET = millis() - ST;
  if (ET >= M*300000) {
  M++;
  tim++;
}
if(tim == 1){
  tim = 0;
  count = 0;
}
Serial.println("I");
for(int i=0;i<6;i++){
  mySerial.print(Data[i]); //Write the serial data
  Serial.print(Data[i]);
  mySerial.println();
  Serial.println();
  //delay(600);
  }
mySerial.println();
Serial.println();
}
