#include "activeBuzzer.h"

    void activeBuzzer::init(){
        pinMode(beepPin, OUTPUT); 
    }

    void activeBuzzer::on(){
        digitalWrite(beepPin, LOW);
    }

    void activeBuzzer::off(){
        digitalWrite(beepPin, HIGH);
    }