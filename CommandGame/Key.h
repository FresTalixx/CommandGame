#pragma once

#include "Player.h"
class Room;
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Key : public Item {
private:
	string keyID;
	Player* player;
	string exitDirection;
public:
	Key(const string& keyName, const string& keyDesc, const string& keyID, const string& exitDirection)
	{
		setName(keyName);
		setDescription(keyDesc);
		this->keyID = keyID;
		this->player = nullptr;
		this->exitDirection = exitDirection;
	}

	Key(const string& keyName, const string& keyDesc, const string& keyID, const string& exitDirection, Player* player)
	{
		setName(keyName);
		setDescription(keyDesc);
		this->keyID = keyID;
		this->player = player;
		this->exitDirection = exitDirection;
	}

	void setPlayer(Player* player) {
		this->player = player;
	}

	void use(string& returnMessage) override {
		if (!player) {
			returnMessage = "No player assigned to use the key.";
			return;
		}
		Room* nextRoom = player->getCurrentRoom()->getExit(exitDirection);

		nextRoom->setLocked(false);
		returnMessage = "You used " + itemName + " to unlock the door.";
		player->getInventory().deleteItem(this);
	}
};
