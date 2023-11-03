#include "FastLED.h"

#define NUM_LEDS 256
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10); //Number 0-255
  FastLED.clear();
}

int eyes_seconds = 2;
int reg_ghost_seconds = 10;

int feet_delay = 220; //delay in ms b/w feet v1 v2
int eye_loop = (eyes_seconds*1000)/feet_delay; // how many times to look left and right before switching 

int reg_ghost_loop = reg_ghost_seconds/eyes_seconds; 
int sad_ghost_loop = 50;
int sad_ghost_blink_loop = 10;


int filler[] = {
138,116,117,107,108,84,83,82,78,77,
76,49,50,51,45,153,133,122,123,100,
99,91,92,93,67,66,65,60,61,62,
34
};

int colorcalc;

int color[] = {
160, 170, 180
};

//char color[] = {'Blue', 'Red', 'Green'};

void loop() {

    colorcalc = 0;
    
    for(int i = 0; i < 5; i++){

       for(int j = 0; j < 256; j++){

            colorcalc = colorcalc + 1;

            //leds[j] = CRGB::Blue;

            leds[j].setHue(colorcalc);
            FastLED.show();
            delay(05);

       } 

       for(int j = 256; j > 0; j--){
          leds[j] = CRGB::Black;
          FastLED.show();
          delay(05);
       }
    }
    for(int i = 0; i < 5; i++){

       for(int j = 0; j < 256; j++){

            colorcalc = colorcalc + 1;

            //leds[j] = CRGB::Blue;

            leds[j].setHue(colorcalc);
            FastLED.show();
            delay(050);

            leds[j] = CRGB::Black;
            FastLED.show();


        } 

    } 
}
