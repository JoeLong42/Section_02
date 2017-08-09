//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Joseph Long on 8/8/17.
//  Copyright © 2017 Joseph Long. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

bool FBullCowGame::IsGameWon() const
{
    return 0;
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
}

FString FBullCowGame::IsGuessValid(FString)
{
    return "";
}

// receives a valid guess and increments turn and returns bullcowcount
FBullCowCount FBullCowGame::SubmitGuess (FString guess)
{
    MyCurrentTry++;
    FBullCowCount bullCowCount;
    
    for (int32 i = 0; i < guess.length(); i++)
    {
        if (guess[i] == MyHiddenWord[i])
        {
            bullCowCount.bulls++;
        }
        else
        {
            for (int32 j = 0; j < guess.length(); j++)
            {
                if (guess[i] == MyHiddenWord[j])
                {
                    bullCowCount.cows++;
                }
            }
        }
    }
    
    
    return bullCowCount;
}


