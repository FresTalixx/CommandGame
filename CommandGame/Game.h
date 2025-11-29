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
#include "ActionTake.h"
#include "MapRenderer.h"
#include "Key.h"
#include "Flashlight.h"
#include "ActionToggleFlashlight.h"

#define MAP_HEIGHT 7
#define MAP_WIDTH 25
#define MAP_START_X 20
#define MAP_START_Y 10


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
		ActionGo* goNorth = new ActionGo(&player, "north", "Go North");
		ActionGo* goEast = new ActionGo(&player, "east", "Go East");
		ActionGo* goSouth = new ActionGo(&player, "south", "Go South");
		ActionGo* goWest = new ActionGo(&player, "west", "Go West");
		ActionTake* takeAction= new ActionTake(&player);
		ActionToggleFlashlight* toggleFlashlight = new ActionToggleFlashlight(&player);

		


		vector<Action*> actions = {
			goNorth,
			goEast,
			goSouth,
			goWest,
			takeAction,
		};

		for (auto action : actions) {
			player.addAction(action);
		}

		Room* corridor = new Room("Corridor", "A long, narrow corridor with flickering lights.", actions );
		Room* kitchen = new Room("Kitchen", "A messy kitchen with dirty dishes piled up.", actions);
		Room* library = new Room("Library", "A quiet library filled with dusty books.", actions);
		Room* garden = new Room("Garden", "A beautiful garden with blooming flowers.", actions);
		Room* basement = new Room("Basement", "A dark basement with a musty smell.", actions);
		Room* attic = new Room("Attic", "A cluttered attic filled with old furniture.", actions);
		Room* bedroom = new Room("Bedroom", "A cozy bedroom with a comfortable bed.", actions);
		Room* bathroom = new Room("Bathroom", "A clean bathroom with a shiny mirror.", actions);
		Room* exitRoom = new Room("Exit", "A bright exit leading outside.", actions);

		Key* goldenKeyKitchen = new Key("Golden key", "A shiny golden key.", "golden_key_001", "north", &player);
		Flashlight* flashlight = new Flashlight("Flashlight", "A battery-powered flashlight.", &player);
		Key* goldenKeyBasement = new Key("Basement key", "A rusty basement key.", "basement_key_001", "north", &player);
		// temp
		Key* bedroomKey = new Key("Bedroom key", "A small bedroom key.", "bedroom_key_001", "south", &player);
		Key* atticKey = new Key("Attic key", "An old attic key.", "attic_key_001", "north", &player);

		player.setCurrentRoom(corridor);

		// Item init
		kitchen->addVisibleItem(goldenKeyKitchen);
		exitRoom->setLocked(true);
		exitRoom->setKey(goldenKeyKitchen);
		exitRoom->setLockedDescription("A bright exit leading outside. It seems to be locked. You need a key to open it.");
		
		bathroom->addVisibleItem(flashlight);
		bathroom->addHiddenItem(bedroomKey);
		bathroom->addHiddenItem(atticKey);

		basement->addHiddenItem(goldenKeyBasement); // The basement key is hidden initially

		// room connection
		attic->setLocked(true);
		attic->setKey(goldenKeyBasement);
		attic->setLockedDescription("A cluttered attic filled with old furniture. The door is locked. You need a key to open it.");

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
		string returnedMessage;


		bool hasFlashlight = false;
		Flashlight* flashlight = nullptr;

		while (isRunning) {
			system("cls");

			SetCursorPosition(0, 0);
			SetColor(BLUE, BLACK);
			cout << "You are in: " << player.getCurrentRoom()->getName() << endl;
			cout << player.getCurrentRoom()->getDescription() << endl;

			cout << "Inventory: ";
			for (auto& item : player.getInventory().getItems()) {
				cout << item->getName() << " ";

				if (item->getItemID() == "flashlight") {
					hasFlashlight = true;
					flashlight = dynamic_cast<Flashlight*>(item);
				}
				else {
					hasFlashlight = false;
					flashlight = nullptr;
				}
			}

			MapRenderer map(player.getCurrentRoom(), MAP_HEIGHT, MAP_WIDTH, MAP_START_X, MAP_START_Y);
			map.render();


			SetColor(WHITE, BLACK);
			SetCursorPosition(0, 4);
			cout << returnedMessage << endl;
			returnedMessage = "";

			cout << endl << endl;

			auto actions = player.getPossibleActions();
			vector<string> actionsDescriptions;

			for (auto a : player.getPossibleActions()) {
				actionsDescriptions.push_back(a->getDescription());
			}

			SetCursorPosition(11, 6);
			
			SetColor(DARK_MAGENTA, BLACK);
			if (hasFlashlight) {
				cout << flashlight->getName() << " is ";

				if (flashlight->getState()) {
					SetColor(DARK_YELLOW, BLACK);
					cout << "ON";
				}
				else {
					SetColor(GREY, BLACK);
					cout << "OFF";
				}
			}

			SetColor(GREEN, BLACK);
			
			int choice = menuControl(actionsDescriptions, 0, 10, GREEN, BLACK, RED, BLACK);

			actions[choice - 1]->execute(returnedMessage);
			
			//_getch();

		}
		
	}

	
};

