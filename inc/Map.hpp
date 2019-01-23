/*
 * Class: Map
 * -------------------------
 * This is the interface file for the Map class. This class builds the game map based on what is
 * connected to the starting space. The class also allows the user to move around the map and prints out
 * basic information about where the user is currently located. The dveloper can also manually add
 * and connect spaces from this class.
 */

#ifndef MAP_HPP
#define MAP_HPP

#include "Space.hpp"

class Map {
public:
    Map();                             //Default Constructor
    ~Map();                            //Destructor
    
    //Functions
    void createMap();                  //Generates entire map which is linked to StartSpace
    void moveNorth();                  //Moves player north on map
    void moveSouth();                  //Moves player south on map
    void moveEast();                   //Moves player east on map
    void moveWest();                   //Moves player west on map
    string currentRoom();              //Returns the room/space object name
    
    //Getters
    Space* getLocation();              //Return location pointer
    
private:
    //Functions
    void printLocation();                           //Prints out a location description
    void addSpace(Space*&, Space*&, string);        //Creates a Space objects to add and connects it
    void connectSpace(Space*, Space*, string);      //Connects two existing Space objects
    
    //Variables
    Space* head;
    Space* tail;
    Space* location;
    Space* temp;
};
#endif 
