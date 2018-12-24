/*
 * Class: DetentionBlock
 * -------------------------
 * This is the interface file for the DetentionBlock class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef DETENTIONBLOCK_HPP
#define DETENTIONBLOCK_HPP

#include "Space.hpp"

class DetentionBlock : public Space {
public:
    DetentionBlock();                                       //Default Constructor
    DetentionBlock(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~DetentionBlock();                              //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                            //Prints choice menu
    virtual string getChoice();                             //Gets choice from user
    
private:
    bool doorOpen;
};
#endif
