#include <wiringPi.h>
#include <stdio.h>

//This class is for a standard push button
class button{
    public:
        button(int Pin = -1):pin(Pin){};
        void init();
        bool pressed();
        bool read();
        bool isIdle();
        void setPin(int Pin);
    private:
        int pin;
};