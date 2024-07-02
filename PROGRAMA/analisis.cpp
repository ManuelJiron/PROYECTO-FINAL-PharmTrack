#include "analisis.h"

using namespace std;

void productosMasVendidos()
{
    system("cls");
    cout << "\n--------------------------";
    cout << "\nProductos mas vendidos";
    cout << "\n--------------------------" << endl;
    if (numVentas == 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    int cantidadVendida[MAX_PRODUCTOS] = {0}; // Arreglo para almacenar la cantidad vendida de cada producto

    for (int i = 0; i < numVentas; i++) // Contar la cantidad vendida de cada producto
    {
        for (int j = 0; j < numProductos; j++)
        {
            if (ventas[i].productoId == inventario[j].id) // Verificar si el ID del producto en la venta coincide con el ID del producto en el inventario
            {
                cantidadVendida[j] += ventas[i].cantidadVendida; // Incrementar la cantidad vendida del producto
                break;
            }
        }
    }

    int maxIndex = 0;                      // Variable para almacenar el índice del producto con la mayor cantidad vendida
    for (int i = 1; i < numProductos; i++) // Encontrar el producto con la mayor cantidad vendida
    {
        if (cantidadVendida[i] > cantidadVendida[maxIndex]) /*Verificar si la cantidad vendida del producto actual es mayor que
                                                            la cantidad vendida del producto con la mayor cantidad vendida*/
        {
            maxIndex = i; // Actualizar el índice del producto con la mayor cantidad vendida
        }
    }

    cout << "Producto mas vendido: " << inventario[maxIndex].nombre << endl; // Mostrar el producto más vendido
    cout << "Cantidad vendida: " << cantidadVendida[maxIndex] << endl;       // Mostrar la cantidad vendida del producto más vendido
}

void productoMenosVendido()
{
    system("cls");
    cout << "\n--------------------------";
    cout << "\nProducto menos vendido";
    cout << "\n--------------------------" << endl;
    if (numVentas == 0) // Verificar si no hay ventas registradas
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    int ventasPorProducto[MAX_PRODUCTOS] = {0}; // Arreglo para almacenar las ventas por producto

    for (int i = 0; i < numVentas; i++)
    {
        for (int j = 0; j < numProductos; j++)
        {
            if (ventas[i].productoId == inventario[j].id) // Verificar si el ID del producto en la venta coincide con el ID del producto en el inventario
            {
                ventasPorProducto[j] += ventas[i].cantidadVendida; // Incrementar las ventas por producto
                break;
            }
        }
    }

    int minIndex = 0; // Variable para almacenar el índice del producto con la menor cantidad vendida
    for (int i = 1; i < numProductos; i++)
    {
        if (ventasPorProducto[i] < ventasPorProducto[minIndex]) // Encontrar el producto con la menor cantidad vendida
        {
            minIndex = i; // Actualizar el índice del producto con la menor cantidad vendida
        }
    }

    cout << "Producto menos vendido: " << inventario[minIndex].nombre << endl; // Mostrar el producto menos vendido
    cout << "Cantidad vendida: " << ventasPorProducto[minIndex] << endl;       // Mostrar la cantidad vendida del producto menos vendido
}

void calcularIngresosTotales()
{
    system("cls");
    float ingresos = 0;
    cout << "\n--------------------------";
    cout << "\nIngresos Totales";
    cout << "\n--------------------------" << endl;
    for (int i = 0; i < numVentas; i++)
    {
        for (int j = 0; j < numProductos; j++)
        {
            if (ventas[i].productoId == inventario[j].id)
            {
                ingresos += ventas[i].cantidadVendida * inventario[j].precio;
            }
        }
    }
    cout << "El ingreso total es: " << ingresos << endl;
}

void clientesMasFrecuentes()
{
    system("cls");
    cout << "\n--------------------------";
    cout << "\nClientes mas frecuentes";
    cout << "\n--------------------------" << endl;
    int maxFrecuencia = 0;                     // Variable para almacenar la mayor frecuencia de un cliente
    char clienteMasFrecuente[MAX_NAME_LENGTH]; // Variable para almacenar el nombre del cliente más frecuente

    for (int i = 0; i < numVentas; i++)
    {
        int frecuencia = 0; // Variable para almacenar la frecuencia de un cliente
        for (int j = 0; j < numVentas; j++)
        {
            if (strcmp(ventas[i].cliente, ventas[j].cliente) == 0) /*Verificar si el nombre del cliente coincide
                                                                     strcmp() compara dos cadenas y devuelve 0 si son iguales*/
            {
                frecuencia++; // Incrementar la frecuencia si el nombre del cliente coincide
            }
        }
        if (frecuencia > maxFrecuencia) // Verificar si la frecuencia del cliente actual es mayor que la frecuencia del cliente más frecuente
        {
            maxFrecuencia = frecuencia;                     // Actualizar la mayor frecuencia
            strcpy(clienteMasFrecuente, ventas[i].cliente); // Copiar el nombre del cliente más frecuente, strcpy() copia una cadena a otra
        }
    }
    cout << "\nCliente más frecuente: " << clienteMasFrecuente << " con " << maxFrecuencia << " compras \n"
         << endl;
}

void stockCritico()
{
    system("cls");
    cout << "\n--------------------------";
    cout << "\nStock Critico";
    cout << "\n--------------------------" << endl;
    for (int i = 0; i < numProductos; i++)
    {
        if (inventario[i].cantidad <= 5) // Verificar si la cantidad del producto es igual o menor a 5
        {                                // Mostrar los productos en stock crítico
            cout << "ID: " << inventario[i].id << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Marca: " << inventario[i].marca << endl;
            cout << "Clasificacion: " << inventario[i].clasificacion << endl;
            cout << "Nicho de mercado: " << inventario[i].nichoMercado << endl;
            cout << "Precio: " << inventario[i].precio << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            cout << "--------------------------------------------\n";
        }
    }
}

void menuAnalisis()
{
    int opt; // Variable para almacenar la opción seleccionada por el usuario
    do
    {
        cout << "\n--------------------------";
        cout << "\n Analisis del Mercado";
        cout << "\n--------------------------";
        cout << "\n1. Productos mas vendidos";
        cout << "\n2. Producto menos vendido";
        cout << "\n3. Calcular ingresos totales";
        cout << "\n4. Clientes mas frecuentes";
        cout << "\n5. Stock critico";
        cout << "\n6. Volver al menu principal";
        cout << "\nSeleccione una opcion: ";
        cin >> opt; // Leer la opción

        switch (opt)
        {
        case 1:
            productosMasVendidos(); // Llamar a la función productosMasVendidos()
            break;
        case 2:
            productoMenosVendido(); // Llamar a la función productoMenosVendido()
            break;
        case 3:
            calcularIngresosTotales(); // Llamar a la función calcularIngresosTotales()
            break;
        case 4:
            clientesMasFrecuentes(); // Llamar a la función clientesMasFrecuentes()
            break;
        case 5:
            stockCritico(); // Llamar a la función stockCritico()
            break;
        case 6:
            break;
        default:
            cout << "Opcion no valida.";
            break;
        }
    } while (opt != 6);
}