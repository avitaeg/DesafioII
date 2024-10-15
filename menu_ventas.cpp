#include "menu_ventas.h"
#include "red_nacional.h"
#include "surtidor.h"
#include <iostream>
#include <limits>

using namespace std;

void menu_simular_venta(red_nacional& red) {
    int codigo_estacion;
    cout << "Ingrese el código de la estación de servicio: ";
    cin >> codigo_estacion;

    // Buscar la estación con el código dado
    bool found = false;
    for (eds& estacion : red.get_estaciones_servicio()) {
        if (estacion.get_codigo() == codigo_estacion) {
            found = true;

            // Obtener datos de la venta
            float cantidad;
            int tipo_combustible;
            string metodo_pago, documento_cliente;

            cout << "Ingrese la cantidad de combustible: ";
            cin >> cantidad;
            cout << "Ingrese el tipo de combustible (1, 2, 3): ";
            cin >> tipo_combustible;
            cout << "Ingrese el método de pago (Efectivo, TDebito, TCredito): ";
            cin >> metodo_pago;
            cout << "Ingrese el número de documento del cliente: ";
            cin >> documento_cliente;

            // Simular la venta
            estacion.simular_venta(cantidad, tipo_combustible, metodo_pago, documento_cliente);

            break;
        }
    }

    if (!found) {
        cout << "Estación no encontrada." << endl;
    }
}
