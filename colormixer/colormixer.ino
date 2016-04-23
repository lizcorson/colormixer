/* ColorMixer
 *  Use a clear (common anode) RGB LED and a diffused WS2812B 
 *  through-hole LED to demonstrate the science of color mixing.
 *
 * Liz Corson
 * 22 April 2016
 */

#define RED 9
#define GREEN 10
#define BLUE 11

#define POT1 A1
#define POT2 A2
#define POT3 A3

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 1
#define DATA_PIN 4

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {    
  // Initialize the LED pins as outputs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(POT1, INPUT);
  pinMode(POT2, INPUT);
  pinMode(POT3, INPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // start with all colors off
  digitalWrite(RED, HIGH);  
  digitalWrite(GREEN, HIGH);  
  digitalWrite(BLUE, HIGH);  
  leds[0].setRGB(0,0,0);
  FastLED.show();
}
 
void loop() {
  int pot1val = analogRead(POT1);
  int color1val = map(pot1val,0,1024,0,255);
  if (color1val > 250) { // make sure LED turns off fully even if the pot is a bit off
    color1val = 255;
  }
  
  int pot2val = analogRead(POT2);
  int color2val = map(pot2val,0,1024,0,255);
  if (color2val > 250) { // make sure LED turns off fully even if the pot is a bit off
    color2val = 255;
  }

  int pot3val = analogRead(POT3);
  int color3val = map(pot3val,0,1024,0,255);
  if (color3val > 250) { // make sure LED turns off fully even if the pot is a bit off
    color3val = 255;
  }
  
  analogWrite(RED,color1val);
  analogWrite(GREEN,color2val);
  analogWrite(BLUE,color3val);
  //Since I used a common anode RGB LED I need to flip the scale for the WS2812B LED
  leds[0].setRGB(255-color1val,255-color2val,255-color3val);
  FastLED.show(); 
}
