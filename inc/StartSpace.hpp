/*
 * Class: StartSpace
 * -------------------------
 * This is the interface file for the StartSpace class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef STARTSPACE_HPP
#define STARTSPACE_HPP

#include "Space.hpp"

class StartSpace : public Space {
public:
    StartSpace();                                       //Default Constructor
    StartSpace(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~StartSpace();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                        //Choice Menu
    virtual string getChoice();                         //Gets choice from user
};
#endif

