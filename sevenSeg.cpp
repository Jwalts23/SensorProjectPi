#include "sevenSeg.h"

void sevenSeg::setBasePinMode(){
    pinMode(SDI, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(SRCLK, OUTPUT);
}

void sevenSeg::init(){
    setBasePinMode();
    digitalWrite(SDI, 0);
    digitalWrite(RCLK, 0);
    digitalWrite(SRCLK, 0);
}

void sevenSeg::setPins(int sdi, int rclk, int srkclk){
    SDI = sdi;
    RCLK = rclk;
    SRCLK = srkclk;
}

// takes a hex char
void sevenSeg::hc595_shift(unsigned char dat){
    int i;
    for(i=0;i<8;i++){
        digitalWrite(SDI, 0x80 & (dat << i));
        digitalWrite(SRCLK, 1);
        delayMicroseconds(1);
        digitalWrite(SRCLK, 0);
    }

    digitalWrite(RCLK, 1);
    delayMicroseconds(1);
    digitalWrite(RCLK, 0);
}

unsigned char sevenSeg::getHexChar(int i){
    return SegCode[i];
}

void sevenSeg::clearDisplay(){
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(SDI, 1);
        digitalWrite(SRCLK, 1);
        delayMicroseconds(1);
        digitalWrite(SRCLK, 0);
    }
    digitalWrite(RCLK, 1);
    delayMicroseconds(1);
    digitalWrite(RCLK, 0);
}