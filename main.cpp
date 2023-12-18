#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "LightSwitch.h"
#include <array>

#endif // _INCLUDES_H_


LightSwitch ls = LightSwitch();


void init(){
    wiringPiSetup();
    ls.init();

}

int main(void){

    init(); 

    while(1){
        // printf("%d\n", Button.buttonPressed());
        ls.demoCycle();
    }

}


