#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "LEDmatrix.h"
#include <array>

#endif // _INCLUDES_H_

LEDmatrix matrix = LEDmatrix();


void init(){
    wiringPiSetup();
    matrix.init();

}

int main(void){

    init(); 
    matrix.testLoop();

}


