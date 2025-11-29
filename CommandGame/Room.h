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

	vector<Item*> visibleItems;
	vector<Item*> hiddenItems;

	Room* northExit;
	bool isNorthExitHidden = false;
	Room* eastExit;
	bool isEastExitHidden = false;
	Room* southExit;
	bool isSouthExitHidden = false;
	Room* westExit;
	bool isWestExitHidden = false;
	
	bool isVisited;
	bool showHiddenThings = false;

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

	bool isRoomLocked(const string& direction) const;

	void setVisited(bool isVisited);

	bool getIsVisited() const;

	void setHiddenExit();

	void getHiddenExit() const;

	void addHiddenItem(Item* item);

	vector<Item*> getHiddenItems() const;

	void removeHiddenItem(Item* item);

	void addVisibleItem(Item* item);

	vector<Item*> getVisibleItems() const;

	void removeVisibleItem(Item* item);

	void showHiddenThingsRoom(const bool& state);

	bool getShowHiddenThingsRoom() const;

	//~Room();
};
