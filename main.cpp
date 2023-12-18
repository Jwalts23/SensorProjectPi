#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "rotaryEncoder.h"
#include <array>

#endif // _INCLUDES_H_


rotaryEncoder re = rotaryEncoder();


void init(){
    wiringPiSetup();
    re.init();

}

int main(void){

    init(); 


    while(1){
        re.rotaryDeal();

        // delay(100);
    }
}


