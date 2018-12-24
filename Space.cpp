/*
 * Class: Space
 * -------------------------
 * This is the implementation file for the Space class. This class servers as the superclass for the
 * different types of spaces within the game. The player will traverse the various types of spaces
 * to collect items and reach the final boss.
 */

#include "Space.hpp"

/*
 * Function: Space::Space()
 * Usage: Space()
 * -------------------------
 * This is the default constructor for the Space class. This function sets default values for the
 * Space object.
 */
Space::Space() {
    Space::roomName = "";
    Space::roomDescription= "";
    
    Space::top = nullptr;
    Space::bottom = nullptr;
    Space::left = nullptr;
    Space::right = nullptr;
}

/*
 * Function: Space::~Space()
 * Usage: ~Space()
 * -------------------------
 * This is the default destructor for the Space class.
 */
Space::~Space() {}

/****************************************************************************************************
 *                                          GETTERS                                                 *
 ***************************************************************************************************/
/*
 * Function: string Space::getRoomName()
 * Usage: obj.getRoomName()
 * -------------------------
 * This is a public member function of the Space class. This function returns the room name.
 */
string Space::getRoomName() {
    return roomName;
}

/*
 * Function: string Space::getRoomDescription()
 * Usage: obj.getRoomDescription()
 * -------------------------
 * This is a public member function of the Space class. This function returns the room description.
 */
string Space::getRoomDescription() {
    return roomDescription;
}

/*
 * Function: Space* Space::getTop()
 * Usage: obj.getTop()
 * -------------------------
 * This is a public member function of the Space class. This function returns what the north side of the
 * the room is connected to.
 */
Space* Space::getTop() {
    return top;
}

/*
 * Function: Space* Space::getBottom()
 * Usage: obj.getBottom()
 * -------------------------
 * This is a public member function of the Space class. This function returns what the south side of the
 * the room is connected to.
 */
Space* Space::getBottom() {
    return bottom;
}

/*
 * Function: Space* Space::getLeft()
 * Usage: obj.getLeft()
 * -------------------------
 * This is a public member function of the Space class. This function returns what the west side of the
 * the room is connected to.
 */
Space* Space::getLeft() {
    return left;
}

/*
 * Function: Space* Space::getRight()
 * Usage: obj.getRight()
 * -------------------------
 * This is a public member function of the Space class. This function returns what the est side of the
 * the room is connected to.
 */
Space* Space::getRight() {
    return right;
}
/****************************************************************************************************
 *                                          SETTERS                                                 *
 ***************************************************************************************************/
/*
 * Function: void Space::setRoomName(string roomName)
 * Usage: obj.setRoomName(roomName)
 * -------------------------
 * This is a public member function of the Space class. This function sets the room name.
 */
void Space::setRoomName(string roomName) {
    this->roomName = roomName;
}

/*
 * Function: void Space::setRoomDescription(string roomDescription)
 * Usage: obj.setRoomDescription(roomDescription)
 * -------------------------
 * This is a public member function of the Space class. This function sets the room description.
 */
void Space::setRoomDescription(string roomDescription) {
    this->roomDescription = roomDescription;
}

/*
 * Function: void Space::setTop(Space* top)
 * Usage: obj.setTop(top)
 * -------------------------
 * This is a public member function of the Space class. This function connects another room to the
 * north side of the room.
 */
void Space::setTop(Space* top) {
    this->top = top;
}

/*
 * Function: void Space::setBottom(Space* bottom)
 * Usage: obj.setBottom(bottom)
 * -------------------------
 * This is a public member function of the Space class. This function connects another room to the
 * south side of the room.
 */
void Space::setBottom(Space* bottom) {
    this->bottom = bottom;
}

/*
 * Function: void Space::setLeft(Space* left)
 * Usage: obj.setLeft(left)
 * -------------------------
 * This is a public member function of the Space class. This function connects another room to the
 * west side of the room.
 */
void Space::setLeft(Space* left) {
    this->left = left;
}

/*
 * Function: void Space::setRight(Space* right)
 * Usage: obj.setRight(right)
 * -------------------------
 * This is a public member function of the Space class. This function connects another room to the
 * east side of the room.
 */
void Space::setRight(Space* right) {
    this->right = right;
}

/****************************************************************************************************
 *                                      PUBLIC FUNCTIONS                                            *
 ***************************************************************************************************/
