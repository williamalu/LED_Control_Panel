#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic v1 (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixels data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

byte input = 0;
byte stopCode = 99;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to off
}

void loop() {
  if (Serial.available()) {
    input = Serial.read();
    Serial.println(input);
  }
  
  switch(input) {
    case '0': // Off
      colorWipe(strip.Color(0, 0, 0), 0);
      input = stopCode;
      break;
    case '1': // White
      colorWipe(strip.Color(150, 150, 75), 0);
      input = stopCode;
      break;
    case '2': // Red
      colorWipe(strip.Color(255, 0, 0), 0);
      input = stopCode;
      break;
    case '3': // Green
      colorWipe(strip.Color(0, 255, 0), 0);
      input = stopCode;
      break;
    case '4': // Blue
      colorWipe(strip.Color(0, 0, 255), 0);
      input = stopCode;
      break;
    case '5': // Rainbow
      rainbow(5);
      break;
    case '6': // Red Chase
      theaterChase(strip.Color(255, 0, 0), 100);
      break;
    case '7': // Green Chase
      theaterChase(strip.Color(0, 255, 0), 100);
      break;
    case '8': // Blue Chase
      theaterChase(strip.Color(0, 0, 255), 100);
      break;
    case '9': //Rainbow Chase
      theaterChaseRainbow(100);
      break;
    case '99':
      break;
  }
}

// Set the entire strip to a randomly generated color.
void setStripRandom() {
  int red = random(0, 256);
  int green = random(0, 256);
  int blue = random(0, 256);
  uint32_t color = strip.Color(red, green, blue);
  for(int pixelNum=0; pixelNum<strip.numPixels(); pixelNum++) {
    strip.setPixelColor(pixelNum, color);
  }
  strip.show();
}

// Set the entire strip to a given color.
void setStrip(uint32_t color) {
  for(int pixelNum=0; pixelNum<strip.numPixels(); pixelNum++) {
    strip.setPixelColor(pixelNum, color);
  }
  strip.show();
}

// Wipe the strip with a given color.
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
