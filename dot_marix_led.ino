#include <LedControl.h>
int DIN = 8;
int CS =  3;
int CLK = 6;
int a = 1500;
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,0);      //Adjust the brightness maximum is 15
 lc.clearDisplay(0);    
}

void loop(){ 
    
    byte cross[8]={0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81,};
    byte tick[8]={0x00,0x00,0x01,0x02,0x04,0x88,0x50,0x20,};
    
    printByte(cross);
    
    delay(a);
      
    printByte(tick);
     
    delay(a);

    
     }

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
