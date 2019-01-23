/*
 * Class: SnokeSpace
 * -------------------------
 * This is the interface file for the SnokeSpace class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef SNOKESPACE_HPP
#define SNOKESPACE_HPP

#include "Space.hpp"

class SnokeSpace : public Space {
public:
    SnokeSpace();                                       //Default Constructor
    SnokeSpace(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~SnokeSpace();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                        //Prints user menu
    virtual string getChoice();                         //Gets choice from user
};
#endif
