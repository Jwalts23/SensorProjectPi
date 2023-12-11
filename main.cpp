#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "passiveBuzzer.h"
#include <array>

#endif // _INCLUDES_H_

#define BeepPin 0

passiveBuzzer passive = passiveBuzzer(BeepPin);


void init(){
    wiringPiSetup();
    passive.init();

}

int main(void){

    init(); 
    while(1){
        int len = sizeof(passive.song_1) / sizeof(passive.song_1[0]);
        passive.playSong(passive.song_1, passive.beat_1, len);
        delay(1000);
        len = sizeof(passive.song_2) / sizeof(passive.song_2[0]);
        passive.playSong(passive.song_2, passive.beat_2, len);
        delay(1000);
    }

}


