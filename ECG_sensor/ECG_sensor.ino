// Define the pin connected to the AD8232 ECG sensor's OUT
#define ECG_PIN 35  // Use GPIO35 for the analog input

// Variables to store ECG data
int ecgValue = 0;  // Variable to store the analog value from the sensor

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  
  // Brief delay for sensor stabilization
  delay(2000);

  // Print a startup message to indicate the program has started
  Serial.println("ECG Sensor AD8232 is ready");
}

void loop() {
  // Read the analog value from the ECG sensor (range 0-4095 on ESP32)
  ecgValue = analogRead(ECG_PIN);

  // Print the ECG sensor reading to the serial monitor
  Serial.print("ECG Value: ");
  Serial.println(ecgValue);

  // Small delay to allow for readable data on the serial monitor
  delay(1000);  // You can adjust this delay to control the rate of data display
}
