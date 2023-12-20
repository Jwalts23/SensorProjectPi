#include <iostream>
#include <wiringPi.h>
#pragma once

// This class is made for a Pull down LED
class LED{
    public:
        void setPin(int pin);
        LED(int Pin = -1) : pin(Pin) {};
        void init();
        void on();
        void off();

    private:
        int pin;
};