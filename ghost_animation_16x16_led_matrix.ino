
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

int body[] = {
0,1,2,3,4,5,6,7,21,22,
23,24,25,26,27,28,29,30,31,32,
33,34,35,36,37,38,39,40,41,42,
43,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,81,82,
83,84,85,86,87,88,89,90,91,92,
93,94,95,96,97,98,99,100,101,102,
103,104,105,106,107,108,109,110,113,114,
115,116,117,118,119,120,121,122,123,124,
125,126,127,128,129,130,131,132,133,134,
135,136,137,138,139,140,141,142,145,146,
147,148,149,150,151,152,153,154,155,156,
157,158,159,160,161,162,163,164,165,166,
167,168,169,170,171,172,173,174,178,179,
180,181,182,183,184,185,186,187,188,189,
190,191,192,193,194,195,196,197,198,199,
200,201,202,203,204,212,213,214,215,216,
217,218,219,220,221,222,223,224,225,226,
227,228,229,230,231,232,233,234,248,249,
250,251,252,253,254,255
};

int eyes_left[] = {
54,55,56,
70,71,72,73,74,
85,86,87,88,89,
103,104,105,
150,151,152,
166,167,168,169,170,
181,182,183,184,185,
199,200,201};

int eyes_right[] = {
71,72,73,
85,86,87,88,89,
102,103,104,105,106,
118,119,120,
169,168,167,
181,182,183,184,185,
202,201,200,199,198,
214,215,216};

int eyes_fill_body[] = {
149,150,151,152,153,53,54,55,56,57};


//remove pixels around feet
int void_pixels_1[] = {8, 29, 30, 31, 83, 84, 85, 86, 138, 139, 140, 161};
int void_pixels_2[] = {7, 31, 55, 56, 57, 112, 113, 114, 138, 162};


int feet_fill_body[] = {
224,222,129,128,63,33};

int sad_ghost[] = {11, 26, 35, 48, 49, 53, 60, 64, 65, 80, 89, 104, 105, 109, 116, 120, 121, 134, 143, 158};

int eyes_seconds = 2;
int reg_ghost_seconds = 10;

int feet_delay = 220; //delay in ms b/w feet v1 v2
int eye_loop = (eyes_seconds*1000)/feet_delay; // how many times to look left and right before switching 

int reg_ghost_loop = reg_ghost_seconds/eyes_seconds; 
int sad_ghost_loop = 50;
int sad_ghost_blink_loop = 10;


int pupil_right[] = {
151,152,
168,167,
72,71,
55,56};

int pupil_left[] = {
215,216,
200,199,
119,120,
104,103};


int feet_left[] = {
222,224,223,192,
129,126,128,127,
33,63,32,31};

int feet_right[] = {
255,
190,191,192,160,
65,64,63,95,
0};

int feet_fill[] = {
31,32,33,
224,223,222,
129,128,126,127};

int feet_fill2[] = {
31,32,33,
224,223,222,
129,128,126,127};

int feet_clear[] = {
254,225,222,193,190,161,158,129,126,97,94,65,62,33,30,1,
255,224,223,192,191,160,159,128,127,96,95,64,63,32,31,0
  };

void loop() {

    for(int i = 0; i < reg_ghost_loop; i++){

        for(int i = 0; i < eye_loop; i++){

            //BODY
            for (int i = 0; i < 206; i++){      //was 166
                  leds[body[i]] = CRGB::Green;
            }

            //EYES 
            for (int i = 0; i < 32; i++){
                leds[eyes_left[i]] = CRGB::White;
            }
            
            //PUPIL
            for (int i = 0; i < 8; i++){
                leds[pupil_right[i]] = CRGB::DarkBlue;
            }

            FastLED.show();

            //FEET
            for(int i = 0; i < 2; i++){

              //set feet 
              for (int i = 0; i < 12; i++){
                  leds[feet_left[i]] = CRGB::Black;
               }
              FastLED.show();
              delay(feet_delay);

              //set feet 
              for (int i = 0; i < 12; i++){
                  leds[feet_right[i]] = CRGB::Black;
              }
              for (int i = 0; i < 10; i++){
                  leds[feet_fill[i]] = CRGB::Green;
              }
              FastLED.show();
              delay(feet_delay);

              for (int i = 0; i < 32; i++){
                  leds[feet_clear[i]] = CRGB::Green;
              }


            } //end feet loop


            //CHANGE EYES
            
            //BODY
            for (int i = 0; i < 206; i++){      //was 166
                  leds[body[i]] = CRGB::Green;
            }

            //EYES 
            for (int i = 0; i < 32; i++){
                leds[eyes_right[i]] = CRGB::White;
            }
            
            //PUPIL
            for (int i = 0; i < 8; i++){
                leds[pupil_left[i]] = CRGB::DarkBlue;
            }

            FastLED.show();

            //FEET
            for(int i = 0; i < 2; i++){

              //set feet 
              for (int i = 0; i < 12; i++){
                  leds[feet_left[i]] = CRGB::Black;
               }
              FastLED.show();
              delay(feet_delay);

              //set feet 
              for (int i = 0; i < 12; i++){
                  leds[feet_right[i]] = CRGB::Black;
              }
              for (int i = 0; i < 10; i++){
                  leds[feet_fill[i]] = CRGB::Green;
              }
              FastLED.show();
              delay(feet_delay);

              for (int i = 0; i < 32; i++){
                  leds[feet_clear[i]] = CRGB::Green;
              }


            } 
         }  
    } 
}
