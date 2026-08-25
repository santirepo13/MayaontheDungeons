#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Direction {
private:
    char directionKey;
    string directionName;

public:
    Direction(char key) {
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

    char getKey() { return directionKey; }
    string getName() { return directionName; }
    bool isValid() { return directionName != "Invalida"; }
};

class Player {
private:
    string playerName;
    int playerHealth;
    bool playerHasLockpick;
    bool playerHasCompass;
    int playerScore;

public:
    Player(string name) {
        playerName = name;
        playerHealth = 73;
        playerHasLockpick = false;
        playerHasCompass = false;
        playerScore = 0;
    }

    string getName() { return playerName; }
    int getHealth() { return playerHealth; }
    bool hasLockpickItem() { return playerHasLockpick; }
    bool hasCompassItem() { return playerHasCompass; }
    int getScore() { return playerScore; }

    void setHealth(int newHealth) { playerHealth = newHealth; }
    void heal(int amount) { playerHealth = playerHealth + amount; }
    void takeDamage(int damage) { playerHealth = playerHealth - damage; }
    void addScore(int points) { playerScore = playerScore + points; }
    void pickUpLockpick() {
        playerHasLockpick = true;
        playerScore = playerScore + 1;
    }
    void pickUpCompass() {
        playerHasCompass = true;
    }

    void displayStatus() {
        cout << "\n--- " << playerName << " ---" << endl;
        cout << "Salud: " << playerHealth << endl;
        cout << "Puntos: " << playerScore << endl;
        cout << "Objetos: ";
        if (playerHasLockpick) cout << "[Ganzua] ";
        if (playerHasCompass) cout << "[Brujula] ";
        if (!playerHasLockpick && !playerHasCompass) cout << "Ninguno";
        cout << endl;
    }
};

class Room {
private:
    string roomName;
    string roomDescription;
    bool roomHasItem;
    string roomItemName;

public:
    Room(string name, string description) {
        roomName = name;
        roomDescription = description;
        roomHasItem = false;
        roomItemName = "";
    }

    string getName() { return roomName; }
    string getDescription() { return roomDescription; }
    bool hasItem() { return roomHasItem; }
    string getItemName() { return roomItemName; }

    void setItem(string itemName) { roomHasItem = true; roomItemName = itemName; }
    void removeItem() { roomHasItem = false; roomItemName = ""; }
};

int main() {
    Player player("Profesora Carter");
    Room entrance("Sala de Entrada", "Una habitacion oscura con dos pasajes.");
    Room corridor("Corredor Oscuro", "Un pasaje angosto. Escuchas goteo de agua.");

    // Backstory
    cout << "\n========================================" << endl;
    cout << "  UNA PROFESORA DE GEOGRAFIA PERDIDA EN LAS MAZMORRAS" << endl;
    cout << "========================================" << endl;
    cout << "\nLa Profesora Maya Carter despierta en una mazmorra oscura..." << endl;
    cout << "\n--- RETROSPECTIVA ---" << endl;
    cout << "Maya Carter, de 42 anios, es profesora de geografia en la" << endl;
    cout << "Secundaria Riverside. La semana pasada, llevo a sus alumnos" << endl;
    cout << "a una excursion para estudiar formaciones de cuevas." << endl;
    cout << "Durante la expedicion, resbalo y cayo en un pasaje oculto." << endl;
    cout << "Desperto aqui, herida y sola, sin memoria de cuanto tiempo" << endl;
    cout << "ha estado inconsciente." << endl;
    cout << "\nSus heridas:" << endl;
    cout << "  - Esguince del tobillo izquierdo" << endl;
    cout << "  - Cortaduras y moretones en los brazos" << endl;
    cout << "  - Un golpe en la cabeza" << endl;
    cout << "\nDebe encontrar la salida antes de que sus alumnos" << endl;
    cout << "y colegas dejen de buscarla." << endl;
    cout << "========================================" << endl;

    // Entrance Chamber
    cout << "\n=== " << entrance.getName() << " ===" << endl;
    cout << entrance.getDescription() << endl;
    cout << "\nVes:" << endl;
    cout << "  W - Arriba - Corredor Oscuro" << endl;
    cout << "  S - Abajo - Muro (bloqueado)" << endl;

    char entranceChoice;
    cout << "\nElección: ";
    cin >> entranceChoice;

    Direction entranceDir(entranceChoice);

    if (entranceDir.isValid() && entranceDir.getKey() == 'W' || entranceDir.getKey() == 'w') {
        cout << "\nEntras al Corredor Oscuro..." << endl;

        // Dark Corridor
        cout << "\n=== " << corridor.getName() << " ===" << endl;
        cout << corridor.getDescription() << endl;

        // Switch case for corridor choices (WASD)
        cout << "\nVes cuatro caminos:" << endl;
        cout << "  W - Arriba" << endl;
        cout << "  S - Abajo" << endl;
        cout << "  D - Derecha" << endl;
        cout << "  A - Izquierda" << endl;

        char corridorChoice;
        cout << "\nElección: ";
        cin >> corridorChoice;

        Direction dir(corridorChoice);

        if (dir.isValid()) {
            cout << "\nVas hacia " << dir.getName() << "..." << endl;

            switch (dir.getKey()) {
                case 'W':
                case 'w':
                    // Arriba - find compass
                    cout << "Encuentras una brujula en el suelo." << endl;
                    player.pickUpCompass();
                    cout << "¡Encontraste una Brujula!" << endl;
                    break;
                case 'S':
                case 's':
                    // Abajo - cold damage
                    cout << "El pasaje está helado. El frío te cala los huesos." << endl;
                    cout << "No hay lugar seguro para descansar." << endl;
                    player.takeDamage(5);
                    cout << "Salud -5 por el frío." << endl;
                    break;
                case 'D':
                case 'd':
                    // Derecha - locked door
                    cout << "Encuentras una puerta cerrada con candado." << endl;
                    cout << "¿Abrirán las nuevas puertas de la cámara?" << endl;
                    cout << "Necesitas algo para abrirla..." << endl;
                    break;
                case 'A':
                case 'a':
                    // Izquierda - find lockpick
                    cout << "Encuentras una ganzua oxidada en el suelo." << endl;
                    player.pickUpLockpick();
                    cout << "¡Encontraste una Ganzua oxidada!" << endl;
                    break;
            }
        } else {
            cout << "Direccion invalida." << endl;
        }

        player.displayStatus();

        cout << "\nEscuchas un ruido detras de ti..." << endl;
        cout << "Decides descansar aqui." << endl;
    }
    else if (entranceDir.isValid() && entranceDir.getKey() == 'S' || entranceDir.getKey() == 's') {
        cout << "\n¡Intentas ir abajo pero hay un muro!" << endl;
        cout << "Te quedas en la Sala de Entrada." << endl;
    }
    else {
        cout << "\nOpcion invalida. Dudas y te quedas donde estas." << endl;
    }

    cout << "\n=== FIN DEL CAPITULO 1 ===" << endl;
    cout << "Puntos Finales: " << player.getScore() << endl;
    cout << "Salud Final: " << player.getHealth() << endl;
    cout << "Objetos: ";
    if (player.hasLockpickItem()) cout << "[Ganzua] ";
    if (player.hasCompassItem()) cout << "[Brujula] ";
    if (!player.hasLockpickItem() && !player.hasCompassItem()) cout << "No items";
    cout << endl;

    // Pause so player can see results
    cout << "\nPresiona Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}
