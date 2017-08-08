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
struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
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
    BullCowCount SubmitGuess (FString);
    
private:
    int32 MyMaxTries; // see contructor for initilization 
    int32 MyCurrentTry;
};


#endif /* FBullCowGame_hpp */