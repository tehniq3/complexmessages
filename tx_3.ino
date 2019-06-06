// CommaDelimitedOutput sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
// sender v.1a using SoftwareSerial 
// sketch adapted by Nicu FLORICA - http://www.arduinotehniq.com 
// to coding and send complex values
// sender v.3 - change as https://electronics-project-hub.com/send-data-to-thingspeak-using-esp8266/

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

int a0 = tempe/100; 
int a12 = tempe%100;
int a1 = a12/10;
int a2 = a12%10;
int a3 = semn;
int a4 = vibratie;
int a5 = procent/100;
int a67 = procent%100;
int a6 = a67/10;
int a7 = a67%10;


Serial.print("--------------");
Serial.print("*");
Serial.print(a0);
Serial.print(a1);
Serial.print(a2);
Serial.print(a3);
Serial.print(a4);
Serial.print(a5);
Serial.print(a6);
Serial.print(a7);
Serial.print("#");
Serial.println("--------------");

//------Sending Data to receiver--------//
    mySerial.print('*'); // Starting char
    mySerial.print(a0); 
    mySerial.print(a1); 
    mySerial.print(a2); 
    mySerial.print(a3); 
    mySerial.print(a4); 
    mySerial.print(a5); 
    mySerial.print(a6); 
    mySerial.print(a7); 
    mySerial.print('#'); // Ending char
    //------------------------------------//
  Serial.println(" ");
  delay (5000);
}
