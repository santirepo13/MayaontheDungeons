#pragma once

#include <string>

using std::string;

class NPC {
private:
    string npcName;

public:
    NPC(string name);
    string getName();
};