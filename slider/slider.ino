const int stepPin =3 ;

const int dirPin = 4;

const int enPin = 2;

const int homeSwitchPin = A0;


void setup() {


   Serial.begin(9600);


  // Sets the two pins as Outputs

  pinMode(stepPin,OUTPUT);

  pinMode(dirPin,OUTPUT);

  pinMode(homeSwitchPin , INPUT_PULLUP);

  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);



  // Set Dir to Home switch

  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction

}

void loop() {

    int homeSw = digitalRead( homeSwitchPin);

    if( homeSw == HIGH && (digitalRead(dirPin) == LOW) ){

        motorStep(1);

    }

    else if( homeSw == LOW && (digitalRead(dirPin) == LOW) ){

          digitalWrite(dirPin,HIGH);

          delay(2000);

    }



    if( (digitalRead(dirPin) == HIGH) ){

        motorStep(2000);

        digitalWrite(dirPin,LOW);

        delay(2000);

    }

 
}

void motorStep( int MAX){


   for(int x = 0; x < MAX; x++) {

        digitalWrite(stepPin,HIGH);

        delayMicroseconds(1000);

        digitalWrite(stepPin,LOW);

        delayMicroseconds(1000);

      }

}