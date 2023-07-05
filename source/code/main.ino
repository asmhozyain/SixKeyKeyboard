

#include "Keyboard.h"
#include "FastLED.h"          // библиотека для работы с лентой

#define LED_COUNT 6          // число светодиодов в кольце/ленте
#define LED_DT 21             // пин, куда подключен DIN ленты

int max_bright = 255;         // максимальная яркость (0 - 255)
int ledMode = 3;

//declaring button pins
const int buttonPinT = 4;
const int buttonPinY = 5;
const int buttonPinR = 6;
const int buttonPinE = 7;
const int buttonPinW = 8;
const int buttonPinQ = 9;

int previousButtonStateT = HIGH;
int previousButtonStateY = HIGH;
int previousButtonStateR = HIGH;
int previousButtonStateE = HIGH;
int previousButtonStateW = HIGH;
int previousButtonStateQ = HIGH;

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
int BOTTOM_INDEX = 0;        // светодиод начала отсчёта
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)

int thisdelay = 200;          //-FX LOOPS DELAY VAR
int thisstep = 1;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR

int thisindex = 0;
int thisRED = 0;
int thisGRN = 0;
int thisBLU = 0;

int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue = 0;                //-HUE (0-255)
int ibright = 0;             //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR
// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_allHSV(int ahue) {    //-SET ALL LEDS TO ONE COLOR (HSV)
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i] = CHSV(ahue, thissat, 255);
  }
}

void setup() {
  LEDS.setBrightness(max_bright);
  LEDS.addLeds<WS2812B, LED_DT, GRB>(leds, LED_COUNT);
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();  
  
  //declare the buttons as input_pullup
  pinMode(buttonPinT, INPUT_PULLUP);
  pinMode(buttonPinY, INPUT_PULLUP);
  pinMode(buttonPinR, INPUT_PULLUP);
  pinMode(buttonPinE, INPUT_PULLUP);
  pinMode(buttonPinW, INPUT_PULLUP);
  pinMode(buttonPinQ, INPUT_PULLUP); 
  Keyboard.begin();
  //one_color_all(255, 255, 255); LEDS.show();
}

void loop() {
  rainbow_fade();
  
  //checking the state of the button
  int buttonStateT = digitalRead(buttonPinT);
  int buttonStateY = digitalRead(buttonPinY);
  int buttonStateR = digitalRead(buttonPinR);
  int buttonStateE = digitalRead(buttonPinE);
  int buttonStateW = digitalRead(buttonPinW);
  int buttonStateQ = digitalRead(buttonPinQ);
 //replaces button press with UP arrow
  if (buttonStateT == LOW && previousButtonStateT == HIGH) {
      // and it's currently pressed:
    Keyboard.press(104);
    delay(50);
  }

  if (buttonStateT == HIGH && previousButtonStateT == LOW) {
      // and it's currently released:
    Keyboard.release(104);
    delay(50);
  }


   if (buttonStateY == LOW && previousButtonStateY == HIGH) {
      // and it's currently pressed:
    Keyboard.press(103);
    delay(50);
  }

  if (buttonStateY == HIGH && previousButtonStateY == LOW) {
      // and it's currently released:
    Keyboard.release(103);
    delay(50);
  }

     if (buttonStateR == LOW && previousButtonStateR == HIGH) {
      // and it's currently pressed:
    Keyboard.press(102);
    delay(50);
  }

  if (buttonStateR == HIGH && previousButtonStateR == LOW) {
      // and it's currently released:
    Keyboard.release(102);
    delay(50);
  }

  if (buttonStateE == LOW && previousButtonStateE == HIGH) {
      // and it's currently pressed:
    Keyboard.press(100);
    delay(50);
  }

  if (buttonStateE == HIGH && previousButtonStateE == LOW) {
      // and it's currently released:
    Keyboard.release(100);
    delay(50);
  }

  if (buttonStateW == LOW && previousButtonStateW == HIGH) {
      // and it's currently pressed:
    Keyboard.press(115);
    delay(50);
  }

  if (buttonStateW == HIGH && previousButtonStateW == LOW) {
      // and it's currently released:
    Keyboard.release(115);
    delay(50);
  }

    if (buttonStateQ == LOW && previousButtonStateQ == HIGH) {
      // and it's currently pressed:
    Keyboard.press(97);
    delay(50);
  }

  if (buttonStateQ == HIGH && previousButtonStateQ == LOW) {
      // and it's currently released:
    Keyboard.release(97);
    delay(50);
  }
  
  previousButtonStateT = buttonStateT;
  previousButtonStateY = buttonStateY;
  previousButtonStateR = buttonStateR;
  previousButtonStateE = buttonStateE;
  previousButtonStateW = buttonStateW;
  previousButtonStateQ = buttonStateQ;
}
