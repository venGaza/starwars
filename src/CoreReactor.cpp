/*
 * Class: CoreReactor
 * -------------------------
 * This is the implementation file for the CoreReactor class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "CoreReactor.hpp"
#include "Corridor.hpp"
#include "DetentionBlock.hpp"
#include "Infirmary.hpp"

/*
 * Function: CoreReactor::CoreReactor()
 * Usage: CoreReactor()
 * -------------------------
 * This is the default constructor for the CoreReactor class. This function sets default values for the
 * Space object.
 */
CoreReactor::CoreReactor() {
    Space::roomName = "Core Reactor";
    Space::roomDescription= "The heart of the Starship. A towering plasma cylinder glows ahead lighting the entire room. Maybe there is something useful in here...";
    
    Space::top = new Corridor;
    Space::top->setBottom(this);
    Space::bottom = new DetentionBlock;
    Space::bottom->setTop(this);
    Space::left = nullptr;
    Space::right = new Infirmary;
    Space::right->setLeft(this);
    
    lightsaberAvail = true;
}

/*
 * Function: CoreReactor::CoreReactor(space*, space*, space*, space*)
 * Usage: CoreReactor(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the CoreReactor class. This function sets default
 * values for the Space object.
 */
CoreReactor::CoreReactor(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: CoreReactor::~CoreReactor()
 * Usage: ~CoreReactor()
 * -------------------------
 * This is the default destructor for the CoreReactor class.
 */
CoreReactor::~CoreReactor() {
    delete Space::getTop();
    delete Space::getBottom();
    delete Space::getRight();      //Delete Infirmary
}

/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: CoreReactor::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the CoreReactor class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void CoreReactor::printChoices() {
    if (lightsaberAvail) {
        cout << "1) North - Mysterious Room" << endl
        << "2) East - Infirmary" << endl
        << "3) South - Detention Center " << endl
        << "4) West - Blast Site " << endl
        << "5) Item Inventory " << endl
        << "6) Look around" << endl
        << "7) Pick up light saber " << endl << endl;
    } else {
        cout << "1) North - Mysterious Room" << endl
        << "2) East - Infirmary" << endl
        << "3) South - Detention Center" << endl
        << "4) West - Blast Site" << endl
        << "5) Item Inventory " << endl
        << "6) Look around" << endl << endl;
    }
}

/*
 * Function: CoreReactor::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the CoreReactor class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string CoreReactor::getChoice() {
    if (lightsaberAvail) {
        cout << "Please select a choice (enter integer): ";
        int choice = getInteger();
        validate(choice, 1, 7);
        cout << endl;
        
        if (choice == 1) {
            return "north";
        } else if (choice == 2) {
            return "east";
        } else if (choice == 3) {
            return "south";
        } else if (choice == 4) {
            return "west";
        } else if (choice == 5){
            return "items";
        } else if (choice == 6) {
            return "look";
        } else {
            lightsaberAvail = false;
            return "lightsaber";
        }
    } else {
        cout << "Please select a choice (enter integer): ";
        int choice = getInteger();
        validate(choice, 1, 6);
        cout << endl;
        
        if (choice == 1) {
            return "north";
        } else if (choice == 2) {
            return "east";
        } else if (choice == 3) {
            return "south";
        } else if (choice == 4) {
            return "west";
        } else if (choice == 5){
            return "items";
        } else {
            return "look";
        }
    }
}
