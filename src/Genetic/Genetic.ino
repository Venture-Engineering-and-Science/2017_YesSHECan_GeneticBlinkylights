#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define F_CPU 16000000
#define PIN            6
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

typedef struct dna_t {
    uint8_t colors[15];
    uint8_t rotate;
    uint8_t delay_time;
    uint8_t pause_time;
    char* pattern;
} dna_t;


dna_t LED_DNA = {
    .colors = {
        255, 0, 15,
        0, 255, 113,
        255, 113, 0,
    },
    .rotate = 0,
    .delay_time = 50,
    .pause_time = 200,
    .pattern = "4",
};

void setup() {
    pixels.begin();
    pixels.show();
}

void loop() {
  //none();
  run_DNA();
}
