#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "button.h"
#include "LED.h"
#include <array>

#endif // _INCLUDES_H_

#define BeepPin 1
#define LEDpin 0

button Button = button(BeepPin);
LED led = LED(LEDpin);


void init(){
    wiringPiSetup();
    Button.init();
    led.init();

}

int main(void){

    init(); 
    led.off();

    // variable = (condition) ? expressionTrue : expressionFalse;

    bool on = false; 
    while(1){
        // printf("%d\n", Button.buttonPressed());
        
        if(Button.buttonPressed()){
            (on)? led.off(): led.on(); 
            on = !on;
        }
        delay(40);
    }

}


