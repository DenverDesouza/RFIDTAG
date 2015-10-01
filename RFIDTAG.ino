#include <SoftwareSerial.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);// include the Software Serial Library

SoftwareSerial rfid_reader(7,1); // Creat a Software Serial Object Mapping it to 7th pin as Rx and 1st Pin as Tx

int count = 0; // A variable to count the length of the Tag DATA


void setup()
{
  lcd.begin(16,2);
  rfid_reader.begin(9600); // Initialise Serial Communication with the RFID reader
  Serial.begin(9600); // Initialise Serial Communication with the Serial Monitor
}

void loop()
{
  
  int i=0;
  if(rfid_reader.available()) // Check if there is Incoming Data in the RFID Reader Serial Buffer. 
  {
        
    while(rfid_reader.available()) // Keep reading Byte by Byte from the Buffer till the RFID Reader Buffer is empty
    {
      
    char  s = rfid_reader.read(); // Read 1 Byte of data and store it in a character variable
      Serial.print(s);
       
      lcd.print(s); 
      
      
      delay(2);
      
       // Print the Data
    }
    delay(2000);
    lcd.clear();
   }
}
