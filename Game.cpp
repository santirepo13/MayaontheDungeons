#include "Game.h"
#include "Direction.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game() :
    player("Profesora Carter"),
    entrance("Sala de Entrada", "Una construccion abandonada que parece extenderse en linea recta."),
    corridor("Corredor de la Construccion", "El pasillo principal esta cubierto de polvo y restos de materiales."),
    cavities("Cavidades Estrechas", "Espacios angostos entre las paredes de la construccion."),
    rabbit("Conejo"),
    gameRunning(true) {
    corridor.addItem("Cajon");
    corridor.addItem("Estante");
    corridor.addItem("Puerta");
    corridor.addItem("una ganzua oxidada");
}

bool Game::confirmQuit() {
    char answer;

    do {
        cout << "¿Deseas salir del juego? (S/N): ";
        cin >> answer;

        if (answer == 'S' || answer == 's') {
            return true;
        }
        else if (answer == 'N' || answer == 'n') {
            return false;
        }
        else {
            cout << "Respuesta invalida. Escribe S o N." << endl;
        }
    } while (true);
}

void Game::examine(Room& room, string objectName, string foundItem, ItemReward reward) {
    if (!room.hasItem(objectName)) {
        story.show(ACTION_FAILED, "Ese objeto no se encuentra aqui.");
    }
    else if (room.hasBeenExamined(objectName)) {
        story.show(OBJECT_ALREADY_EXAMINED, objectName);
    }
    else if (foundItem == "") {
        story.show(OBJECT_CLOSED, objectName);
        room.markAsExamined(objectName);
    }
    else if (room.hasItem(foundItem)) {
        story.show(OBJECT_EXAMINED, objectName);
        story.show(ITEM_FOUND, foundItem);

        if (reward == LOCKPICK_REWARD) {
            player.pickUpLockpick();
        }

        room.removeItem(foundItem);

        story.show(ITEM_COLLECTED, foundItem);
        room.markAsExamined(objectName);
    }
    else {
        story.show(NOTHING_FOUND, objectName);
        room.markAsExamined(objectName);
    }
}

void Game::leave(Room& currentPlace) {
    story.show(LEAVING_PLACE, currentPlace.getName());
}

