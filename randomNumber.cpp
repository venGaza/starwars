/*
 * Function: randomNumber
 * Usage: randomNumber(int min, int max)
 * -------------------------
 * This function takes two parameters whicha are the min and max values and returns a random number
 * between those values.
 */

#include "randomNumber.hpp"
#include <random>

int randomNumber(int min, int max) {
    std::random_device rd;                             //Create seed object
    std::minstd_rand0 engine(rd());                    //Seed the engine
    std::uniform_int_distribution<int> work(min, max); //Set range for distribution
    int randomNumber = work(engine);
    
    return randomNumber;
}
