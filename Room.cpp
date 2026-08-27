#include "Room.h"

using std::string;

Room::Room(string name, string description) {
    roomName = name;
    roomDescription = description;
    roomHasItem = false;
    roomItemName = "";
}

string Room::getName() { return roomName; }
string Room::getDescription() { return roomDescription; }
bool Room::hasItem() { return roomHasItem; }
string Room::getItemName() { return roomItemName; }

void Room::setItem(string itemName) { roomHasItem = true; roomItemName = itemName; }
void Room::removeItem() { roomHasItem = false; roomItemName = ""; }