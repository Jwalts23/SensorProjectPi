#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "pot.h"
#include <array>
#include "LED.h"

#endif // _INCLUDES_H_

#define     LedPin    3

enum STATE {WELCOME,GENERATE_NUM, ENTER_NUMBER,TOO_HIGH, TOO_LOW, END_GAME, PLAY_AGAIN};
STATE state = WELCOME;

pot p = pot();


void init(){
    wiringPiSetup();


}

int main(void){
    int num;
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
                std::cout << "Enter a number: ";
                std::cin >> num;



                if (!std::cin){
                    std::cout << "Invalid input. Try again. \n";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    state = ENTER_NUMBER;
                    break;
                }
                
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
                state = ENTER_NUMBER;
            break; 

            case TOO_LOW:
                std::cout << "Too low!\n";
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


