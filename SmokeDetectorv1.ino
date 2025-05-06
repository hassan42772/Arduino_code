// Pin definitions
const int mq5Pin = A0;
const int buzzerPin = 2;
const int redLedPin = 3;
const int greenLedPin = 4;

// Threshold value (adjust based on testing)
const int gasThreshold = 250;

void setup() {
  Serial.begin(9600);

  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Read value from MQ-5 sensor
  int gasValue = analogRead(mq5Pin);
  Serial.print("MQ-5 Value: ");
  Serial.println(gasValue);

  // Check gas concentration
  if (gasValue > gasThreshold) {
    // Danger! Gas detected
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Safe
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500); // Small delay for stability
}
