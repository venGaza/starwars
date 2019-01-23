/*
 * Class: Door
 * -------------------------
 * This is the interface file for the Door class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef DOOR_HPP
#define DOOR_HPP

#include "Space.hpp"

class Door : public Space {
public:
    Door();                                       //Default Constructor
    Door(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~Door();                                      //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                  //Prints user menu
    virtual string getChoice();                   //Gets choice from user
};
#endif
