
//RFID CARD PROJECT
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LedControl.h>
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4  //define green LED pin
#define LED_R 2  //define red LED
const int buzzerPin = A3;  //buzzer pin
#define Relay 7
int DIN = 8;
int CS =  3;
int CLK = 6;
int a = 1000;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
LedControl lc=LedControl(DIN,CLK,CS,0);
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(5); //servo pin
  myServo.write(0); //servo start position
  
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(Relay, OUTPUT);
  // noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  digitalWrite(Relay,HIGH);
  lc.shutdown(0,false);       
  lc.setIntensity(0,0);      //Adjust the brightness maximum is 15
  lc.clearDisplay(0);

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
  if (content.substring(1) == "02 4B A4 1B" || content.substring(1) == "11 6C EF 29" || content.substring(1) == "F3 5F D8 55") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    byte tick[8]={0x00,0x00,0x01,0x02,0x04,0x88,0x50,0x20,};
    printByte(tick);
    delay(a);
    lc.clearDisplay(0);
    delay(500);
    digitalWrite(LED_G, HIGH);
    analogWrite(buzzerPin, 255);
    delay(500);
    analogWrite(buzzerPin, 0);
    //  delay(500);

    // tone(BUZZER, 500);
    // delay(300);
    // noTone(BUZZER);
    myServo.write(180);
    digitalWrite(Relay,LOW);
    delay(3000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    digitalWrite(Relay,HIGH);
  }
 
 else   {
    Serial.println(" Access denied");
    byte cross[8]={0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81,};
    printByte(cross);
    delay(a);
    lc.clearDisplay(0);
    digitalWrite(LED_R, HIGH);
    analogWrite(buzzerPin, 255);
    // tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    // noTone(BUZZER);
     delay(500);
    analogWrite(buzzerPin, 0);
  }
  
}  
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}