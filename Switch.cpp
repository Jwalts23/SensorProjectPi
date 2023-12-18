#include "Switch.h"

    void Switch::init(){
        pinMode(pin, INPUT);
    }

    bool Switch::read(){
        return digitalRead(pin);
    }

    void Switch::setPin(int Pin){
        pin = Pin;
    }