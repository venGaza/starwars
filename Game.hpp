/*
 * Class: Game
 * -------------------------
 * This is the interface file for the Game class. This class runs provides the menu interface for the
 * game and controls the flow of the adventure and story. It is also responsible for generating items,
 * keeping track of the player health, interactions, and determining when the game is over.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Map.hpp"
#include <vector> //for vector
#include <string> //for string
#include "Items.hpp"
using std::vector;
using std::string;

class Game {
public:
    Game();                         //Constructor
    ~Game();                        //Destructor
    
    //Functions
    void menu();                    //Creates initial game menu
    
    //Getters
    bool getExitGame();             //Return the gameOver bool to exit game
    
private:
    //Functions
    void getPlayerName();           //Gets the name from the user
    void doAction(string, Map&);    //Executes user choice
    void printItems();
    void addLightsaber();
    void addPaper();
    void doorInteraction(Map&);     //Lets user interact with the door space
    void advance(Map&);             //Advances the game by one room / health unit
    void snokeLoss();               //Print loss message due to Supreme Leader Snoke showing up
    void kyloWin();                 //If Kylo wins, it prints a message and ends game
    void kyloLoss();                //If Kylo loses, it prints message and game continues
    void winMessage();              //End of game message if user reaches Launch Bay
    void pause();                   //Pauses the game
    
    
    //Variables
    string playerName;
    bool exitGame;
    bool kyloWinGame;
    bool gameOver;
    bool chewbaccaFree;
    int playerHealth;
    int doorCode;
    
    vector<Items> inventory;        //Container for player items
    
};

#endif
