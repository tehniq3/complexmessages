/*
 * SerialReceiveMultipleFields sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
 * This code expects a message in the format: 12,145,7,....,175
 * This code requires a newline character to indicate the end of the data
 * Set the serial monitor to send newline characters
 * receiver v.4
 * sketch writed by Nicu FLORICA - http://www.arduinotehniq.com
 * to receive and decode complex string
 * https://github.com/tehniq3/complexmessages/blob/master/rx_2.ino
 */

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

const int NUMBER_OF_FIELDS = 10; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

 int te1, te2, te3, te4, te5, te6, te7;  // temperatures 
 int con1, con2, con3;  // switches


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
      te1 = values[0];
      te2 = values[1];
      te3 = values[2];
      te4 = values[3];
      te5 = values[4];
      te6 = values[5];
      te7 = values[6];
      con1 = values[7];
      con2 = values[8];
      con3 = values[9];

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
 
      
      for(int i=0; i <= fieldIndex; i++)
      {
      // Serial.println(values[i]);
        values[i] = 0; // set the values to zero, ready for the next message
      }
      fieldIndex = 0;  // ready to start over       
    }   
  }
} // end main loop
