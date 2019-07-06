#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_TYPE      WS2812B
#define MATRIX_WIDTH  16
#define MATRIX_HEIGHT 16
#define BRIGHTNESS    17
#define DATA_PIN      3

#define arr_len( x )  ( sizeof( x ) / sizeof( *x ) )

// Matrix setup params
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, DATA_PIN,
NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

//Editing part.
char* Text[]= {"Atthah Info Media Pvt. Ltd."};
const uint16_t colors[] = {
  matrix.Color(255, 0, 255), matrix.Color(100, 255, 0), matrix.Color(255, 255, 0), matrix.Color(255, 0, 255), matrix.Color(0, 255, 255), matrix.Color(255, 255, 255)};

int numMode = arr_len(Text)-1;
int numColor = arr_len(colors)-1;
int maxDisplacement;
int mode = 0;

int y = matrix.width();
int x = matrix.height();

int pass = 0;
int line_pass = 0;
int displaySize = matrix.height()/8;
int pixelPerChar = displaySize*6;

void setup() { 
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(BRIGHTNESS);
  matrix.setTextColor(colors[0]);
}

void loop() {
  // if mode greater than numMode reset
  if (mode > numMode)
    mode = 0;
  matrix.fillScreen(50);
  matrix.setCursor(x, 1);
  scroll(Text[mode],50);
}

// scrolling
void scroll(char* message,int delays) {
  matrix.setTextSize(displaySize);
  maxDisplacement = strlen(message) * pixelPerChar + matrix.width();
  if(++line_pass > matrix.width())
    line_pass = 0;
  matrix.print(String(message));
  if(--x < -maxDisplacement) {
    x = matrix.width();
    if(++pass >= numColor)
      pass = 0;
    matrix.setTextColor(colors[pass]);
    mode++;
  }
  matrix.show();
  delay(delays);
}
