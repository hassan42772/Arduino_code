#include <Servo.h>
#define led 5
#define ir1 2
#define ir2 3
#define ldr A0 
int ir1reader;
int ir2reader;
int ldrreader;
int ldr_value;
int led_value;
Servo motor;
int ser;
int j=0;


void setup() {
  Serial.begin(9600);
  motor.attach(7);
  pinMode(led, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ldr, INPUT);


  // put your setup code here, to run once:
}

void loop() {
  bright(ldr_value);
  has (ldr_value);
  ir1reader = digitalRead(ir1);
  ir2reader = digitalRead(ir2);
  ldrreader = analogRead(ldr);
  Serial.print("Analog valuu= ");
  Serial.print(ldrreader);
  ldr_value = map(ldrreader, 0, 1023, 0, 180);
  Serial.print(" , maped_value= ");
  Serial.print(ldr_value);
  Serial.println("%");
  
  // Serial.print("ir sensor 1: ");
  // Serial.print(ir1reader);
  // Serial.print(" , ir sensor 2: ");
  // Serial.print(ir2reader);
  // Serial.print(" , ldr sensor: ");
  // Serial.print(ldrreader);
  // // Serial.println("");
  //  delay(1000);
  //  if (ir1reader==0){
  //    Serial.println("sensor1");
  //  }
  //  if (ir2reader==0){
  //    Serial.println("sensor2");
  //  }
  //  if(ir1reader==0 || ir2reader==0){
  //     bright(220,50);
  //  }


  // put your main code here, to run repeatedly:
}

void bright(int i){
  analogWrite(led, i);
}

void has (int j){
  motor.write(j);
}


// void bright(int i, int tim) {
//   analogWrite(led, i);
//   delay(tim);
//   analogWrite(led, 0);
//   delay(tim);
// }