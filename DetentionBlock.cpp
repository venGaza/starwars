/*
 * Class: DetentionBlock
 * -------------------------
 * This is the implementation file for the DetentionBlock class. This class is a subclass of the
 * superclass Space object and is one of the types of spaces within the game. The player will traverse
 * the various types of spaces to collect items and reach the final boss.
 */

#include "DetentionBlock.hpp"

/*
 * Function: DetentionBlock::DetentionBlock()
 * Usage: DetentionBlock()
 * -------------------------
 * This is the default constructor for the DetentionBlock class. This function sets default values
 * for the Space object.
 */
DetentionBlock::DetentionBlock() {
    Space::roomName = "Detention Block";
    Space::roomDescription= "A bunch of cells line the wall of the room. It appears there is only one prisoner currently in the First Order's captivity. Who could it be?";
    
    Space::top = nullptr;
    Space::bottom = nullptr;
    Space::left = nullptr;
    Space::right = nullptr;
    
    doorOpen = false;
}

/*
 * Function: DetentionBlock::DetentionBlock(space*, space*, space*, space*)
 * Usage: DetentionBlock(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the DetentionBlock class. This function sets default values
 * for the Space object.
 */
DetentionBlock::DetentionBlock(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: DetentionBlock::~DetentionBlock()
 * Usage: ~DetentionBlock()
 * -------------------------
 * This is the default destructor for the DetentionBlock class.
 */
DetentionBlock::~DetentionBlock() {}

/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: DetentionBlock::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the DetentionBlock class. This function prints out the menu
 * choices for this space. This is an abstract function inherited from Space class.
 */
void DetentionBlock::printChoices() {
    if (!doorOpen) {
        cout << "1) North - Core Reactor" << endl
             << "2) Item Inventory " << endl
             << "3) Look around" << endl
             << "4) Open Cell Door" << endl << endl;
    } else {
        cout << "1) North " << endl
        << "2) Item Inventory " << endl
        << "3) Look around" << endl << endl;
    }
}

/*
 * Function: DetentionBlock::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the DetentionBlock class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string DetentionBlock::getChoice() {
    if (!doorOpen) {
        cout << "Please select a choice (enter integer): ";
        int choice = getInteger();
        validate(choice, 1, 4);
        cout << endl;
        
        if (choice == 1) {
            return "north";
        } else if (choice == 2) {
            return "items";
        } else if (choice == 3){
            return "look";
        } else {
            doorOpen = true;
            return "open";
        }
    } else {
        cout << "Please select a choice (enter integer): ";
        int choice = getInteger();
        validate(choice, 1, 4);
        cout << endl;
        
        if (choice == 1) {
            return "north";
        } else if (choice == 2) {
            return "items";
        } else {
            return "look";
        }
    }
}
