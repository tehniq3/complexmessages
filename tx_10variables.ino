// CommaDelimitedOutput sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
// sender v.4 using SoftwareSerial 
// sketch adapted by Nicu FLORICA - http://www.arduinotehniq.com 
// to coding and send complex values
// https://github.com/tehniq3/complexmessages/blob/master/tx_2.ino

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

int te1, te2, te3, te4, te5, te6, te7; 
int con1, con2, con3;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  int te1 = random(10,101); // random value from 10 to 100
  int te2 = random(10,101); // random value from 10 to 100
  int te3 = random(10,101); // random value from 10 to 100
  int te4 = random(10,301); // random value from 10 to 300
  int te5 = random(10,101); // random value from 10 to 100
  int te6 = random(10,101); // random value from 10 to 100
  int te7 = random(10,101); // random value from 10 to 100

  int con1 = random(2);  // random value 0 or 1   
  int con2 = random(2);  // random value 0 or 1  
  int con3 = random(2);  // random value 0 or 1  


 Serial.println("--------------------");
 Serial.print("Temperature1 = ");
 Serial.print(te1);
 Serial.println(" degree Celsius");
 Serial.print("Temperature2 = ");
 Serial.print(te2);
 Serial.println(" degree Celsius");
 Serial.print("Temperature3 = ");
 Serial.print(te3);
 Serial.println(" degree Celsius");
 Serial.print("Temperature4 = ");
 Serial.print(te4);
 Serial.println(" degree Celsius");
 Serial.print("Temperature5 = ");
 Serial.print(te5);
 Serial.println(" degree Celsius");
 Serial.print("Temperature6 = ");
 Serial.print(te6);
 Serial.println(" degree Celsius");
 Serial.print("Temperature7 = ");
 Serial.print(te7);
 Serial.println(" degree Celsius");
 Serial.print("Switch1 = ");
 Serial.println(con1);
 Serial.print("Switch2 = ");
 Serial.println(con2);
 Serial.print("Switch3 = ");
 Serial.println(con3);
 

//  mySerial.print('H'); // unique header to identify start of message
//  mySerial.print(",");
  mySerial.print(te1,DEC);
  mySerial.print(",");
  mySerial.print(te2,DEC);
  mySerial.print(",");
  mySerial.print(te3,DEC);
  mySerial.print(",");
  mySerial.print(te4,DEC);
  mySerial.print(",");
  mySerial.print(te5,DEC);
  mySerial.print(",");
  mySerial.print(te6,DEC);
  mySerial.print(",");  
  mySerial.print(te7,DEC);
  mySerial.print(",");
  mySerial.print(con1,DEC);
  mySerial.print(",");
  mySerial.print(con2,DEC);
  mySerial.print(",");  
  mySerial.print(con3,DEC);
  mySerial.print(",");  // note that a comma is sent after the last field
  mySerial.print(" ");  // send a cr/lf
//  delay(100);
  Serial.println(" ");
  delay (5000);
}
