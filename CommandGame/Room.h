#pragma once

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Utils.h"
#include "ActionSystem.h"
#include "ActionGo.h"
#include "Inventory.h"
#include "Item.h"

class Key;

using namespace std;

class Room {
private:
	string name;
	int id;
	string description;

	bool isLocked;
	Key* requiredKey;
	string lockedDescription;

	Item* restedItem;

	Room* northExit;
	Room* eastExit;
	Room* southExit;
	Room* westExit;
	
	bool isVisited;

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

	Key* getKey() const;

	void setKey(Key* key);

	void setLockedDescription(const string& desc);

	string getLockedDescription();

	void setLocked(bool locked);

	void setItem(Item* item);

	Item* getItem();

	bool isRoomLocked(const string& direction) const;

	void removeItem();

	void setVisited(bool isVisited);

	bool getIsVisited() const;
};
