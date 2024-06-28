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
    int id; // Identificador del producto
    char nombre[MAX_NAME_LENGTH];
    char marca[MAX_NAME_LENGTH];
    char clasificacion[MAX_NAME_LENGTH];
    char nichoMercado[MAX_NAME_LENGTH];
    float precio;
    int cantidad;
};

typedef struct VENTA
{
    int productoId;                        // Identificador del producto vendido
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
void editarProducto();         // Prototipo de la función para editar un producto
void eliminarProducto();       // Prototipo de la función para eliminar un producto

void registrarVenta(); // Prototipo de la función para registrar una venta
void guardarVentas();  // Prototipo de la función para guardar las ventas en un archivo
int cargarVentas();    // Prototipo de la función para cargar las ventas desde un archivo
void mostrarVentas();  // Prototipo de la función para mostrar las ventas

void productosMasVendidos();

void menuRegistro(); // Prototipo de la función para mostrar el menú de registro de productos
void menuVentas();   // Prototipo de la función para mostrar el menú de ventas
void menuAnalisis(); //Prototipo de la funcioón parar mostrar el el menu de analisis
void menu();         // Prototipo de la función para mostrar el menú principal



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
        cout << "\nIngrese el ID del producto: ";
        cin >> producto.id;

        cout << "\nIngrese el nombre del producto: ";
        scanf(" %[^\n]", producto.nombre); // Leer el nombre del producto (incluye espacios en blanco)

        cout << "Ingrese la marca del producto: ";
        scanf(" %[^\n]", producto.marca); // Leer la marca del producto (incluye espacios en blanco)

        cout << "Ingrese la clasificación del producto: ";
        scanf(" %[^\n]", producto.clasificacion); // Leer la clasificación del producto (incluye espacios en blanco)

        cout << "Ingrese el nicho de mercado del producto: ";

        scanf(" %[^\n]", producto.nichoMercado); // Leer el nicho de mercado del producto (incluye espacios en blanco)
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
    numProductos = 0; // Inicializar el número de productos en 0
    while (archivo >> inventario[numProductos].id) // Leer el ID del producto
    {
        archivo.getline(inventario[numProductos].nombre, MAX_NAME_LENGTH); // Leer el nombre del producto
        archivo.getline(inventario[numProductos].marca, MAX_NAME_LENGTH); // Leer la marca del producto
        archivo.getline(inventario[numProductos].clasificacion, MAX_NAME_LENGTH); // Leer la clasificación del producto
        archivo.getline(inventario[numProductos].nichoMercado, MAX_NAME_LENGTH); // Leer el nicho de mercado del producto
        archivo >> inventario[numProductos].precio; // Leer el precio del producto
        archivo >> inventario[numProductos].cantidad; // Leer la cantidad del producto
        numProductos++; // Incrementar el número de productos
    }
    archivo.close();
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
        archivo << inventario[i].id << endl;
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
        cout << "ID: " << inventario[opc - 1].id << endl;
        cout << "Nombre: " << inventario[opc - 1].nombre << endl;
        cout << "Marca: " << inventario[opc - 1].marca << endl;
        cout << "Clasificación: " << inventario[opc - 1].clasificacion << endl;
        cout << "Nicho de Mercado: " << inventario[opc - 1].nichoMercado << endl;
        cout << "Precio: " << inventario[opc - 1].precio << endl;
        cout << "Cantidad: " << inventario[opc - 1].cantidad << endl;
    }
}

void editarProducto()
{
    int id; // Variable para almacenar el ID del producto a editar
    cout << "Ingrese el ID del producto a editar: ";
    cin >> id;

    for (int i = 0; i < numProductos; i++) // Recorrer el inventario
    {
        if (inventario[i].id == id) // Verificar si el ID del producto coincide
        {
            cout << "Editar producto " << endl;

            cout << "Nombre actual: " << inventario[i].nombre << endl; // Mostrar el nombre actual del producto
            cout << "Nuevo nombre: ";
            scanf(" %[^\n]", inventario[i].nombre); // Leer el nuevo nombre del producto (incluye espacios en blanco)

            cout << "Marca actual: " << inventario[i].marca << endl; // Mostrar la marca actual del producto
            cout << "Nueva marca: ";
            scanf(" %[^\n]", inventario[i].marca); // Leer la nueva marca del producto (incluye espacios en blanco)

            cout << "Clasificación actual: " << inventario[i].clasificacion << endl; // Mostrar la clasificación actual del producto
            cout << "Nueva clasificación: ";
            scanf(" %[^\n]", inventario[i].clasificacion); // Leer la nueva clasificación del producto (incluye espacios en blanco)

            cout << "Nicho de mercado actual: " << inventario[i].nichoMercado << endl; // Mostrar el nicho de mercado actual del producto
            cout << "Nuevo nicho de mercado: ";
            scanf(" %[^\n]", inventario[i].nichoMercado); // Leer el nuevo nicho de mercado del producto (incluye espacios en blanco)

            cout << "Precio actual: " << inventario[i].precio << endl; // Mostrar el precio actual del producto
            cout << "Nuevo precio: ";
            cin >> inventario[i].precio; // Leer el nuevo precio del producto

            cout << "Cantidad actual: " << inventario[i].cantidad << endl; // Mostrar la cantidad actual del producto
            cout << "Nueva cantidad: ";
            cin >> inventario[i].cantidad; // Leer la nueva cantidad del producto

            cout << "Producto editado con éxito." << endl; // Mostrar mensaje de éxito
            guardarInventario();                           // Guardar los cambios en el archivo
            return;                                        // Salir de la función
        }
    }
    cout << "Producto no encontrado." << endl; // Mostrar mensaje si el producto no se encontró
}

