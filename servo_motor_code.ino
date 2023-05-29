#include <Servo.h>
int Red = 3;
int Yellow = 4;
int Green = 5;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int i = 0;
int j = 0;
int k =0;
int L=0;
int m=0;

  // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
    // attaches the servo on pin 9 to the servo object
}

void loop() {
led();
delay(3000);
Hassan();
delay(3000);
}






void Hassan() {
  for (i = 0; i >= 0; i--){
  myservo.write(i);
  delay(5);
  }
  delay(2000);
  for (j = 0; j <= 90; j++){
  myservo.write(j);
  delay(5);
  }
  delay(2000);
  for (k = 0; k <= 180; k++){
  myservo.write(k);
  delay(5);
  }
  delay(2000);
}


void led() {
  for(i = 0; i <= 10; i +=1){
  Serial.print("IN RED LIGHT FOR LOOP");
  digitalWrite(Red, HIGH);
  delay(100);
  digitalWrite(Red, LOW);
  delay(100);
  }
delay(100);
  for(j = 0; j <= 10; j +=1){
  Serial.print("IN YELLOW LIGHT FOR LOOP");
  digitalWrite(Yellow, HIGH);
  delay(100);
  digitalWrite(Yellow, LOW);
  delay(100);
  }
  delay(100);
  digitalWrite(Green, HIGH);
  delay(100);
  digitalWrite(Green,LOW);
  delay(100);
}






//   for (i = 0; i <= 180; i += 1) { // goes from 0 degrees to 180 degrees
//     // in steps of 1 degree
//     myservo.write(i);              // tell servo to go to position in variable 'pos'
//     delay(5);                       // waits 15 ms for the servo to reach the position
//   }
//   delay(3000);
//   for (i = 180; i >= 0; i -= 1) { // goes from 180 degrees to 0 degrees
//     myservo.write(i);              // tell servo to go to position in variable 'pos'
//     delay(15);                       // waits 15 ms for the servo to reach the position
//   }
//   delay(3000);
// }