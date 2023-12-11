#include <wiringPi.h>
#include <stdio.h>

class activeBuzzer{
    public:
        activeBuzzer(int BeepPin = -1) : beepPin(BeepPin){};
        void init();
        void on();
        void off();

    private:
        int beepPin;

};