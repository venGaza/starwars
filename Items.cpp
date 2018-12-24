/*
 * Class: Items
 * -------------------------
 * This is the implementation file for the Items class. This class allows the user to create items which
 * includes a name and description. This was set as a class object for future flexibility.
 */

#include "Items.hpp"

/*
 * Function: Items::Items()
 * Usage: Items()
 * -------------------------
 * This is the default constructor for the Items class. This function sets default values for the
 * Items object.
 */
Items::Items() {
    itemName = "";
    itemDescription = "";
}

/*
 * Function: Items::Items()
 * Usage: Items()
 * -------------------------
 * This is the overloaded constructor for the Items class. This function sets default values for the
 * Items object by taking two string parameters.
 */
Items::Items(string name, string description) {
    itemName = name;
    itemDescription = description;
}
