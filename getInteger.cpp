/*
 * Function: getInteger
 * -------------------------
 * This is the implementation file for the getInteger function. This function allows the user
 * to input an integer and checks input for validity. This function is based off code from the
 * simpio.h library getInteger function. See citation below.
 *                                          CITATION
 * Title: simpio.h / getInteger
 * Author: Roberts, E Zelenski, J. Schwarz, K.
 * Date: 2017/10/01
 * Code Version: 2015/07/05
 * Availability: https://stanford.edu/~stepp/cppdoc/simpio.html
 */


#include "getInteger.hpp"
#include <iostream> //for cin, cout, endl
#include <sstream> //for istringstream
#include <string> //for string
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

int getInteger() {                      //See code citation in comment at top of page
    int integer;
    while (true) {
        string line;
        getline(cin, line);
        
        istringstream stream(line);
        stream >> integer;
        if (!stream.fail() && stream.eof() && integer >= 0) { //Num Validation & Pos Number Validation
            break;
        } else {
            cout << "The value you entered is not a valid integer. Please \n"
                    << "enter another integer: ";
        }
    }
    
    return integer;
}
