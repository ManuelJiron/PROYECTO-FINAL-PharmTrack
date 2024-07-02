#include "inventario.h" //incluimos inventario.h

using namespace std; // usamos el espacio de nombres std

PRODUCTO inventario[MAX_PRODUCTOS]; // Arreglo de productos
int numProductos = 0;               // Número de productos

void ingresarDatosProductos()
{
    system("cls");     // limpiamos la pantalla
    int num;           // variable para almacenar la cantidad de productos a registrar
    PRODUCTO producto; // variable de tipo PRODUCTO para almacenar los datos de un producto

    cout << "\nIngrese la cantidad de productos a registrar: ";
    cin >> num;   // Lee la cantidad de productos a registrar
    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < num; i++)
    {
        cout << "\n--------------------------";
        cout << "\nProducto " << i + 1;
        cout << "\n--------------------------";
        cout << "\nIngrese el ID del producto: ";
        cin >> producto.id;

        cout << "\nIngrese el nombre del producto: ";
        scanf(" %[^\n]", producto.nombre); // Lee el nombre del producto

        cout << "Ingrese la marca del producto: ";
        scanf(" %[^\n]", producto.marca); // Lee la marca del producto

        cout << "Ingrese la clasificacion del producto: ";
        scanf(" %[^\n]", producto.clasificacion); // Lee la clasificación del producto

        cout << "Ingrese el nicho de mercado del producto: ";
        scanf(" %[^\n]", producto.nichoMercado); // Lee el nicho de mercado del producto

        cout << "Ingrese el precio del producto: ";
        cin >> producto.precio; // Lee el precio del producto

        cout << "Ingrese la cantidad del producto: ";
        cin >> producto.cantidad; // Lee la cantidad del producto

        cin.ignore(); // Limpiar el buffer de entrada

        inventario[numProductos++] = producto; // Agregar el producto al inventario
        cout << "\nProducto registrado con exito." << endl;
    }
}

int cargarInventario()
{
    ifstream archivo("inventario.txt"); // Abrir el archivo para lectura
    if (archivo.fail())                 // Verificar si no se pudo abrir el archivo
    {
        return 0;
    }
    numProductos = 0;                              // Inicializar el número de productos
    while (archivo >> inventario[numProductos].id) // Leer el ID del producto
    {
        archivo.getline(inventario[numProductos].nombre, MAX_NAME_LENGTH);        // Leer el nombre del producto
        archivo.getline(inventario[numProductos].marca, MAX_NAME_LENGTH);         // Leer la marca del producto
        archivo.getline(inventario[numProductos].clasificacion, MAX_NAME_LENGTH); // Leer la clasificación del producto
        archivo.getline(inventario[numProductos].nichoMercado, MAX_NAME_LENGTH);  // Leer el nicho de mercado del producto
        archivo >> inventario[numProductos].precio;                               // Leer el precio del producto
        archivo >> inventario[numProductos].cantidad;                             // Leer la cantidad del producto
        numProductos++; // Incrementar el número de productos
    }
    archivo.close(); // Cerrar el archivo
    return 1; // Retornar 1 si se cargó el inventario con éxito
}

void guardarInventario()
{
    ofstream archivo;
    archivo.open("inventario.txt"); // Abrir el archivo para escritura
    if (archivo.fail()) // Verificar si no se pudo abrir el archivo
    {
        cout << "No se puede abrir el archivo." << endl;
        exit(1);
    }
    for (int i = 0; i < numProductos; i++) // Escribir los datos de los productos en el archivo
    {
        archivo << inventario[i].id << endl; // Escribir el ID del producto
        archivo << inventario[i].nombre << endl; // Escribir el nombre del producto
        archivo << inventario[i].marca << endl; // Escribir la marca del producto
        archivo << inventario[i].clasificacion << endl; // Escribir la clasificación del producto
        archivo << inventario[i].nichoMercado << endl; // Escribir el nicho de mercado del producto
        archivo << inventario[i].precio << endl; // Escribir el precio del producto
        archivo << inventario[i].cantidad << endl; // Escribir la cantidad del producto
    }
    archivo.close(); // Cerrar el archivo
}

