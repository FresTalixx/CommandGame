#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

#include "Room.h"

using namespace std;

class Player {
private:
	string name;
	int health = 100;
	Inventory inventory;

	Room* currentRoom;

public:
	Player();

	Player(string name, Room* currentRoom);

	string getName() const;

	int getHealth() const;

	Room* getCurrentRoom() const;

	void setCurrentRoom(Room* room);

	void moveTo(const string& direction, string& returnMessage);

	Inventory& getInventory();
};