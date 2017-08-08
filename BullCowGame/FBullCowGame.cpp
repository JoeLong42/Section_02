//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Joseph Long on 8/8/17.
//  Copyright © 2017 Joseph Long. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

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
    
    MyCurrentTry = 1;
}

std::string FBullCowGame::IsGuessValid(std::string)
{
    return "";
}