void mostrarInventario()
{
    int opc; // Variable para almacenar la opción seleccionada por el usuario
    cout << "\n--------------------------";
    cout << "\nProducto es Farmacia";
    cout << "\n--------------------------" << endl;
    for (int i = 0; i < numProductos; i++)
    {
        cout << i + 1 << ": " << inventario[i].nombre << endl; // Mostrar el nombre del producto
    }
    cout << "\nSeleccione el numero del producto del cual quiere ver detalles: ";
    cin >> opc; // Leer la opción seleccionada por el usuario

    if (opc > numProductos || opc <= 0) // Verificar si la opción seleccionada es válida
    {
        cout << "Seleccione un numero de producto valido";
    }
    else
    {
        cout << "\nDetalles del producto " << opc << endl;
        cout << "-------------------------" << endl;
        cout << "ID: " << inventario[opc - 1].id << endl; // Mostrar el ID del producto
        cout << "Nombre: " << inventario[opc - 1].nombre << endl; // Mostrar el nombre del producto
        cout << "Marca: " << inventario[opc - 1].marca << endl; // Mostrar la marca del producto
        cout << "Clasificacion: " << inventario[opc - 1].clasificacion << endl; // Mostrar la clasificación del producto
        cout << "Nicho de Mercado: " << inventario[opc - 1].nichoMercado << endl; // Mostrar el nicho de mercado del producto
        cout << "Precio: " << inventario[opc - 1].precio << endl; // Mostrar el precio del producto
        cout << "Cantidad: " << inventario[opc - 1].cantidad << endl; // Mostrar la cantidad del producto
    }
}

void editarProducto()
{
    int id; // Variable para almacenar el ID del producto a editar
    cout << "Ingrese el ID del producto a editar: ";
    cin >> id; // Leer el ID del producto a editar

    for (int i = 0; i < numProductos; i++) // Recorre el producto en el inventario
    {
        if (inventario[i].id == id) // Verificar si el ID del producto es igual al ID ingresado
        {
            cout << "Editar producto " << endl;

            cout << "Nombre actual: " << inventario[i].nombre << endl; // Mostrar el nombre actual del producto
            cout << "Nuevo nombre: ";
            scanf(" %[^\n]", inventario[i].nombre); // Leer el nuevo nombre del producto (incluye espacios en blanco)

            cout << "Marca actual: " << inventario[i].marca << endl; // Mostrar la marca actual del producto
            cout << "Nueva marca: ";
            scanf(" %[^\n]", inventario[i].marca); // Leer la nueva marca del producto (incluye espacios en blanco)

            cout << "Clasificacion actual: " << inventario[i].clasificacion << endl; // Mostrar la clasificacion actual del producto
            cout << "Nueva clasificacion: ";
            scanf(" %[^\n]", inventario[i].clasificacion); // Leer la nueva clasificacion del producto (incluye espacios en blanco)

            cout << "Nicho de mercado actual: " << inventario[i].nichoMercado << endl; // Mostrar el nicho de mercado actual del producto
            cout << "Nuevo nicho de mercado: ";
            scanf(" %[^\n]", inventario[i].nichoMercado); // Leer el nuevo nicho de mercado del producto (incluye espacios en blanco)

            cout << "Precio actual: " << inventario[i].precio << endl; // Mostrar el precio actual del producto
            cout << "Nuevo precio: ";
            cin >> inventario[i].precio; // Leer el nuevo precio del producto

            cout << "Cantidad actual: " << inventario[i].cantidad << endl; // Mostrar la cantidad actual del producto
            cout << "Nueva cantidad: ";
            cin >> inventario[i].cantidad; // Leer la nueva cantidad del producto

            cout << "Producto editado con exito." << endl; // Mostrar mensaje de éxito
            guardarInventario();                           // Guardar los cambios en el archivo
            return; 
        }
    }
    cout << "Producto no encontrado." << endl; // Mostrar mensaje si el producto no se encuentra
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
            cout << "Producto eliminado con exito." << endl;
            guardarInventario(); // Guardar los cambios en el archivo
            return;              // Salir de la función
        }
    }
    cout << "Producto no encontrado." << endl;
}

void menuRegistro()
{
    int opt; // Variable para almacenar la opción seleccionada por el usuario
    do
    {
        cout << "\n--------------------------";
        cout << "\n Registro de Productos";
        cout << "\n--------------------------";
        cout << "\n1. Ingresar nuevos productos";
        cout << "\n2. Mostrar inventario";
        cout << "\n3. Editar producto";
        cout << "\n4. Eliminar producto";
        cout << "\n5. Volver al menu principal";
        cout << "\nSeleccione una opcion: ";
        cin >> opt; // Leer la opción seleccionada por el usuario

        switch (opt)
        {
        case 1:
            ingresarDatosProductos(); // Llamar a la función para ingresar los datos de los productos
            guardarInventario(); // Guardar los cambios en el archivo
            break;
        case 2:
            mostrarInventario(); // Llamar a la función para mostrar el inventario
            break;
        case 3:
            editarProducto(); // Llamar a la función para editar un producto
            break;
        case 4:
            eliminarProducto(); // Llamar a la función para eliminar un producto
            break;
        case 5:
            break;
        default:
            cout << "Opcion no valida.";
            break;
        }
    } while (opt != 5);
}