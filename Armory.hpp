/*
 * Class: Armory
 * -------------------------
 * This is the interface file for the Armory class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef ARMORY_HPP
#define ARMORY_HPP

#include "Space.hpp"

class Armory : public Space {
public:
    Armory();                                       //Default Constructor
    Armory(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~Armory();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                    //Prints choice menu
    virtual string getChoice();                     //Gets choice from user
    
private:
    bool codeAvail;
};
#endif
