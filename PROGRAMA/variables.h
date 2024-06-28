#define MAX_PRODUCTOS 100  // Máximo número de productos
#define MAX_NAME_LENGTH 30 // Máximo de longitud de los nombres
#define MAX_VENTAS 100     // Máximo número de ventas

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