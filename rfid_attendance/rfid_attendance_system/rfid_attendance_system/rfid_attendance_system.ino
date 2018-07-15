#include <Wire.h>


char rfid_receive[13];     // buffer to store the reading card
char rfid_token1[13]="160066805AAA"; // token to compare
char rfid_token2[13]="8400811EC5DE";
char rfid_token3[13]="8500427942FC";
char rfid_token_master[13]="6C00908D3B4A";  // master token to check the attandance 


int atd_vikas=0;
int atd_ankit=0;
int atd_monty=0;


void setup()

{
  Serial.begin(9600);    // initializing the serial with 9600 baud rate  
  lcd.begin(20, 4);      // initialing the lcd as 20x4
  lcd.print("show your card"); // printing first statement on lcd first line

}

void loop()
{
  if(Serial.available() > 0)  // checking if card is punched or not
  {
    Serial.readBytesUntil('\0',rfid_receive,12);  // storing the card number in rfid_receive
    if(!(strcmp(rfid_receive,rfid_token1)))  // comparing the two string if matched
    {
      lcd.clear();
      lcd.setCursor(0,1);            // selecting column and line and printing data 
      lcd.print("   Welcome ");
      lcd.setCursor(0,2);
      lcd.print(" Mr.vikas sharma ");  // printing the name of the owner of the card
      lcd.setCursor(0,3);
      lcd.print(" attendance =  ");
      lcd.print(++atd_vikas);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("show your card");
    }
    else if(!(strcmp(rfid_receive,rfid_token2)))
    {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("   Welcome ");
      lcd.setCursor(0,2);
      lcd.print(" Mr. ankit sahu");
      lcd.setCursor(0,3);
      lcd.print(" attendance =  ");
      lcd.print(++atd_ankit);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("show your card");
    }
    else if(!(strcmp(rfid_receive,rfid_token3)))
    {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("   Welcome ");
      lcd.setCursor(0,2);
      lcd.print("   Mr. monty  ");
      lcd.setCursor(0,3);
      lcd.print(" attendance =  ");
      lcd.print(++atd_monty);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("show your card");
    }
    else if(!(strcmp(rfid_receive,rfid_token_master)))  // this sequence shows the attandance of all person
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Mr. vikas = ");
      lcd.print(atd_vikas);
      lcd.setCursor(0,1);
      lcd.print("Mr. monty = ");
      lcd.print(atd_monty);
      lcd.setCursor(0,2);
      lcd.print("Mr. ankit = ");
      lcd.print(atd_ankit);
      delay(5000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("show your card");
    }
    else
    {
      lcd.setCursor(0,1);    // printing sequence if none of them matched 
      lcd.print("not recognized ");
      delay(1);
      lcd.setCursor(0,2);
      lcd.print("please enter again ");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("show your card");
    }
  }
}
