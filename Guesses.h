#include <array>
#include <stdio.h>
#include <iostream>

// This class is meant to hold the tools for controlling guesses in games
class Guesses{
    public:
    Guesses(){};
    void recordGuess(int Guess);
    void printGuesses(int range);
    int length();
    int getPermittedGuesses();
    int getCurrentGuessNumber();
    int remainingGuesses();
    void reset();
    bool IsPreviousGuessTheSame(int num);

    private:
        // variables for guess tracking
        int guess = 0;
        std::array<int, 10> guesses = {};
        //size of the array
        int permittedGuesses = sizeof(guesses) / sizeof(guesses[0]);
        int Length = permittedGuesses - 1;
};