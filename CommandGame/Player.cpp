#include "Player.h"
#include <iostream>
#include <string>

#include "Key.h"
#include "Flashlight.h"

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
			Key* requiredKey = nextRoom->getKey();

			if (find(items.begin(), items.end(), requiredKey)
				!= items.end()) {

				requiredKey->use(returnMessage);
			}
			else {
				returnMessage = nextRoom->getLockedDescription();
				return;
			}
		}
		
		for (auto item : items) {
			item->onPlayerLeave();
		}
		currentRoom = currentRoom->changeRoom(casedDirection);
	}
}

Inventory& Player::getInventory() {
	return inventory;
}

void Player::addAction(Action* action) {
	possibleActions.push_back(action);
}

vector<Action*> Player::getPossibleActions() const {
	return possibleActions;
}

void Player::removeAction(Action* action) {
	possibleActions.erase(
		remove(possibleActions.begin(), possibleActions.end(), action),
		possibleActions.end()
	);
}