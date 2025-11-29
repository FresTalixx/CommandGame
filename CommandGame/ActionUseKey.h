#pragma once
#include <string>
#include "Key.h"
#include "ActionSystem.h"
#include <vector>
#include "Room.h"

class ActionUseKey : public Action {
	private:
	Key* key;
	std::string direction;
	Room* currentRoom;

public:
	ActionUseKey(const std::string& desc, Key* key, const std::string& direction, Room* currentRoom)
		: Action(desc), key(key), direction(direction), currentRoom(currentRoom) {}

	void execute(std::string& returnMessage) override {
		if (currentRoom) {
			if (currentRoom->isRoomLocked(direction)) {
				key->use(returnMessage);
			}
			else {
				returnMessage = "The door is already unlocked.";
			}
		}
		else {
			returnMessage = "No current room assigned.";
		}
	}
};