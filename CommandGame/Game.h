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

#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77


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

		Room* armoury = new Room("Armoury", "A long dusty armoury with a lot of armour all around.", actions);
		Room* ashwell = new Room("Ashwell", "An old ashwell with a creaky wooden cover.", actions);
		Room* diningRoom = new Room("Dining Room", "A grand dining room with a large table set for a feast.", actions);
		Room* hall = new Room("Hall", "A spacious hall with portraits lining the walls.", actions);
		Room* lounge = new Room("Lounge", "A comfortable lounge with plush sofas and a fireplace.", actions);
		Room* study = new Room("Study", "A quiet study filled with bookshelves and a large desk.", actions);
		Room* pantry = new Room("Pantry", "A small pantry stocked with food and supplies.", actions);
		Room* conservatory = new Room("Conservatory", "A bright conservatory filled with plants and sunlight.", actions);
		Room* ballroom = new Room("Ballroom", "An elegant ballroom with a polished dance floor and chandeliers.", actions);
		Room* gallery = new Room("Gallery", "An art gallery showcasing beautiful paintings and sculptures.", actions);
		Room* musicRoom = new Room("Music Room", "A music room filled with various instruments and sheet music.", actions);
		Room* nursery = new Room("Nursery", "A cheerful nursery decorated with toys and colorful furniture.", actions);
		Room* smokingRoom = new Room("Smoking Room", "A cozy smoking room with leather chairs and a humidor.", actions);
		Room* veranda = new Room("Veranda", "A charming veranda overlooking the garden.", actions);
		Room* secretRoom = new Room("Secret Room", "A hidden room filled with treasures.", actions);

		Room* exitRoom = new Room("Exit", "A bright exit leading outside.", actions);

		// Initialising items
		Flashlight* flashlight = new Flashlight("Flashlight", "A battery-powered flashlight.", &player);
		Key* redKeyAttic = new Key("Red key", "A rusty red key.", "attic_key_001", "north", &player);
		Key* blueKeyBathroom = new Key("Blue key", "A blue key.", "veranda_key_001", "east", &player);
		Key* goldenKeyExit = new Key("Shiny key", "A shiny golden key.", "exit_key_001", "north", &player);
		Key* nurseryKeyGreen = new Key("Greeb key", "A greenish key", "nursery_key_001", "south", &player);
		Key* hallKey = new Key("Hall key", "An old hall key.", "hall_key_001", "north", &player);
		Key* basementKeyGray = new Key("Gray key", "A pretty creepy key", "basement_key_001", "north", &player);

		player.setCurrentRoom(corridor);

		// Item init

		kitchen->addHiddenItem(goldenKeyExit);
		exitRoom->setLocked(true);
		exitRoom->setKey(goldenKeyExit);
		exitRoom->setLockedDescription("A bright exit leading outside. It seems to be locked with a golden lock. You need a key to open it.");
		
		secretRoom->addVisibleItem(goldenKeyExit);
		secretRoom->addHiddenItem(basementKeyGray);
		exitRoom->setLocked(true);
		exitRoom->setKey(goldenKeyExit);
		exitRoom->setLockedDescription("A bright exit leading outside. It seems to be locked with a golden lock. You need a key to open it.");
		
		exitRoom->addVisibleItem(basementKeyGray);
		basement->setLocked(true);
		basement->setKey(basementKeyGray);
		basement->setLockedDescription("A dark basement with a musty smell. The door is locked with a gray lock. You need a key to open it.");

		bathroom->addVisibleItem(flashlight);
		
		basement->addHiddenItem(redKeyAttic); // The basement key is hidden initially
		attic->setLocked(true);
		attic->setKey(redKeyAttic);
		attic->setLockedDescription("A cluttered attic filled with old furniture. The door is locked with a red lock. You need a key to open it.");

		bathroom->addHiddenItem(blueKeyBathroom);
		veranda->setLocked(true);
		veranda->setKey(blueKeyBathroom);
		veranda->setLockedDescription("A charming veranda overlooking the garden. The door is locked with a blue lock. You need a key to open it.");

		ashwell->addHiddenItem(nurseryKeyGreen);
		nursery->setLocked(true);
		nursery->setKey(nurseryKeyGreen);
		nursery->setLockedDescription("A cheerful nursery decorated with toys and colorful furniture. The door is locked with a green lock. You need a key to open it.");

		musicRoom->addVisibleItem(hallKey);
		hall->setLocked(true);
		hall->setKey(hallKey);
		hall->setLockedDescription("A spacious hall with portraits lining the walls. The door is locked with a hall lock. You need a key to open it.");



		//connecting rooms
		corridor->setExit(kitchen, "east");
		corridor->setExit(library, "west");
		corridor->setExit(hall, "north");

		kitchen->setExit(corridor, "west");
		kitchen->setExit(pantry, "south");
		kitchen->setExit(garden, "east");
		kitchen->setExit(attic, "north");

		attic->setExit(kitchen, "south");
		attic->setExit(study, "east");

		garden->setExit(kitchen, "west");
		garden->setExit(smokingRoom, "east");

		smokingRoom->setExit(garden, "west");

		pantry->setExit(kitchen, "north");

		study->setExit(attic, "west");
		study->setExit(diningRoom, "north");


		hall->setExit(corridor, "south");
		hall->setExit(diningRoom, "east");
		hall->setExit(gallery, "north");

		diningRoom->setExit(hall, "west");
		diningRoom->setExit(study, "south");
		diningRoom->setExit(secretRoom, "north");

		secretRoom->setExit(diningRoom, "south");
		secretRoom->setExit(gallery, "west");

		gallery->setExit(hall, "south");
		gallery->setExit(secretRoom, "east");
		gallery->setExit(armoury, "north");
		gallery->setExit(lounge, "west");

		armoury->setExit(gallery, "south");

		lounge->setExit(gallery, "east");
		lounge->setExit(ashwell, "north");

		ashwell->setExit(lounge, "south");


		library->setExit(corridor, "east");
		library->setExit(bedroom, "south");
		library->setExit(bathroom, "west");
		library->setExit(basement, "north");

		bedroom->setExit(library, "north");
		bedroom->setExit(veranda, "east");
		bedroom->setExit(ballroom, "west");

		veranda->setExit(bedroom, "west");

		ballroom->setExit(bathroom, "north");
		ballroom->setExit(bedroom, "east");
		ballroom->setExit(nursery, "south");

		nursery->setExit(ballroom, "north");

		bathroom->setExit(library, "east");
		bathroom->setExit(ballroom, "south");
		bathroom->setExit(conservatory, "west");
		bathroom->setExit(musicRoom, "north");

		conservatory->setExit(bathroom, "east");

		musicRoom->setExit(bathroom, "south");

		basement->setExit(library, "south");
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
			
			/*int choice = menuControl(actionsDescriptions, 0, 10, GREEN, BLACK, RED, BLACK);

			actions[choice - 1]->execute(returnedMessage);*/

			keyMovement(returnedMessage);

			//WIN CONDITION
			if (player.getCurrentRoom()->getName() == "Exit") {
				system("cls");
				SetColor(YELLOW, BLACK);
				cout << "Congratulations! You have found the exit and escaped the house!\n";
				cout << "Thank you for playing House Explorer!\n";
				isRunning = false;
			}
			
			//_getch();

		}
	}

	bool keyMovement(std::string& returnedMessage) {
		ShowConsoleCursor(false);
		int key = _getch();

		// handle extended keys (arrows)
		if (key == 224) {
			key = _getch(); // actual keycode

			string direction;

			if (key == UP_ARROW_KEY)        direction = "north";
			else if (key == DOWN_ARROW_KEY) direction = "south";
			else if (key == LEFT_ARROW_KEY) direction = "west";
			else if (key == RIGHT_ARROW_KEY) direction = "east";
			else return false;

			// find matching action
			for (auto action : player.getPossibleActions()) {
				ActionGo* go = dynamic_cast<ActionGo*>(action);
				if (go->getDirection() == direction) {
					go->execute(returnedMessage);
					return true;
				}
			}
		}

		// non-arrow keys:
		if (key == 'f' || key == 'F') {
			// toggle flashlight
			for (auto action : player.getPossibleActions()) {
				ActionToggleFlashlight* tf = dynamic_cast<ActionToggleFlashlight*>(action);
				if (tf) {
					tf->execute(returnedMessage);
					return true;
				}
			}
		}

		if (key == 't' || key == 'T') {
			// take item
			for (auto action : player.getPossibleActions()) {
				ActionTake* take = dynamic_cast<ActionTake*>(action);
				if (take) {
					take->execute(returnedMessage);
					return true;
				}
			}
		}

		if (key == 'q' || key == 'Q') {
			// quit game
			isRunning = false;
			return true;
		}

		return false;
	}


	
};

