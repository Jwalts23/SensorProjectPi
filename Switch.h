#include <wiringPi.h>
#include <stdio.h>

class Switch{
    public: 
        Switch(int Pin = -1):pin(Pin){};
        void init();
        bool read();
        void setPin(int Pin);

    private:
        int pin;
};