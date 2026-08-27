#pragma once

#include <string>

using std::string;

class Player {
private:
    string playerName;
    int playerHealth;
    bool playerHasLockpick;
    bool playerHasCompass;
    int playerScore;

public:
    Player(string name);

    string getName();
    int getHealth();
    bool hasLockpickItem();
    bool hasCompassItem();
    int getScore();

    void setHealth(int newHealth);
    void heal(int amount);
    void takeDamage(int damage);
    void addScore(int points);
    void pickUpLockpick();
    void pickUpCompass();
    void displayStatus();
};