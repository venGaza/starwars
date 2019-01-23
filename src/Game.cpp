/*
 * Class: Game
 * -------------------------
 * This is the implementation file for the Game class. This class runs provides the menu interface for
 * the game and controls the flow of the adventure and story. It is also responsible for generating
 * items, keeping track of the player health, interactions, and determining when the game is over.
 */

#include "Game.hpp"
#include "Map.hpp"
#include <iostream> //for cout, cin, endl
#include <iomanip>  //for setw
#include "getInteger.hpp"
#include "validate.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

/*
 * Function: Game::Game()
 * Usage: Game()
 * -------------------------
 * This is the default constructor for the Game class. This function sets default values for the
 * Game object.
 */
Game::Game() {
    playerName = "Luke";
    exitGame = false;
    gameOver = false;
    playerHealth = 10;
    doorCode = 1225;
    kyloWinGame = true;
    chewbaccaFree = false;
}

/*
 * Function: Game::~Game()
 * Usage: ~Game()
 * -------------------------
 * This is the destructor for the Game class.
 */
Game::~Game() {}
/****************************************************************************************************
 *                                      PUBLIC FUNCTIONS                                            *
 ***************************************************************************************************/
/*
 * Function: Game::menu()
 * Usage: gameObj.menu()
 * -------------------------
 * This is a public member function for the Game class. This function creates the menu for the class
 * and allows the user to play through the game or exit.
 */
void Game::menu() {
    cout << "1. Start Adventure" << endl             //Menu Choices
         << "2. Exit" << endl << endl
         << "Please select a number: ";
    
    int menuSelection = getInteger();
    cout << endl;
    
    validate(menuSelection, 1, 2);
    
    if (menuSelection == 1) {                       //1. Add a new node to head
        getPlayerName();
        
        Map map;                                        //Generate map
        map.createMap();
        
        while (!gameOver) {
            //Determine what room player is in and advance accordingly
            if (map.getLocation()->getRoomName() == "Supreme Leader Snoke") {
                snokeLoss();
            } else if (map.getLocation()->getRoomName() == "Door") {
                doorInteraction(map);
            } else if (map.getLocation()->getRoomName() == "Command Center") {
                if (kyloWinGame) {
                    kyloWin();
                    gameOver = true;
                } else {
                    kyloLoss();
                    advance(map);
                }
            } else if (map.getLocation()->getRoomName() == "Launch Bay") {
                winMessage();
                gameOver = true;
            } else {
                advance(map);
            }
        }
    } else {                                        //2. Exit program
        exitGame = true;
    }
}

/*
 * Function: Game::getExitGame()
 * Usage: gameObj.getExitGame()
 * -------------------------
 * This is a public member function for the Game class. This function returns the bool value for
 * exitGame. If true, the game will exit. Otherwise the game menu will present again.
 */
bool Game::getExitGame() {
    return exitGame;
}


/*
 * Function: resetGame
 * Usage: resetGame()
 * -------------------------
 * This is a member function for the Game class. This function resets the gameOver
 * variable so the player can restart the game.
 */
void Game::resetGame() {
    gameOver = false;
}
/****************************************************************************************************
 *                                     PRIVATE FUNCTIONS                                            *
 ***************************************************************************************************/
/*
 * Function: Game::getPlayerName()
 * Usage: gameObj.getPlayerName()
 * -------------------------
 * This is a private member function for the Game class. This function starts the beginning of the
 * story and gets the name from the user.
 */
void Game::getPlayerName() {
    cout << "In a galaxy far far away....." << endl << endl;
    pause();
    
    cout << "You wake up in a daze from a recent blast. A man wearing a resistance uniform pulls "
         << "you from the rubble and asks for your name. You answer back: ";
    getline(cin, playerName);
    
    while (playerName == "") {
        cout << "You must be dazed from the blast. Your name is: ";
        getline(cin, playerName);
    }
    
    cout << endl << "After further examination you realize the man is Poe Dameron, a legendary "
         << "resistance pilot." << endl << endl;
    
    cout << "Poe: \"You are lucky to have survived the blast, " << playerName << ", but you better "
         << "get moving because Supreme Leader Snoke, Kylo Ren and an army of stormtroopers are "
         << "after you on this starship. As one of the last remaining Jedi in the galaxy, you are the "
         << "best chance we have at defeating the First Order. It looks like some of your equipment "
         << "landed over to the east in the reactor room. You might want to head in that direction "
         << "first before heading off to fight Kylo Ren. May the force be you " << playerName
         << "!\" (cool action music starts playing in the background)" ;
    cout << endl << endl;
    
    cout << "(You think to yourself that hopefully there is a med pod bay to use somewhere around here as you feel drained from the blast)" << endl << endl;
}

