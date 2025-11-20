#include "Player.h"
#include <iostream>
#include <string>

Player::Player() {
	this->name = "Hero";
	this->currentRoom = nullptr;
	this->health = 100;
}

Player::Player(string name, Room* currentRoom) {
	this->name = name;
	this->currentRoom = currentRoom;
	this->health = 100;
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
		if (currentRoom->isRoomLocked()) {
			string requiredKey = currentRoom->getKey();
			if (find(inventory.getItems().begin(), inventory.getItems().end(), requiredKey)
				!= inventory.getItems().end()) {

				currentRoom->setLocked(false);
			}
			else {
				cout << currentRoom->getLockedDescription();
				return;
			}
		}
		currentRoom = currentRoom->changeRoom(casedDirection);
	}
}

Inventory Player::getInventory() {
	return inventory;
}