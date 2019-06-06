/*
 * SerialReceiveMultipleFields sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
 * This code expects a message in the format: 12,345,678
 * This code requires a newline character to indicate the end of the data
 * Set the serial monitor to send newline characters
 * receiver v.3 - use info from https://electronics-project-hub.com/send-data-to-thingspeak-using-esp8266/
 * sketch writed by Nicu FLORICA - http://www.arduinotehniq.com
 * to receive and decode complex string
 * 
 */

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

 float te;  // temperature
 int tempe; // x10 temperature
 int semn;  // sing for temperature (1 for munus)  
 int vibratie;  // vibration / shock
 int procent; // water level as procent 

//unsigned char buff[10], i;
String buffer1;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("--------------------");
}

void loop()
{
while (mySerial.available() > 0)
    {
      buffer1 = mySerial.readString();
      if (buffer1[0] == '*')
      {
        if (buffer1[9] == '#')
        {
          Serial.println(buffer1);
          tempe = ((buffer1[1] - 0x30) * 100 + (buffer1[2] - 0x30)*10 + (buffer1[3] - 0x30));
          vibratie = ((buffer1[4] - 0x30) * 10 + (buffer1[5] - 0x30));
          procent = ((buffer1[6] - 0x30) * 100 + (buffer1[7] - 0x30)*10 + (buffer1[8] - 0x30));
 
semn = vibratie/10;
vibratie = vibratie%10;

if (semn == 1) 
  {
  te = - tempe/10.;
  }
 else
  te = tempe/10.;

// Serial.println("--------------------");
 Serial.print("Temperature = ");
 Serial.print(te);
 Serial.print(" degree Celsiu, Shock = ");
 Serial.print(vibratie);
 Serial.print(", Water level = ");
 Serial.print(procent);
 Serial.println("%"); 
 Serial.println("--------------------");     
        }
      }
    }
} // end main loop
