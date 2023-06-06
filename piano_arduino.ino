//Arduino Piano
/*

Visit the Channel for more interesting projects

https://www.youtube.com/channel/UCks-9JSnVb22dlqtMgPjrlg

*/
#define T_A 440
#define T_B 493
#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392

const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
const int H = 9;


const int Buzz = A0;


void
  setup()
{
  pinMode(A, INPUT);
  digitalWrite(A,HIGH);

  
  pinMode(B, INPUT);
  digitalWrite(B,HIGH);
  
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);

  
  pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);


}

void loop()
{
  while(digitalRead(A)
  == LOW)
  {
    tone(Buzz,T_A);
    
  }


  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B);
    

  }

  while(digitalRead(C) == LOW)
  {
    tone(Buzz,T_C);
    

  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
    

  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
    

  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F);
    

  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
    

  }

  noTone(Buzz);
  

}

