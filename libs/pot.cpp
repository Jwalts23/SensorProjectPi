#include "pot.h"

    void pot::init(){
        pinMode(adcCS,  OUTPUT);
        pinMode(adcCLK, OUTPUT);
    }

    char pot::get_ADC_Result(unsigned int channel){
        unsigned dat1=0, dat2=0;
        int sel = channel > 1 & 1;
        int odd = channel & 1;

        pinMode(adcDIO, OUTPUT);
        digitalWrite(adcCS, 0);
        // Start bit
        digitalWrite(adcCLK,0);
        digitalWrite(adcDIO,1);    delayMicroseconds(2);
        digitalWrite(adcCLK,1);    delayMicroseconds(2);
        // Single End mode
        digitalWrite(adcCLK,0);
        digitalWrite(adcDIO,1);    delayMicroseconds(2);
        digitalWrite(adcCLK,1);    delayMicroseconds(2);
        // ODD
        digitalWrite(adcCLK,0);
        digitalWrite(adcDIO,odd);  delayMicroseconds(2);
        digitalWrite(adcCLK,1);    delayMicroseconds(2);
        // Select
        digitalWrite(adcCLK,0);
        digitalWrite(adcDIO,sel);    delayMicroseconds(2);
        digitalWrite(adcCLK,1);

        digitalWrite(adcDIO,1);    delayMicroseconds(2);
        digitalWrite(adcCLK,0);
        digitalWrite(adcDIO,1);    delayMicroseconds(2);

        for(int i=0;i<8;i++){
            digitalWrite(adcCLK,1);    delayMicroseconds(2);
            digitalWrite(adcCLK,0);    delayMicroseconds(2);

            pinMode(adcDIO, INPUT);
            dat1=dat1<<1 | digitalRead(adcDIO);
        }

        for(int j=0;j<8;j++){
            dat2 = dat2 | ((unsigned char)(digitalRead(adcDIO))<<j);
            digitalWrite(adcCLK,1);    delayMicroseconds(2);
            digitalWrite(adcCLK,0);    delayMicroseconds(2);
        }

        digitalWrite(adcCS,1);
        pinMode(adcDIO, OUTPUT);
        return(dat1==dat2) ? dat1 : 0;
    }