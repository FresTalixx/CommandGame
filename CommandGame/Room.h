#pragma once

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"
#include "ActionSystem.h"
#include "ActionGo.h"

using namespace std;

class Room {
private:
	string name;
	int id;
	string description;

	Room* northExit;
	Room* eastExit;
	Room* southExit;
	Room* westExit;

	vector<Action> allActions;

public:
	Room(string name, string description, vector<Action> actions);

	string getName() const;

	string getDescription() const;

	int getID() const;

	Room* getExit(string direction);

	void setExit(Room* anotherRoom, const string direction);

	bool isExitExist(const string& direction);

	Room* changeRoom(const string& direction);

	vector<Action> actions() {
		return allActions;
	}
};
