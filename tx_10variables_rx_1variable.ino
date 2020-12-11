// CommaDelimitedOutput sketch - https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html
// sender v.5 using SoftwareSerial 
// sketch adapted by Nicu FLORICA - http://www.arduinotehniq.com 
// to coding and send complex values
// https://github.com/tehniq3/complexmessages/
// add receiver function for 1 variable

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

int te1, te2, te3, te4, te5, te6, te7; 
int con1, con2, con3;
int fb1;
unsigned long tptrimitere = 0;
unsigned long tppauza = 10000; 

const int NUMBER_OF_FIELDS = 1; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{

  if ((millis() - tptrimitere) > tppauza)
  {
  te1 = random(10,101); // random value from 10 to 100
  te2 = random(10,101); // random value from 10 to 100
  te3 = random(10,101); // random value from 10 to 100
  te4 = random(10,301); // random value from 10 to 300
  te5 = random(10,101); // random value from 10 to 100
  te6 = random(10,101); // random value from 10 to 100
  te7 = random(10,101); // random value from 10 to 100

  con1 = random(2);  // random value 0 or 1   
  con2 = random(2);  // random value 0 or 1  
  con3 = random(2);  // random value 0 or 1  


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

  tptrimitere = millis();  // note time 
  }

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
      fb1 = values[0];
      /*
      te2 = values[1];
      te3 = values[2];
      te4 = values[3];
      te5 = values[4];
      te6 = values[5];
      te7 = values[6];
      con1 = values[7];
      con2 = values[8];
      con3 = values[9];
       */
 Serial.println("--------------------");
 Serial.print("Feedback = ");
 Serial.print(fb1);
 Serial.println(" ! ");
 /*
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
  */
      
      for(int i=0; i <= fieldIndex; i++)
      {
      // Serial.println(values[i]);
        values[i] = 0; // set the values to zero, ready for the next message
      }
      fieldIndex = 0;  // ready to start over       
    }   
  }
//  delay (2000);
}
