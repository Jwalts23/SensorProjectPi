#include "passiveBuzzer.h"



    void passiveBuzzer::init(){
        // sets ups pin
        // include pinMode and digitalWrite LOW
        // starts a thread for that pin 
        softToneCreate(beepPin);
    }

    void passiveBuzzer::playNote(int song[], int beat[], int index){
        softToneWrite(beepPin, song[index]);
        delay(beat[index] * 500);

    }

    void passiveBuzzer::playSong(int song[], int beat[], int len){
        for(int i=0;i<len/4;i++){
            playNote(song, beat, i);
        }
    }
