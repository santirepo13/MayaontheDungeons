#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Player {
private:
    string playerName;
    int playerHealth;
    bool playerHasKey;
    bool playerHasCompass;
    int playerScore;

public:
    Player(string name) {
        playerName = name;
        playerHealth = 73;
        playerHasKey = false;
        playerHasCompass = false;
        playerScore = 0;
    }

    string getName() { return playerName; }
    int getHealth() { return playerHealth; }
    bool hasKeyItem() { return playerHasKey; }
    bool hasCompassItem() { return playerHasCompass; }
    int getScore() { return playerScore; }

    void setHealth(int newHealth) { playerHealth = newHealth; }
    void heal(int amount) { playerHealth = playerHealth + amount; }
    void takeDamage(int damage) { playerHealth = playerHealth - damage; }
    void addScore(int points) { playerScore = playerScore + points; }
    void pickUpKey() {
        playerHasKey = true;
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
        if (playerHasKey) cout << "[Llave] ";
        if (playerHasCompass) cout << "[Brujula] ";
        if (!playerHasKey && !playerHasCompass) cout << "Ninguno";
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

    corridor.setItem("Llave Antigua");

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
    cout << "  1. Norte - Corredor Oscuro" << endl;
    cout << "  2. Sur - Muro (bloqueado)" << endl;

    int choice;
    cout << "\nElección: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nEntras al Corredor Oscuro..." << endl;

        // Dark Corridor
        cout << "\n=== " << corridor.getName() << " ===" << endl;
        cout << corridor.getDescription() << endl;

        if (corridor.hasItem()) {
            cout << "\n¡Encontraste: " << corridor.getItemName() << "!" << endl;
            player.pickUpKey();
            corridor.removeItem();
        }

        // Switch case for corridor choices
        cout << "\nVes tres caminos:" << endl;
        cout << "  1. Puerta cerrada con candado" << endl;
        cout << "  2. Objeto brillante en el suelo" << endl;
        cout << "  3. Puerta abierta" << endl;

        int corridorChoice;
        cout << "\nElección: ";
        cin >> corridorChoice;

        switch (corridorChoice) {
            case 1:
                // Locked door - resting bonus
                cout << "\nEncuentras una puerta cerrada con candado." << endl;
                cout << "¿Abrirán las nuevas puertas de la cámara?" << endl;
                cout << "Necesitas algo para abrirla..." << endl;
                cout << "\nEncuentras un rincon seguro para descansar..." << endl;
                player.heal(1);
                cout << "Te vendas las heridas. Salud +1." << endl;
                break;
            case 2:
                // Compass - no recovery, no damage
                cout << "\nEncuentras una brujula rota en el suelo." << endl;
                cout << "\n¿Qué debo hacer? ¿Debo seguir explorando" << endl;
                cout << "o buscar la salida de estas cámaras?" << endl;
                cout << "\nDecides dejar todo y buscar la salida..." << endl;
                break;
            case 3:
                // Unlocked door - damage from cold
                cout << "\nEntras por la puerta abierta." << endl;
                cout << "El pasaje está helado. El frío te cala los huesos." << endl;
                cout << "No hay lugar seguro para descansar." << endl;
                player.takeDamage(5);
                cout << "Salud -5 por el frío." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }

        player.displayStatus();

        cout << "\nEscuchas un ruido detras de ti..." << endl;
        cout << "Decides descansar aqui." << endl;
    }
    else if (choice == 2) {
        cout << "\n¡Intentas ir al sur pero hay un muro!" << endl;
        cout << "Te quedas en la Sala de Entrada." << endl;
    }
    else {
        cout << "\nOpcion invalida. Dudas y te quedas donde estas." << endl;
    }

    cout << "\n=== FIN DEL CAPITULO 1 ===" << endl;
    cout << "Puntos Finales: " << player.getScore() << endl;
    cout << "Salud Final: " << player.getHealth() << endl;
    cout << "Objetos: ";
    if (player.hasKeyItem()) cout << "[Llave] ";
    if (player.hasCompassItem()) cout << "[Brujula] ";
    if (!player.hasKeyItem() && !player.hasCompassItem()) cout << "Ninguno";
    cout << endl;

    return 0;
}
