/* OPERATION GAME
    * Just your basic operation game
        * Conductive edges of holes in person are connected to ground
        * Metal tongs tethered to game with wire connected to TONGS_PIN
        * Nose of operation guy lit up by pixel ring
        * relay connects to buzzer
    * Initially I was thinking of using capacitive touch as the sense method (using MPR121).
      This has enough channels to connect each hole to a different input and then use pixel
      LEDs inside to flash where the mistakes were made. Being capacitive touch people could
      just use their hands to retrieve things and still trigger a fault.... BUT I didn't
      have time to get that working initially, but this method works well
*/

// Libraries
#include "FastLED.h"

// IO Setup
#define TONGS_PIN 	4
#define RELAY_PIN 	2
#define LED_PIN 		3

// Pixel setup
#define NUM_LEDS 		12
CRGB leds[NUM_LEDS];

// Misc variables
#define FLASH_TIME	250 		// (ms) Half cycle length of operation guy complaining


void setup()
{
	FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
	pinMode(TONGS_PIN, INPUT_PULLUP);
	pinMode(RELAY_PIN, OUTPUT);

	digitalWrite(RELAY_PIN, LOW);

	// Start with LEDs off
	fill_solid(leds, NUM_LEDS, CRGB::Black);
	FastLED.show();
}

void loop()
{
	if (!digitalRead(TONGS_PIN)) 												// If surgeon touched edge of hole in operation guy
	{
		for (uint8_t i = 0; i < 2; ++i) 									// Flash LEDs & buzzer twice
		{
			digitalWrite(RELAY_PIN, HIGH);  
			fill_solid( leds, NUM_LEDS, CRGB::Red);
			FastLED.show();
			delay(FLASH_TIME);

			digitalWrite(RELAY_PIN, LOW); 
			fill_solid( leds, NUM_LEDS, CRGB::Black);
			FastLED.show(); 
			delay(FLASH_TIME);
		}
	}
}
