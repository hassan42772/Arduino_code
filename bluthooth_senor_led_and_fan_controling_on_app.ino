int led = 8;
int led1 = 7;
int led2 = 10;
int driver1 = 11; // in1 pin
int driver2 = 12; // in2 pin
int en=9; // speed control pin
int data;
int speed=225;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(driver1, OUTPUT);
  pinMode(driver2, OUTPUT);
  
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data);

    if (data == '1') {
      digitalWrite(led, HIGH);
    }
    if (data == '0') {
      digitalWrite(led, LOW);
    }
        if (data == '2') {
      digitalWrite(led1, HIGH);
    }
    if (data == '3') {
      digitalWrite(led1, LOW);
    }
      if (data == '4') {
      digitalWrite(led2, HIGH);
    }
    if (data == '5') {
      digitalWrite(led2, LOW);
    }
    if (data == '6') {
      analogWrite(en,speed);
      digitalWrite(driver1, HIGH);

    }
    if (data == '7') {
      digitalWrite(driver1, LOW);
    }
    
  }
}