void Game::run() {
    story.show(INTRODUCTION);

    bool atEntrance = true;

    while (gameRunning && atEntrance) {
        cout << "\n=== " << entrance.getName() << " ===" << endl;
        cout << entrance.getDescription() << endl;
        cout << "\nLista de movimientos:" << endl;
        cout << "  W - Entrar al corredor de la construccion" << endl;
        cout << "  Q - Salir del juego" << endl;
        cout << "\nMovimiento: ";

        char entranceChoice;
        cin >> entranceChoice;

        if (entranceChoice == 'Q' || entranceChoice == 'q') {
            if (confirmQuit()) {
                gameRunning = false;
            }
            else {
                story.show(GAME_CONTINUED);
            }
        }
        else if (entranceChoice == 'W' || entranceChoice == 'w') {
            story.show(LOCATION_ENTERED, corridor.getName());
            atEntrance = false;
        }
        else {
            story.show(ACTION_FAILED, "Movimiento invalido. Maya permanece en la entrada.");
        }
    }

    bool chamberAccessible = true;

    while (gameRunning && chamberAccessible) {
        cout << "\n=== " << corridor.getName() << " ===" << endl;
        cout << corridor.getDescription() << endl;
        cout << "\nLista de movimientos:" << endl;
        cout << "  W - Avanzar por la construccion" << endl;
        cout << "  S - Entrar en las cavidades estrechas" << endl;
        cout << "  D - Ir hacia la puerta" << endl;
        cout << "  A - Ir hacia el cajon" << endl;
        cout << "  Q - Salir del juego" << endl;
        cout << "\nMovimiento: ";

        char corridorChoice;
        cin >> corridorChoice;

        if (corridorChoice == 'Q' || corridorChoice == 'q') {
            if (confirmQuit()) {
                gameRunning = false;
            }
            else {
                story.show(GAME_CONTINUED);
            }
            continue;
        }

        Direction direction(corridorChoice);

        if (!direction.isValid()) {
            story.show(ACTION_FAILED, "Direccion invalida.");
        }
        else {
            switch (direction.getKey()) {
            case 'W':
            case 'w':
                if (!player.hasCompassItem()) {
                    story.show(ITEM_FOUND, "una brujula");
                    player.pickUpCompass();
                    story.show(ITEM_COLLECTED, "una brujula");
                }
                else {
                    story.show(NOTHING_FOUND, "el camino superior");
                }
                break;

            case 'S':
            case 's': {
                story.show(LOCATION_ENTERED, cavities.getName());
                story.show(CAVITIES_ENTERED);
                player.takeDamage(5);
                story.show(DAMAGE_RECEIVED, "5");

                bool insideCavities = true;

                while (gameRunning && insideCavities) {
                    cout << "\n=== " << cavities.getName() << " ===" << endl;
                    cout << cavities.getDescription() << endl;
                    cout << "\nLista de movimientos:" << endl;
                    cout << "  S - Continuar a traves de las cavidades" << endl;
                    cout << "  Q - Salir del juego" << endl;
                    cout << "\nMovimiento: ";

                    char cavityChoice;
                    cin >> cavityChoice;

                    if (cavityChoice == 'Q' || cavityChoice == 'q') {
                        if (confirmQuit()) {
                            gameRunning = false;
                        }
                        else {
                            story.show(GAME_CONTINUED);
                        }
                    }
                    else if (cavityChoice == 'S' || cavityChoice == 's') {
                        story.show(CAVITIES_EXITED);
                        leave(cavities);
                        story.show(CHARACTER_FOUND, rabbit.getName());
                        story.show(RABBIT_INJURED);
                        insideCavities = false;
                        chamberAccessible = false;
                    }
                    else {
                        story.show(ACTION_FAILED, "Movimiento invalido. Las cavidades solo permiten avanzar.");
                    }
                }
                break;
            }

            case 'D':
            case 'd':
                story.show(OBJECT_LOCKED, "la puerta");
                break;

            case 'A':
            case 'a': {
                story.show(DRAWER_AREA_ENTERED);
                bool inDrawerArea = true;

                while (gameRunning && inDrawerArea) {
                    cout << "\n=== Zona del cajon ===" << endl;
                    cout << "  E - Examinar el cajon" << endl;
                    cout << "  A - Continuar hacia el estante" << endl;
                    cout << "  S - Regresar al corredor" << endl;
                    cout << "  Q - Salir del juego" << endl;
                    cout << "\nMovimiento: ";

                    char drawerChoice;
                    cin >> drawerChoice;

                    if (drawerChoice == 'Q' || drawerChoice == 'q') {
                        if (confirmQuit()) {
                            gameRunning = false;
                        }
                        else {
                            story.show(GAME_CONTINUED);
                        }
                    }
                    else if (drawerChoice == 'E' || drawerChoice == 'e') {
                        examine(corridor, "Cajon", "", NO_REWARD);
                    }
                    else if (drawerChoice == 'A' || drawerChoice == 'a') {
                        story.show(SHELF_AREA_ENTERED);
                        bool atShelf = true;

                        while (gameRunning && atShelf) {
                            cout << "\n=== Zona del estante ===" << endl;
                            cout << "  E - Examinar el estante" << endl;
                            cout << "  S - Regresar al cajon" << endl;
                            cout << "  Q - Salir del juego" << endl;
                            cout << "\nMovimiento: ";

                            char shelfChoice;
                            cin >> shelfChoice;

                            if (shelfChoice == 'Q' || shelfChoice == 'q') {
                                if (confirmQuit()) {
                                    gameRunning = false;
                                }
                                else {
                                    story.show(GAME_CONTINUED);
                                }
                            }
                            else if (shelfChoice == 'E' || shelfChoice == 'e') {
                                examine(corridor, "Estante", "una ganzua oxidada", LOCKPICK_REWARD);
                            }
                            else if (shelfChoice == 'S' || shelfChoice == 's') {
                                story.show(DRAWER_AREA_RETURNED);
                                atShelf = false;
                            }
                            else {
                                story.show(ACTION_FAILED, "Movimiento invalido.");
                            }
                        }
                    }
                    else if (drawerChoice == 'S' || drawerChoice == 's') {
                        story.show(CORRIDOR_RETURNED);
                        inDrawerArea = false;
                    }
                    else {
                        story.show(ACTION_FAILED, "Movimiento invalido.");
                    }
                }
                break;
            }
        }
        }
    }

    while (gameRunning && !chamberAccessible) {
        cout << "\n=== Despues de la salida ===" << endl;
        cout << "\nLista de movimientos:" << endl;
        cout << "  Q - Salir del juego" << endl;
        cout << "\nMovimiento: ";

        char outsideChoice;
        cin >> outsideChoice;

        if (outsideChoice == 'Q' || outsideChoice == 'q') {
            if (confirmQuit()) {
                gameRunning = false;
            }
            else {
                story.show(GAME_CONTINUED);
            }
        }
        else {
            story.show(MOVEMENT_UNAVAILABLE);
        }
    }

    story.show(ENDING);
    cout << "Puntos Finales: " << player.getScore() << endl;
    cout << "Salud Final: " << player.getHealth() << endl;
    cout << "Objetos: ";
    if (player.hasLockpickItem()) cout << "[Ganzua] ";
    if (player.hasCompassItem()) cout << "[Brujula] ";
    if (!player.hasLockpickItem() && !player.hasCompassItem()) cout << "Ninguno";
    cout << endl;

    cout << "\nPresiona Enter para salir...";
    cin.ignore();
    cin.get();
}