// FastLED Cylon Example, using Non-Blocking WS2812Serial

#include <WS2812Serial.h>
#define USE_WS2812SERIAL
#include <FastLED.h>

//oled screen includes
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)



// How many leds in your strip?
#define NUM_LEDS1 10
#define NUM_LEDS2 64
#define NUM_LEDS3 24
#define NUM_LEDS4 24

int numLEDs[4] = {10, 64, 24, 24};
int pinLEDs[4] = { 8, 26, 32, 33};

// Usable pins:
//   Teensy LC:   1, 4, 5, 24
//   Teensy 3.2:  1, 5, 8, 10, 31   (overclock to 120 MHz for pin 8)
//   Teensy 3.5:  1, 5, 8, 10, 26, 32, 33, 48
//   Teensy 3.6:  1, 5, 8, 10, 26, 32, 33
//   Teensy 4.0:  1, 8, 14, 17, 20, 24, 29, 39
#define DATA_PIN 32

// Define the array of leds
CRGB leds1[NUM_LEDS1];
CRGB leds2[NUM_LEDS2];
CRGB leds3[NUM_LEDS3];
CRGB leds4[NUM_LEDS4];

void setup() {
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<WS2812SERIAL,14,RGB>(leds1,NUM_LEDS1);
  LEDS.addLeds<WS2812SERIAL,17,RGB>(leds2,NUM_LEDS2);
  LEDS.addLeds<WS2812SERIAL,24,RGB>(leds3,NUM_LEDS3);
  LEDS.addLeds<WS2812SERIAL,29,RGB>(leds4,NUM_LEDS4);
  
	LEDS.setBrightness(84);
  Serial.begin(115200);

    //display init
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println("OLED begun");
  
  // Clear the buffer
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(__FILENAME__);
  display.println(__DATE__);
  display.println(__TIME__);
  display.println("Initializing...");
  display.display(); // actually display all of the above
  delay(1000);
  
}

void fadeall() {
  for(int i = 0; i < 100; i++) {
    int imap1 = map(i,0, 100-1, 0, NUM_LEDS1-1);
    int imap2 = map(i,0, 100-1, 0, NUM_LEDS2-1);
    int imap3 = map(i,0, 100-1, 0, NUM_LEDS3-1);
    int imap4 = map(i,0, 100-1, 0, NUM_LEDS4-1);
    leds1[imap1].nscale8(250);
    leds2[imap2].nscale8(250);
    leds3[imap3].nscale8(250);
    leds4[imap4].nscale8(250); 
    } 
  }

void loop() {
	static uint8_t hue = 0;
	Serial.print("x");
	// First slide the led in one direction
	for(int i = 0; i < 100; i++) {
		// Set the i'th led to red
    int imap1 = map(i,0, 100-1, 0, NUM_LEDS1-1);
    int imap2 = map(i,0, 100-1, 0, NUM_LEDS2-1);
    int imap3 = map(i,0, 100-1, 0, NUM_LEDS3-1);
    int imap4 = map(i,0, 100-1, 0, NUM_LEDS4-1);

    
		leds1[imap1] = CHSV(hue++, 255, 255);
		leds2[imap2] = CHSV(hue++, 255, 255);
    leds3[imap3] = CHSV(hue++, 255, 255);
    leds4[imap4] = CHSV(hue++, 255, 255);
    // Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(20);
	}
	Serial.print("x");

	// Now go in the other direction.
	for(int i = (100)-1; i >= 0; i--) {

    int imap1 = map(i,0, 100-1, 1, NUM_LEDS1-1);
    int imap2 = map(i,0, 100-1, 1, NUM_LEDS2-1);
    int imap3 = map(i,0, 100-1, 1, NUM_LEDS3-1);
    int imap4 = map(i,0, 100-1, 1, NUM_LEDS4-1);

		// Set the i'th led to red
		leds1[imap1] = CHSV(hue++, 255, 255);
		leds2[imap2] = CHSV(hue++, 255, 255);
    leds3[imap3] = CHSV(hue++, 255, 255);
    leds4[imap4] = CHSV(hue++, 255, 255);
    // Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(20);
	}
}
