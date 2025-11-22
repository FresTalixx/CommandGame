#include "ActionTake.h"
#include <iostream>

void ActionTake::execute(string& returnMessage) {
    Room* room = player->getCurrentRoom();

    string item = room->getItem();

    if (item.empty()) {
        returnMessage = "There is nothing to take here.";
        return;
    }

    // Add item to inventory
    player->getInventory().addItem(item);
    returnMessage = "You picked up: " + item;

    // Remove item from room
    room->removeItem();
}
