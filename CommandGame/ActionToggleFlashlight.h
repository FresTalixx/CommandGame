#pragma once
#include "ActionSystem.h"
#include "Flashlight.h"

class ActionToggleFlashlight : public Action {
private:
	Player* player;

public:
	ActionToggleFlashlight(Player* player) :
		Action("Toggle flashlight"), player(player) {
	}

	void execute(string& returnMessage) override {
		auto& inventory = player->getInventory().getItems();
		for (auto& item : inventory) {
			if (item->getItemID() == "flashlight") {
				Flashlight* flashlight = dynamic_cast<Flashlight*>(item);

				if (flashlight) {
					flashlight->toggle();
					if (flashlight->getState()) {
						flashlight->use(returnMessage);
					} else {
						flashlight->stopUsing(returnMessage);
					}
					return;
				}
			}
			else {
				returnMessage = "You don't have a flashlight in your inventory.";
			}
		}

	}

};
