#include <wiringPi.h>
#include <stdio.h>

class button{
    public:
        button(int Pin = -1):pin(Pin){};
        void init();
        bool buttonPressed();
        bool read();
        bool isIdle();
        void setPin(int Pin);
    private:
        int pin;
};