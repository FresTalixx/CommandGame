#include "ActionTake.h"
#include <iostream>

void ActionTake::execute() {
    Room* room = player->getCurrentRoom();

    string item = room->getItem();

    if (item.empty()) {
        cout << "There is nothing to take here.\n";
        return;
    }

    // Add item to inventory
    player->getInventory().addItem(item);
    cout << "You picked up: " << item << "\n";

    // Remove item from room
    room->removeItem();
}
