/*#ifndef en C++ se utiliza para verificar si un identificador no ha sido definido previamente
 en el archivo o en un archivo incluido.*/

#ifndef VENTAS_H // Si no está definido el archivo ventas.h
#define VENTAS_H // Definir el archivo ventas.h

#include <iostream> // Librería para el manejo de entrada y salida
#include <fstream> // Para operaciones de archivos
#include <cstdlib> // Para funciones generales de C
#include <cstring> // Para funciones de manipulación de cadenas
#include "inventario.h" // Incluir el archivo inventario.h

#define MAX_VENTAS 100 // Definir el número máximo de ventas

typedef struct VENTA // Estructura para almacenar la información de una venta
{
    int productoId; // Identificador del producto
    char productoVendido[MAX_NAME_LENGTH]; // Nombre del producto
    int cantidadVendida; // Cantidad vendida
    char cliente[MAX_NAME_LENGTH]; // Nombre del cliente
} VENTA;

/*Al declarar una variable o función como extern, le decimos al compilador que la variable o 
función ya existe en otro archivo o módulo de programa.*/

extern VENTA ventas[MAX_VENTAS]; // Arreglo de ventas
extern int numVentas; // Número de ventas

void registrarVenta(); // Registrar una venta
void guardarVentas(); // Guardar las ventas en un archivo
int cargarVentas(); // Cargar las ventas de un archivo
void mostrarVentas(); // Mostrar las ventas
void menuVentas(); // Menú de ventas

#endif // Fin de la definición del archivo ventas.h