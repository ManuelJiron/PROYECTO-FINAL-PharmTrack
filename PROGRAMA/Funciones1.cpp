#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define MAX_PRODUCTOS 100  // Máximo número de productos
#define MAX_NAME_LENGTH 30 // Máximo de longitud de los nombres
#define MAX_VENTAS 100     // Máximo número de ventas

using namespace std;

// Estructura para almacenar la información de un producto
typedef struct PRODUCTO
{
    char nombre[MAX_NAME_LENGTH];
    char marca[MAX_NAME_LENGTH];
    char clasificacion[MAX_NAME_LENGTH];
    char nichoMercado[MAX_NAME_LENGTH];
    float precio;
    int cantidad;
};

typedef struct VENTA
{
    char productoVendido[MAX_NAME_LENGTH]; // Nombre del producto vendido
    int cantidadVendida;                   // Cantidad de productos vendidos
    char cliente[MAX_NAME_LENGTH];         // Nombre del cliente
};

PRODUCTO inventario[MAX_PRODUCTOS]; // Arreglo para almacenar los productos en inventario
VENTA ventas[MAX_VENTAS];           // Arreglo para almacenar las ventas realizadas
int numProductos = 0;
int numVentas = 0;

void ingresarDatosProductos(); // Prototipo de la función para ingresar los datos de los productos
int cargarInventario();        // Prototipo de la función para cargar el inventario desde un archivo
void guardarInventario();      // Prototipo de la función para guardar el inventario en un archivo
void mostrarInventario();      // Prototipo de la función para mostrar el inventario
void registrarVenta();         // Prototipo de la función para registrar una venta
void guardarVentas();          // Prototipo de la función para guardar las ventas en un archivo
int cargarVentas();           // Prototipo de la función para cargar las ventas desde un archivo
void mostrarVentas();          // Prototipo de la función para mostrar las ventas
void menuRegistro();           // Prototipo de la función para mostrar el menú de registro de productos
void menuVentas();             // Prototipo de la función para mostrar el menú de ventas
void menu();                   // Prototipo de la función para mostrar el menú principal

void ingresarDatosProductos()
{
    system("cls");
    int num;
    PRODUCTO producto;

    cout << "\nIngrese la cantidad de productos a registrar: ";
    cin >> num;   // Lee la cantidad de productos a registrar
    cin.ignore(); // Limpiar el buffer de entrada

    // Ingresar los datos del producto
    for (int i = 0; i < num; i++)
    {
        cout << "\n--------------------------";
        cout << "\nProducto " << i + 1;
        cout << "\n--------------------------";
        cout << "\nIngrese el nombre del producto: ";
        cin.getline(producto.nombre, MAX_NAME_LENGTH);

        cout << "Ingrese la marca del producto: ";
        cin.getline(producto.marca, MAX_NAME_LENGTH);

        cout << "Ingrese la clasificación del producto: ";
        cin.getline(producto.clasificacion, MAX_NAME_LENGTH);

        cout << "Ingrese el nicho de mercado del producto: ";
        cin.getline(producto.nichoMercado, MAX_NAME_LENGTH);

        cout << "Ingrese el precio del producto: ";
        cin >> producto.precio;

        cout << "Ingrese la cantidad del producto: ";
        cin >> producto.cantidad;

        cin.ignore(); // Limpiar el buffer de entrada

        inventario[numProductos++] = producto; // Agregar el producto al inventario
        cout << "\nProducto registrado con éxito." << endl;
    }
}

int cargarInventario()
{
    ifstream archivo("inventario.txt"); // Abrir el archivo para lectura
    if (archivo.fail())
    {
        return 0;
    }
    PRODUCTO producto; // Variable para almacenar los datos de un producto
    while (archivo.getline(producto.nombre, MAX_NAME_LENGTH) &&
           archivo.getline(producto.marca, MAX_NAME_LENGTH) &&
           archivo.getline(producto.clasificacion, MAX_NAME_LENGTH) &&
           archivo.getline(producto.nichoMercado, MAX_NAME_LENGTH) &&
           archivo >> producto.precio &&
           archivo.ignore() &&
           archivo >> producto.cantidad &&
           archivo.ignore())
    {
        // Leer los datos de cada producto del archivo y agregarlos al inventario
        inventario[numProductos++] = producto;
    }
    archivo.close();
    return 1;
}

void guardarInventario()
{
    ofstream archivo;
    archivo.open("inventario.txt"); // Abrir el archivo para escritura
    if (archivo.fail())             // Verificar si se pudo abrir el archivo
    {
        cout << "No se puede abrir el archivo." << endl;
        exit(1);
    }
    for (int i = 0; i < numProductos; i++) // Escribir los datos de los productos en el archivo
    {
        archivo << inventario[i].nombre << endl;
        archivo << inventario[i].marca << endl;
        archivo << inventario[i].clasificacion << endl;
        archivo << inventario[i].nichoMercado << endl;
        archivo << inventario[i].precio << endl;
        archivo << inventario[i].cantidad << endl;
    }
    archivo.close();
}

void mostrarInventario()
{
    int opc;
    cout << "\n--------------------------";
    cout << "\nProducto es Farmacia";
    cout << "\n--------------------------" << endl;
    for (int i = 0; i < numProductos; i++)
    {
        cout << i + 1 << ": " << inventario[i].nombre << endl;
    }
    cout << "\nSeleccione el numero del producto del cual quiere ver detalles: ";
    cin >> opc;

    if (opc > numProductos || opc <= 0)
    {
        cout << "Seleccione un numero de producto valido";
    }
    else
    {
        cout << "\nDetalles del producto " << opc << endl;
        cout << "-------------------------" << endl;
        cout << "Nombre: " << inventario[opc - 1].nombre << endl;
        cout << "Marca: " << inventario[opc - 1].marca << endl;
        cout << "Clasificación: " << inventario[opc - 1].clasificacion << endl;
        cout << "Nicho de Mercado: " << inventario[opc - 1].nichoMercado << endl;
        cout << "Precio: " << inventario[opc - 1].precio << endl;
        cout << "Cantidad: " << inventario[opc - 1].cantidad << endl;
    }
}

