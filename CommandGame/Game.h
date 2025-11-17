#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

#include "consoleCommands.h"
#include "Player.h"
#include "Room.h"
#include "Utils.h"
#include "ActionSystem.h"
#include "ActionGo.h"
#include "keyboardMenuControll.h"


using namespace std;

class Game {
private:
	Player player;
	bool isRunning;

public:
	Game() {
		isRunning = true;
	}

	void init() {
		//initialising player
		player = Player("Hero", nullptr);


		/* initialising rooms*/
		ActionGo goNorth(&player, "north", "Go North");
		ActionGo goEast(&player, "east", "Go East");
		ActionGo goSouth(&player, "south", "Go South");
		ActionGo goWest(&player, "west", "Go West");

		vector<Action> actions = {
			goNorth,
			goEast,
			goSouth,
			goWest
		};

		Room* corridor = new Room("Corridor", "A long, narrow corridor with flickering lights.", actions);
		Room* kitchen = new Room("Kitchen", "A messy kitchen with dirty dishes piled up.", actions);
		Room* library = new Room("Library", "A quiet library filled with dusty books.", actions);
		Room* garden = new Room("Garden", "A beautiful garden with blooming flowers.", actions);
		Room* basement = new Room("Basement", "A dark basement with a musty smell.", actions);
		Room* attic = new Room("Attic", "A cluttered attic filled with old furniture.", actions);
		Room* bedroom = new Room("Bedroom", "A cozy bedroom with a comfortable bed.", actions);
		Room* bathroom = new Room("Bathroom", "A clean bathroom with a shiny mirror.", actions);
		Room* exitRoom = new Room("Exit", "A bright exit leading outside.", actions);


		player.setCurrentRoom(corridor);

		//connecting rooms
		corridor->setExit(kitchen, "east");
		kitchen->setExit(corridor, "west");

		kitchen->setExit(garden, "east");
		garden->setExit(kitchen, "west");

		kitchen->setExit(attic, "north");
		attic->setExit(kitchen, "south");


		corridor->setExit(library, "west");
		library->setExit(corridor, "east");

		library->setExit(bedroom, "south");
		bedroom->setExit(library, "north");

		library->setExit(basement, "north");
		basement->setExit(library, "south");

		library->setExit(bathroom, "west");
		bathroom->setExit(library, "east");


		basement->setExit(exitRoom, "north");

	}

	void start() {
		init();

		SetColor(GREEN, BLACK);
		cout << "Welcome to House Explorer!\n";
		cout << "You find yourself in a mysterious house. Explore the rooms and find your way out!\n\n";
		SetColor(WHITE, BLACK);
		cout << "Press any key to start your adventure...\n";
		_getch();

		gameloop();
	}

	void gameloop() {
		string inputString;
		while (isRunning) {
			system("cls");

			SetCursorPosition(0, 0);
			SetColor(BLUE, BLACK);
			cout << "You are in: " << player.getCurrentRoom()->getName() << endl;
			cout << player.getCurrentRoom()->getDescription() << endl;

			cout << endl << endl;

			auto actions = player.getCurrentRoom()->actions();
			vector<string> actionsDescriptions;

			for (auto a : actions) {
				actionsDescriptions.push_back(a.getDescription());
			}

			SetColor(GREEN, BLACK);
			
			int choice = menuControl(actionsDescriptions, 0, 5, GREEN, BLACK, RED, BLACK);

			/*cout << "Enter your command: \n";
			getline(cin, inputString);
			*/
			handleInput(actionsDescriptions[choice - 1]);

		}
		
	}

	void handleInput(string& inputString) {
		vector<string> splittedString = split(inputString, " ");

		if (toLower(splittedString[0]) == "go") {
			string direction = toLower(splittedString[1]);

			if (direction == "north") {
				player.moveTo("north");
			}
			else if (direction == "south") {
				player.moveTo("south");
			}
			else if (direction == "east") {
				player.moveTo("east");
			}
			else if (direction == "west") {
				player.moveTo("west");
			}
			else {
				SetColor(RED, BLACK);
				cout << "Invalid direction! Use north, south, east, or west.\n";
				SetColor(WHITE, BLACK);
				cout << "Press any key to continue...\n";
				_getch();
			}
		}
	}
};

