#pragma once
#include <iostream>
#include <string>
#include "ActionSystem.h"

class Player;
class Room;

using namespace std;

class ActionGo : public Action{
private:
	string direction;
	Player* player;
public:
	ActionGo();

	ActionGo(Player* player, string direction, string description);
	
	void setDirection(const string& direction);

	

	void execute() override;
};
