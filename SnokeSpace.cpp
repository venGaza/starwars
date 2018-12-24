/*
 * Class: SnokeSpace
 * -------------------------
 * This is the implementation file for the SnokeSpace class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "SnokeSpace.hpp"

/*
 * Function: SnokeSpace::SnokeSpace()
 * Usage: SnokeSpace()
 * -------------------------
 * This is the default constructor for the SnokeSpace class. This function sets default values for the
 * Space object.
 */
SnokeSpace::SnokeSpace() {
    Space::roomName = "Supreme Leader Snoke";
    Space::roomDescription= "A figure emerges from the back of the room. The dark side emanates greatly. ";
    
    Space::top = nullptr;
    Space::bottom = nullptr;
    Space::left = nullptr;
    Space::right = nullptr;
}

/*
 * Function: SnokeSpace::SnokeSpace(space*, space*, space*, space*)
 * Usage: SnokeSpace(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the SnokeSpace class. This function sets default values
 * for the Space object.
 */
SnokeSpace::SnokeSpace(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: SnokeSpace::~SnokeSpace()
 * Usage: ~SnokeSpace()
 * -------------------------
 * This is the default destructor for the SnokeSpace class.
 */
SnokeSpace::~SnokeSpace() {}
/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: SnokeSpace::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the SnokeSpace class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void SnokeSpace::printChoices() {
    
}

/*
 * Function: SnokeSpace::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the SnokeSpace class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string SnokeSpace::getChoice() {
    cout << "Please select a choice (enter integer): ";
    int choice = getInteger();
    validate(choice, 1, 5);
    cout << endl;
    
    if (choice == 1) {
        return "north";
    } else if (choice == 2) {
        return "east";
    } else if (choice == 3) {
        return "south";
    } else if (choice == 4) {
        return "items";
    } else {
        return "look";
    }
}
