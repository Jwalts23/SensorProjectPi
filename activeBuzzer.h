#include <wiringPi.h>
#include <stdio.h>

// The active buzzer is the buzzer  that can make beeps for the set amount of time.
class activeBuzzer{
    public:
        activeBuzzer(int BeepPin = -1) : beepPin(BeepPin){};
        void init();
        void on();
        void off();

    private:
        int beepPin;

};