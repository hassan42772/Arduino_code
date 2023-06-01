#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int trigPin = 7;
const int echoPin = 6;
// defines variables
long duration;
int distance;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  

}





void distance(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

}

void screen(){
    lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("distance:");
  lcd.setCursor(10,0);
  lcd.print(distance);
  delay(500);
  lcd.clear();

}