/*
 * Function: Game::doAction()
 * Usage: gameObj.doAction()
 * -------------------------
 * This is a private member function for the Game class. This function executes the user's choice of
 * action.
 */
void Game::doAction(string choice, Map& map) {
    if (choice == "north") {
        map.moveNorth();
    } else if (choice == "south") {
        map.moveSouth();
    } else if (choice == "east") {
        map.moveEast();
    } else if (choice == "west") {
        map.moveWest();
    } else if (choice == "items") {
        printItems();
    } else if (choice == "look") {
        cout << map.getLocation()->getRoomDescription() << endl << endl;
    } else if (choice == "lightsaber") {
        addLightsaber();
    } else if (choice == "paper") {
        addPaper();
    } else if (choice == "open") {
        cout << "You open the cell door and discover that the prisoner being held is the most famous wookie in the galaxy, Chewbacca! He lets out a thunderous grrrwaaaaaarggggh and heads off to kick some First Order butt!" << endl << endl;
        chewbaccaFree = true;
    } else {
        cout << "You decide to enter the med pod bay for a few minutes and your health is restored."
             << endl << endl;
        playerHealth = 50;
    }
}

/*
 * Function: Game::printItems()
 * Usage: gameObj.printItems()
 * -------------------------
 * This is a private member function for the Game class. This function prints out the items currently
 * in the user's inventory.
 */
void Game::printItems() {
    cout << setw(18) << "Inventory" << endl  //Header
    << "---------------------------------" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i].itemName << ": " << inventory[i].itemDescription << endl;
    }
    cout << endl;
}

/*
 * Function: Game::addLightsaber()
 * Usage: gameObj.addLightsaber()
 * -------------------------
 * This is a private member function for the Game class. This function creates a lightsaber object
 * adds it to the inventory vector.
 */
void Game::addLightsaber() {
    Items lightsaber;
    lightsaber.itemName = "GREEN LIGHT SABER: ";
    lightsaber.itemDescription = "The weapon of choice for a jedi.";
    inventory.push_back(lightsaber);
    kyloWinGame = false;
}

/*
 * Function: Game::addPaper()
 * Usage: gameObj.addPaper()
 * -------------------------
 * This is a private member function for the Game class. This function creates a crumpled paper
 * object and add it to the user's inventory.
 */
void Game::addPaper() {
    Items accessCode;
    accessCode.itemName = "CRUMPLED PAPER: ";
    accessCode.itemDescription = "There is some writing in Ewokese: 1225... how mysterious...";
    inventory.push_back(accessCode);
}

/*
 * Function: Game::doorInteraction()
 * Usage: gameObj.doorInteraction()
 * -------------------------
 * This is a private member function for the Game class. This function lets the user interact with
 * the door space. The user is required to enter a code in order for the door to open. If the user
 * enters the right code, the user will enter the Command Center. If not, they will remain in the
 * armory. The current code is: 1225.
 */
void Game::doorInteraction(Map& map) {
    cout << map.getLocation()->getRoomDescription() << endl << endl;
    
    cout << "Please enter an access code: ";
    int userInput = getInteger();
    cout << endl;
    if (userInput == doorCode) {   //Door code is 1225 and found on paper description
        cout << "Access GRANTED (The door whirs open with a whoosh)" << endl << endl;
        map.moveSouth();
        pause();
    } else {
        cout << "Access DENIED (I guess you will be admiring the blasters a little longer)"       << endl << endl;
        map.moveWest();
        pause();
    }
}

/*
 * Function: Game::advance()
 * Usage: gameObj.advance()
 * -------------------------
 * This is a private member function for the Game class. This function advances the game forward one
 * step or health unit. It allows the player to move to another room and also checks to see if the
 * player still has health.
 */
void Game::advance(Map& map) {
    cout << setw(9) << map.currentRoom() << " | Health: " << playerHealth << endl  //Header
    << "---------------------------------" << endl;
    
    map.getLocation()->printChoices();
    
    string choice = map.getLocation()->getChoice();
    doAction(choice, map);          //If not execute player choice
    
    //Update player health after turn
    playerHealth--;
    if (playerHealth == 0) {
        cout << "The combined effects of the blast and adventure have taken its toll... the galaxy starts to slip into darkness as you lose consciousness." << endl << endl;
        gameOver = true;
    }
    pause();
}

