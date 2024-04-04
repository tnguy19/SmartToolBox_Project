#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
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
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "DA 06 F5 80") //change here the UID of the card/cards that you want to give access
  {
    analogWrite(3,100);
    delay(1000);
    analogWrite(3,0);
    delay(200);
  }
  if 
  (content.substring(1) == "A9 D8 31 68") //change here the UID of the card/cards that you want to give access
  {
   
    digitalWrite(5,100);
     delay(1000);
    digitalWrite(5,0);
    delay(1000);

  }
 if 
  (content.substring(1) == "5A 3E 82 81") //change here the UID of the card/cards that you want to give access
  {
   
    digitalWrite(6,100);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
  }
}
