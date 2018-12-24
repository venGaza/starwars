/*
 * Class: KyloSpace
 * -------------------------
 * This is the implementation file for the KyloSpace class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "KyloSpace.hpp"
#include "SnokeSpace.hpp"
#include "LaunchBay.hpp"

/*
 * Function: KyloSpace::KyloSpace()
 * Usage: KyloSpace()
 * -------------------------
 * This is the default constructor for the KyloSpace class. This function sets default values for the
 * Space object.
 */
KyloSpace::KyloSpace() {
    Space::roomName = "Command Center";
    Space::roomDescription= "The Command Center where all the nefarious bad guys tend to hang out. Oh look, Kylo Ren is here and he does not look happy to see you!";
    
    Space::top = nullptr;
    Space::bottom = new SnokeSpace;
    Space::bottom->setTop(this);
    Space::left = new LaunchBay;
    Space::left->setRight(this);
    Space::right = new SnokeSpace;
    Space::right->setLeft(this);
}

/*
 * Function: KyloSpace::KyloSpace(space*, space*, space*, space*)
 * Usage: KyloSpace(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the KyloSpace class. This function sets default values for the
 * Space object.
 */
KyloSpace::KyloSpace(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: KyloSpace::~KyloSpace()
 * Usage: ~KyloSpace()
 * -------------------------
 * This is the default destructor for the KyloSpace class.
 */
KyloSpace::~KyloSpace() {
    delete Space::getBottom();
    delete Space::getLeft();
    delete Space::getRight();
}
/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: KyloSpace::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the KyloSpace class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void KyloSpace::printChoices() {
    cout << "1) North - Startanium Door" << endl
    << "2) East - Mysterious Room" << endl
    << "3) West - Launch Bay" << endl
    << "4) Item Inventory " << endl
    << "5) Look around" << endl << endl;
}

/*
 * Function: KyloSpace::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the KyloSpace class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string KyloSpace::getChoice() {
    cout << "Please select a choice (enter integer): ";
    int choice = getInteger();
    validate(choice, 1, 5);
    cout << endl;
    
    if (choice == 1) {
        return "north";
    } else if (choice == 2) {
        return "east";
    } else if (choice == 3) {
        return "west";
    } else if (choice == 4) {
        return "items";
    } else {
        return "look";
    }
}
