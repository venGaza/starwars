/*
 * Class: Space
 * -------------------------
 * This is the interface file for the Space class. This class servers as the superclass for the
 * different types of spaces within the game. The player will traverse the various types of spaces
 * to collect items and reach the final boss.
 */

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream> //for cout, endl
#include <string>
#include "getInteger.hpp"
#include "validate.hpp"
using std::cout;
using std::endl;
using std::string;

class Space {
public:
    Space();                            //Default Constructor
    virtual ~Space();                   //Destructor
    
    //Getters
    string getRoomName();               //Returns room name
    string getRoomDescription();        //Returns room description
    Space* getTop();                    //Returns Space pointer connected to top
    Space* getBottom();                 //Returns Space pointer connected to bottom
    Space* getRight();                  //Returns Space pointer connected to right
    Space* getLeft();                   //Returns Space pointer connected to left
    
    //Setters
    void setRoomName(string);           //Sets the room name
    void setRoomDescription(string);    //Sets the room description
    void setTop(Space*);                //Sets top Space pointer
    void setBottom(Space*);             //Sets top Space pointer
    void setRight(Space*);              //Sets top Space pointer
    void setLeft(Space*);               //Sets top Space pointer
    
    //Pure Virtual Functions
    virtual void printChoices() = 0;    //ABSTRACT: Prints out choices for specific space
    virtual string getChoice() = 0;     //ABSTRACT: Gets choices based on specific space
    
protected:
    string roomName;
    string roomDescription;
    Space* top;
    Space* bottom;
    Space* right;
    Space* left;
};
#endif
