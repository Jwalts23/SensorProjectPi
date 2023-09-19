#include "Switch.h"
#include "LED.h"

#define switchPin              0
#define led1pin                   3
#define led2pin                   2


class LightSwitch{
    public:
        LightSwitch(int swPin = switchPin, int L1 =led1pin, int L2 =led2pin){sw.setPin(swPin);led1.setPin(L1);led2.setPin(L2);};
        void init();
        void setPins(int swPin, int L1, int L2);
        void demoCycle();
    private:
        LED led1 = LED();
        LED led2 = LED();
        Switch sw = Switch();
};



