#include "button.h"

    void button::init(){
        pinMode(pin, INPUT);
    }

    bool button::read(){
        return digitalRead(pin);
    }
    bool button::buttonPressed(){
        static bool lastButtonState;
        bool buttonState = read();
        if (buttonState != lastButtonState)
        {
            lastButtonState = buttonState;
            if (buttonState == HIGH)
                return true;
        }
        return false;
    }

    bool button::isIdle()
    {
        return digitalRead(pin) == 1;
    }

    void button::setPin(int Pin){
        pin=Pin;
    }
    