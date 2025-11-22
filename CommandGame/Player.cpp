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

void Player::moveTo(const string& direction, string& returnMessage) {
	string casedDirection = toLower(direction);
	auto& items = inventory.getItems();

	if (currentRoom->isExitExist(casedDirection)) {
		Room* nextRoom = currentRoom->getExit(casedDirection);

		if (currentRoom->isRoomLocked(casedDirection)) {
			string requiredKey = nextRoom->getKey();

			if (find(items.begin(), items.end(), requiredKey)
				!= items.end()) {

				nextRoom->setLocked(false);
				returnMessage = "You used " + requiredKey + " to unlock the door.";
				Player::getInventory().deleteItem(requiredKey);
			}
			else {
				returnMessage = nextRoom->getLockedDescription();
				return;
			}
		}
		currentRoom = currentRoom->changeRoom(casedDirection);
	}
}

Inventory& Player::getInventory() {
	return inventory;
}