#include "activeBuzzer.h"

    void activeBuzzer::init(){
        pinMode(beepPin, OUTPUT); 
    }
    
    //Set the buzzer to low to turn it on
    void activeBuzzer::on(){
        digitalWrite(beepPin, LOW);
    }

    //Set the buzzer to high to turn it off
    void activeBuzzer::off(){
        digitalWrite(beepPin, HIGH);
    }