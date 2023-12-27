
#include "Guesses.h"

void Guesses::recordGuess(int Guess){
    guesses[guess] = Guess;
    guess++;
}

void Guesses::printGuesses(int range){
    std::cout << "Your guesses are : ";
    if(range > permittedGuesses){
        range = permittedGuesses;
    }

    for (int i = 0; i < range; i++)
    {
        std::cout << guesses[i];
        if (!(i == (range - 1))){
             std::cout <<", ";
        }
        
    }
    std::cout << "\n";
    std::cout << "\n";
}

int Guesses::getCurrentGuessNumber(){
    return (guess + 1);
}

// length of array so size-1
int Guesses::length(){
    return Length;
}

int Guesses::remainingGuesses(){
    int remaining = permittedGuesses - guess;
    return remaining;
}

int Guesses::getPermittedGuesses(){
    return permittedGuesses;
}

void Guesses::reset(){
    for (int i = 0; i < permittedGuesses; i++){
        guesses[i] = 0;
    }
    guess = 0;
}

// compare guess and previous guess for button debouncing
bool Guesses::IsPreviousGuessTheSame(int num){
    bool IsSame = false;
    if (guess > 0){
        int prev = guesses[guess - 1];
        if (prev == num){
            IsSame = true;
        }
    }
    return IsSame;
}
