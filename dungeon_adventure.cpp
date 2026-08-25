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
    int playerScore;

public:
    Player(string name) {
        playerName = name;
        playerHealth = 73;
        playerHasKey = false;
        playerScore = 0;
    }

    string getName() { return playerName; }
    int getHealth() { return playerHealth; }
    bool hasKeyItem() { return playerHasKey; }
    int getScore() { return playerScore; }

    void setHealth(int newHealth) { playerHealth = newHealth; }
    void heal(int amount) { playerHealth = playerHealth + amount; }
    void addScore(int points) { playerScore = playerScore + points; }
    void pickUpKey() {
        playerHasKey = true;
        playerScore = playerScore + 1;
    }

    void displayStatus() {
        cout << "\n--- " << playerName << " ---" << endl;
        cout << "Salud: " << playerHealth << endl;
        cout << "Puntos: " << playerScore << endl;
        if (playerHasKey) cout << "Objeto: [Llave]" << endl;
        else cout << "Objeto: Ninguno" << endl;
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

        cout << "\n=== " << corridor.getName() << " ===" << endl;
        cout << corridor.getDescription() << endl;

        if (corridor.hasItem()) {
            cout << "\n¡Encontraste: " << corridor.getItemName() << "!" << endl;
            player.pickUpKey();
            corridor.removeItem();
        }

        cout << "\nEncuentras un rincon seguro para descansar..." << endl;
        player.heal(1);
        cout << "Te vendas las heridas. Salud +1." << endl;
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
    if (player.hasKeyItem()) cout << "[Llave]";
    else cout << "Ninguno";
    cout << endl;

    return 0;
}
