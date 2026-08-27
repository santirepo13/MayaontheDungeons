#include "Story.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void Story::show(StoryEvent event, string detail) {
    switch (event) {
        case INTRODUCTION:
            cout << "\n========================================" << endl;
            cout << "  UNA PROFESORA DE GEOGRAFIA EN UNA CONSTRUCCION ABANDONADA" << endl;
            cout << "========================================" << endl;
            cout << "\nLa Profesora Maya Carter despierta dentro de una construccion abandonada..." << endl;
            cout << "\n--- RETROSPECTIVA ---" << endl;
            cout << "Maya Carter, de 42 anios, es profesora de geografia en la" << endl;
            cout << "Secundaria Riverside. La semana pasada, llevo a sus alumnos" << endl;
            cout << "a una excursion para estudiar formaciones de cuevas." << endl;
            cout << "Durante la expedicion, cayo en un acceso oculto de una construccion." << endl;
            cout << "Desperto aqui, herida y sola, sin memoria de cuanto tiempo" << endl;
            cout << "ha estado inconsciente." << endl;
            cout << "\nSus heridas:" << endl;
            cout << "  - Esguince del tobillo izquierdo" << endl;
            cout << "  - Cortaduras y moretones en los brazos" << endl;
            cout << "  - Un golpe en la cabeza" << endl;
            cout << "\nDebe encontrar la salida antes de que sus alumnos" << endl;
            cout << "y colegas dejen de buscarla." << endl;
            cout << "========================================" << endl;
            break;

        case LOCATION_ENTERED:
            cout << "\nMaya entra en " << detail << "." << endl;
            break;

        case CHARACTER_FOUND:
            cout << "\nMaya encuentra a " << detail << "." << endl;
            if (detail == "Conejo") {
                cout << "El animal no se mueve y al principio parece un cadaver." << endl;
                cout << "Todavia se encuentra en sus ultimos segundos de vida." << endl;
                cout << "Tiene una mordida grande en el cuerpo." << endl;
                cout << "Maya comprende que algo peligroso esta cerca." << endl;
            }
            else {
                cout << "El personaje no muestra ninguna otra senal." << endl;
            }
            break;

        case OBJECT_EXAMINED:
            cout << "Maya examina " << detail << "." << endl;
            break;

        case OBJECT_ALREADY_EXAMINED:
            cout << "Maya ya ha examinado " << detail << "." << endl;
            cout << "No encuentra nada nuevo." << endl;
            break;

        case OBJECT_CLOSED:
            cout << "Maya examina " << detail << "." << endl;
            cout << detail << " esta cerrado." << endl;
            break;

        case OBJECT_LOCKED:
            cout << "Maya encuentra " << detail << "." << endl;
            cout << "La puerta esta cerrada con candado." << endl;
            cout << "Necesita algo para abrirla." << endl;
            break;

        case ITEM_FOUND:
            cout << "Maya encuentra " << detail << "." << endl;
            break;

        case NOTHING_FOUND:
            cout << "Maya no encuentra nada util en " << detail << "." << endl;
            break;

        case LEAVING_PLACE:
            cout << "\nMaya encuentra una puerta de salida y deja " << detail << "." << endl;
            break;

        case DAMAGE_RECEIVED:
            cout << "Las heridas de Maya empeoran al atravesar las cavidades." << endl;
            cout << "Salud -" << detail << "." << endl;
            break;

        case ACTION_COMPLETED:
            cout << detail << endl;
            break;

        case ACTION_FAILED:
            cout << detail << endl;
            break;

        case ENDING:
            cout << "\n=== FIN DEL CAPITULO 1 ===" << endl;
            break;
    }
}