#pragma once

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"

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

public:
	Room(string name, string description) : name{ name }, description{ description } {
		northExit = nullptr;
		southExit = nullptr;
		eastExit = nullptr;
		westExit = nullptr;
	}

	string getName() const {
		return name;
	}

	string getDescription() const {
		return description;
	}

	int getID() const {
		return id;
	}

	void setExit(Room* anotherRoom, string direction) {
		direction = toLower(direction);

		if (direction == "north") {
			northExit = anotherRoom;
		}
		else if (direction == "east") {
			eastExit = anotherRoom;
		}
		else if (direction == "south") {
			southExit = anotherRoom;
		}
		else if (direction == "west") {
			westExit = anotherRoom;
		}
		else {
			throw invalid_argument("Invalid direction");
		}
	}
};
