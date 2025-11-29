#include "ActionGo.h"
#include "Player.h"
#include "Room.h"

ActionGo::ActionGo() {
	player = nullptr;
	direction = "";
}

ActionGo::ActionGo(Player* player, string direction, string description)
	: player(player), direction(direction), Action(description) {}

void ActionGo::setDirection(const string& direction) {
	this->direction = direction;
}

string ActionGo::getDirection() const {
	return direction;
}

void ActionGo::execute(string& returnMessage) {
	string casedDirection = toLower(direction);

	Room* currentRoom = player->getCurrentRoom();

	if (currentRoom->isExitExist(casedDirection)) {
		player->moveTo(direction, returnMessage);
		if (returnMessage.empty()) {
			returnMessage = "You moved " + direction + " to "
				+ currentRoom->getExit(casedDirection)->getName() + ".";
		}
	}
	else {
		returnMessage = "You cannot go " + direction + " from here.";
	}
}