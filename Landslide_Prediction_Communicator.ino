#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
int C1 = A1;
int C2 = A2;
int C3 = A3;
int C4 = A4;
int C5 = A5;
int TB = 2;
int CV1 = 0;
int CV2 = 0;
int CV3 = 0;
int CV4 = 0;
int CV5 = 0;
boolean TBV = 0;
unsigned long ST=0;
unsigned long ET=0;
const long TD = 10;
unsigned long tim;
float HI = 0;
int count = 0;
int M = 1;
//int Data Array[] = {CV1,CV2,CV3,CV4,CV5};
//int myPins[] = {2, 4, 8, 3, 6};
;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
pinMode(C1,INPUT);
pinMode(C2,INPUT);
pinMode(C3,INPUT);
pinMode(C4,INPUT);
pinMode(C5,INPUT);
pinMode(TB,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
CV1=analogRead(C1);
CV2=analogRead(C2);
CV3=analogRead(C3);
CV4=analogRead(C4);
CV5=analogRead(C5);
TBV=digitalRead(TB);

mySerial.println(CV1);
/*mySerial.println(CV2);
mySerial.println(CV3);
mySerial.println(CV4);
mySerial.println(CV5);
//Serial.println(CV1);

/*HI = pulseIn(2,HIGH);
if(HI < 2000 && HI > 0){
  count++;
  delay(500);}
if (ET >= M*300000) {
  M++;
  tim++;
}
if(tim == 1){
  Serial.write("TBV",count*0.7/2500000);
  tim = 0;
  count = 0;
}

/*unsigned long NT=millis();
if((NT-ST)>=TD) {
  Serial.write(C1);
}
else if((NT-ST)>=2*TD) {
  Serial.write(C2);
}
else if((NT-ST)>=2*TD) {
  Serial.write(C2);
}
else if((NT-ST)>=2*TD) {
  Serial.write(C2);
}
else if((NT-ST)>=2*TD) {
  Serial.write(C2);*/
}
