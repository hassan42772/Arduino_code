// Pin Definitions
const int trigPin = 9;  // Trig pin of the distance sensor
const int echoPin = 8;  // Echo pin of the distance sensor
const int ledPin1 = 11; // LED pin
const int ledPin2 = 12;
const int ledPin3 = 3;
const int ledPin4 = 2;
const int ledPin5 = 4;
const int ledPin6 = 5;
const int ledPin7 = 6;
const int ledPin8 = 7;
const int buttonPin = 10; // Push button pin

// Variables
long duration;             // To store the duration of the ultrasonic pulse
int distance;              // To store the calculated distance in centimeters
bool ledOn = false;        // LED state
bool buttonState = false; // Button state
bool lastButtonState = false; // Previous button state

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
//  pinMode(ledPin8, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor for the button
  Serial.begin(9600); // Initialize serial communication

  // Initially, turn off the LED
  digitalWrite(ledPin1, HIGH);
  ledOn = false;
  digitalWrite(ledPin2, HIGH);
  ledOn = false;
  digitalWrite(ledPin3, HIGH);
  ledOn = false;
  digitalWrite(ledPin4, HIGH);
  ledOn = false;
  digitalWrite(ledPin5, HIGH);
  ledOn = false;
  digitalWrite(ledPin6, HIGH);
  ledOn = false;
  digitalWrite(ledPin7, HIGH);
  ledOn = false;
  digitalWrite(ledPin8, HIGH);
  ledOn = false;
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the button has been pressed (LOW) and the LED is on
  if (!buttonState && ledOn) {
    // Turn off the LED
    digitalWrite(ledPin1, HIGH);
    ledOn = false;
    digitalWrite(ledPin2, HIGH);
    ledOn = false;
    digitalWrite(ledPin3, HIGH);
    ledOn = false;
    digitalWrite(ledPin4, HIGH);
    ledOn = false;
    digitalWrite(ledPin5, HIGH);
    ledOn = false;
    digitalWrite(ledPin6, HIGH);
    ledOn = false;
    digitalWrite(ledPin7, HIGH);
    ledOn = false;
    digitalWrite(ledPin8, HIGH);
    ledOn = false;
  }

  // Measure the distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2; // Calculate distance in centimeters

  // Check if the object is detected at a distance of 10 cm or less
  if (distance <= 10) {
    // Turn on the LED
    digitalWrite(ledPin1, LOW);
    ledOn = true;
    digitalWrite(ledPin2, LOW);
    ledOn = true;
    digitalWrite(ledPin3, LOW);
    ledOn = true;
    digitalWrite(ledPin4, LOW);
    ledOn = true;
    digitalWrite(ledPin5, LOW);
    ledOn = true;
    digitalWrite(ledPin6, LOW);
    ledOn = true;
    digitalWrite(ledPin7, LOW);
    ledOn = true;
    digitalWrite(ledPin8, LOW);
    ledOn = true;
  }
}
