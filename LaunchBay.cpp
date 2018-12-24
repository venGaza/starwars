/*
 * Class: LaunchBay
 * -------------------------
 * This is the implementation file for the LaunchBay class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "LaunchBay.hpp"

/*
 * Function: LaunchBay::LaunchBay()
 * Usage: LaunchBay()
 * -------------------------
 * This is the default constructor for the LaunchBay class. This function sets default values for the
 * Space object.
 */
LaunchBay::LaunchBay() {
    Space::roomName = "Launch Bay";
    Space::roomDescription= "The heart of the Starship. A towering plasma cylinder glow ahead lighting the entire room.";
    
    Space::top = nullptr;
    Space::bottom = nullptr;
    Space::left = nullptr;
    Space::right = nullptr;
}

/*
 * Function: LaunchBay::LaunchBay(space*, space*, space*, space*)
 * Usage: LaunchBay(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the LaunchBay class. This function sets default values for the
 * Space object.
 */
LaunchBay::LaunchBay(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: LaunchBay::~LaunchBay()
 * Usage: ~LaunchBay()
 * -------------------------
 * This is the default destructor for the LaunchBay class.
 */
LaunchBay::~LaunchBay() {}
/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: LaunchBay::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the LaunchBay class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void LaunchBay::printChoices() {
    cout << "1) East " << endl
         << "2) Item Inventory " << endl
         << "3) Look around" << endl << endl;
}

/*
 * Function: LaunchBay::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the LaunchBay class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string LaunchBay::getChoice() {
    cout << "Please select a choice (enter integer): ";
    int choice = getInteger();
    validate(choice, 1, 3);
    cout << endl;
    
    if (choice == 1) {
        return "east";
    } else if (choice == 2) {
        return "items";
    } else {
        return "look";
    }
}
