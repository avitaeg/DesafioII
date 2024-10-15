#include "red_nacional.h"
#include <iostream>
using namespace std;

// Constructor por defecto
red_nacional::red_nacional() {
    pais = "";
    ventas = 0.0;
    precio_ctipo1 = 0.0;
    precio_ctipo2 = 0.0;
    precio_ctipo3 = 0.0;
    estaciones_activa = true;
}

// Calcular ventas por tipo de combustible
void red_nacional::calcular_ventas() {
    float total_ventas_tipo1 = 0.0;
    float total_ventas_tipo2 = 0.0;
    float total_ventas_tipo3 = 0.0;

    for (const eds& estacion : estaciones_servicio) {
        // Sumar las ventas por tipo de combustible
        total_ventas_tipo1 += estacion._litros_vendidos_tipo1() * precio_ctipo1;
        total_ventas_tipo2 += estacion._litros_vendidos_tipo2() * precio_ctipo2;
        total_ventas_tipo3 += estacion._litros_vendidos_tipo3() * precio_ctipo3;
    }

    // Mostrar las ventas discriminadas por tipo de combustible
    cout << "Ventas Tipo 1: " << total_ventas_tipo1 << endl;
    cout << "Ventas Tipo 2: " << total_ventas_tipo2 << endl;
    cout << "Ventas Tipo 3: " << total_ventas_tipo3 << endl;
}

// Fijar los precios del combustible
void red_nacional::fijar_precios() {
    cout << "Ingrese el precio del combustible tipo 1: ";
    cin >> precio_ctipo1;

    cout << "Ingrese el precio del combustible tipo 2: ";
    cin >> precio_ctipo2;

    cout << "Ingrese el precio del combustible tipo 3: ";
    cin >> precio_ctipo3;
}

// Agregar estación de servicio
void red_nacional::agregar_estacion() {
    eds nueva_estacion; // Cambiado de surtidor a eds
    nueva_estacion._nombre();
    nueva_estacion._codigo();
    nueva_estacion._region();
    nueva_estacion._ubicacion();
    nueva_estacion._gerente();
    nueva_estacion._cant_surtidores();
    nueva_estacion._capacidad_tanque();

    // Agregar la nueva estación al vector
    estaciones_servicio.push_back(nueva_estacion);
    cout << "Estación agregada con éxito." << endl;
}

// Eliminar estación de servicio
void red_nacional::eliminar_estacion() {
    int codigo;
    cout << "Ingrese el código de la estación a eliminar: ";
    cin >> codigo;

    // Buscar la estación por código
    for (auto it = estaciones_servicio.begin(); it != estaciones_servicio.end(); ++it) {
        if (it->get_codigo() == codigo) {
            // Eliminar la estación si no tiene surtidores activos
            if (it->get_cant_surtidores() == 0) {
                estaciones_servicio.erase(it);
                cout << "Estación eliminada con éxito." << endl;
            } else {
                cout << "Error: No se puede eliminar la estación, tiene surtidores activos." << endl;
            }
            return;
        }
    }

    cout << "Error: Estación no encontrada." << endl;
}
