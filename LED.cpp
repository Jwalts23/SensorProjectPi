#include "LED.h"

void LED::setPin(int pin){
    this->pin = pin;
}

void LED::init(){
    wiringPiSetup();
    pinMode(pin, OUTPUT);
}

void LED::on(){
    digitalWrite(pin, HIGH);
}

void LED::off(){
    digitalWrite(pin, LOW);
}
