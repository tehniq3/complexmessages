// CommaDelimitedOutput sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
// sender v.1a using SoftwareSerial 
// sketch adapted by Nicu FLORICA - http://www.arduinotehniq.com 
// to coding and send complex values

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

float te; 

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  int tempe = random(351); // random value from 0 to 350
  int semn = random(2);  // random value 0 or 1   
  int vibratie = random(2);  // random value 0 or 1
  int procent = random(101); // random value from 0 to 100 

 if (semn == 1) 
  {
  te = - tempe/10.;
  }
 else
  te = tempe/10.;

 Serial.println("--------------------");
 Serial.print("Temperature = ");
 Serial.print(te);
 Serial.print(" degree Celsiu, Shock = ");
 Serial.print(vibratie);
 Serial.print(", Water level = ");
 Serial.print(procent);
 Serial.println("%");
 
 Serial.println("--------------------");
//  Serial.print('H'); // unique header to identify start of message
//  Serial.print(",");
  Serial.print(tempe,DEC);
  Serial.print(",");
  Serial.print(10*semn+vibratie,DEC);
  Serial.print(",");
  Serial.print(procent,DEC);
  Serial.print(",");  // note that a comma is sent after the last field
  Serial.println();  // send a cr/lf
  delay(100);

//  mySerial.print('H'); // unique header to identify start of message
//  mySerial.print(",");
  mySerial.print(tempe,DEC);
  mySerial.print(",");
  mySerial.print(10*semn+vibratie,DEC);
  mySerial.print(",");
  mySerial.print(procent,DEC);
  mySerial.print(",");  // note that a comma is sent after the last field
  mySerial.print(" ");  // send a cr/lf
//  delay(100);
  Serial.println(" ");
  delay (2000);
}
