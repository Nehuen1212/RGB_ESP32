#include "RGB.h"

Color::Color() : red(0), green(0), blue(0) {}

Color::Color(int _red, int _green, int _blue) : red(_red), green(_green), blue(_blue) {}

void Color::invertColor(){
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
}

RGB_LED::RGB_LED(int RedPin, int GreenPin, int BluePin,  int res, int _brightnessPin){
    R = RedPin;
    G = GreenPin;
    B = BluePin;

    if (_brightnessPin == -1) brightnessControl = false;
    else {
        brightnessPin = _brightnessPin; 
        brightnessControl = true;
    }    

    resolution = res;

}

void RGB_LED::reversePolarity() {
    reverse = true;
}

void RGB_LED::init(){
    ledcAttach(R, 5000, resolution);
    ledcAttach(G, 5000, resolution);
    ledcAttach(B, 5000, resolution);
    ledcAttach(brightnessPin, 5000, resolution);

    maxbrightness = pow(2, resolution);
}

void RGB_LED::setColor(int _red, int _green, int _blue){
    Color color(_red,_green,_blue);

    if(reverse) color.invertColor();

    ledcWrite(R, color.red);
    ledcWrite(G, color.green);
    ledcWrite(B, color.blue);

    lastColor = color;
}

void RGB_LED::setColor(Color color){
    setColor(color.red, color.green, color.blue);
}

void RGB_LED::setColorNoSave(int _red, int _green, int _blue){
    Color color(_red,_green,_blue);

    if(reverse) color.invertColor();

    ledcWrite(R, color.red);
    ledcWrite(G, color.green);
    ledcWrite(B, color.blue);
}

void RGB_LED::on(){
    if (brightnessControl){
        ledcWrite(brightnessPin, maxbrightness);
    }else{
        setColor(lastColor);
    }
}

void RGB_LED::off(){
    if(brightnessControl){
        ledcWrite(brightnessPin, 0);
    }else{
        setColorNoSave(0,0,0);
    }
    
}

void RGB_LED::setBrightness(int _brightness){
    int brightPWM;
    bright = _brightness;
    if(reverse) brightPWM = map(bright,0, 100, 0, maxbrightness);
    else{
         brightPWM = map(bright,0, 100, maxbrightness, 0);
    }
    if(brightnessControl){
        ledcWrite(brightnessPin, bright);
    }else {
        setColor(lastColor.red - brightPWM, lastColor.green - brightPWM, lastColor.blue - brightPWM);
    }
}

void RGB_LED::setBrightness(){
    int brightPWM;
    if(reverse) brightPWM = map(bright,0, 100, 0, maxbrightness);
    else{
         brightPWM = map(bright,0, 100, maxbrightness, 0);
    }
    if(brightnessControl){
        ledcWrite(brightnessPin, bright);
    }else {
        setColor(lastColor.red - brightPWM, lastColor.green - brightPWM, lastColor.blue - brightPWM);
    }
}

void RGB_LED::addBrightness(int _brightnessADD){
    bright += _brightnessADD;
    setBrightness();
}

void RGB_LED::lowerBrightness(int _brightnessLOW){
    bright -= _brightnessLOW;
    setBrightness();
}



