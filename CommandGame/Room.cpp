#include "Room.h"
#include <iostream>
#include <string>
#include <vector>

Room::Room(string name, string description, vector<Action*> allActions) : name{ name }, description{ description } {
	northExit = nullptr;
	southExit = nullptr;
	eastExit = nullptr;
	westExit = nullptr;
	this->allActions = allActions;
	isLocked = false;
	isVisited = false;
}

string Room::getName() const {
	return name;
}

string Room::getDescription() const {
	return description;
}

int Room::getID() const {
	return id;
}

Room* Room::getExit(string direction) {
	string casedDirection = toLower(direction);

	if (casedDirection == "north") {
		return this->northExit;
	}
	else if (casedDirection == "east") {
		return this->eastExit;
	}
	else if (casedDirection == "south") {
		return this->southExit;
	}
	else if (casedDirection == "west") {
		return this->westExit;
	}
	else {
		throw invalid_argument("Invalid direction");
	}
}

void Room::setExit(Room* anotherRoom, const string& direction) {
	string casedDirection = toLower(direction);

	if (casedDirection == "north") {
		northExit = anotherRoom;
	}
	else if (casedDirection == "east") {
		eastExit = anotherRoom;
	}
	else if (casedDirection == "south") {
		southExit = anotherRoom;
	}
	else if (casedDirection == "west") {
		westExit = anotherRoom;
	}
	else {
		throw invalid_argument("Invalid direction");
	}
}

bool Room::isExitExist(const string& direction) const  {
	string casedDirection = toLower(direction);

	if (casedDirection == "north") {
		return northExit;
	}
	else if (casedDirection == "east") {
		return eastExit;
	}
	else if (casedDirection == "south") {
		return southExit;
	}
	else if (casedDirection == "west") {
		return westExit;
	}
	else {
		throw invalid_argument("Invalid direction");
	}
}
Room* Room::changeRoom(const string& direction) {
	string casedDirection = toLower(direction);
	if (casedDirection == "north") {
		return northExit;
	}
	else if (casedDirection == "east") {
		return eastExit;
	}
	else if (casedDirection == "south") {
		return southExit;
	}
	else if (casedDirection == "west") {
		return westExit;
	}
	else {
		throw invalid_argument("Invalid direction");
	}
}

vector<Action*> Room::actions() {
	return allActions;
}

Key* Room::getKey() const {
	return requiredKey;
}

void Room::setKey(Key* key) {
	requiredKey = key;
}

void Room::setLockedDescription(const string& desc) {
	lockedDescription = desc;
}

string Room::getLockedDescription() {
	return lockedDescription;
}

void Room::setLocked(bool locked) {
	isLocked = locked;
}

bool Room::isRoomLocked(const string& direction) const {
	string casedDirection = toLower(direction);

	if (!isExitExist(casedDirection)) {
		return false;
	}

	Room* nextRoom = nullptr;

	if (casedDirection == "north") nextRoom = northExit;
	else if (casedDirection == "south") nextRoom = southExit;
	else if (casedDirection == "east")  nextRoom = eastExit;
	else if (casedDirection == "west")  nextRoom = westExit;

	if (nextRoom == nullptr)
		return false;

	return nextRoom->isLocked;
}

void Room::setVisited(bool isVisited) {
	this->isVisited = isVisited;
}

bool Room::getIsVisited() const {
	return isVisited;
}

void Room::showHiddenThingsRoom(const bool& state) {
	showHiddenThings = state;
}

bool Room::getShowHiddenThingsRoom() const {
	return showHiddenThings;
}

void Room::addHiddenItem(Item* item) {
	hiddenItems.push_back(item);
}

vector<Item*> Room::getHiddenItems() const {
	return hiddenItems;
}

void Room::removeHiddenItem(Item* itemToRemove) {
	auto it = std::find(hiddenItems.begin(), hiddenItems.end(), itemToRemove);
	if (it != hiddenItems.end()) {
		hiddenItems.erase(it);
	}
}


void Room::addVisibleItem(Item* item) {
	visibleItems.push_back(item);
}

vector<Item*> Room::getVisibleItems() const {
	return visibleItems;
}

void Room::removeVisibleItem(Item* itemToRemove) {
	auto it = std::find(visibleItems.begin(), visibleItems.end(), itemToRemove);
	if (it != visibleItems.end()) {
		visibleItems.erase(it);
	}
}
