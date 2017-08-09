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
constexpr int32 WORD_LENGTH = 6;
constexpr int32 MAX_GUESSES = 3;

//functions start here
void GameIntro ()
{
    FText name = "";
    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Hello " + name + ", welcome to Bulls and Cows!\n" << std::endl;
    std::cout << "The length of the isogram is " << WORD_LENGTH << " letters long." << std::endl;
    std::cout << "You have " << MAX_GUESSES << " tries." << std::endl;
}

bool IsGuessValid (FText guess)
{
    if (guess.length() != WORD_LENGTH)
    {
        std::cout << "INVALID: Your guess is not " << WORD_LENGTH << " letters long." << std::endl;
        return false;
    }
    for (int32 i = 0; i < guess.length(); i++)
    {
        if (!isalpha(guess[i]))
        {
            std::cout << "INVALID: Your guess can only contain letters" << std::endl;
            return false;
        }
    }
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
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
        if (BullCowCount.bulls == WORD_LENGTH)
        {
            std::cout << "Great Job, You Won!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Bulls = " << BullCowCount.bulls << std::endl;
            std::cout << "Cows = " << BullCowCount.cows << std::endl;
        }
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
int main(void)
{
    GameIntro();
    do
    {
        PlayGame();
    } while (AskToPlayAgain());
    
    return 0;
}
