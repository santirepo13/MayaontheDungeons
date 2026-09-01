#pragma once

#include "Player.h"
#include "Room.h"
#include "Story.h"
#include "NPC/Animals/Rabbit.h"

using std::string;

enum ItemReward {
    NO_REWARD,
    LOCKPICK_REWARD
};

class Game {
private:
    Player player;
    Room entrance;
    Room corridor;
    Room cavities;
    Story story;
    Rabbit rabbit;
    bool gameRunning;

    void examine(Room& room, string objectName, string foundItem, ItemReward reward);
    void leave(Room& currentPlace);
    bool confirmQuit();

public:
    Game();
    void run();
};