/**************************************************************************************************
 ** Name: Dustin Jones
 ** Date: Dec 02, 2017
 ** Description: This is a text based adventure game based in the Star Wars universe. The player will
 ** make decisions to navigate through a map to collect items to defeat his or her foes and ultimately
 ** the final boss. 
 **************************************************************************************************/

#include <iostream> //for cout, endl
#include "Game.hpp"
using std::cout;
using std::cin;
using std::endl;

/* Function Prototypes */
void welcomeMessage();

/* Main Function */
int main() {
    welcomeMessage();
    
    Game game;
    while (!game.getExitGame()) {
        game.menu();
        game.resetGame();
    }
    
    cout << "Have a great holiday and may the force be with you! Make sure to check out "
         << "Star Wars: The Last Jedi" << endl << endl;
    
    return 0;
}

/*
 * Function: welcomeMessage
 * Usage: welcomeMessage()
 * -------------------------
 * Prints a welcome message to the screen and explains what the program does.
 */
void welcomeMessage() {
    cout << "Welcome to a text based adventure based in the Star Wars universe! As one of the last "
         << "remaining Jedi in the galaxy, you will combat Kylo Ren and the First order for control "
         << "of the galaxy. Enjoy!!! \n" << endl;
}
