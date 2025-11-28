#pragma once
#include "Item.h"
#include "Player.h"

class Flashlight : public Item {
private:
	bool isOn;
	Player* player;
	/*int batteryCells;*/
public:
	Flashlight() : Item("Flashlight", "An old flashlight which seems to work"),
		isOn(false), player(nullptr) {}

	Flashlight(const string& name, const string& desc, Player* player) {
		itemName = name;
		itemDescription = desc;
		this->player = player;
		isOn = false;
		itemID = "flashlight";
	}

	void toggle() {
		isOn = !isOn;
	}
	bool getState() const {
		return isOn;
	}

	void use(string& returnMessage) override {
		isOn = true;
		player->getCurrentRoom()->showHiddenThingsRoom(true);
		returnMessage = "You turned on: " + getName();
		isOn = true;
	}

	void stopUsing(string& returnMessage) {
		isOn = false;
		player->getCurrentRoom()->showHiddenThingsRoom(false);
		returnMessage = "You turned off: " + getName();
		isOn = false;
	}

	void onPlayerLeave() override {
		if (isOn) {
			isOn = false;
			player->getCurrentRoom()->showHiddenThingsRoom(false);
		}
	}
};

