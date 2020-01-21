#include <Adafruit_NeoPixel.h>

#define PIN 6 //input pin neopixel is attached to

#define NUMPIXELS 27 //number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5; //timing delay in milliseconds
class Color {
  public:
    int red = 0;
    int green = 0;
    int blue = 0;
    void newColor() {
      red = random(0, 255);
      green = random(0, 255);
      blue = random(0, 255);
    }
  //i did math here
    void fadeTo(Color color) {
      red = red * 0.99 + color.red * 0.01;
      green = green * 0.99 + color.green * 0.01;
      blue = blue * 0.99 + color.blue * 0.01;
    }
};

Color c1;
Color c2;
Color c3;
int flip;

void setup() {
  //initialize the neopixel library.
  pixels.begin();
}

void loop() {
  //random colors
  c1.newColor();
  c2.newColor();
  c3.newColor();
  
  //flip flop
  flip = 0;
  
  //setup
  for (int i = 0; i < NUMPIXELS; i++) {
    //every other color is different
    if (!flip) {
      pixels.setPixelColor(i, pixels.Color(c1.red, c1.green, c1.blue));
    } else {
      pixels.setPixelColor(i, pixels.Color(c2.red, c2.green, c2.blue));
    }
    flip = 1 - flip;
  }
  pixels.show();
  delay(500);
  
  //man loop
  for (int i = 0; i < 180; i++) {
    //idk what animation to do so I just made it fade
    c1.fadeTo(c3);
    c2.fadeTo(c3);
    flip = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      if (!flip) {
        pixels.setPixelColor(i, pixels.Color(c1.red, c1.green, c1.blue));
      } else {
        pixels.setPixelColor(i, pixels.Color(c2.red, c2.green, c2.blue));
      }
      //flip every time
      flip = 1 - flip;
    }
    pixels.show();

    //wait
    delay(delayval);
  }
}
