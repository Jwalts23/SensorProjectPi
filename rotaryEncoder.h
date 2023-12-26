#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

static volatile int globalCounter = 0;

void btnISR();

class rotaryEncoder{
    public:
        rotaryEncoder(int CLKpin = 0, int DTpin = 1, int SWpin = 2):clkPin(CLKpin), dtPin(DTpin), swPin(SWpin) {};
        void init();    
        void rotaryDeal();
        int readDTpin();
        int readCLKpin();
        void rotaryDealPositiveRanged(int range);
        int getCounts();

    private:
        int clkPin;
        int dtPin;
        int swPin;
        unsigned char flag;
        unsigned char Last_dtPin_Status;
        unsigned char Current_dtPin_Status;


};