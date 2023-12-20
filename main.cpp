#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "pot.h"
#include <array>

#endif // _INCLUDES_H_

#define     LedPin    3

pot p = pot();


void init(){
    wiringPiSetup();
    p.init();
    softPwmCreate(LedPin,  0, 100);

}

int main(void){

    init(); 


    while(1){
        int analogVal = p.get_ADC_Result(0);
        printf("Current analogVal : %d\n", analogVal);
        softPwmWrite(LedPin, analogVal);
        delay(100);
    }
}


