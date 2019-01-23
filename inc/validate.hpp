/*
 * Function: Game::validate(int&, int, int)
 * Usage: validate(selection, min, max)
 * -------------------------
 * This is the interface file for the validate function. This function validates the user input to
 * make sure it falls between a certain range. It takes a selection choice by reference as well as
 * a min and max value.
 */

#ifndef VALIDATE_HPP
#define VALIDATE_HPP

void validate(int& selection, int min, int max);

#endif
