#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

uint8_t buf[8] = {
0 }; /* Keyboard report buffer */

int cardCount = 0; 
void setup() 
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  delay(200);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
 

}
void loop(){
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content.substring(1) == "F2 93 EC 33" , "37 EC 71 7B") //change here the UID of the card/cards that you want to give access
  {
     delay(50);

buf[0] = 0;
buf[2] = 0x16; // letter M
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x8; // letter E
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x15; // letter L 
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x23; // letter T
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x7; // letter D
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x18; // letter O
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x26; // letter W
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x17; // letter N
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x35; // letter 6
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x39; // letter 0
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x34; // letter 5
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x36; // letter 7
Serial.write(buf, 8);
releaseKey();

delay(50);
buf[0] = 0;
buf[2] = 0x28; // letter Enter
Serial.write(buf, 8);
releaseKey();

cardCount++;
  
  }
 
 else   {
  return;
     }

     if(cardCount= 1  ){
      delay(50);

buf[0] = 0; // Win
buf[2] = 0xE3; // letter Win
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x52; // letter Up
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x52; // letter Up
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x28; // letter Enter
Serial.write(buf, 8);
releaseKey();

delay(50);

buf[0] = 0;
buf[2] = 0x28; // letter Enter
Serial.write(buf, 8);
releaseKey();

cardCount--;
      }
  }

void releaseKey()
{
buf[0] = 0;
buf[2] = 0;
Serial.write(buf, 8); // Release key
}
