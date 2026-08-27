#pragma once

#include <string>

using std::string;

class Room {
private:
    string roomName;
    string roomDescription;

    static const int MAX_ITEMS = 10;
    string roomItems[MAX_ITEMS];
    bool itemExamined[MAX_ITEMS];
    int itemCount;

    int findItem(string itemName);

public:
    Room(string name, string description);

    string getName();
    string getDescription();

    bool addItem(string itemName);
    bool hasItem(string itemName);
    bool removeItem(string itemName);

    bool hasBeenExamined(string itemName);
    bool markAsExamined(string itemName);
};