#include "button.h"

    void button::init(){
        pinMode(pin, INPUT);
    }

    bool button::read(){
        return digitalRead(pin);
    }

    //If the button is pressed reurn true
    //The purpose of this funcrion is to catch a button press once so it can be used to set off other things
    // AKA debouncing
    bool button::pressed(){
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
    