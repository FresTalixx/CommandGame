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

	string getExit(string direction) const {
		
	}

	void setExit(Room* anotherRoom, const string direction) {
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

	bool isExitExist(const string& direction) {
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
		Room* changeRoom(const string& direction) {
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
	
};
