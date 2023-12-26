#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "pot.h"
#include "button.h"
#include <array>
#include "LED.h"

#endif // _INCLUDES_H_

// LED pins -  23,24,22 
#define     GreenLED    4
#define     YellowLED   5
#define     RedLED      3

//pin 26
#define     ButtonPin   25

//Pot pins - 17,18,27
#define     ADCcs       0
#define     ADCclk      1 
#define     ADCdio      2

enum STATE {WELCOME,GENERATE_NUM, ENTER_NUMBER,TOO_HIGH, TOO_LOW, END_GAME, PLAY_AGAIN};
STATE state = WELCOME;

pot p = pot(ADCcs,ADCclk, ADCdio);

button selector = button(ButtonPin);
LED red = LED(RedLED);
LED yellow = LED(YellowLED);
LED green = LED(GreenLED);


void init(){
    wiringPiSetup();
    red.init();
    yellow.init();
    green.init();
    selector.init();
    p.init();
}

int main(void){
    int num;
    int temp;
    char playAgain;
    bool generateRand = true;
    init(); 
    int random;
    while(1){

        switch (state){
            case WELCOME:
                std::cout << "Welcome to the high low game.\n";
                std::cout << "You will enter a number until you guess the computer's number.\n";
                state = GENERATE_NUM;
            break;

            case GENERATE_NUM:
                srand((int)time(0));
                random = rand()%101;
                state = ENTER_NUMBER;
            break; 

            case ENTER_NUMBER:
                std::cout << "Spin the knob to display a number. \n";
                std::cout << "Press button to select number: \n";
                // std::cin >> num;
                
                while(!selector.pressed()){
                    temp = p.get_ADC_Result(0);
                    if (temp != 0){
                        num = temp;
                        std::cout << "Current Number is: " << num << "\n";
                    }
                    

                    // delay (20);
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
                delay(20);
                state = ENTER_NUMBER;
            break; 

            case TOO_LOW:
                std::cout << "Too low!\n";
                delay(20);
                state = ENTER_NUMBER;
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


