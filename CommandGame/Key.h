#pragma once

#include "Player.h"
class Room;
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

class Key : public Item {
private:
	std::string keyID;
	Player* player;
	std::string exitDirection;
public:
	Key(const std::string& keyName, const std::string& keyDesc,
		const std::string& keyID, const std::string& exitDirection);

	Key(const std::string& keyName, const std::string& keyDesc,
		const std::string& keyID, const std::string& exitDirection, Player* player);

	void setPlayer(Player* player);

	void use(std::string& returnMessage) override;
};
