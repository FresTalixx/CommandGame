#pragma once

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"
#include "ActionSystem.h"
#include "ActionGo.h"
#include "Inventory.h"

using namespace std;

class Room {
private:
	string name;
	int id;
	string description;

	bool isLocked;
	string requiredKey;
	string lockedDescription;

	string restedItem;

	Room* northExit;
	Room* eastExit;
	Room* southExit;
	Room* westExit;

	vector<Action*> allActions;

public:
	Room(string name, string description, vector<Action*> actions);

	string getName() const;

	string getDescription() const;

	int getID() const;

	Room* getExit(string direction);

	void setExit(Room* anotherRoom, const string& direction);

	bool isExitExist(const string& direction) const;

	Room* changeRoom(const string& direction);

	vector<Action*> actions();

	string getKey() const;

	void setKey(const string& key);

	void setLockedDescription(const string& desc);

	string getLockedDescription();

	void setLocked(bool locked);

	void setItem(string& item);

	string getItem();

	bool isRoomLocked(const string& direction) const;

	void removeItem();
};
