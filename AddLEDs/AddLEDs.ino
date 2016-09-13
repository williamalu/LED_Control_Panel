// Main file

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Create a strip object for both LED strips
Adafruit_NeoPixel strip = Adafruit_NeoPixel(530, PIN, NEO_GRB + NEO_KHZ800);

// Default lights to off
byte currentCode = 0;
byte stopCode = 999;
byte previousCode = 999;

void setup() {
  Serial.begin(9600);
  
  strip.begin();
  strip.show();
}

void loop() {
  // Read serial for new command
  readSerial();
  
  // Set the lights to the given state
  switch(currentCode) {
    case 'a': // Off
      setStrip(strip.Color(0, 0, 0));
      currentCode = stopCode;
      break;
    case 'b': // White
      setStrip(strip.Color(255, 197, 143));
      currentCode = stopCode;
      break;
    case 'c': // Red
      setStrip(strip.Color(255, 0, 0));
      currentCode = stopCode;
      break;
    case 'd': // Green
      setStrip(strip.Color(0, 255, 0));
      currentCode = stopCode;
      break;
    case 'e': // Blue
      setStrip(strip.Color(0, 0, 255));
      currentCode = stopCode;
      break;
    case 'f': // Full rainbow (same color across room)
      rainbowFull(currentCode, 100);
      break;
    case 'g': // Normal rainbow (colors cycling around room)
      rainbow(currentCode, 100);
      break;
    case 'h': // Red Chase
      theaterChase(strip.Color(255, 0, 0), 100);
      break;
    case 'i': // Green Chase
      theaterChase(strip.Color(0, 255, 0), 100);
      break;
    case 'j': // Blue Chase
      theaterChase(strip.Color(0, 0, 255), 100);
      break;
    case 'k': //Random color fill
      randomRandom(currentCode, 10);
      break;
//    case 'z': //Notification
//      notify(S, stripS.Color(255, 0, 0), 5);
//      currentCode = stopCode;
//      break;
    case '999':
      break;
      
    previousCode = currentCode;
  }
}
