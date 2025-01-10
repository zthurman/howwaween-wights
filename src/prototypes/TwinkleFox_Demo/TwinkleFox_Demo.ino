#include "FastLED.h"
#include "fx/1d/twinklefox.hpp"

//#define NUM_LEDS        300
#define NUM_LEDS        150
#define LED_TYPE        APA102
//#define COLOR_ORDER     RGB
#define COLOR_ORDER     RGB
#define DATA_PIN        13
#define CLOCK_PIN       11
#define VOLTS           5
#define MAX_MA          4000
#define SECONDS_PER     60

CRGBArray<NUM_LEDS> leds;
TwinkleFox twinkleFox(NUM_LEDS);

void setup() {
  delay(3000); // safety startup delay
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_MA);
  FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setRgbw();
}

void loop() {
  //EVERY_N_SECONDS(SECONDS_PER_PALETTE) {
  EVERY_N_SECONDS(SECONDS_PER) {  
    twinkleFox.chooseNextColorPalette(twinkleFox.targetPalette); 
  }
  twinkleFox.draw(Fx::DrawContext(millis(), leds));
  FastLED.show();
}
