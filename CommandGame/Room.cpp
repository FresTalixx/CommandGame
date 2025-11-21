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
	restedItem = "";

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

string Room::getKey() const {
	return requiredKey;
}

void Room::setKey(const string& key) {
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

void Room::setItem(string& item) {
	this->restedItem = item;
}

string Room::getItem() {
	return restedItem;
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


void Room::removeItem() {
	restedItem = "";
}
