#include <AccelStepper.h>

// Motor 1 (IN1-IN4: 8, 10, 9, 11)
AccelStepper motor1(AccelStepper::FULL4WIRE, 8, 10, 9, 11);  // IN1, IN3 , IN2, IN4

// Motor 2 (IN1-IN4: 4, 6, 5, 7)
AccelStepper motor2(AccelStepper::FULL4WIRE, 4, 6, 5, 7);

int rainSensor = A0;
int buzzer = 3;

const int led1 = 2;
const int led2 = 12;

bool rainDetected = false;
bool rainTriggered = false;

long targetSteps = 15000;

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(rainSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led2, HIGH);

  motor1.setMaxSpeed(1600);
  motor1.setAcceleration(800);
  motor2.setMaxSpeed(1600);
  motor2.setAcceleration(800);
}

void loop() {
  int rainValue = analogRead(rainSensor);
  Serial.println(rainValue);

  // 🌧️ If rain is detected and not already triggered
  if (rainValue < 700 && !rainTriggered) {
    motor1.moveTo(targetSteps);
    motor2.moveTo(targetSteps);

    // Buzzer during forward motion
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);

      motor1.run();
      motor2.run();
    }

    rainDetected = true;
    rainTriggered = true;
  }

  // 🌤️ If rain stops and was previously triggered
  else if (rainDetected && rainValue > 700) {
    motor1.moveTo(0);
    motor2.moveTo(0);

    // Buzzer during reverse motion
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);

      motor1.run();
      motor2.run();
    }

    rainDetected = false;
    rainTriggered = false;
  }

  // Keep motors running outside of buzzer blocks
  motor1.run();
  motor2.run();
}
