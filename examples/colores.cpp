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

  miLed.setColor(255, 0, 0);  //Color rojo
  
  Color verde(0, 255, 0); //Podemos almacenar colores
  miLed.setColor(verde);

}