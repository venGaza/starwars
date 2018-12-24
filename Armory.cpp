/*
 * Class: Armory
 * -------------------------
 * This is the implementation file for the Armory class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "Armory.hpp"
#include "Door.hpp"
#include "Corridor.hpp"

/*
 * Function: Armory::Armory()
 * Usage: Armory()
 * -------------------------
 * This is the default constructor for the Armory class. This function sets default values for the
 * Space object.
 */
Armory::Armory() {
    Space::roomName = "Armory";
    Space::roomDescription= "The space where all the weapons are stored on the ship. Mostly plasma blasters but you are too cool for those.";
    
    Space::top = new Corridor;
    Space::top->setBottom(this);
    Space::bottom = new Corridor;
    Space::top->setTop(this);
    Space::left = nullptr;
    Space::right = new Door;
    Space::right->setLeft(this);
    
    codeAvail = true;
}

/*
 * Function: Armory::Armory(space*, space*, space*, space*)
 * Usage: Armory(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the Armory class. This function sets default values for the
 * Space object.
 */
Armory::Armory(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: Armory::~Armory()
 * Usage: ~Armory()
 * -------------------------
 * This is the default destructor for the Armory class.
 */
Armory::~Armory() {
    delete Space::getBottom();
    delete Space::getTop();
    delete Space::getRight();               //Delete the door
}
/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: Armory::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the Armory class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void Armory::printChoices() {
    if (codeAvail) {
        cout << "1) North - Mysterious Room" << endl
             << "2) East - Startanium Door" << endl
             << "3) South - Mysterious Room" << endl
             << "4) West - Infirmary" << endl
             << "5) Item Inventory " << endl
             << "6) Look around" << endl
             << "7) Pick up crumpled paper" << endl << endl;
    } else {
        cout << "1) North - Mysterious Room" << endl
        << "2) East - Startanium Door" << endl
        << "3) South - Mysterious Room" << endl
        << "4) West - Infirmary" << endl
        << "5) Item Inventory " << endl
        << "6) Look around" << endl << endl;
    }
}

/*
 * Function: Armory::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the Armory class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string Armory::getChoice() {
    if (codeAvail) {
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
        } else if (choice == 5) {
            return "items";
        } else if (choice == 6) {
            return "look";
        } else {
            codeAvail = false;
            return "paper";
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
        } else if (choice == 5) {
            return "items";
        } else {
            return "look";
        }
    }
}
