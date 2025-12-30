#ifndef RGB_ESP32_H
#define RGB_ESP32_H

#include <Arduino.h>
#include <cmath>

struct Color{
    int red;
    int green;
    int blue;

    Color();
    Color(int _red, int _green, int _blue);

    void invertColor();    
};

class RGB_LED {
public:
    
    RGB_LED(int RedPin, int GreenPin, int BluePin, int res = 8, int _brightnessPin = -1);
    void init();
    void reversePolarity();
    
    void setColor(int rojo, int verde, int azul); // 0 - 2 ** resolution
    void setColor(Color color); 
    void setColorNoSave(int rojo, int verde, int azul);
    void on();
    void off();

    void setBrightness(int _brightness); // 0 - 100
    void setBrightness();
    void addBrightness(int _brightnessADD);
    void lowerBrightness(int _brightnessLOW);

    int resolution;

private:
    int R;
    int G;
    int B;
    int brightnessPin;

    int bright;
    
    Color lastColor;
    bool brightnessControl;

    double maxbrightness;
    bool reverse = false;
};

#endif // RGB_H
