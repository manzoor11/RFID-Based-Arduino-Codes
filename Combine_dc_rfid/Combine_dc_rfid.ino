#include <SoftwareSerial.h>

int sensorValue = 0;
int transistorPin = 4;
char tag = "";
char tag_fast = "3E0067D29E15";
char tag_slow = "8400811EC5DE";
int DriveValue = 200;
int SlowValue  = 0;

    SoftwareSerial mySerial(2, 3);
    void setup() 
    {
      Serial.begin(9600);
      Serial.println("Scan RFID Tag!");
      pinMode(transistorPin, OUTPUT);
      // set the data rate for the NewSoftSerial port
      mySerial.begin(9600);
    }
    void loop()                     // run over and over again
    {
      tag = "";
      if (mySerial.available()) {
        tag = ((char)mySerial.read());
        Serial.print(tag);
          if (tag = tag_fast)
            {
              analogWrite(transistorPin, DriveValue);
              Serial.println("speed Tag");
            }
          else // if (tag = tag_slow)
            {
               analogWrite(transistorPin, SlowValue);
               Serial.println("slow Tag");
            }
                  
       }
       if (Serial.available()) {
          mySerial.print((char)Serial.read());
      }
    }
