Proceso registrarCompra
	Definir nombreProducto, marcaProducto, clasificacionProducto Como Cadena;
	Definir cantidadProducto Como Entero;
	Definir precioProducto, total Como Real;
	Escribir 'Ingrese el nombre del producto: ';
	Leer nombreProducto;
	Escribir 'Ingrese la marca del producto: ';
	Leer marcaProducto;
	Escribir 'Ingrese la clasificación del producto: ';
	Leer clasificacionProducto;
	Escribir 'Ingrese la cantidad: ';
	Leer cantidadProducto;
	Escribir 'Ingrese el precio del producto: ';
	Leer precioProducto;
	total <- cantidadProducto*precioProducto;
FinProceso
