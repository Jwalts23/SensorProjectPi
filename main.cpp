#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <wiringPi.h>
#include "rotaryEncoder.h"
#include "button.h"
#include <array>
#include <thread>
#include "LED.h"
#include "sevenSeg4.h"
#include "Guesses.h"

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

enum STATE
{
    WELCOME,
    GENERATE_NUM,
    CHECK_GUESSES,
    ENTER_NUMBER,
    TOO_HIGH,
    TOO_LOW,
    END_GAME,
    PLAY_AGAIN
};
STATE state = WELCOME;
int range = 100;

// Create all the objects
Guesses gc = Guesses();
rotaryEncoder re = rotaryEncoder(); // using pin 0,1,2
button selector = button(ButtonPin);
LED red = LED(RedLED);
LED yellow = LED(YellowLED);
LED green = LED(GreenLED);

//int Dig1Pin = -1, int Dig2Pin = -1, int Dig3Pin = -1, int Dig4Pin = -1, int sdi = -1, int rclk = -1, int srkclk = -1
sevenSeg4 sevenSeg = sevenSeg4(DIG1, DIG2, DIG3, DIG4, SDI, RCLK, SRCLK);

// SevenSeg thread variables
bool stopFlag = false;
bool dispHighLowMode = false;
bool isLow = false;

// this function is for the thread to be able to continuosly display teh updated number on the 7 segment.
void displayNumber(int &num, bool &isLow){
    while (true && !stopFlag){
        if (!dispHighLowMode){
            sevenSeg.displayNumber(num);
        }
        else{
            sevenSeg.displayHiLo(isLow);
        }
    }
    sevenSeg.clearDisplay();
    std::cout << "Display thread stopped. \n";
}

//This function is a wrapper for running the encoder code in a thread
void rotaryDealRanged(int &range, int &counts){
    while (true && !stopFlag){
        re.rotaryDealPositiveRanged(range);
        //read the encoder and update counts 
        counts = re.getCounts();
    }
    std::cout << "Encoder thread stopped. \n";
    
}

void init(){
    wiringPiSetup();
    red.init();
    yellow.init();
    green.init();
    selector.init();
    re.init();
    sevenSeg.init();
}

// Flash all the Leds
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
    int random = 0;
    int temp;
    char playAgain;
    bool generateRand = true;
    int counts;
    bool enterNumFirstTime = true;
    int RemaingGuesses;
    int PermittedGuesses;
    bool printGuesses = false;
    init(); 

       // Start the Seven Seg thread
    std::thread seg(displayNumber, std::ref(num), std::ref(isLow));

    //Start the encoder thead
    std::thread enc(rotaryDealRanged, std::ref(range), std::ref(counts));

    // Play the game
    while(1){
        switch (state){
            case WELCOME:
                std::cout << "Welcome to the high low game.\n";
                std::cout << "You will enter a number until you guess the computer's number.\n";
                std::cout << "Spin the knob to display a number. \n";
                std::cout << "Press button to select number. \n";
                std::cout << "\n";
                delay(50);
                state = GENERATE_NUM;
            break;

            case GENERATE_NUM:
                srand((int)time(0));
                random = rand()%(range+1);
                state = CHECK_GUESSES;
            break; 

            case CHECK_GUESSES:
                RemaingGuesses = gc.remainingGuesses();
                PermittedGuesses = gc.getPermittedGuesses();
                
                if (printGuesses){
                    gc.printGuesses(PermittedGuesses - RemaingGuesses);
                }
                else{
                    printGuesses = true;
                }

                if (RemaingGuesses == 0){
                    std::cout << "You used all " << PermittedGuesses << " guesses!\n";
                    std::cout << "The number was " << random << ".\n";
                    gc.reset();
                    state = PLAY_AGAIN;
                    break;
                }
                else if (RemaingGuesses == 1){
                    std::cout << "Last guess!\n";
                }
                else if(RemaingGuesses == PermittedGuesses){
                    std::cout << "You have " << PermittedGuesses << " guesses to get the number!\n";
                }
                else{
                    std::cout << "You have " << RemaingGuesses << " guesses left!\n";
                }
                
                state = ENTER_NUMBER;
            break;

            case ENTER_NUMBER:


                // keep reading the encoder until the button is pressed.
                if (!selector.pressed()){

                    // Encoder counts being updated by thread
                    
                    // if the encoder value has changed update the number
                    if (temp != counts){
                        num = counts;
                        dispHighLowMode = false;
                        std::cout << "Current guess is: " << num << "\n";
                        temp = counts;
                    }else{
                        // display resume message after high and low
                        if(enterNumFirstTime){
                            std::cout << "Spin the knob to continue. \n";\
                            std::cout << "\n";
                            enterNumFirstTime = false;
                        }
                        
                    }

                    // repeat this step
                    state = ENTER_NUMBER;
                    break;
                }

                // TEMP: printing the value for the sake of testing features
                // std::cout << "The number is " << random << "\n";
                std::cout << "You entered " << num << "\n";

                // need to check if the previous guess is the same to deal with button debouncing
                if (!gc.IsPreviousGuessTheSame(num)){
                    // record guess
                    gc.recordGuess(num);

                }else{
                    // no need to check below
                    std::cout << "The current guess can not be the same as the previous.\n";
                    state = ENTER_NUMBER;
                    break;
                }



                if (num == random){
                    std::cout << "You did it!\n";
                    gc.printGuesses((PermittedGuesses - RemaingGuesses)+1);
                    gc.reset();
                    printGuesses = false;
                    for (int i = 0; i < 5; i++){
                        strobe();
                    }
                    state = PLAY_AGAIN;
                }
                else if (num > random){
                    state = TOO_HIGH;
                }
                else if (num < random){
                    state = TOO_LOW;
                }
                else{
                    state = CHECK_GUESSES;
                }

            break;

            case TOO_HIGH:
                // Set 7Seg variables
                isLow = false;
                dispHighLowMode = true;

                std::cout << "Too high!\n" << "\n";;

                //set resume message to appear
                enterNumFirstTime = true;

                // Flash the red light
                red.on();
                delay(15);
                state = CHECK_GUESSES;
                red.off();
            break; 

            case TOO_LOW:
                // Set 7Seg variables
                isLow = true;
                dispHighLowMode = true;

                std::cout << "Too low!\n" << "\n";

                //set resume message to appear
                enterNumFirstTime = true;

                // Flash the yellow light
                yellow.on();
                delay(15);
                state = CHECK_GUESSES;
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
                // kill the threads
                std::cout << "Shutting Down...\n";
                stopFlag = true;
                seg.join();
                enc.join();
                std::cout << "Thanks for playing\n";
                return 0;
            break; 
        }
    }
}


