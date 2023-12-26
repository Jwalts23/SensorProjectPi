#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "rotaryEncoder.h"
#include "button.h"
#include <array>
#include "LED.h"
#include "sevenSeg4.h"

#endif // _INCLUDES_H_

// LED pins -  23,24,22 
#define     GreenLED    4
#define     YellowLED   5
#define     RedLED      3

//pin 26
#define     ButtonPin   25

// //Pot pins - 17,18,27
// #define     ADCcs       0
// #define     ADCclk      1 
// #define     ADCdio      2

// pins SPICO, 16, 12
#define SDI 26
#define RCLK 27
#define SRCLK 10
//GPIO 19
#define DIG4 24
// GPIO 13
#define DIG3 23
// pin 6
#define DIG2 22
// SPIMOSI
#define DIG1 12

// using PI 0,1,2

enum STATE {WELCOME,GENERATE_NUM, ENTER_NUMBER,TOO_HIGH, TOO_LOW, END_GAME, PLAY_AGAIN};
STATE state = WELCOME;

rotaryEncoder re = rotaryEncoder();
button selector = button(ButtonPin);
LED red = LED(RedLED);
LED yellow = LED(YellowLED);
LED green = LED(GreenLED);

//int Dig1Pin = -1, int Dig2Pin = -1, int Dig3Pin = -1, int Dig4Pin = -1, int sdi = -1, int rclk = -1, int srkclk = -1
sevenSeg4 sevenSeg = sevenSeg4(DIG1, DIG2, DIG3, DIG4, SDI, RCLK, SRCLK);


void init(){
    wiringPiSetup();
    red.init();
    yellow.init();
    green.init();
    selector.init();
    re.init();
    sevenSeg.init();
}

void strobe(){
    red.on();
    delay(30);
    red.off();
    yellow.on();
    delay(30);
    yellow.off();
    green.on();
    delay(30);
    green.off();
}

int main(void){
    int num;
    int temp;
    char playAgain;
    bool generateRand = true;
    int counts;
    init(); 
    int random = 1255;
    num = 0000;

    // while(1){
    //     // for (int j=0; j<2; j++){
    //         sevenSeg.displayNumber(random);
    //     // }
    //     // delay(100);
    //     num++;
    // }
 
    while(1){

        switch (state){
            case WELCOME:
                std::cout << "Welcome to the high low game.\n";
                std::cout << "You will enter a number until you guess the computer's number.\n";
                std::cout << "Spin the knob to display a number. \n";
                std::cout << "Press button to select number. \n";
                delay(50);
                state = GENERATE_NUM;
            break;

            case GENERATE_NUM:
                srand((int)time(0));
                random = rand()%101;
                state = ENTER_NUMBER;
            break; 

            case ENTER_NUMBER:
                
                // counts = re.getCounts();
                // // std::cin >> num;
                // std::cout << "Current Number is: " << num << "\n";
                // std::cout << "temp Number is: " << temp << "\n";
                if (!selector.pressed()){
                    re.rotaryDealPositiveRanged(100);
                    counts = re.getCounts();
                if (temp != counts){
                    num = counts;
                        // for (int j=0; j<10000; j++){
                            sevenSeg.displayNumber(num);
                        // }
                    std::cout << "Current guess is: " << num << "\n";
                    temp = counts;
                    }
                  
                   state = ENTER_NUMBER;
                   break;
                }


                // if (!std::cin){
                //     std::cout << "Invalid input. Try again. \n";
                //     std::cin.clear();
                //     std::cin.ignore(1000,'\n');
                //     state = ENTER_NUMBER;
                //     break;
                // }
                
                std::cout << "The number is " << random << "\n";
                std::cout << "You entered " << num << "\n";

                if (num == random){
                    std::cout << "You did it!\n";
                    for(int i=0; i<5; i++){
                        strobe();
                    }
                    state = PLAY_AGAIN;

                }
                else if (num > random){
                    state = TOO_HIGH;
                }
                else if (num < random){
                   state = TOO_LOW;
                }else {
                    state = ENTER_NUMBER;
                }

            break;

            case TOO_HIGH:
                std::cout << "Too high!\n";
                red.on();
                delay(15);
                state = ENTER_NUMBER;
                red.off();
            break; 

            case TOO_LOW:
                std::cout << "Too low!\n";
                yellow.on();
                delay(15);
                state = ENTER_NUMBER;
                yellow.off();
            break; 

            case PLAY_AGAIN:
                std::cout << "Would you like to play again? y or n\n";
                std::cin >> playAgain;
                if (playAgain == 'y' || playAgain == 'Y'){

                    state = WELCOME;
                }
                else if (playAgain == 'n' || playAgain == 'N'){
                    state = END_GAME;
                }
                else{
                    std::cout << "Invalid input " << random << "\n";
                    state = PLAY_AGAIN;
                }
            break;

            case END_GAME:
                std::cout << "Thanks for playing\n";
                return 0;
            break; 
        }
    }
}


