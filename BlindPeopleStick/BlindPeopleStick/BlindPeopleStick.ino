#define TRIG_PIN 9   // Signal transmit
#define ECHO_PIN 10  // Receiver pin
#define BUZZER_PIN 2  // Define buzzer pin

void setup() {

  // Run ony once
  
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);  // Set buzzer pin as output
}

void loop() {
  // Clear TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10µs pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  float distance = duration * 0.0343 / 2;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Buzzer logic
  if (distance < 10) {  // You can change 10 to any threshold
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
  }

  delay(500);
}
