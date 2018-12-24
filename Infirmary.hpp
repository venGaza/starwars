/*
 * Class: Infirmary
 * -------------------------
 * This is the interface file for the Infirmary class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#ifndef INFIRMARY_HPP
#define INFIRMARY_HPP

#include "Space.hpp"

class Infirmary : public Space {
public:
    Infirmary();                                       //Default Constructor
    Infirmary(Space*, Space*, Space*, Space*);         //Overloaded Constructor
    virtual ~Infirmary();                                      //Destructor
    
    //Virtual Public Functions
    virtual void printChoices();                       //Prints choice menu
    virtual string getChoice();                        //Gets choice from user
    
private:
    bool medPodAvail;
};
#endif
