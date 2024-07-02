#include "ventas.h" // Incluir el archivo ventas.h

using namespace std; // Espacio de nombres estándar

VENTA ventas[MAX_VENTAS]; // Arreglo de ventas
int numVentas = 0;        // Número de ventas

void registrarVenta()
{
    system("cls"); // Limpiar la consola
    int id;        // Identificador del producto
    VENTA venta;   // Estructura para almacenar la información de una venta
    cout << "\n--------------------------";
    cout << "\nRegistro de Venta";
    cout << "\n--------------------------";
    cout << "\nIngrese el ID del producto vendido: ";
    cin >> id;

    for (int i = 0; i < numProductos; i++)
    {
        if (inventario[i].id == id)
        {                                                        // Verificar si el ID del producto coincide con el ID del producto en el inventario
            venta.productoId = id;                               // Asignar el ID del producto a la venta
            strcpy(venta.productoVendido, inventario[i].nombre); // Copiar el nombre del producto al producto vendido
            cout << "Ingrese la cantidad vendida: ";             // Solicitar la cantidad vendida
            cin >> venta.cantidadVendida;

            if (inventario[i].cantidad < venta.cantidadVendida) // Verificar si hay suficiente stock
            {
                cout << "No hay suficiente stock." << endl;
                return;
            }

            inventario[i].cantidad -= venta.cantidadVendida; // Actualizar la cantidad en el inventario

            cout << "Ingrese el nombre del cliente: "; // Solicitar el nombre del cliente
            scanf(" %[^\n]", venta.cliente); // Leer el nombre del cliente

            ventas[numVentas++] = venta; // Agregar la venta al arreglo de ventas
            guardarInventario(); // Guardar el inventario
            guardarVentas(); // Guardar las ventas
            cout << "Venta registrada con exito." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void guardarVentas()
{
    ofstream archivo;
    archivo.open("ventas.txt", ios::app);
    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo." << endl;
        exit(1);
    }

    for (int i = 0; i < numVentas; i++) // Escribir los datos de las ventas en el archivo
    {
        archivo << ventas[i].productoId << endl;
        archivo << ventas[i].productoVendido << endl;
        archivo << ventas[i].cantidadVendida << endl;
        archivo << ventas[i].cliente << endl;
    }

    archivo.close();
}

int cargarVentas()
{
    ifstream archivo("ventas.txt"); // Abrir el archivo para lectura
    if (archivo.fail())             // Verificar si se pudo abrir el archivo
    {
        return 0;
    }
    VENTA venta; // Variable para almacenar los datos de una venta
    while (archivo >> venta.productoId &&
           archivo.getline(venta.productoVendido, MAX_NAME_LENGTH) &&
           archivo >> venta.cantidadVendida &&
           archivo.ignore() &&
           archivo.getline(venta.cliente, MAX_NAME_LENGTH))
    {
        // Leer los datos de cada venta del archivo y agregarlos al registro de ventas
        ventas[numVentas++] = venta;
    }
    archivo.close(); // Cerrar el archivo
    return 1;        // Retornar 1 si se cargaron las ventas exitosamente
}

void mostrarVentas()
{
    system("cls");
    cout << "\n--------------------------";
    cout << "\nVentas Realizadas";
    cout << "\n--------------------------" << endl;
    for (int i = 0; i < numVentas; i++) // Mostrar las ventas realizadas
    {
        cout << "\nVenta " << i + 1 << endl;
        cout << "Producto ID: " << ventas[i].productoId << endl; // Mostrar los datos de la venta
        cout << "Producto: " << ventas[i].productoVendido << endl; // Mostrar los datos de la venta
        cout << "Cantidad: " << ventas[i].cantidadVendida << endl; // Mostrar los datos de la venta
        cout << "Cliente: " << ventas[i].cliente << endl; // Mostrar los datos de la venta
    }
}

void menuVentas()
{
    system("cls");
    int optCase2;
    cout << "\nVenta de productos";
    cout << "\n------------------------";
    cout << "\n1. Registrar venta";
    cout << "\n2. Mostrar ventas";
    cout << "\n3. Volver" << endl;
    cout << "\nSeleccione una opcion: ";
    cin >> optCase2;
    switch (optCase2)
    {
    case 1:
        registrarVenta();
        break;
    case 2:
        mostrarVentas();
        break;
    case 3:
        break;
    default:
        cout << "Opcion no valida";
        break;
    }
}