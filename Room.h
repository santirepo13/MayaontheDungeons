#pragma once

#include <string>

using std::string;

class Room {
private:
    string roomName;
    string roomDescription;
    bool roomHasItem;
    string roomItemName;

public:
    Room(string name, string description);

    string getName();
    string getDescription();
    bool hasItem();
    string getItemName();

    void setItem(string itemName);
    void removeItem();
};