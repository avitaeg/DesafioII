#include "menu_principal.h"
#include "menu_red.h"
#include "menu_eds.h"
#include "menu_ventas.h"
#include "red_nacional.h"
#include <iostream>
#include <limits>

using namespace std;

void menu_principal() {
    red_nacional red; // Instancia de la clase red_nacional

    while (true) {
        int opcion;
        cout << "BIENVENIDO, ESCOJA LA OPCIÓN DE SU PREFERENCIA" << endl;
        cout << "1) GESTIÓN DE LA RED." << endl;
        cout << "2) GESTIÓN DE ESTACIONES DE SERVICIO." << endl;
        cout << "3) DETECTAR FUGAS." << endl;
        cout << "4) SIMULAR VENTA." << endl;
        cout << "5) SALIR." << endl;

        while (true) {
            cout << "Ingrese una opción (1-5): ";
            if (cin >> opcion && opcion >= 1 && opcion <= 5) {
                break;
            } else {
                cout << "Tipo de dato inválido o fuera de rango, vuelva a intentar." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (opcion) {
        case 1:
            menu_gestion_red(red); // Llamar al menú de gestión de red
            break;
        case 2:
            menu_gestion_eds(red); // Llamar al menú de gestión de estaciones de servicio
            break;
        case 3:
            cout << "Opción de DETECTAR FUGAS (por implementar)." << endl;
            break;
        case 4:
            menu_simular_venta(red); // Llamar al menú de simular venta
            break;
        case 5:
            cout << "Gracias por utilizar el sistema." << endl;
            return;
        }
    }
}
