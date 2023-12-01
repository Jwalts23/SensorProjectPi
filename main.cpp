#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "sevenSeg4.h"
#include <array>

#endif // _INCLUDES_H_

#define   SDI   5   //serial data input
#define   RCLK  4   //memory clock input(STCP)
#define   SRCLK 1   //shift register clock input(SHCP)
#define   Dig1 12
#define   Dig2 3
#define   Dig3 2
#define   Dig4 0

sevenSeg4 nums = sevenSeg4(Dig1, Dig2, Dig3, Dig4, SDI, RCLK, SRCLK);


void init(){
    wiringPiSetup();
    nums.init();

}

int main(void){

    init(); 
    nums.testLoop();

}


