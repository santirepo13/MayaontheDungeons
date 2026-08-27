#include "Player.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Player::Player(string name) {
    playerName = name;
    playerHealth = 73;
    playerHasLockpick = false;
    playerHasCompass = false;
    playerScore = 0;
}

string Player::getName() { return playerName; }
int Player::getHealth() { return playerHealth; }
bool Player::hasLockpickItem() { return playerHasLockpick; }
bool Player::hasCompassItem() { return playerHasCompass; }
int Player::getScore() { return playerScore; }

void Player::setHealth(int newHealth) { playerHealth = newHealth; }
void Player::heal(int amount) { playerHealth = playerHealth + amount; }
void Player::takeDamage(int damage) { playerHealth = playerHealth - damage; }
void Player::addScore(int points) { playerScore = playerScore + points; }

void Player::pickUpLockpick() {
    playerHasLockpick = true;
    playerScore = playerScore + 1;
}

void Player::pickUpCompass() {
    playerHasCompass = true;
}

void Player::displayStatus() {
    cout << "\n--- " << playerName << " ---" << endl;
    cout << "Salud: " << playerHealth << endl;
    cout << "Puntos: " << playerScore << endl;
    cout << "Objetos: ";
    if (playerHasLockpick) cout << "[Ganzua] ";
    if (playerHasCompass) cout << "[Brujula] ";
    if (!playerHasLockpick && !playerHasCompass) cout << "Ninguno";
    cout << endl;
}