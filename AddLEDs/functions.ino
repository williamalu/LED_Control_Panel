// Functions file

// Set every third LED the given color
void setEveryThird(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    if (i%3 == 0) {
      strip.setPixelColor(i, c);
    }
    else {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
    
    delay(wait);
  }
}

void randomRandom(byte inputCode, uint8_t wait) {
  int selectedPixel;
  uint32_t color = Wheel(random(0, 256));
  unsigned long previousTime = 0;
  unsigned long currentTime = millis();

  for (int i=0; i<strip.numPixels()/2;) {
    currentTime = millis();
    if (currentTime - previousTime >= wait) {
      previousTime = currentTime;
      selectedPixel = random(0, strip.numPixels());
      strip.setPixelColor(selectedPixel, color);
      strip.show();
      i++;
    }
    // Break if a new command is sent
    readSerial();
    if (currentCode != inputCode) {
      return;
    }
  }
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

// Fade the strip from on to off
void fadeOnToOff(byte inputCode, uint32_t wait) {
  float initialDim = .6;
  byte r = 255*initialDim;
  byte g = 197*initialDim;
  byte b = 143*initialDim;
  for(float i=1.0; i>0.05; i-=.001) {
    setStrip(strip.Color(r*i, g*i, b*i));
    delay(wait);
    
    // Break if a new command is sent
    readSerial();
    if (currentCode != inputCode) {
      return;
    }
  }
  setStrip(strip.Color(0, 0, 0));
  currentCode = stopCode;
}

void rainbow(byte inputCode, uint8_t wait) {
  uint16_t i, j;
  unsigned long previousTime = 0;
  unsigned long currentTime = millis();

  for(j=0; j<256;) {
    if (currentTime - previousTime >= wait) {
      for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel((i+j) & 255));
      }
      strip.show();
      j++;
    }
    // Break if a new command is sent
    readSerial();
    if (currentCode != inputCode) {
      return;
    }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) {
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// The entire strip cycles through the rainbow
void rainbowFull(byte inputCode, uint8_t wait) {
  uint16_t i;
  unsigned long previousTime = 0;
  unsigned long currentTime = millis();
  
  for (i=0; i<256;) {
    currentTime = millis();
    if (currentTime - previousTime >= wait) {
      previousTime = currentTime;
      setStrip(Wheel(i));
      i++;
    }
    // Break if a new command is sent
    readSerial();
    if (currentCode != inputCode) {
      return;
    }
  }
  
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);    //turn every third pixel off
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

void pixelWar(byte inputCode) {
  // Initialize a new random seed so the random numbers aren't always the same
  randomSeed(analogRead(0));
  
  uint32_t battleFront = strip.numPixels()/2;
  while((battleFront > 0) && (battleFront < strip.numPixels())) {
    for (int i=0; i<strip.numPixels(); i++) {
      if (i < battleFront) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
      }
      else {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
      }
    }
    strip.show();
    delay(50);
    battleFront += random(-10, 10);
    
    // Break if a new command is sent
    readSerial();
    if (currentCode != inputCode) {
      return;
    }
  }
  currentCode = stopCode;
}

void twinkle() {
  // Initialize a new random seed so the random numbers aren't always the same
  //randomSeed(analogRead(0));
  
  int min_brightness = random(0, 10);
  int max_brightness = min_brightness + 90;
  int rand_brightness;
  int led_start = random(0, 9);
  int led_increment = random(1, 10);
  for (int i=led_start; i<strip.numPixels(); i+=led_increment) {
    rand_brightness = random(min_brightness, max_brightness);
    strip.setPixelColor(i, strip.Color(rand_brightness, rand_brightness, rand_brightness));
    
    // Break if a new command is sent
    readSerial();
    if (currentCode != twinkleCode) {
      return;
    }
  }
  strip.show();
  delay(100);
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

// Reads serial for a new command
void readSerial() {
  if (Serial.available()) {
    byte newRead;
    String newCode;
    while(Serial.available() > 0) {
      newRead = Serial.read() - 97;
      newCode += String(newRead);
      delay(5);
    }
    currentCode = newCode.toInt();
    Serial.println(currentCode);
  }
}
