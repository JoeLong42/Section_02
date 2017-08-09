//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Joseph Long on 8/8/17.
//  Copyright © 2017 Joseph Long. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

//unreal type names
using FString = std::string;
using int32 = int;

// structs
struct FBullCowCount
{
    int32 bulls = 0;
    int32 cows = 0;
};

class FBullCowGame
{
public:
    FBullCowGame(); // constructor
    void Reset();
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    FString IsGuessValid(FString);
    FBullCowCount SubmitGuess (FString);
    
private:
    int32 MyMaxTries; // see contructor for initilization 
    int32 MyCurrentTry;
    FString MyHiddenWord;
};


#endif /* FBullCowGame_hpp */