void registrarVenta()
{
    int num;     // Variable para almacenar la cantidad de productos a vender
    VENTA venta; // Variable para almacenar los datos de la venta

    cout << "\nIngrese la cantidad de productos a vender: ";
    cin >> num; // Lee la cantidad de productos a vender

    // Ingresar los datos de la venta
    for (int i = 0; i < num; i++)
    {
        cout << "\n--------------------------";
        cout << "\nVenta " << i + 1;
        cout << "\n--------------------------";
        cout << "\nIngrese el nombre del producto vendido: ";
        scanf(" %[^\n]", venta.productoVendido); // Leer el nombre del producto vendido (incluye espacios en blanco)

        cout << "Ingrese la cantidad de productos vendidos: ";
        cin >> venta.cantidadVendida; // Leer la cantidad de productos vendidos

        cout << "Ingrese el nombre del cliente: ";
        scanf(" %[^\n]", venta.cliente); // Leer el nombre del cliente (incluye espacios en blanco)

        // Buscar el producto en el inventario
        int pos = -1; // Variable para almacenar la posición del producto en el inventario
        for (int j = 0; j < numProductos; j++)
        {
            if (strcmp(venta.productoVendido, inventario[j].nombre) == 0) // Comparar el nombre del producto vendido con el nombre del producto en el inventario
            {
                pos = j; // Almacenar la posición del producto en el inventario
                break;   // Salir del ciclo
            }
        }

        if (pos != -1)
        {                                                          // Si el producto se encuentra en el inventario
            if (inventario[pos].cantidad >= venta.cantidadVendida) // Si la cantidad de productos en el inventario es mayor o igual a la cantidad de productos vendidos
            {
                inventario[pos].cantidad -= venta.cantidadVendida; // Actualizar la cantidad de productos en el inventario
                ventas[numVentas++] = venta;                       // Agregar la venta al registro de ventas
                cout << "\nVenta registrada con éxito." << endl;
            }
            else
            {
                cout << "\nNo hay suficientes productos en el inventario." << endl;
            }
        }
    }
}

void guardarVentas()
{
    ofstream archivo;
    archivo.open("ventas.txt");
    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo." << endl;
        exit(1);
    }

    for (int i = 0; i < numVentas; i++) // Escribir los datos de las ventas en el archivo
    {
        archivo << ventas[i].productoVendido << endl;
        archivo << ventas[i].cantidadVendida << endl;
        archivo << ventas[i].cliente << endl;
    }

    archivo.close();
}

int cargarVentas(){
    ifstream archivo("ventas.txt"); // Abrir el archivo para lectura
    if (archivo.fail()) // Verificar si se pudo abrir el archivo
    {
        return 0;
    }
    VENTA venta; // Variable para almacenar los datos de una venta
    while (archivo.getline(venta.productoVendido, MAX_NAME_LENGTH) &&
           archivo >> venta.cantidadVendida &&
           archivo.ignore() &&
           archivo.getline(venta.cliente, MAX_NAME_LENGTH))
    {
        // Leer los datos de cada venta del archivo y agregarlos al registro de ventas
        ventas[numVentas++] = venta;
    }
    archivo.close();
    return 1;
}

void mostrarVentas()
{
    cout << "\nVentas realizadas";
    cout << "\n------------------------";
    for (int i = 0; i < numVentas; i++)
    {
        cout << "\nVenta " << i + 1;
        cout << "\nProducto vendido: " << ventas[i].productoVendido;
        cout << "\nCantidad vendida: " << ventas[i].cantidadVendida;
        cout << "\nCliente: " << ventas[i].cliente;
        cout << "\n------------------------";
    }
}
void menuRegistro()
{
    system("cls");
    int optCase1;
    cout << "\nRegistro de productos";
    cout << "\n------------------------";
    cout << "\n1. Agregar producto";
    cout << "\n2. Mostrar inventario de productos";
    cout << "\n3. Editar producto";
    cout << "\n4. Eliminar producto";
    cout << "\n5. Volver" << endl;
    cout << "\nSeleccione una opcion: ";
    cin >> optCase1;
    switch (optCase1)
    {
    case 1:
        ingresarDatosProductos();
        guardarInventario();
        break;
    case 2:
        mostrarInventario();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        menu();
        break;
    default:
        cout << "Opcion no valida";
        break;
    }
}

void menu()
{
    int opt;
    do
    {
        cout << "\n------------------------------------" << endl;
        cout << "PHARM TRACK" << endl;
        cout << "------------------------------------" << endl;
        cout << "\n1. Registro de productos" << endl;
        cout << "2. Venta de producto" << endl;
        cout << "3. Analisis del mercado" << endl;
        cout << "4. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            menuRegistro();
            break;
        case 2:
            menuVentas();
            break;
        case 3:
            // Implementa la lógica para análisis del mercado
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

int main()
{
    cargarInventario(); // Cargar el inventario al inicio del programa
    menu();             // Llamar al menú principal
    return 0;
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
        guardarVentas();
        break;
    case 2:
        mostrarVentas();
        break;
    case 3:
        menu();
        break;
    default:
        cout << "Opcion no valida";
        break;
    }
}

