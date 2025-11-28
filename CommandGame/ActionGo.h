#pragma once
#include <iostream>
#include <string>
#include "ActionSystem.h"

class Player;
class Room;

using namespace std;

class ActionGo : public Action{
private:
	std::string direction;
	Player* player;
public:
	ActionGo();

	ActionGo(Player* player, std::string direction, std::string description);
	
	void setDirection(const std::string& direction);

	

	void execute(std::string& returnMessage) override;
};