/*
 * Function: Game::snokeLoss()
 * Usage: gameObj.snokeLoss()
 * -------------------------
 * This is a private member function for the Game class. This function prints out the ending of the
 * adventure if Snoke wins.
 */
void Game::snokeLoss() {
    cout << "A dark figure emerges from the darkest shadows of the room. The dark side emanates from this being as you have never felt before. You realize that coming in this room was a mistake because you realize the being is Supreme Leader Snoke! Snoke cackles and says, \"It is unfortunate that you decided to come this way young jedi...your adventure ends here with me. As Snoke annihilates you with his force lighting, you keep thinking what would have happened if you had gone the other way..." << endl << endl;
    gameOver = true;
}

/*
 * Function: Game::kyloWin()
 * Usage: gameObj.kyloWin()
 * -------------------------
 * This is a private member function for the Game class. This function prints out the ending of the
 * adventure if Kylo Ren wins. This occurs if player did not pick up lightsaber.
 */
void Game::kyloWin() {
    cout << "Kylo Ren says, \"" << playerName << " , we meet again! What kind of Jedi shows up to battle without his lighsaber? You were always quite the fool and now... the entire galaxy will descend into darkness.\" Kylo Ren draws his lightsaber and puts an end to your adventure as he cackles maniacally. I guess the galaxy won't be saved by you after all." << endl << endl;
}

/*
 * Function: Game::kyloLoss()
 * Usage: gameObj.kyloLoss()
 * -------------------------
 * This is a private member function for the Game class. This function prints out a message if the
 * user defeats Kylo Ren in the command center. This occurs if the player picked up the light saber
 * found in the core reactor.
 */
void Game::kyloLoss() {
    cout << "Kylo Ren says, \"" << playerName << " , we meet again! It looks like you found your lightsaber  after our last battle. What does it matter? I'll finish you off this time and show the galaxy once and for all why the dark side will always win!\" Kylo Ren draws his lightsaber and tries to strike you down, but you are able to draw your own lightsaber and quickly counter. After a dramatic fight scene and a lot of pew pew sound fx, you are able to strike Kylo Ren down and put an end to his dark ways. Oddly enough, Kylo still wears his arrogant grin as his life force slowly drains. It is now time for you to evacuate off this ship. You notice that the escape pods are located to the west... however, you can't help but notice a secret room located off to the east. Hmmm, what will you do? " << endl << endl;
}

/*
 * Function: Game::winMessage()
 * Usage: gameObj.winMessage()
 * -------------------------
 * This is a private member function for the Game class. This function prints out a message if the
 * user reaches the launch bay and still has at least 1 health. At this point, the user has completed
 * the game and will be congratulated.
 */
void Game::winMessage() {
    if (chewbaccaFree) {
    cout << "You quickly glance around the Launch Bay. Luckily, there is one star ship available for you to commandeer and escape the ship. As you board the ship, Poe and Chewbacca run up the ramp to give you a high five for defeating Kylo Ren. The action music again starts to blare as alarms go off in the launch bay. You fire up the engines and take off from the ship knowing that Supreme Leader Snoke still needs to be found and dealt with. After a long deliberation with Poe and Chewbacca, you all decide to stop at the Mos Eisley cantina for a well deserved break! As you engage the light drive, the ship you left behind disintegrates into billions of pieces... Chewy must have made some modifications in the core reactor." << endl << endl;
    } else {
        cout << "You quickly glance around the Launch Bay. Luckily, there is one star ship available for you to commandeer and escape the ship. As you board the ship, Poe runs up the ramp to give you a high five for defeating Kylo Ren. The action music again starts to blare as alarms go off in the launch bay. You fire up the engines and take off from the ship knowing that Supreme Leader Snoke still needs to be found and dealt with. After a long deliberation with Poe, you all decide to stop at the Mos Eisley cantina for a well deserved break! As you engage the light drive, you hear a faint grrrwaaaaaarggggh and can't help but to think that someone was left in the detention block. Oh well... " << endl << endl;
    }
    
    cout << "Congratulation you have COMPLETED this Star Wars adventure!" << endl << endl;
}

/*
 * Function: pause
 * Usage: pause()
 * -------------------------
 * This is a member function for the Game class. This function pauses the program.
 */
void Game::pause() {
    cout << "Press enter to continue" << endl;
    char ch  = cin.get();   //PAUSE
    while (ch != '\n') {
        cin.clear();
        ch = cin.get();
    }
}