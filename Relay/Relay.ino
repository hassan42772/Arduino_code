int relayPin = 2;  // Define the pin where the relay is connected

void setup() {
  pinMode(relayPin, OUTPUT); // Set the relay pin as an output
  digitalWrite(relayPin, LOW); // Initially turn off the relay
}

void loop() {
  digitalWrite(relayPin, HIGH); // Turn ON the relay (connect NO to COM)
  delay(2000);                  // Keep it on for 5 seconds
  
  digitalWrite(relayPin, LOW);  // Turn OFF the relay (disconnect NO from COM)
  delay(2000);                  // Keep it off for 5 seconds
}
