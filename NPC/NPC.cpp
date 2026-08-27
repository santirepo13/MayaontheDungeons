#include "NPC.h"

using std::string;

NPC::NPC(string name) {
    npcName = name;
}

string NPC::getName() {
    return npcName;
}