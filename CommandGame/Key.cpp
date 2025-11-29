#include "Key.h"

#include <iostream>

Key::Key(const std::string& keyName, const std::string& keyDesc, const std::string& keyID, const std::string& exitDirection)
{
	setName(keyName);
	setDescription(keyDesc);
	this->keyID = keyID;
	this->player = nullptr;
	this->exitDirection = exitDirection;
	itemID = "key";
}

Key::Key(const std::string& keyName, const std::string& keyDesc, const std::string& keyID, const std::string& exitDirection, Player* player)
{
	setName(keyName);
	setDescription(keyDesc);
	this->keyID = keyID;
	this->player = player;
	this->exitDirection = exitDirection;
	itemID = "key";
}

void Key::setPlayer(Player* player) {
	this->player = player;
}

void Key::use(std::string& returnMessage) {
	if (!player) {
		returnMessage = "No player assigned to use the key.";
		return;
	}
	Room* nextRoom = player->getCurrentRoom()->getExit(exitDirection);
	if (!nextRoom) {
		returnMessage = "You can't unlock room from this side";
		return;
	}
	nextRoom->setLocked(false);
	returnMessage = "You used " + itemName + " to unlock the door.";
	player->getInventory().deleteItem(this);
}