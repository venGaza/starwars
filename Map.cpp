/*
 * Class: Map
 * -------------------------
 * This is the implementation file for the Map class. This class builds the game map based on what is
 * connected to the starting space. The class also allows the user to move around the map and prints out
 * basic information about where the user is currently located. The dveloper can also manually add
 * and connect spaces from this class.
 */

#include "Map.hpp"
#include "StartSpace.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;


/*
 * Function: Map::Map()
 * Usage: Map()
 * -------------------------
 * This is the default constructor for the Map class. This function sets default values for the
 * Map object.
 */
Map::Map() {
    head = nullptr;
    tail = nullptr;
    temp =nullptr;
    location = nullptr;
}

/*
 * Function: Map::~Map()
 * Usage: ~Map()
 * -------------------------
 * This is the default destructor for the Map class.
 */
Map::~Map() {
    delete head;
    
    /*
    if (head->getRight() != nullptr){
        temp = head->getRight();
    }
    
    if (head->getTop() != nullptr) {
        delete head->getTop();
    }
    
    if (head->getLeft() != nullptr){
        delete head->getLeft();
    }
    
    if (head->getBottom() != nullptr){
        delete head->getBottom();
    }
     */
    
    
}
/****************************************************************************************************
 *                                      PUBLIC FUNCTIONS                                            *
 ***************************************************************************************************/
/*
 * Function: Map::createMap()
 * Usage: createMap()
 * -------------------------
 * This is a public function for the Map class. This function creates the entire map for the game.
 */
void Map::createMap() {
    head = new StartSpace();              //Create Start Room (Snoke Space connected to South)
    location = head;
}

/*
 * Function: Map::moveNorth()
 * Usage: moveNorth()
 * -------------------------
 * This is a public function for the Map class. This function allows the player to move north.
 */
void Map::moveNorth() {
    if (location->getTop() != nullptr) {
        location = location->getTop();
        printLocation();
    } else {
        cout << "Cannot move in that direction." << endl;
    }
    
}

/*
 * Function: Map::moveSouth()
 * Usage: moveSouth()
 * -------------------------
 * This is a public function for the Map class. This function allows the player to move south.
 */
void Map::moveSouth() {
    if (location->getBottom() != nullptr) {
        location = location->getBottom();
        printLocation();
    } else {
        cout << "Cannot move in that direction." << endl;
    }
}

/*
 * Function: Map::moveEast()
 * Usage: moveEast()
 * -------------------------
 * This is a public function for the Map class. This function allows the player to move east.
 */
void Map::moveEast() {
    if (location->getRight() != nullptr) {
        location = location->getRight();
        printLocation();
    } else {
        cout << "Cannot move in that direction." << endl;
    }
}

/*
 * Function: Map::moveWest()
 * Usage: moveWest()
 * -------------------------
 * This is a public function for the Map class. This function allows the player to move west.
 */
void Map::moveWest() {
    if (location->getLeft() != nullptr) {
        location = location->getLeft();
        printLocation();
    } else {
        cout << "Cannot move in that direction." << endl;
    }
}

/*
 * Function: Map::currentRoom()
 * Usage: currentRoom()
 * -------------------------
 * This is a public function for the Map class. This function returns the name of the room that
 * the player is currently inside.
 */
string Map::currentRoom() {
    return location->getRoomName();
}
/****************************************************************************************************
 *                                          GETTERS                                                 *
 ***************************************************************************************************/
/*
 * Function: Map::getLocation()
 * Usage: getLocation()
 * -------------------------
 * This is a public function for the Map class. This function returns the Space* of the current
 * location.
 */
Space* Map::getLocation() {
    return location;
}
/****************************************************************************************************
 *                                     PRIVATE FUNCTIONS                                            *
 ***************************************************************************************************/
/*
 * Function: Map::printLocation()
 * Usage: printLocation()
 * -------------------------
 * This is a public function for the Map class. This function prints out a location description after
 * the player moves to another space/room.
 */
void Map::printLocation() {
    if (location->getRoomName() != "Supreme Leader Snoke" && location->getRoomName() != "Door") {
        cout << "You are in the " << location->getRoomName() << endl << endl;
    } else if (location->getRoomName() != "Supreme Leader Snoke" &&
               location->getRoomName() == "Door") {
        cout << "Hmmm, it seems we have a problem..." << endl << endl;
    } else {
        cout << "You probably should not have come in here..." << endl << endl;
    }
}

/*
 * Function: Map::addSpace()
 * Usage: addSpace()
 * -------------------------
 * This is a public function for the Map class. This function takes 3 parameters which include two
 * Space pointers and a string. It will use these parameters to create a Space object to connect to
 * the current object.
 */
void Map::addSpace(Space*& location, Space*& newSpace, string side) {
    if (side == "right") {
        location->setRight(newSpace);
        newSpace->setLeft(location);
        newSpace = nullptr;
    } else if (side == "left") {
        location->setLeft(newSpace);
        newSpace->setRight(location);
        newSpace = nullptr;
    } else if (side == "top") {
        location->setTop(newSpace);
        newSpace->setBottom(location);
        newSpace = nullptr;
    } else {
        location->setBottom(newSpace);
        newSpace->setTop(location);
        newSpace = nullptr;
    }
}

/*
 * Function: Map::connectSpace()
 * Usage: connectSpace()
 * -------------------------
 * This is a public function for the Map class. This function takes 3 parameters which include two
 * Space pointers and a string. It will use these parameters to connect two existing Space objects.
 */
void Map::connectSpace(Space* location, Space* connection, string side) {
    if (side == "right") {
        location->setRight(connection);
        connection->setLeft(location);
    } else if (side == "left") {
        location->setLeft(connection);
        connection->setRight(location);
    } else if (side == "top") {
        location->setTop(connection);
        connection->setRight(location);
    } else {
        location->setBottom(connection);
        connection->setTop(location);
    }
}

