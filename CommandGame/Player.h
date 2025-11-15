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
};