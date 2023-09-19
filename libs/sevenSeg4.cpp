#include "sevenSeg4.h"

void timer(int timer1);
int counter = 0;

void sevenSeg4::init(){
    setBasePinMode();
    for (int i = 0; i < 4; i++){
        // printf("%d\n", placePin[i]);
        pinMode(placePin[i], OUTPUT);
        digitalWrite(placePin[i], HIGH);
    }
    signal(SIGALRM, timer);
    alarm(1);
}

void timer(int timer1){
    if (timer1 == SIGALRM){
        counter++;
        alarm(1);
        // printf("%d\n", counter);
    }
}

void sevenSeg4::pickDigit(int digit){
    for (int i = 0; i < 4; i++){
        digitalWrite(placePin[i], 0);
        // printf("%d\n", placePin[i]);
    }
    digitalWrite(placePin[digit], 1);
}

void sevenSeg4::displayNumber(int num){
        
        clearDisplay();
        pickDigit(0);
        hc595_shift(number[num % 10]);
        // printf("%d ones\n", num % 10);

        clearDisplay();
        pickDigit(1);
        hc595_shift(number[num % 100 / 10]);
        // printf("%d tens\n", num % 100 / 10);

        clearDisplay();
        pickDigit(2);
        hc595_shift(number[num % 1000 / 100]);
        // printf("%d huns\n", num % 1000 / 100);

        clearDisplay();
        pickDigit(3);
        hc595_shift(number[num % 10000 / 1000]);
        // printf("%d thos\n", num % 10000 / 1000);
}

// display high or low - defaults to high

void sevenSeg4::displayHiLo(bool low){
    // set chars to high
    unsigned char L1 = Hi[0];
    unsigned char L2 = Hi[1];

    // switch to low
    if (low){
        L1 = Lo[0];
        L2 = Lo[1];
    }

    clearDisplay();
    pickDigit(1);
    hc595_shift(L1);
    // printf("%d huns\n", num % 1000 / 100);

    clearDisplay();
    pickDigit(0);
    hc595_shift(L2);
}

void sevenSeg4::testLoop(){
        // signal(SIGALRM, timer);
        // alarm(1);
    while(1){
        printf("%d\n", counter);
        displayNumber(counter);
    }
}

void sevenSeg4::setPins(int Dig1Pin, int Dig2Pin, int Dig3Pin, int Dig4Pin, int sdi, int rclk, int srkclk){
    dig1Pin=Dig1Pin;
    dig2Pin=Dig2Pin;
    dig3Pin=Dig3Pin;
    dig4Pin=Dig4Pin;
    sevenSeg::setPins(sdi,rclk,srkclk);
}