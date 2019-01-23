/*
 * Class: Corridor
 * -------------------------
 * This is the interface file for the Corridor class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef Corridor_hpp
#define Corridor_hpp

#include "Space.hpp"

class Corridor : public Space {
public:
    Corridor();                                       //Default Constructor
    Corridor(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~Corridor();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                      //Prints choice menu
    virtual string getChoice();                       //Gets choice from user
};
#endif
