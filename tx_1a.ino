// CommaDelimitedOutput sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
// sender v.1a using SoftwareSerial 
// sketch writed by Nicu FLORICA - http://www.arduinotehniq.com 

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  int value1 = random(1000);    // some hardcoded values to send
  int value2 = random(1000);
  int value3 = random(1000);

//  Serial.print('H'); // unique header to identify start of message
//  Serial.print(",");
  Serial.print(value1,DEC);
  Serial.print(",");
  Serial.print(value2,DEC);
  Serial.print(",");
  Serial.print(value3,DEC);
  Serial.print(",");  // note that a comma is sent after the last field
  Serial.println();  // send a cr/lf
  delay(100);

//  mySerial.print('H'); // unique header to identify start of message
//  mySerial.print(",");
  mySerial.print(value1,DEC);
  mySerial.print(",");
  mySerial.print(value2,DEC);
  mySerial.print(",");
  mySerial.print(value3,DEC);
  mySerial.print(",");  // note that a comma is sent after the last field
  mySerial.print(" ");  // send a cr/lf
  delay(100);


  delay (2000);
}
