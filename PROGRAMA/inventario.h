/*#ifndef en C++ se utiliza para verificar si un identificador no ha sido definido previamente
 en el archivo o en un archivo incluido.*/

#ifndef INVENTARIO_H // Si no está definido el archivo inventario.h
#define INVENTARIO_H // Definir el archivo inventario.h

#include <iostream> // Librería para el manejo de entrada y salida
#include <fstream>  // Para operaciones de archivos
#include <cstdlib>  // Para funciones generales de C
#include <cstring>  // Para funciones de manipulación de cadenas

#define MAX_PRODUCTOS 100  // Número máximo de productos
#define MAX_NAME_LENGTH 30 // Longitud máxima de los nombres

typedef struct PRODUCTO // Estructura para almacenar la información de un producto
{
    int id;                              // Identificador del producto
    char nombre[MAX_NAME_LENGTH];        // Nombre del producto
    char marca[MAX_NAME_LENGTH];         // Marca del producto
    char clasificacion[MAX_NAME_LENGTH]; // Clasificación del producto
    char nichoMercado[MAX_NAME_LENGTH];  //  Nicho de mercado del producto
    float precio;                        // Precio del producto
    int cantidad;                        // Cantidad del producto
} PRODUCTO;

/*Al declarar una variable o función como extern, le decimos al compilador que la variable o 
función ya existe en otro archivo o módulo de programa.*/

extern PRODUCTO inventario[MAX_PRODUCTOS]; // Arreglo de productos
extern int numProductos; // Número de productos

void ingresarDatosProductos(); // Ingresar los datos de los productos
int cargarInventario();        // Cargar el inventario de un archivo
void guardarInventario();      // Guardar el inventario en un archivo
void mostrarInventario();      // Mostrar el inventario
void editarProducto();         // Editar un producto del inventario
void eliminarProducto();       // Eliminar un producto del inventario
void menuRegistro();           // Menú de registro de productos

#endif // Fin de la definición del archivo inventario.h