#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Room.h"

using namespace std;

class Player {
private:
	string name;
	int health = 100;

	Room* currentRoom;

public:
	Player() {
		this->name = "Hero";
		this->currentRoom = nullptr;
	}

	Player(string name, Room* currentRoom) {
		this->name = name;
		this->currentRoom = currentRoom;
	}

	string getName() const {
		return name;
	}

	int getHealth() const {
		return health;
	}

	Room* getCurrentRoom() const {
		return currentRoom;
	}

	void setCurrentRoom(Room* room) {
		this->currentRoom = room;
	}

	void moveTo(string direction) {
		string casedDirection = toLower(direction);
		
		if (currentRoom->isExitExist(casedDirection)) {
			if (casedDirection == "north") {
				currentRoom = currentRoom->changeRoom("north");
			}
			else if (casedDirection == "south") {
				currentRoom = currentRoom->changeRoom("south");
			}
			else if (casedDirection == "east") {
				currentRoom = currentRoom->changeRoom("east");
			}
			else if (casedDirection == "west") {
				currentRoom = currentRoom->changeRoom("west");
			}
			else {
				cout << "Invalid direction!" << endl;
			}
		}
	}
};