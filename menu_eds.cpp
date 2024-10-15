#include "menu_eds.h"
#include "red_nacional.h"
#include "eds.h"
#include "surtidor.h"
#include <iostream>
#include <limits>

using namespace std;

void menu_gestion_eds(red_nacional& red) {
    while (true) {
        int subopcion;
        cout << "\n--- MENÚ DE GESTIÓN DE ESTACIONES DE SERVICIO ---" << endl;
        cout << "1) Agregar/eliminar surtidor." << endl;
        cout << "2) Activar/desactivar surtidor." << endl;
        cout << "3) Consultar el histórico de transacciones." << endl;
        cout << "4) Reportar la cantidad de litros vendidos." << endl;
        cout << "5) Simular una venta." << endl;
        cout << "6) Asignar capacidad del tanque." << endl;
        cout << "7) Volver al menú principal." << endl;

        cout << "Seleccione una opción: ";
        if (cin >> subopcion && subopcion >= 1 && subopcion <= 7) {
            if (subopcion == 7) break; // Volver al menú principal
        } else {
            cout << "Tipo de dato inválido o fuera de rango, vuelva a intentar." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (subopcion) {
        case 1: {
            // Agregar/eliminar surtidor
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            bool found = false;
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    found = true;
                    int cant_surtidores = estacion.get_cant_surtidores();
                    int accion;
                    cout << "Seleccione la acción:\n1) Agregar surtidor\n2) Eliminar surtidor" << endl;
                    cin >> accion;

                    if (accion == 1) {
                        if (cant_surtidores < 12) {
                            estacion._cant_surtidores();
                            cout << "Surtidor agregado correctamente." << endl;
                        } else {
                            cout << "No se pueden agregar más surtidores, el máximo es 12." << endl;
                        }
                    } else if (accion == 2) {
                        if (cant_surtidores > 2) {
                            // Lógica para eliminar surtidor
                            cout << "Surtidor eliminado correctamente." << endl;
                        } else {
                            cout << "No se pueden eliminar más surtidores, el mínimo es 2." << endl;
                        }
                    } else {
                        cout << "Opción inválida." << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Estación no encontrada." << endl;
            }
            break;
        }
        case 2: {
            // Activar/desactivar surtidor
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            bool found = false;
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    found = true;
                    int accion;
                    cout << "Seleccione la acción:\n1) Activar surtidor\n2) Desactivar surtidor" << endl;
                    cin >> accion;

                    if (accion == 1) {
                        // Lógica para activar surtidor
                        cout << "Surtidor activado correctamente." << endl;
                    } else if (accion == 2) {
                        // Lógica para desactivar surtidor
                        cout << "Surtidor desactivado correctamente." << endl;
                    } else {
                        cout << "Opción inválida." << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Estación no encontrada." << endl;
            }
            break;
        }
        case 3: {
            // Consultar histórico de transacciones
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            bool found = false;
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    found = true;
                    int surtidor_index;
                    cout << "Ingrese el número del surtidor a consultar: ";
                    cin >> surtidor_index;

                    // Lógica para consultar el histórico del surtidor
                    cout << "Historial de transacciones del surtidor " << surtidor_index << ":" << endl;
                    // Asumiendo que la clase surtidor tiene el método consultar_historico
                    // estacion.get_surtidor(surtidor_index).consultar_historico();
                    break;
                }
            }
            if (!found) {
                cout << "Estación no encontrada." << endl;
            }
            break;
        }
        case 4: {
            // Reportar la cantidad de litros vendidos
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            bool found = false;
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    found = true;
                    cout << "Litros vendidos de tipo 1: " << estacion._litros_vendidos_tipo1() << endl;
                    cout << "Litros vendidos de tipo 2: " << estacion._litros_vendidos_tipo2() << endl;
                    cout << "Litros vendidos de tipo 3: " << estacion._litros_vendidos_tipo3() << endl;
                    cout << "Total litros vendidos: " << estacion._litros_vendidos() << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Estación no encontrada." << endl;
            }
            break;
        }
        case 5: {
            // Simular una venta
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            bool found = false;
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    found = true;

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
            break;
        }
        case 6: {
            // Asignar capacidad del tanque
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            bool found = false;
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    found = true;
                    estacion._capacidad_tanque();
                    cout << "Capacidad del tanque asignada exitosamente." << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Estación no encontrada." << endl;
            }
            break;
        }
        }
    }
}
