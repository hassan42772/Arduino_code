#include <DHT.h>

// Define the DHT sensor type (DHT11)
#define DHT_TYPE DHT11

// Pin to which the DHT sensor is connected (Digital Pin 13)
const int dhtPin = 3;

// Initialize the DHT sensor
DHT dht(dhtPin, DHT_TYPE);

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature and humidity from the DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if the readings are valid

  // Print temperature and humidity to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");


  // Add a delay before the next reading
  delay(2000);
}