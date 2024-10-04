int relayPin = 2; // Pin connected to the relay

void setup() {
  // Initialize serial communication at 9600 baud rate (the default for HC-05)
  Serial.begin(9600);
  
  // Set the relay pin as output
  pinMode(relayPin, OUTPUT);
  
}

void loop() {
  // Check if there is any data coming from the Bluetooth module
  if (Serial.available()) {
    char data = Serial.read(); // Read one character from the Bluetooth

    // Print received data to the serial monitor
    Serial.print("Received: ");
    Serial.println(data);

    // Control the relay based on received data
    if (data == '1') {
      digitalWrite(relayPin, HIGH); // Turn ON the relay
      Serial.println("Relay is ON");
    } else if (data == '0') {
      digitalWrite(relayPin, LOW); // Turn OFF the relay
      Serial.println("Relay is OFF");
    }
  }

  // Add a small delay to avoid reading the same value repeatedly
  delay(100);
}
