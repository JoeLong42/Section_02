//
//  main.cpp
//  BullCowGame
//
//  Created by Joseph Long on 8/6/17.
//  Copyright © 2017 Joseph Long. All rights reserved.
//

#include <iostream>
#include <ctype.h>

//dont use more than one "using namespace" call
using FText = std::string;
using int32 = int;

#include "FBullCowGame.hpp"

FBullCowGame BCGame; //initilizes game instance 

// constants
constexpr int32 WORD_LENGTH = 2;
constexpr int32 MAX_GUESSES = 2;

//functions start here
void GameIntro ()
{
    FText name = "";
    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Hello " + name + ", welcome to Bulls and Cows!\n" << std::endl;
    std::cout << "The length of the isogram is " << WORD_LENGTH << " letters long." << std::endl;
}

bool IsGuessValid (FText guess)
{
    if (guess.length() != WORD_LENGTH)
    {
        std::cout << "Your guess is the wrong word length" << std::endl;
        return false;
    }
    for (int32 i = 0; i < guess.length(); i++)
    {
        if (!isalpha(guess[i]))
        {
            std::cout << "Your guess can only contain letters" << std::endl;
            return false;
        }
    }
    std::cout << "Valid Guess!" << std::endl;
    return true;
}

FText GetGuess ()
{
    FText guess = "";
    std::cout << "Enter your guess: ";
    getline(std::cin, guess);
    std::cout << std::endl;
    return guess;
}

void PlayGame ()
{
    BCGame.Reset();
    for (int32 i = 1; i <= MAX_GUESSES; i++)
    {
        FText guess = "";
        do
        {
            std::cout << "(" << i << ") ";
            guess = GetGuess();
        } while (!IsGuessValid(guess));
    }
}

bool AskToPlayAgain ()
{
    FText response = "";
    std::cout << "Do you want to play again? (y/n) ";
    getline(std::cin, response);
    return ('y' == tolower(response[0]));
}

//MAIN ------------------
int main(void) {
    do
    {
        GameIntro();
        PlayGame();
    } while (AskToPlayAgain());
    
    return 0;
}
