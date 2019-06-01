/*
 * SerialReceiveMultipleFields sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
 * This code expects a message in the format: 12,345,678
 * This code requires a newline character to indicate the end of the data
 * Set the serial monitor to send newline characters
 * receiver v.1
 * sketch writed by Nicu FLORICA - http://www.arduinotehniq.com
 * to receive and decode complex string
 */

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

 float te;  // temperature
 int tempe; // x10 temperature
 int semn;  // sing for temperature (1 for munus)  
 int vibratie;  // vibration / shock
 int procent; // water level as procent 


void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("--------------------");
}

void loop()
{
  if( mySerial.available())
  {
    char ch = mySerial.read();
    if(ch >= '0' && ch <= '9') // is this an ascii digit between 0 and 9?
    {
      // yes, accumulate the value
      values[fieldIndex] = (values[fieldIndex] * 10) + (ch - '0'); 
    }
    else if (ch == ',')  // comma is our separator, so move on to the next field
    {
      if(fieldIndex < NUMBER_OF_FIELDS-1)
        fieldIndex++;   // increment field index
    }
    else
    {
      // any character not a digit or comma ends the acquisition of fields
      // in this example it's the newline character sent by the Serial Monitor
      Serial.print( fieldIndex +1);
      Serial.println(" fields received:");
      tempe = values[0];
      vibratie = values[1];
      procent = values[2];
Serial.println("--------------");
Serial.print("Values received: ");  
Serial.print(tempe);
Serial.print(", ");
Serial.print(vibratie);
Serial.print(", ");
Serial.print(procent);
Serial.println("...");
      
      for(int i=0; i <= fieldIndex; i++)
      {
      // Serial.println(values[i]);
        values[i] = 0; // set the values to zero, ready for the next message
      }
      fieldIndex = 0;  // ready to start over
semn = vibratie/10;
vibratie = vibratie%10;

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
 Serial.println(" ");       
    }   
  }
} // end main loop
