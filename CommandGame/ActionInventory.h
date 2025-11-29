#pragma once
#include <string>
#include "Item.h"
#include "ActionSystem.h"
#include <vector>
#include <algorithm>
#include "Player.h"
#include "consoleCommands.h"

class ActionInventory : public Action {
private:
	Player* player;

	int startX = 0;
	int startY = 0;
public:
	ActionInventory(const std::string& desc, Player* player)
		: Action(desc), player(player) {}

	void setStartPosition(int x, int y) {
		startX = x;
		startY = y;
	}

	void execute(std::string& returnMessage) override {
		SetCursorPosition(startX, startY);
		auto& items = player->getInventory().getItems();
		if (items.empty()) {
			returnMessage = "Your inventory is empty.";
			return;
		}
		std::cout << "Inventory:\n";
		for (const auto& item : items) {
			std::cout << "- " << item->getName() << ": " << item->getDescription() << "\n";
		}


	}

};