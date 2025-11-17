#include "Room.h"
#include <iostream>
#include <string>
#include <vector>

Room::Room(string name, string description, vector<Action> allActions) : name{ name }, description{ description } {
	northExit = nullptr;
	southExit = nullptr;
	eastExit = nullptr;
	westExit = nullptr;
	this->allActions = allActions;
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

void Room::setExit(Room* anotherRoom, const string direction) {
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

bool Room::isExitExist(const string& direction) {
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
