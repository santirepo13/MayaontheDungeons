#include "Room.h"

using std::string;

Room::Room(string name, string description) {
    roomName = name;
    roomDescription = description;
    itemCount = 0;
}

string Room::getName() { return roomName; }
string Room::getDescription() { return roomDescription; }

int Room::findItem(string itemName) {
    int itemIndex = -1;
    int i = 0;

    while (i < itemCount && itemIndex == -1) {
        if (roomItems[i] == itemName) {
            itemIndex = i;
        }
        else {
            i++;
        }
    }

    return itemIndex;
}

bool Room::addItem(string itemName) {
    if (itemCount >= MAX_ITEMS) {
        return false;
    }
    else {
        roomItems[itemCount] = itemName;
        itemExamined[itemCount] = false;
        itemCount++;

        return true;
    }
}

bool Room::hasItem(string itemName) {
    if (findItem(itemName) != -1) {
        return true;
    }
    else {
        return false;
    }
}

bool Room::removeItem(string itemName) {
    int itemIndex = findItem(itemName);

    if (itemIndex == -1) {
        return false;
    }
    else {
        for (int i = itemIndex; i < itemCount - 1; i++) {
            roomItems[i] = roomItems[i + 1];
            itemExamined[i] = itemExamined[i + 1];
        }

        itemCount--;
        roomItems[itemCount] = "";
        itemExamined[itemCount] = false;

        return true;
    }
}

bool Room::hasBeenExamined(string itemName) {
    int itemIndex = findItem(itemName);

    if (itemIndex == -1) {
        return false;
    }
    else {
        return itemExamined[itemIndex];
    }
}

bool Room::markAsExamined(string itemName) {
    int itemIndex = findItem(itemName);

    if (itemIndex == -1) {
        return false;
    }
    else {
        itemExamined[itemIndex] = true;
        return true;
    }
}