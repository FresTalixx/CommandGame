#include "Player.h"
#include <iostream>
#include <string>

Player::Player() {
	this->name = "Hero";
	this->currentRoom = nullptr;
}

Player::Player(string name, Room* currentRoom) {
	this->name = name;
	this->currentRoom = currentRoom;
}

string Player::getName() const {
	return name;
}

int Player::getHealth() const {
	return health;
}

Room* Player::getCurrentRoom() const {
	return currentRoom;
}

void Player::setCurrentRoom(Room* room) {
	this->currentRoom = room;
}

void Player::moveTo(string direction) {
	string casedDirection = toLower(direction);

	if (currentRoom->isExitExist(casedDirection)) {
		if (casedDirection == "north") {
			currentRoom = currentRoom->changeRoom("north");
		}
		else if (casedDirection == "south") {
			currentRoom = currentRoom->changeRoom("south");
		}
		else if (casedDirection == "east") {
			currentRoom = currentRoom->changeRoom("east");
		}
		else if (casedDirection == "west") {
			currentRoom = currentRoom->changeRoom("west");
		}
		else {
			cout << "Invalid direction!" << endl;
		}
	}
}