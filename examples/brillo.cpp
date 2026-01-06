#include "RGB_ESP32.h"

const int PIN_RED = 18;
const int PIN_GREEN = 19;
const int PIN_BLUE = 21;

RGB_LED rgb(PIN_RED, PIN_GREEN, PIN_BLUE, 8);

void setup() {
  Serial.begin(115200);
  rgb.init();
}

void loop() {

    //setColor(R,G,B)
  miLed.setColor(255, 0, 0);  //Color rojo
  

  //Itera y va disminuyendo el brillo
  for(int b = 100; b >= 0; b -= 10) {
    miLed.setBrightness(b);
    delay(100);
  }

}