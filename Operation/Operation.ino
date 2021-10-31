#include "FastLED.h"

#define NUM_LEDS 12
#define DATA_PIN 3

CRGB leds[NUM_LEDS];


int tongsPin = 4;  // Digital 2
int relaypin = 2;
int temp = 1;

void setup(){
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(tongsPin, INPUT);
  pinMode(relaypin, OUTPUT);
  digitalWrite(tongsPin, HIGH); //enable pullup resistor
  digitalWrite(relaypin, LOW);

  fill_solid( leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop(){
  
  temp = digitalRead(tongsPin);
  
    if (temp == 0)
    {

      digitalWrite(relaypin, HIGH);  
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(250);

      digitalWrite(relaypin, LOW); 
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show(); 
      delay(250);

      digitalWrite(relaypin, HIGH); 
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(250);

      digitalWrite(relaypin, LOW);  
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show(); 
      delay(250);
    }
    delay(1);
}
