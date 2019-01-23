/*
 * Class: CoreReactor
 * -------------------------
 * This is the interface file for the CoreReactor class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef COREREACTOR_HPP
#define COREREACTOR_HPP

#include "Space.hpp"

class CoreReactor : public Space {
public:
    CoreReactor();                                       //Default Constructor
    CoreReactor(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~CoreReactor();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                         //Prints choice menu
    virtual string getChoice();                          //Gets choice from user
    
private:
    bool lightsaberAvail;
};

#endif
