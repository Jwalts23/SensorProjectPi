#include "rgbLED.h"

rgbLED::rgbLED(int RedPin, int GreenPin, int BluePin){

    redLED.setPin(RedPin);
    greenLED.setPin(GreenPin);
    blueLED.setPin(BluePin);
}

void rgbLED::init(){
    redLED.init();
    greenLED.init();
    blueLED.init();
}

void rgbLED::setColor(string color){
    if (color.compare("white") == 0)
    {
        redLED.on();
        greenLED.on();
        blueLED.on();
    }
    if (color.compare("red") == 0)
    {
        redLED.on();
        greenLED.off();
        blueLED.off();
    }
    if (color.compare("green") == 0)
    {
        redLED.off();
        greenLED.on();
        blueLED.off();
    }
    if (color.compare("blue") == 0)
    {
        redLED.off();
        greenLED.off();
        blueLED.on();
    }
    if (color.compare("yellow") == 0)
    {
        redLED.on();
        greenLED.on();
        blueLED.off();
    }
    if (color.compare("purple") == 0)
    {
        redLED.on();
        greenLED.off();
        blueLED.off();
    }
    if (color.compare("lightBlue") == 0)
    {
        redLED.off();
        greenLED.on();
        blueLED.on();
    }
}

void rgbLED::off(){
    redLED.off();
    greenLED.off();
    blueLED.off();
}

void rgbLED::cycleColors(){
    setColor("white");
    // RgbLED.off();
    delay(500);
    setColor("green");
    delay(500);
    setColor("red");
    delay(500);
    setColor("blue");
    delay(500);
    setColor("purple");
    delay(500);
    setColor("yellow");
    delay(500);
    setColor("lightBlue");
    delay(500);
}