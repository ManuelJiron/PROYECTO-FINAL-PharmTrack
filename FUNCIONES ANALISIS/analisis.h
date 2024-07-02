/*#ifndef en C++ se utiliza para verificar si un identificador no ha sido definido previamente
 en el archivo o en un archivo incluido.*/

#ifndef ANALISIS_H // Para evitar errores si se llegase a definir dos veces la misma librería
#define ANALISIS_H // Definir la librería

#include <iostream> // Librería para el manejo de entrada y salida
#include <fstream> // Para operaciones de archivos
#include <cstdlib> // Para funciones generales de C
#include <cstring> // Para funciones de manipulación de cadenas
#include "inventario.h" // Incluir el archivo inventario.h
#include "ventas.h" // Incluir el archivo ventas.h

void productosMasVendidos(); // Función para mostrar los productos más vendidos
void productoMenosVendido(); // Función para mostrar el producto menos vendido
void calcularIngresosTotales(); // Función para calcular los ingresos totales
void clientesMasFrecuentes(); // Función para mostrar los clientes más frecuentes
void stockCritico(); // Función para mostrar los productos en stock crítico
void menuAnalisis(); // Función para mostrar el menú de análisis

#endif // Fin de la librería