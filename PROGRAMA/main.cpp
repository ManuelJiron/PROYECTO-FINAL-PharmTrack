#include <iostream> // Incluir la biblioteca iostream
#include "inventario.cpp" // Incluir el archivo inventario.cpp
#include "ventas.cpp" // Incluir el archivo ventas.cpp
#include "analisis.cpp" // Incluir el archivo analisis.cpp

using namespace std; // Espacio de nombres estándar

void menu(); // Prototipo de la función menu

int main() {
    cargarInventario(); // Cargar el inventario
    cargarVentas(); // Cargar las ventas
    menu(); // Mostrar el menú
    return 0;
}

void menu() {
    int opt;
    do {
        cout << "\n-----------------------------------------------------------------------" << endl;
        cout << "   ____  _   _    _    ____  __  __   _____ ____      _    ____ _  __" << endl;
        cout << "  |  _ \\| | | |  / \\  |  _ \\|  \\/  | |_   _|  _ \\    / \\  / ___| |/ /" << endl;
        cout << "  | |_) | |_| | / _ \\ | |_) | |\\/| |   | | | |_) |  / _ \\| |   | ' / " << endl;
        cout << "  |  __/|  _  |/ ___ \\|  _ <| |  | |   | | |  _ <  / ___ \\ |___| . \\ " << endl;
        cout << "  |_|   |_| |_/_/   \\_\\_| \\_\\_|  |_|   |_| |_| \\_\\/_/   \\_\\____|_|\\_\\ " << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "\n1. Registro de productos" << endl;
        cout << "2. Venta de producto" << endl;
        cout << "3. Analisis del mercado" << endl;
        cout << "4. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opt;

        switch (opt) {
            case 1:
                menuRegistro(); // Llamar a la función menuRegistro()
                break;
            case 2:
                menuVentas(); // Llamar a la función menuVentas()
                break;
            case 3:
                menuAnalisis(); // Llamar a la función menuAnalisis()
                break;
            case 4:
                cout << "Gracias por usar PHARM TRACK";
                break;
            default:
                cout << "Opcion no valida";
                break;
        }
    } while (opt != 4);
}