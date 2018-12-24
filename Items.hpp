/*
 * Class: Items
 * -------------------------
 * This is the interface file for the Items class. This class allows the user to create items which
 * includes a name and description. This was set as a class object for future flexibility.
 */

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string> //for string
using std::string;

class Items {
public:
    Items();                            //Constructor
    Items(string, string);              //Overloaded Constructor
    
    //Variables
    string itemName;
    string itemDescription;
private:
};
#endif
