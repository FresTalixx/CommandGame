#include "ActionTake.h"
#include <iostream>

void ActionTake::execute(string& returnMessage) {
    Room* room = player->getCurrentRoom();

    Item* item = room->getItem();

    if (!item) {
        returnMessage = "There is nothing to take here.";
        return;
    }

    // Add item to inventory
    player->getInventory().addItem(item);
    returnMessage = "You picked up: " + item->getName();

    // Remove item from room
    room->removeItem();
}
