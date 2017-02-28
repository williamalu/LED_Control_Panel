// Main file

#include <Adafruit_NeoPixel.h>

const byte lightsPin = 6;
const byte microphonePin = 2;

// Create a strip object for both LED strips
Adafruit_NeoPixel strip = Adafruit_NeoPixel(510, lightsPin, NEO_GRB + NEO_KHZ800);

// Define light modes
const byte offCode = 0;
const byte whiteCode = 1;
const byte redCode = 2;
const byte greenCode = 3;
const byte blueCode = 4;
const byte homoRainbowCode = 5;
const byte heteroRainbowCode = 6;
const byte redChaseCode = 7;
const byte greenChaseCode = 8;
const byte blueChaseCode = 9;
const byte randomRandomCode = 10;
const byte fadeOnToOffCode = 11;
const byte pixelWarCode = 12;
const byte twinkleCode = 13;
const byte checkForClapCode = 254;
const byte stopCode = 255;

// Default lights to off
byte currentCode = 0;
byte previousCode = stopCode;

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
  case offCode: // Off
    setStrip(strip.Color(0, 0, 0));
    currentCode = stopCode;
    break;
  case whiteCode: // White
    setStrip(strip.Color(255, 197, 143));
    currentCode = stopCode;
    break;
  case redCode: // Red
    setStrip(strip.Color(255, 0, 0));
    currentCode = stopCode;
    break;
  case greenCode: // Green
    setStrip(strip.Color(0, 255, 0));
    currentCode = stopCode;
    break;
  case blueCode: // Blue
    setStrip(strip.Color(0, 0, 255));
    currentCode = stopCode;
    break;
  case homoRainbowCode: // Full rainbow (same color across room)
    rainbowFull(currentCode, 100);
    break;
  case heteroRainbowCode: // Normal rainbow (colors cycling around room)
    rainbow(currentCode, 100);
    break;
  case redChaseCode: // Red Chase
    theaterChase(strip.Color(255, 0, 0), 100);
    break;
  case greenChaseCode: // Green Chase
    theaterChase(strip.Color(0, 255, 0), 100);
    break;
  case blueChaseCode: // Blue Chase
    theaterChase(strip.Color(0, 0, 255), 100);
    break;
  case randomRandomCode: //Random color fill
    randomRandom(currentCode, 10);
    break;
  case fadeOnToOffCode: //Fade from on to off
    fadeOnToOff(currentCode, 50);
    break;
  case pixelWarCode: //Pixel war
    pixelWar(currentCode);
    break;
  case twinkleCode:
    twinkle();
    break;
  case stopCode:
    break;
  }
    
  previousCode = currentCode;
}
