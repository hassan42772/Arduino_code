const int fsrPin = A0;  // Analog pin connected to FSR
int fsrReading;         // Variable to store the reading

void setup() {
  Serial.begin(9600);   // Initialize serial communication
}

void loop() {
  fsrReading = analogRead(fsrPin);  // Read the pressure value from the FSR
  Serial.print("FSR Reading: ");
  Serial.println(fsrReading);

  // Based on the reading, you can trigger actions, e.g., seat occupancy detection
  if (fsrReading > 200) {
    Serial.println("Seat Occupied");
  } else {
    Serial.println("Seat Empty");
  }

  delay(500);  // Delay for stability
}