#pragma once

#include "Player.h"
#include "Room.h"

class Game {
private:
    Player player;
    Room entrance;
    Room corridor;

public:
    Game();
    void run();
};