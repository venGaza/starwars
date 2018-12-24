$(CXX) = g++
CFLAGS = -std=c++0x

output: main.o getInteger.o randomNumber.o validate.o Game.o Items.o Map.o Space.o StartSpace.o Corridor.o DetentionBlock.o CoreReactor.o Infirmary.o Armory.o Door.o LaunchBay.o KyloSpace.o SnokeSpace.o
	g++ main.o getInteger.o randomNumber.o validate.o Game.o Items.o Map.o Space.o StartSpace.o Corridor.o DetentionBlock.o CoreReactor.o Infirmary.o Armory.o Door.o LaunchBay.o KyloSpace.o SnokeSpace.o -o StarWars

main.o: main.cpp
	g++ -c  -std=c++0x main.cpp	

getInteger.o: getInteger.cpp
	g++ -c -std=c++0x getInteger.cpp

randomNumber.o: randomNumber.cpp
	g++ -c -std=c++0x randomNumber.cpp

validate.o: validate.cpp
	g++ -c -std=c++0x validate.cpp

Game.o: Game.cpp
	g++ -c -std=c++0x Game.cpp

Items.o: Items.cpp
	g++ -c -std=c++0x Items.cpp

Map.o: Map.cpp
	g++ -c -std=c++0x Map.cpp

Space.o: Space.cpp
	g++ -c -std=c++0x Space.cpp

StartSpace.o: StartSpace.cpp
	g++ -c -std=c++0x StartSpace.cpp

Corridor.o: Corridor.cpp
	g++ -c -std=c++0x Corridor.cpp

DetentionBlock.o: DetentionBlock.cpp
	g++ -c -std=c++0x DetentionBlock.cpp

CoreReactor.o: CoreReactor.cpp
	g++ -c -std=c++0x CoreReactor.cpp

Infirmary.o: Infirmary.cpp
	g++ -c -std=c++0x Infirmary.cpp

Armory.o: Armory.cpp
	g++ -c -std=c++0x Armory.cpp

Door.o: Door.cpp
	g++ -c -std=c++0x Door.cpp

LaunchBay.o: LaunchBay.cpp
	g++ -c -std=c++0x LaunchBay.cpp

KyloSpace.o: KyloSpace.cpp
	g++ -c -std=c++0x KyloSpace.cpp

SnokeSpace.o: SnokeSpace.cpp
	g++ -c -std=c++0x SnokeSpace.cpp

clean:
	rm *.o StarWars