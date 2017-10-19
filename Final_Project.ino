#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 8, 6,
NEO_MATRIX_TOP + NEO_MATRIX_RIGHT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
NEO_GRB + NEO_KHZ800);

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(80, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.






int analogPin = A0; // read from multiplexer using analog input 0
int strobePin = 2; // strobe is attached to digital pin 2
int resetPin = 3; // reset is attached to digital pin 3
int spectrumValue[7]; // to hold a2d values
int col_A = 0;
int col_B = 0;
int col_C = 0;
int adjust = 0;

void setup()
{
  Serial.begin(9600);
  //pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  //analogReference(DEFAULT);

  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);

  Serial.println("MSGEQ7 test by J Skoba");



  
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip.setBrightness(35);
  strip.show(); // Initialize all pixels to 'off'



  
}

void loop()
{

  strip.setPixelColor(0, strip.Color(col_A, col_B, col_C));
  
  
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);

  for (int i = 0; i < 7; i++)
  {
    if (i == 0 || i == 6)
    {
      col_A = 255;
      col_B = 0;
      col_C = 0;
    }
    if (i == 1 || i == 5)
    {
      col_A = 0;
      col_B = 255;
      col_C = 0;
    }
    if (i == 2 || i == 4)
    {
      col_A = 0;
      col_B = 0;
      col_C = 255;
    }
    if (i == 3)
    {
      col_A = 255;
      col_B = 20;
      col_C = 147;
    }
    digitalWrite(strobePin, LOW);
    delayMicroseconds(30); // to allow the output to settle
    spectrumValue[i] = analogRead(analogPin);

    // comment out/remove the serial stuff to go faster
    // - its just here for show
    if (i == 0 || i == 1)
    {
      if (spectrumValue[i] > 0 && spectrumValue[i] < 100)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
      }
    
      if (spectrumValue[i] > 100 && spectrumValue[i] < 200)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, st2rip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 200 && spectrumValue[i] < 300)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 300 && spectrumValue[i] < 400)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 400 && spectrumValue[i] < 500)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
      }
      
      if (spectrumValue[i] > 500 && spectrumValue[i] < 600)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 600 && spectrumValue[i] < 700)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 900 && spectrumValue[i] < 1200)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+7, strip.Color(col_A, col_B, col_C));
      }
   
    }

    if (i == 2)
    {
      if (spectrumValue[i] > 0 && spectrumValue[i] < 100)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        
        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
      }
    
      if (spectrumValue[i] > 100 && spectrumValue[i] < 200)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 200 && spectrumValue[i] < 300)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 300 && spectrumValue[i] < 400)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 400 && spectrumValue[i] < 500)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12, strip.Color(col_A, col_B, col_C));
      }
      
      if (spectrumValue[i] > 500 && spectrumValue[i] < 600)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+13, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 600 && spectrumValue[i] < 700)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+13, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+14, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 900 && spectrumValue[i] < 1200)
      {
        strip.setPixelColor(((8*i)), strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+7, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+13, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+14, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+15, strip.Color(col_A, col_B, col_C));
      }

   
    }

    if (i == 3 || i == 4)
    {
      if (i == 3)
      {
        adjust = 8;
      }
      if (i == 4)
      {
        adjust = 16;
      }
     if (spectrumValue[i] > 0 && spectrumValue[i] < 100)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        
        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
      }
    
      if (spectrumValue[i] > 100 && spectrumValue[i] < 200)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 200 && spectrumValue[i] < 300)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10+adjust, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 300 && spectrumValue[i] < 400)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11+adjust, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 400 && spectrumValue[i] < 500)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12+adjust, strip.Color(col_A, col_B, col_C));
      }
      
      if (spectrumValue[i] > 500 && spectrumValue[i] < 600)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+13+adjust, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 600 && spectrumValue[i] < 700)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+13+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+14+adjust, strip.Color(col_A, col_B, col_C));
      }

      if (spectrumValue[i] > 900 && spectrumValue[i] < 1200)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+7+adjust, strip.Color(col_A, col_B, col_C));

        strip.setPixelColor(((8*i))+adjust+8, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+9+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+10+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+11+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+12+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+13+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+14+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+15+adjust, strip.Color(col_A, col_B, col_C));
      }

   
    }

    if (i == 5 || i == 6)
    {
      if (i == 5)
      {
        adjust = 24;
      }
      if (i == 6)
      {
        adjust = 24;
      }
     if (spectrumValue[i] > 0 && spectrumValue[i] < 100)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
       
      }
    
      if (spectrumValue[i] > 100 && spectrumValue[i] < 200)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));

      }

      if (spectrumValue[i] > 200 && spectrumValue[i] < 300)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));

      }

      if (spectrumValue[i] > 300 && spectrumValue[i] < 400)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));

      }

      if (spectrumValue[i] > 400 && spectrumValue[i] < 500)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));

      }
      
      if (spectrumValue[i] > 500 && spectrumValue[i] < 600)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5+adjust, strip.Color(col_A, col_B, col_C));

      }

      if (spectrumValue[i] > 600 && spectrumValue[i] < 700)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6+adjust, strip.Color(col_A, col_B, col_C));

      }

      if (spectrumValue[i] > 900 && spectrumValue[i] < 1200)
      {
        strip.setPixelColor(((8*i))+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+1+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+2+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+3+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+4+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+5+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+6+adjust, strip.Color(col_A, col_B, col_C));
        strip.setPixelColor(((8*i))+7+adjust, strip.Color(col_A, col_B, col_C));

      }

   
    }
    
    if (spectrumValue[i] < 10)
    {
      Serial.print("\t");
      Serial.print(spectrumValue[i]);
    }
    else if (spectrumValue[i] < 100 )
    {
      Serial.print("\t");
      Serial.print(spectrumValue[i]);
    }
    else
    {
      Serial.print("\t");
      Serial.print(spectrumValue[i]);
    }

    digitalWrite(strobePin, HIGH);
    delayMicroseconds(30);

    
  }
  strip.show();
  Serial.println();

  strip.setPixelColor(0, strip.Color(0,0,0));
  strip.setPixelColor(1, strip.Color(0,0,0));
  strip.setPixelColor(2, strip.Color(0,0,0));
  strip.setPixelColor(3, strip.Color(0,0,0));
  strip.setPixelColor(4, strip.Color(0,0,0));
  strip.setPixelColor(5, strip.Color(0,0,0));
  strip.setPixelColor(6, strip.Color(0,0,0));
  strip.setPixelColor(7, strip.Color(0,0,0));
  strip.setPixelColor(8, strip.Color(0,0,0));
  strip.setPixelColor(9, strip.Color(0,0,0));
  strip.setPixelColor(10, strip.Color(0,0,0));
  strip.setPixelColor(11, strip.Color(0,0,0));
  strip.setPixelColor(12, strip.Color(0,0,0));
  strip.setPixelColor(13, strip.Color(0,0,0));
  strip.setPixelColor(14, strip.Color(0,0,0));
  strip.setPixelColor(15, strip.Color(0,0,0));
  strip.setPixelColor(16, strip.Color(0,0,0));
  strip.setPixelColor(17, strip.Color(0,0,0));
  strip.setPixelColor(18, strip.Color(0,0,0));
  strip.setPixelColor(19, strip.Color(0,0,0));
  strip.setPixelColor(20, strip.Color(0,0,0));
  strip.setPixelColor(21, strip.Color(0,0,0));
  strip.setPixelColor(22, strip.Color(0,0,0));
  strip.setPixelColor(23, strip.Color(0,0,0));
  strip.setPixelColor(24, strip.Color(0,0,0));
  strip.setPixelColor(25, strip.Color(0,0,0));
  strip.setPixelColor(26, strip.Color(0,0,0));
  strip.setPixelColor(27, strip.Color(0,0,0));
  strip.setPixelColor(28, strip.Color(0,0,0));
  strip.setPixelColor(29, strip.Color(0,0,0));
  strip.setPixelColor(30, strip.Color(0,0,0));
  strip.setPixelColor(31, strip.Color(0,0,0));
  strip.setPixelColor(32, strip.Color(0,0,0));
  strip.setPixelColor(33, strip.Color(0,0,0));
  strip.setPixelColor(34, strip.Color(0,0,0));
  strip.setPixelColor(35, strip.Color(0,0,0));
  strip.setPixelColor(36, strip.Color(0,0,0));
  strip.setPixelColor(37, strip.Color(0,0,0));
  strip.setPixelColor(38, strip.Color(0,0,0));
  strip.setPixelColor(39, strip.Color(0,0,0));
  strip.setPixelColor(40, strip.Color(0,0,0));
  strip.setPixelColor(41, strip.Color(0,0,0));
  strip.setPixelColor(42, strip.Color(0,0,0));
  strip.setPixelColor(43, strip.Color(0,0,0));
  strip.setPixelColor(44, strip.Color(0,0,0));
  strip.setPixelColor(45, strip.Color(0,0,0));
  strip.setPixelColor(46, strip.Color(0,0,0));
  strip.setPixelColor(47, strip.Color(0,0,0));
  strip.setPixelColor(48, strip.Color(0,0,0));
  strip.setPixelColor(49, strip.Color(0,0,0));
  strip.setPixelColor(50, strip.Color(0,0,0));
  strip.setPixelColor(51, strip.Color(0,0,0));
  strip.setPixelColor(52, strip.Color(0,0,0));
  strip.setPixelColor(53, strip.Color(0,0,0));
  strip.setPixelColor(54, strip.Color(0,0,0));
  strip.setPixelColor(55, strip.Color(0,0,0));
  strip.setPixelColor(56, strip.Color(0,0,0));
  strip.setPixelColor(57, strip.Color(0,0,0));
  strip.setPixelColor(58, strip.Color(0,0,0));
  strip.setPixelColor(59, strip.Color(0,0,0));
  strip.setPixelColor(60, strip.Color(0,0,0));
  strip.setPixelColor(61, strip.Color(0,0,0));
  strip.setPixelColor(62, strip.Color(0,0,0));
  strip.setPixelColor(63, strip.Color(0,0,0));
  strip.setPixelColor(64, strip.Color(0,0,0));
  strip.setPixelColor(65, strip.Color(0,0,0));
  strip.setPixelColor(66, strip.Color(0,0,0));
  strip.setPixelColor(67, strip.Color(0,0,0));
  strip.setPixelColor(68, strip.Color(0,0,0));
  strip.setPixelColor(69, strip.Color(0,0,0));
  strip.setPixelColor(70, strip.Color(0,0,0));
  strip.setPixelColor(71, strip.Color(0,0,0));
  strip.setPixelColor(72, strip.Color(0,0,0));
  strip.setPixelColor(73, strip.Color(0,0,0));
  strip.setPixelColor(74, strip.Color(0,0,0));
  strip.setPixelColor(75, strip.Color(0,0,0));
  strip.setPixelColor(76, strip.Color(0,0,0));
  strip.setPixelColor(77, strip.Color(0,0,0));
  strip.setPixelColor(78, strip.Color(0,0,0));
  strip.setPixelColor(79, strip.Color(0,0,0)); 
}

void lightFunction(int num_colors, int pix_num){
  int num_lights = num_colors/5;
  int j = pix_num;
  if (num_lights < 5)
  {
    strip.setPixelColor(j, strip.Color(col_A, col_B, col_C));
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<80; i++) {
    strip.setPixelColor(i, c);
    strip.show();
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




