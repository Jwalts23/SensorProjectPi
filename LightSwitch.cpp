#include "LightSwitch.h"

    void LightSwitch::init(){
        led1.init();
        led2.init();
        sw.init();

    }
    void LightSwitch::setPins(int swPin =-1, int L1 =-1, int L2 =-1){
        sw.setPin(swPin);
        led1.setPin(L1);
        led2.setPin(L2);
    }

    void  LightSwitch::demoCycle(){
        printf("%d\n", sw.read());
        if(sw.read() == 1){
            led1.on();
            led2.off();
        }else{
            led1.off();
            led2.on();
        }
        delay(50);
    }