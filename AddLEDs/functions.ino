// Functions file.

void randomRandom(String strips, uint8_t wait) {
  int selectedPixel;
  uint32_t color = stripS.Color(random(0, 256), random(0, 256), random(0, 256));
  setStrip(strips, stripS.Color(0, 0, 0));

  for (int i=0; i<stripS.numPixels(); i++) {
    selectedPixel = random(0, stripS.numPixels());
    if (strips.indexOf(S) != -1) {
      stripS.setPixelColor(selectedPixel, color);
      stripS.show();
    }
    if (strips.indexOf(W) != -1) {
      stripW.setPixelColor(selectedPixel, color);
      stripW.show();
    }
    delay(wait);
  }
}

// Set the entire stripS to a given color.
void setStrip(String strips, uint32_t color) {
  for(int pixelNum=0; pixelNum<stripS.numPixels(); pixelNum++) {
    if (strips.indexOf(S) != -1) {
      stripS.setPixelColor(pixelNum, color);
    }
    if (strips.indexOf(W) != -1) {
      stripW.setPixelColor(pixelNum, color);
    }
  }
  if (strips.indexOf(S) != -1) {
      stripS.show();
  }
  if (strips.indexOf(W) != -1) {
      stripW.show();
  }
}

// Wipe the stripS with a given color.
void colorWipe(String strips, uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<stripS.numPixels(); i++) {
    if (strips.indexOf(S) != -1) {
      stripS.setPixelColor(i, c);
      stripS.show();
    }
    if (strips.indexOf(W) != -1) {
      stripW.setPixelColor(i, c);
      stripW.show();
    }
    
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<stripS.numPixels(); i++) {
      stripS.setPixelColor(i, Wheel((i+j) & 255));
    }
    stripS.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) {
    for(i=0; i< stripS.numPixels(); i++) {
      stripS.setPixelColor(i, Wheel(((i * 256 / stripS.numPixels()) + j) & 255));
    }
    stripS.show();
    delay(wait);
  }
}

void rainbowFull(String strips, uint8_t wait) {
  uint16_t i;
  for (i=0; i<256; i++) {
    setStrip(strips, Wheel(i));
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(String strips, uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < stripS.numPixels(); i=i+3) {
        if (strips.indexOf(S) != -1) {
          stripS.setPixelColor(i+q, c);    //turn every third pixel on
        }
        if (strips.indexOf(W) != -1) {
          stripW.setPixelColor(i+q, c);    //turn every third pixel on
        }
      }
      if (strips.indexOf(S) != -1) {
          stripS.show();
      }
      if (strips.indexOf(W) != -1) {
          stripW.show();
      }

      delay(wait);

      for (int i=0; i < stripS.numPixels(); i=i+3) {
        if (strips.indexOf(S) != -1) {
          stripS.setPixelColor(i+q, 0);    //turn every third pixel off
        }
        if (strips.indexOf(W) != -1) {
          stripW.setPixelColor(i+q, 0);    //turn every third pixel off
        }
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(String strips, uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < stripS.numPixels(); i=i+3) {
        stripS.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      stripS.show();

      delay(wait);

      for (int i=0; i < stripS.numPixels(); i=i+3) {
        stripS.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return stripS.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return stripS.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return stripS.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
