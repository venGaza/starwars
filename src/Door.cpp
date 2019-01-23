/*
 * Class: Door
 * -------------------------
 * This is the implementation file for the Door class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "Door.hpp"
#include "Corridor.hpp"
#include "KyloSpace.hpp"

/*
 * Function: Door::Door()
 * Usage: Door()
 * -------------------------
 * This is the default constructor for the Door class. This function sets default values for the
 * Space object.
 */
Door::Door() {
    Space::roomName = "Door";
    Space::roomDescription= "There appears to be a big startanium door impeding the way. It looks like some access code needs to be entered.";
    
    Space::top = new Corridor;
    Space::top->setBottom(this);
    Space::bottom = new KyloSpace;
    Space::bottom->setTop(this);
    Space::left = nullptr;
    Space::right = nullptr;
}

/*
 * Function: Door::Door(space*, space*, space*, space*)
 * Usage: Door(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the Door class. This function sets default values for the
 * Space object.
 */
Door::Door(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: Door::~Door()
 * Usage: ~Door()
 * -------------------------
 * This is the default destructor for the Door class.
 */
Door::~Door() {
    delete Space::getTop();
    delete Space::getBottom();     //Delete KyloSpace
}
/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: Door::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the Door class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void Door::printChoices() {
    cout << "1) North - Mysterious Room" << endl
         << "2) South - Command Center" << endl
         << "3) West - Armory" << endl
         << "4) Item Inventory " << endl
         << "5) Look around" << endl << endl;
}

/*
 * Function: Door::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the Door class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string Door::getChoice() {
    cout << "Please select a choice (enter integer): ";
    int choice = getInteger();
    validate(choice, 1, 5);
    cout << endl;
    
    if (choice == 1) {
        return "north";
    } else if (choice == 2) {
        return "south";
    } else if (choice == 3) {
        return "west";
    } else if (choice == 4) {
        return "items";
    } else {
        return "look";
    }
}
