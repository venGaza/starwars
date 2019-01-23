/*
 * Class: Corridor
 * -------------------------
 * This is the implementation file for the Corridor class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "Corridor.hpp"

/*
 * Function: Corridor::Corridor()
 * Usage: Corridor()
 * -------------------------
 * This is the default constructor for the Corridor class. This function sets default values for the
 * Corridor object.
 */
Corridor::Corridor() {
    Space::roomName = "Corridor";
    Space::roomDescription= "A long hallway on the Starship with locked doors lining the walls. This seems to be a dead end.";
    
    Space::top = nullptr;
    Space::bottom = nullptr;
    Space::left = nullptr;
    Space::right = nullptr;
}

/*
 * Function: Corridor::Corridor(space*, space*, space*, space*)
 * Usage: obj.Corridor(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the Corridor class. This function sets default values for the
 * Corridor object.
 */
Corridor::Corridor(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: Corridor::~Corridor()
 * Usage: ~Corridor()
 * -------------------------
 * This is the default destructor for the Corridor class.
 */
Corridor::~Corridor() {}

/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: Corridor::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the Corridor class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void Corridor::printChoices() {
    cout << "1) South " << endl
         << "2) Item Inventory " << endl
         << "3) Look around" << endl << endl;
}

/*
 * Function: Corridor::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the Corridor class. This function gets a choice from the user.
 * This is an abstract function inherited from Space class.
 */
string Corridor::getChoice() {
    cout << "Please select a choice (enter integer): ";
    int choice = getInteger();
    validate(choice, 1, 3);
    cout << endl;
    
    if (choice == 1) {
        return "south";
    } else if (choice == 2) {
        return "items";
    } else {
        return "look";
    }
}
