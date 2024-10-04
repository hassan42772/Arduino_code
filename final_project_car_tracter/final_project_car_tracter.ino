#include <Servo.h>  // Include the Servo library
#include <DHT.h>    // Include the DHT library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHT_TYPE DHT11
#define TRIG_PIN 5  // Trigger pin of the ultrasonic sensor
#define ECHO_PIN 4  // Echo pin of the ultrasonic sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sensorPin = A0;  // Pin connected to the soil moisture sensor
int sensorValue = 0;
int relayPin = 2;   // Pin connected to the relay
int servoPin1 = 6;  // Pin connected to the first servo
int servoPin2 = 7;
int servoPin3 = 12;
const int dhtPin = 3;  // Pin connected to the second servo

DHT dht(dhtPin, DHT_TYPE);

Servo myServo1;  // Create the first Servo object
Servo myServo2;  // Create the second Servo object
Servo myServo3;  // Create the second Servo object

// Motor control pins for L298 driver
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int C1 = 22;
int C2 = 24;
int C3 = 26;
int C4 = 28;
unsigned long previousMillis = 0;  // Store the last time the display was updated
const long interval = 3000;        // Interval of 3 seconds
int displayState = 0;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);

  // Set the relay pin as output
  pinMode(relayPin, OUTPUT);

  // Attach the servos to their respective pins
  myServo1.attach(servoPin1);
  myServo2.attach(servoPin2);
  myServo3.attach(servoPin3);
  digitalWrite(relayPin, HIGH);  // Turn ON the relay

  // Initialize the positions of both servos to 0 degrees
  myServo1.write(0);
  myServo2.write(0);
  myServo3.write(153);
  


  // Initialize the DHT sensor
  dht.begin();

  // Set up the ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Set motor control pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Cycle through the sensor values
    if (displayState == 0) {
      // Read and display DHT11 sensor values
      float temperature = dht.readTemperature();
      float humidity = dht.readHumidity();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print(" C");
      lcd.setCursor(0, 1);
      lcd.print("Humidity: ");
      lcd.print(humidity);
      lcd.print(" %");

      displayState = 1;  // Move to the next sensor for the next cycle
    } else if (displayState == 1) {
      // Read and display soil moisture value
      sensorValue = analogRead(sensorPin);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Soil Moisture:");
      lcd.setCursor(0, 1);
      lcd.print(sensorValue);

      displayState = 2;  // Move to the next sensor for the next cycle
    } else if (displayState == 2) {
      // Read and display distance sensor value
      long duration, distance;
      digitalWrite(TRIG_PIN, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG_PIN, LOW);
      duration = pulseIn(ECHO_PIN, HIGH);
      distance = (duration / 2) * 0.0343;  // Convert to distance in cm

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print(" cm");

      displayState = 0;  // Reset to the first sensor for the next cycle
    }
  }

  // Add a small delay to avoid reading the same value repeatedly
  delay(100);
  // Check if there is any data coming from the Bluetooth module
  if (Serial.available()) {
    char data = Serial.read();  // Read one character from the Bluetooth

    // Print received data to the serial monitor
    Serial.println(data);

    // Control the relay based on received data
    if (data == '0') {
      digitalWrite(relayPin, LOW);  // Turn ON the relay
      Serial.println("Relay is ON");
      delay(2000);
      digitalWrite(relayPin, HIGH);  // Turn OFF the relay
      Serial.println("Relay is OFF");
    } else if (data == '1') {
      // Move the first servo from 0 to 90 degrees
      myServo1.write(90);  // Move to 90 degrees
      Serial.println("Lifting leveler down");
    } else if (data == '2') {
      // Move the first servo back to 0 degrees
      myServo1.write(0);  // Move to 0 degrees
      Serial.println("Leveler up");
    } else if (data == '3') {
      myServo2.write(90);
      Serial.println("Moisture leveler up");
    } else if (data == '4') {
      myServo2.write(0);
      Serial.println("Moisture leveler down");
    } else if (data == '5') {
      // Read temperature and humidity from the DHT sensor
      float temperature = dht.readTemperature();
      float humidity = dht.readHumidity();
      // Print temperature and humidity to the serial monitor
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C | Humidity: ");
      Serial.print(humidity);
      Serial.println(" %");

      long duration, distance;
      digitalWrite(TRIG_PIN, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG_PIN, LOW);
      duration = pulseIn(ECHO_PIN, HIGH);
      distance = (duration / 2) * 0.0343;  // Convert to distance in cm

      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      sensorValue = analogRead(sensorPin);

      // Print the sensor value to the serial monitor
      Serial.print("Soil Moisture Value: ");
      Serial.println(sensorValue);
      delay(2000);
    } else if (data == 'L') {
      left();
    } else if (data == 'R') {
      right();
    } else if (data == 'F') {
      forward();
    } else if (data == 'B') {
      reverse();
    } else if (data == 'S') {
      stops();
    } else if (data == 'D') {
      drill();
    } else if (data == 'C') {
      seads();
    }

  }

  // Add a small delay to avoid reading the same value repeatedly
  delay(100);
}

void left() {
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
  Serial.println("Turning left");
}

void forward() {
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  Serial.println("Turning right");
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
  Serial.println("Moving forward");
}

void reverse() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving reverse");
}

void stops() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stopping");
}

void drill() {

  digitalWrite(C1, HIGH);
  digitalWrite(C4, HIGH);
  delay(8000);
  digitalWrite(C2, LOW);
  digitalWrite(C3, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(C4, LOW);
  delay(1000);
  digitalWrite(C2, HIGH);
  digitalWrite(C4, LOW);
  delay(8000); // Wait for 3 seconds
  digitalWrite(C2, LOW);
  digitalWrite(C3, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(C4, LOW);

}

void seads() {

  // Move the servo from 0 degrees to 20 degrees
  myServo3.write(145);
  delay(500); 

  myServo3.write(153);    // Move servo to 0 degrees (starting position) 
}