void eliminarProducto()
{
    int id;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> id;

    // Buscar el producto en el inventario
    for (int i = 0; i < numProductos; i++)
    {
        if (inventario[i].id == id) // Verificar si el ID del producto coincide
        {
            for (int j = i; j < numProductos - 1; j++) // Recorrer el inventario
            {
                inventario[j] = inventario[j + 1]; // Mover los productos una posición hacia adelante
            }
            numProductos--; // Decrementar el número de productos
            cout << "Producto eliminado con éxito." << endl;
            guardarInventario(); // Guardar los cambios en el archivo
            return;              // Salir de la función
        }
    }
    cout << "Producto no encontrado." << endl;
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
        cout << "\nIngrese el ID del producto vendido: ";
        cin >> venta.productoId; // Leer el ID del producto vendido

        cout << "Ingrese el nombre del producto vendido: ";
        scanf(" %[^\n]", venta.productoVendido); // Leer el nombre del producto vendido (incluye espacios en blanco)

        cout << "Ingrese la cantidad de productos vendidos: ";
        cin >> venta.cantidadVendida; // Leer la cantidad de productos vendidos

        cout << "Ingrese el nombre del cliente: ";
        scanf(" %[^\n]", venta.cliente); // Leer el nombre del cliente (incluye espacios en blanco)

        // Buscar el producto en el inventario
        int pos = -1;                          // Variable para almacenar la posición del producto en el inventario
        for (int j = 0; j < numProductos; j++) // Recorrer el inventario para buscar el producto
        {
            if (inventario[j].id == venta.productoId) // Verificar si el ID del producto coincide
            {
                pos = j; // Almacenar la posición del producto
                break;   // Salir del ciclo
            }
        }
        if (pos != -1) // Verificar si se encontró el producto en el inventario
        {
            if (venta.cantidadVendida <= inventario[pos].cantidad) // Verificar si hay suficiente cantidad en el inventario
            {
                inventario[pos].cantidad -= venta.cantidadVendida; // Actualizar la cantidad en el inventario
                ventas[numVentas++] = venta;                       // Agregar la venta al registro de ventas
                cout << "\nVenta registrada con éxito." << endl;
                guardarInventario(); // Guardar los cambios en el inventario
                guardarVentas();     // Guardar la venta en el archivo
            }
            else // Si no hay suficiente cantidad en el inventario
            {
                cout << "\nNo hay suficiente cantidad en el inventario." << endl;
            }
        }
        else // Si no se encontró el producto en el inventario
        {
            cout << "\nProducto no encontrado en el inventario." << endl;
        }
    }
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
    cout << "\nVentas realizadas";
    cout << "\n------------------------";
    for (int i = 0; i < numVentas; i++)
    {
        cout << "\nVenta " << i + 1;
        cout << "\nID del producto: " << ventas[i].productoId;
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
        editarProducto();
        guardarInventario();
        break;
    case 4:
        eliminarProducto();
        guardarInventario();
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

        switch (opt)
        {
        case 1:
            menuRegistro();
            break;
        case 2:
            menuVentas();
            break;
        case 3:
            menuAnalisis();
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
    cargarVentas();     // Cargar las ventas al inicio del programa
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

void menuAnalisis(){
    int optCase3;
    system("cls");
    cout << "\nAnalisis del Mercado";
    cout << "\n------------------------";
    cout << "\n1. Productos mas vendidos";
    cout << "\n2. Productos menos vendidos";
    cout << "\n3. Ingresos totales";
    cout << "\n4. Clientes mas frecuentes";
    cout << "\n5. Stock critico";
    cout << "\n6. Tendencias de ventas";
    cout << "\n7. Volver" << endl;
    cout << "\nSeleccione una opcion: ";
    cin >> optCase3;

    switch (optCase3)
    {
    case 1:
        productosMasVendidos();
        break;
    case 2:

        break;
    
    case 3:

        break;
    
    case 4:

        break;
    
    case 5:

        break;

    case 6:

        break;

    case 7:

        break;
    
    default:
        break;
    }
}

void productosMasVendidos()
{
    if (numVentas == 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    int cantidadVendida[MAX_PRODUCTOS] = {0};

    for (int i = 0; i < numVentas; i++) // Contar la cantidad vendida de cada producto
    {
        for (int j = 0; j < numProductos; j++)
        {
            if (ventas[i].productoId == inventario[j].id)
            {
                cantidadVendida[j] += ventas[i].cantidadVendida;
                break;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < numProductos; i++)  // Encontrar el producto con la mayor cantidad vendida
    {
        if (cantidadVendida[i] > cantidadVendida[maxIndex])
        {
            maxIndex = i;
        }
    }

    cout << "Producto mas vendido: " << inventario[maxIndex].nombre << endl;
    cout << "Cantidad vendida: " << cantidadVendida[maxIndex] << endl;
}
