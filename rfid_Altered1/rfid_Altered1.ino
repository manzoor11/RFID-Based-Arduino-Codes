#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
int transistorPin = 4;

char tag[13];     // buffer to store the reading card
char tag_fast[13]="3E0067D29E15"; // token to compare
char tag_slow[13]="8400811EC5DE";

int DriveValue = 200;
int SlowValue  = 0;

void setup()
{
  // set the data rate for the port
  Serial.begin(9600);
  mySerial.begin(9600);
  
  Serial.println("Scan RFID Tag!");
  pinMode(transistorPin, OUTPUT);
  analogWrite(transistorPin, DriveValue);
}

void loop()
{
  if(mySerial.available() > 0)  // checking if card is punched or not
  {
    mySerial.readBytesUntil('\0',tag,12);  // storing the card number in rfid_receive
    if(!(strcmp(tag,tag_fast)))  // comparing the two string if matched
    {
      analogWrite(transistorPin, DriveValue);
      Serial.println("speed Tag");
    }
    else if(!(strcmp(tag,tag_slow)))
    {
      analogWrite(transistorPin, SlowValue);
      Serial.println("slow Tag");
    }
    else
    {
      Serial.println("Not recognised");
    }
  }
}
