/*
 * Function: Game::validate(int&, int, int)
 * Usage: validate(selection, min, max)
 * -------------------------
 * This is the implementation file for the validate function. This function validates the user input to
 * make sure it falls between a certain range. It takes a selection choice by reference as well as
 * a min and max value.
 */

#include "validate.hpp"
#include <iostream> //for cout, endl
#include "getInteger.hpp"
using std::cout;
using std::endl;


void validate(int& selection, int min, int max) {
    while(selection < min || selection > max) {
        cout << "The number you input is invalid. Please enter a new number: ";
        selection = getInteger();
        cout << endl;
    }
}
