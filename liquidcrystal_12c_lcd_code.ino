#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int Red_light_1 = 3;
int Yellow_light_1 = 4;
int Green_light_1 = 5;
int bazar = 6;
int Red_light_2 = 11;
int Yellow_light_2 = 12;
int Green_light_2 = 13;
int Ir_scensor = 2;
int value_reader;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();
  // initialize the lcd
  // Print a message to the LCD.
  Serial.begin(9600);
  pinMode(Red_light_1, OUTPUT);
  pinMode(Green_light_1, OUTPUT);
  pinMode(Yellow_light_1, OUTPUT);
  pinMode(Red_light_2, OUTPUT);
  pinMode(Green_light_2, OUTPUT);
  pinMode(Yellow_light_2, OUTPUT);
  pinMode(bazar, OUTPUT);
  pinMode(Ir_scensor, INPUT);
  Serial.println("WELCOME TO TRAFFIC LIGHT SYSTEM");

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("TRAFFIC LIGHT");
  lcd.setCursor(3, 1);
  lcd.print("SYSTEM");
  delay(2000);
  lcd.clear();
}


void loop() {
  value_reader = digitalRead(Ir_scensor);

  if (value_reader == LOW) {
    Serial.println("SENSOR DETECTED");
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("SENSOR DETECTED");
    delay(2000);
    lcd.clear();


    // frist red ,second green
    digitalWrite(Red_light_1, HIGH);
    digitalWrite(Green_light_2, HIGH);
    Serial.println("SIDE_ONE: RED_LIGHT_1 IS ON , SIDE_TWO: GREEN_LIGHT_2 IS ON");
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("LEFT SIDE");
    lcd.setCursor(3, 1);
    lcd.print("GO");
    delay(2000);
    lcd.clear();
    delay(2000);
    digitalWrite(bazar, HIGH);
    delay(500);
    digitalWrite(Red_light_1, LOW);
    digitalWrite(Green_light_2, LOW);
    // Serial.println("SIDE_ONE: RED_LIGHT_1 IS OFF , SIDE_TWO: GREEN_LIGHT_2 IS OFF");
    digitalWrite(bazar, LOW);
    // first yellow,second yellow
    digitalWrite(Yellow_light_1, HIGH);
    digitalWrite(Yellow_light_2, HIGH);
    Serial.println("SIDE_ONE: YELLOW_LIGHT_1 IS ON , SIDE_TWO: YELLOW_LIGHT_2 IS ON");
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("WAIT");
    lcd.setCursor(3, 1);
    lcd.print("PLEASE!");
    delay(2000);
    lcd.clear();
    delay(2000);
    digitalWrite(bazar, HIGH);
    delay(500);
    digitalWrite(Yellow_light_1, LOW);
    digitalWrite(Yellow_light_2, LOW);
    // Serial.println("SIDE_ONE: YELLOW_LIGHT_1 IS OFF , SIDE_TWO: YELLOW_LIGHT_2 IS OFF");
    digitalWrite(bazar, LOW);
    // first green,second red
    digitalWrite(Green_light_1, HIGH);
    digitalWrite(Red_light_2, HIGH);
    Serial.println("SIDE_ONE: GREEN_LIGHT_1 IS ON , SIDE_TWO: RED_LIGHT_2 IS ON");
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("RIGHT SIDE");
    lcd.setCursor(0, 1);
    lcd.print("GO");
    delay(2000);
    lcd.clear();
    delay(2000);
    digitalWrite(bazar, HIGH);
    delay(500);
    digitalWrite(Green_light_1, LOW);
    digitalWrite(Red_light_2, LOW);
    // Serial.println("SIDE_ONE: GREEN_LIGHT_1 IS OFF , SIDE_TWO: RED_LIGHT_2 IS OFF");
    digitalWrite(bazar, LOW);
    // program finished
    Serial.println("PROGRAM FINISHED! PLACE AN OBJECT IN FRONT OF SCENSOR TO START AGAIN");
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("PROGRAM FINISHED");
    delay(2000);
    lcd.clear();
    delay(2000);

  } else {
    // -----Nothing-----
  }
}
