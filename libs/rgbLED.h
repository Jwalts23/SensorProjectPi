#include <wiringPi.h>
#include <stdio.h>
#include <string>
#include "LED.h"
using namespace std;

class rgbLED{
    public:
        rgbLED(int GreenPin, int RedPin, int BluePin);
        void init();
        void setColor(string color);
        void off();
        void cycleColors();
    private:
        LED redLED;
        LED greenLED;
        LED blueLED;


};