#include "ActionTake.h"
#include "ActionToggleFlashlight.h"
#include <iostream>

void ActionTake::execute(string& returnMessage) {
    Room* room = player->getCurrentRoom();

    vector<Item*> itemsVisible = room->getVisibleItems();
    vector<Item*> itemsHidden = room->getHiddenItems();

    if (itemsVisible.empty() && itemsHidden.empty()) {
        returnMessage = "It seems there is nothing to take here.";
        return;
    }

    if (!room->getShowHiddenThingsRoom()) {
        if (!itemsVisible.empty()) {
            // Add item to inventory
            player->getInventory().addItem(itemsVisible[0]);
            returnMessage = "You picked up: " + itemsVisible[0]->getName();

            if (itemsVisible[0]->getItemID() == "flashlight") {
                Action* turnOnFlashlight = new ActionToggleFlashlight(player);
                player->addAction(turnOnFlashlight);
            }
            // Remove item from room
            room->removeVisibleItem(itemsVisible[0]);
        }
        else {
            returnMessage = "It seems there is nothing to take here.";
            return;
        }
        
	}
    else {
        if (!itemsVisible.empty()) {
            // Add item to inventory
            player->getInventory().addItem(itemsVisible[0]);
            returnMessage = "You picked up: " + itemsVisible[0]->getName();

            if (itemsVisible[0]->getItemID() == "flashlight") {
                Action* turnOnFlashlight = new ActionToggleFlashlight(player);
                player->addAction(turnOnFlashlight);
            }
            // Remove item from room
            room->removeVisibleItem(itemsVisible[0]);
        }
        else if (!itemsHidden.empty()) {
            // Add item to inventory
            player->getInventory().addItem(itemsHidden[0]);
            returnMessage = "You picked up: " + itemsHidden[0]->getName();
            if (itemsHidden[0]->getItemID() == "flashlight") {
                Action* turnOnFlashlight = new ActionToggleFlashlight(player);
                player->addAction(turnOnFlashlight);
            }
            // Remove item from room
            room->removeHiddenItem(itemsHidden[0]);
		}

        else {
            returnMessage = "It seems there is nothing to take here.";
            return;
        }
    }

    
}
