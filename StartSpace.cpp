/*
 * Class: StartSpace
 * -------------------------
 * This is the implementation file for the StartSpace class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "StartSpace.hpp"
#include "SnokeSpace.hpp"
#include "Corridor.hpp"
#include "CoreReactor.hpp"

/*
 * Function: StartSpace::StartSpace()
 * Usage: Space()
 * -------------------------
 * This is the default constructor for the Space class. This function sets default values for the
 * Space object.
 */
StartSpace::StartSpace() {
    Space::roomName = "Blast Site";
    Space::roomDescription= "It looks like an explosion just took place here. You don't remember what happened though.";
    
    Space::top = new Corridor;
    Space::top->setBottom(this);
    Space::bottom = new SnokeSpace;
    Space::bottom->setTop(this);
    Space::left = nullptr;
    Space::right = new CoreReactor;
    Space::right->setLeft(this);
}

/*
 * Function: StartSpace::StartSpace()
 * Usage: Space(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the Space class. This function sets default values for the
 * Space object.
 */
StartSpace::StartSpace(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: StartSpace::~StartSpace()
 * Usage: ~Space()
 * -------------------------
 * This is the default destructor for the Space class.
 */
StartSpace::~StartSpace() {
    delete Space::getTop();
    delete Space::getBottom();
    delete Space::getRight();               //Delete Core Reactor
}

/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: StartSpace::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the Space class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void StartSpace::printChoices() {
    cout << "1) North - Mysterious Room" << endl
         << "2) East - Core Reactor"  << endl
         << "3) South - Mysterious Room" << endl
         << "4) Item Inventory " << endl
         << "5) Look around" << endl << endl;
}

/*
 * Function: StartSpace::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the Space class. This function gets a choice from the user.
 * This is an abstract function inherited from Space class.
 */
string StartSpace::getChoice() {
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
