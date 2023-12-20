#include "LEDbargraph.h"

// int pins[10] = {0,1,2,3,4,5,6,8,9,10};

//Initialize all pins and turn them off
void LEDbargraph::init(void){
    for(int i=0;i<10;i++){       //make led pins' mode is output
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i],HIGH);
    }
}

//write to the odd pins of the bargraph
void LEDbargraph::oddLedBarGraph(void){
    for(int i=0;i<5;i++){
        int j=i*2;
        digitalWrite(pins[j],HIGH);
        delay(300);
        digitalWrite(pins[j],LOW);
    }
}

//write to the even pins of the bargraph
void LEDbargraph::evenLedBarGraph(void){
    for(int i=0;i<5;i++){
        int j=i*2+1;
        digitalWrite(pins[j],HIGH);
        delay(300);
        digitalWrite(pins[j],LOW);
    }
}

//write to the all pins of the bargraph
void LEDbargraph::allLedBarGraph(void){
    for(int i=0;i<10;i++){
        digitalWrite(pins[i],HIGH);
        delay(300);
        digitalWrite(pins[i],LOW);
    }
}