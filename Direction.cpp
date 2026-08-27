#include "Direction.h"

using std::string;

Direction::Direction(char key) {
    directionKey = key;
    if (key == 'W' || key == 'w') {
        directionName = "Arriba";
    }
    else if (key == 'S' || key == 's') {
        directionName = "Abajo";
    }
    else if (key == 'A' || key == 'a') {
        directionName = "Izquierda";
    }
    else if (key == 'D' || key == 'd') {
        directionName = "Derecha";
    }
    else {
        directionName = "Invalida";
    }
}

char Direction::getKey() { return directionKey; }
string Direction::getName() { return directionName; }
bool Direction::isValid() { return directionName != "Invalida"; }