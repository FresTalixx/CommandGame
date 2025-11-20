#pragma once
#include "ActionSystem.h"
#include "Player.h"
#include "Room.h"

class ActionTake : public Action {
private:
    Player* player;

public:
    ActionTake(Player* player)
        : Action("Take item"), player(player) {
    }

    void execute() override;
};
