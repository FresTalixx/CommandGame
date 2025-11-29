#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

#include "Room.h"
#include "ActionSystem.h"

using namespace std;

class Player {
private:
	string name;
	int health = 100;
	Inventory inventory;

	Room* currentRoom;

	vector<Action*> possibleActions;

public:
	Player();

	Player(string name, Room* currentRoom);

	string getName() const;

	int getHealth() const;

	Room* getCurrentRoom() const;

	void setCurrentRoom(Room* room);

	void moveTo(const string& direction, string& returnMessage);

	void addAction(Action* action);

	vector<Action*> getPossibleActions() const;

	void removeAction(Action* action);

	Inventory& getInventory();

	/*~Player();*/
};