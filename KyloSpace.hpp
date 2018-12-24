/*
 * Class: KyloSpace
 * -------------------------
 * This is the interface file for the KyloSpace class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef KYLOSPACE_HPP
#define KYLOSPACE_HPP

#include "Space.hpp"

class KyloSpace : public Space {
public:
    KyloSpace();                                       //Default Constructor
    KyloSpace(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~KyloSpace();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                       //Prints choice menu
    virtual string getChoice();                        //Gets choice from user
};

#endif
