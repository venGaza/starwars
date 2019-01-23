/*
 * Class: Infirmary
 * -------------------------
 * This is the implementation file for the Infirmary class. This class is a subclass of the superclass
 * Space object and is one of the types of spaces within the game. The player will traverse the various
 * types of spaces to collect items and reach the final boss.
 */

#include "Infirmary.hpp"
#include "Armory.hpp"

/*
 * Function: Infirmary::Infirmary()
 * Usage: Infirmary()
 * -------------------------
 * This is the default constructor for the Infirmary class. This function sets default values for the
 * Space object.
 */
Infirmary::Infirmary() {
    Space::roomName = "Infirmary";
    Space::roomDescription= "There are a few med pods in here... a 20 min nap sounds in order.";
    
    Space::top = nullptr;
    Space::bottom = nullptr;
    Space::left = nullptr;
    Space::right = new Armory;
    Space::right->setLeft(this);
    
    medPodAvail = true;
}

/*
 * Function: Infirmary::Infirmary(space*, space*, space*, space*)
 * Usage: Infirmary(space, space, space, space)
 * -------------------------
 * This is the overloaded constructor for the Infirmary class. This function sets default values for the
 * Space object.
 */
Infirmary::Infirmary(Space* top, Space* bottom, Space* left, Space* right) {
    this->Space::top = top;
    this->Space::bottom = bottom;
    this->Space::left = left;
    this->Space::right = right;
}

/*
 * Function: Infirmary::~Infirmary()
 * Usage: ~Infirmary()
 * -------------------------
 * This is the default destructor for the Infirmary class.
 */
Infirmary::~Infirmary() {
    delete Space::getRight();           //Delete the armory
}
/****************************************************************************************************
 *                                  ABSTRACT PUBLIC FUNCTIONS                                       *
 ***************************************************************************************************/
/*
 * Function: Infirmary::printChoices()
 * Usage: obj.printChoices()
 * -------------------------
 * This is a public member function for the Infirmary class. This function prints out the menu choices
 * for this space. This is an abstract function inherited from Space class.
 */
void Infirmary::printChoices() {
    if (medPodAvail) {
        cout << "1) East - Armory" << endl
             << "2) West - Core Reactor" << endl
             << "3) Item Inventory " << endl
             << "4) Look around" << endl
             << "5) Use Med Pod Bay" << endl << endl;
    } else {
        cout << "1) East - Armory" << endl
        << "2) West - Core Reactor" << endl
        << "3) Item Inventory " << endl
        << "4) Look around" << endl << endl;
    }
}

/*
 * Function: Infirmary::getChoice()
 * Usage: obj.getChoice()
 * -------------------------
 * This is a public member function for the Infirmary class. This function gets a choice from
 * the user. This is an abstract function inherited from Space class.
 */
string Infirmary::getChoice() {
    if (medPodAvail){
        cout << "Please select a choice (enter integer): ";
        int choice = getInteger();
        validate(choice, 1, 5);
        cout << endl;
        
        if (choice == 1) {
            return "east";
        } else if (choice == 2) {
            return "west";
        } else if (choice == 3) {
            return "items";
        } else if (choice == 4) {
            return "look";
        } else {
            medPodAvail = false;
            return "medpod";
        }
    } else {
        cout << "Please select a choice (enter integer): ";
        int choice = getInteger();
        validate(choice, 1, 4);
        cout << endl;
        
        if (choice == 1) {
            return "east";
        } else if (choice == 2) {
            return "west";
        } else if (choice == 3) {
            return "items";
        } else {
            return "look";
        }
    }
}
