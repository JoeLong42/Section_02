//
//  main.cpp
//  BullCowGame
//
//  Created by Joseph Long on 8/6/17.
//  Copyright © 2017 Joseph Long. All rights reserved.
//

#include <iostream>

//dont use more than one "using namespace" call
using namespace std;

int main(void) {
    // insert code here...
    constexpr int WORD_LENGTH = 0;
    
    cout << "Hello, World!\n";
    cout << "Enter your name: ";
    string name = "";
    cin >> name;
    cout << name << std::endl;
    
    cout << "The length of the isogram is " << WORD_LENGTH << " letters long." << endl;
    
    return 0;
}
