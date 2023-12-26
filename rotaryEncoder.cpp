#include "rotaryEncoder.h"

int tmp = 0;
    void btnISR(){
        globalCounter = 0;
        tmp = -1;
        if (tmp != globalCounter) {
            printf("%d counts\n", globalCounter);
            tmp = globalCounter;
        }
    }

    void rotaryEncoder::init(){
        pinMode(swPin, INPUT);
        pinMode(clkPin, INPUT);
        pinMode(dtPin, INPUT);
        pullUpDnControl(swPin, PUD_UP);

        if (wiringPiISR(swPin, INT_EDGE_FALLING, &btnISR) < 0){
            printf("Initialization failed");
        }
    }

    int rotaryEncoder::readDTpin(){
        return digitalRead(dtPin);
    }

    int rotaryEncoder::readCLKpin(){
        return digitalRead(clkPin);
    }

    void rotaryEncoder::rotaryDeal(){
        Last_dtPin_Status = readDTpin();
        flag = 0;
        if (!readCLKpin()){
            // printf("%dclock\n", readCLKpin());
            Current_dtPin_Status = readDTpin();
            // printf("%ddt\n", Current_dtPin_Status);
            flag = 1;
            // delay(50);
        }

        if (flag == 1){
            flag = 0;
            if ((Last_dtPin_Status == 0) && (Current_dtPin_Status == 1)){
                globalCounter--;
            }
            if ((Last_dtPin_Status == 1) && (Current_dtPin_Status == 0)){
                globalCounter++;
            }

            //  if (tmp != globalCounter){
            //      printf("%d counts\n", globalCounter);
            //      tmp = globalCounter;
            //  }
        }
    }

    int rotaryEncoder::getCounts(){
        return globalCounter;
    }

        void rotaryEncoder::rotaryDealPositiveRanged(int range){
        Last_dtPin_Status = readDTpin();
        flag = 0;
        if (!readCLKpin()){
            // printf("%dclock\n", readCLKpin());
            Current_dtPin_Status = readDTpin();
            // printf("%ddt\n", Current_dtPin_Status);
            flag = 1;
            // delay(50);
        }

        if (flag == 1){
            flag = 0;
            if ((Last_dtPin_Status == 0) && (Current_dtPin_Status == 1)){
                globalCounter--;
                if (globalCounter < 0){
                    globalCounter = 100;
                }
            }
            if ((Last_dtPin_Status == 1) && (Current_dtPin_Status == 0)){
                globalCounter++;
                if (globalCounter > range){
                    globalCounter = 0;
                }
            }


            //  if (tmp != globalCounter){
            //      printf("%d counts\n", globalCounter);
            //      tmp = globalCounter;
            //  }
        }
    }