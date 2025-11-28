#include "ActionTake.h"
#include "ActionToggleFlashlight.h"
#include <iostream>

void ActionTake::execute(string& returnMessage) {
    Room* room = player->getCurrentRoom();

    Item* item = room->getItem();

    if (!item) {
        returnMessage = "There is nothing to take here.";
        return;
    }

    if (!item->getHiddenState()) {
        // Add item to inventory
        player->getInventory().addItem(item);
        returnMessage = "You picked up: " + item->getName();

        if (item->getItemID() == "flashlight") {
			Action* turnOnFlashlight = new ActionToggleFlashlight(player);
			player->addAction(turnOnFlashlight);
        }
        // Remove item from room
        room->removeItem();
	}
    else {
        if (room->getShowHiddenThingsRoom()) {
            // Add item to inventory
            player->getInventory().addItem(item);
            returnMessage = "You picked up: " + item->getName();
            // Remove item from room
            room->removeItem();
        }
        else {
			returnMessage = "It seems there is nothing to take here.";
        }
    }

    
}
