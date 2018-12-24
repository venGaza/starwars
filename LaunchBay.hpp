/*
 * Class: LaunchBay
 * -------------------------
 * This is the interface file for the LaunchBay class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef LAUNCHBAY_HPP
#define LAUNCHBAY_HPP

#include "Space.hpp"

class LaunchBay : public Space {
public:
    LaunchBay();                                       //Default Constructor
    LaunchBay(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~LaunchBay();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                       //Prints choice menu
    virtual string getChoice();                        //Gets choice from user
};
#endif
