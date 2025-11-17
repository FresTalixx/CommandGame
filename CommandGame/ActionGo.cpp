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

void ActionGo::execute() {
	Room* currentRoom = player->getCurrentRoom();
	if (currentRoom->isExitExist(toLower(direction))) {
		Room* nextRoom = currentRoom->getExit(toLower(direction));
		player->setCurrentRoom(nextRoom);
		cout << "You moved " << direction << " to "
			<< nextRoom->getName() << "." << endl;
	}
	else {
		cout << "You cannot go " << direction << " from here." << endl;
	}
}