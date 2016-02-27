// Main file

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define pinS 7
#define pinW 6

// Create a strip object for both LED strips
Adafruit_NeoPixel stripS = Adafruit_NeoPixel(150, pinS, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripW = Adafruit_NeoPixel(150, pinW, NEO_GRB + NEO_KHZ800);

// Default lights to off
byte currentCode = 0;
byte stopCode = 999;
byte previousCode = 999;

// Create variables for which LED strip is being controlled
String S = "S";
String W = "W";
String SW = "SW";
String strip = "SW";

void setup() {
  Serial.begin(9600);
  
  stripS.begin();
  stripW.begin();
  
  stripS.show();
  stripW.show();
}

void loop() {
  // Read serial for new command
  readSerial();
  
  // Set the lights to the given state
  switch(currentCode) {
    case '0': // Gain control of both strips
      strip = "SW";
      currentCode = previousCode;
      break;
    case '1': // Gain control of Shane's strip
      strip = "S";
      currentCode = previousCode;
      break;
    case '2': // Gain control of William's strip
      strip = "W";
      currentCode = previousCode;
      break;
    case 'a': // Off
      colorWipe(strip, stripS.Color(0, 0, 0), 0);
      currentCode = stopCode;
      break;
    case 'b': // White
      //colorWipe(strip, stripS.Color(150, 150, 75), 0);
      setHalfStrip(strip, stripS.Color(150, 150, 75));
      currentCode = stopCode;
      break;
    case 'c': // White
      colorWipe(strip, stripS.Color(255, 0, 0), 0);
      currentCode = stopCode;
      break;
    case 'd': // Green
      colorWipe(strip, stripS.Color(0, 255, 0), 0);
      currentCode = stopCode;
      break;
    case 'e': // Blue
      colorWipe(strip, stripS.Color(0, 0, 255), 0);
      currentCode = stopCode;
      break;
    case 'f': // Rainbow
      rainbowFull(currentCode, strip, 100);
      break;
    case 'g': // Red Chase
      theaterChase(strip, stripS.Color(255, 0, 0), 100);
      break;
    case 'h': // Green Chase
      theaterChase(strip, stripS.Color(0, 255, 0), 100);
      break;
    case 'i': // Blue Chase
      theaterChase(strip, stripS.Color(0, 0, 255), 100);
      break;
    case 'j': //Random color fill
      randomRandom(currentCode, strip, 100);
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
