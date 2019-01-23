# StarWars Adventure

This is a CLI rooms program built in C++ based in the Star Wars universe. The game makes use to text based commands to allow the user to move through the gameworld. The user has just crash landed in a strange place and realize he/she has a limited time to escape an impending dark force. Along the way, the user will have a opportunities to discover powerful items which may aid in their escape. Do you have what it takes, or will you succumb to the danger that lurks?     

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
GNU Compiler (Recommend to install with package manager such as Homebrew)
```

### Installing (Bash Terminal)

In the command line within your desired directory, run the following command to download the program:

```
#Downloads the project directory to the current working directory
git clone https://github.com/venGaza/starwars.git
```

Then run the following command to build the project:

```
#Build
make all
```

### Playing the game

To play the game run the following command:

```
bin/StarWars
```

The screen should display the following information if the installation was successful:

```
Welcome to a text based adventure based in the Star Wars universe! As one of the last remaining Jedi in the galaxy, you will combat Kylo Ren and the First order for control of the galaxy. Enjoy!!! 

1. Start Adventure
2. Exit
```

You will navigate throught the world using the numbered options. In this case you would enter 1 + enter to start the game. 

### Errors compiling the game

Try running the following command if there was an error compiling the game:

```
make remake
```

## Uninstalling

If you wish to remove the binary and objects, run the following command:

```
make cleaner
```

or for a full uninstall

```
cd ..; rm -rf starwars
```

## Built With

* [Xcode](https://developer.apple.com/xcode/) - MacOS IDE

## Authors

* **Dustin Jones** - [venGaza](https://github.com/venGaza)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Walt Disney Company
  

