#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "pot.h"
#include <array>
#include "LED.h"

#endif // _INCLUDES_H_

#define     LedPin  3

enum STATE {WELCOME,GENERATE_NUM, ENTER_NUMBER,TOO_HIGH, TOO_LOW, END_GAME, PLAY_AGAIN};
STATE states = WELCOME;



void HLinit(){
    wiringPiSetup();

}

int highLow(void){
    int num;
    char playAgain;
    bool generateRand = true;
    HLinit(); 
    int random;
    while(1){

        switch (states){
            case WELCOME:
                std::cout << "Welcome to the high low game.\n";
                std::cout << "You will enter a number until you guess the computer's number.\n";
                states = GENERATE_NUM;
            break;

            case GENERATE_NUM:
                srand((int)time(0));
                random = rand()%101;
                states = ENTER_NUMBER;
            break; 

            case ENTER_NUMBER:
                std::cout << "Enter a number: ";
                std::cin >> num;



                if (!std::cin){
                    std::cout << "Invalid input. Try again. \n";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    states = ENTER_NUMBER;
                    break;
                }
                
                std::cout << "The number is " << random << "\n";
                std::cout << "You entered " << num << "\n";

                if (num == random){
                    std::cout << "You did it!\n";
                    states = PLAY_AGAIN;

                }
                else if (num > random){
                    states = TOO_HIGH;
                }
                else if (num < random){
                   states = TOO_LOW;
                }else {
                    states = ENTER_NUMBER;
                }

            break;

            case TOO_HIGH:
                std::cout << "Too high!\n";
                states = ENTER_NUMBER;
            break; 

            case TOO_LOW:
                std::cout << "Too low!\n";
                states = ENTER_NUMBER;
            break; 

            case PLAY_AGAIN:
                std::cout << "Would you like to play again? y or n\n";
                std::cin >> playAgain;
                if (playAgain == 'y' || playAgain == 'Y'){
                    states = WELCOME;
                }
                else if (playAgain == 'n' || playAgain == 'N'){
                    states = END_GAME;
                }
                else{
                    std::cout << "Invalid input " << random << "\n";
                    states = PLAY_AGAIN;
                }
            break;

            case END_GAME:
                std::cout << "Thanks for playing\n";
                return 0;
            break; 
        }
    }
}


