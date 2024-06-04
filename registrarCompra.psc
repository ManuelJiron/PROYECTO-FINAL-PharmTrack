Proceso registrarCompra
	Definir cantidad, i Como Entero;
	Definir nombreProducto, marcaProducto, clasificacionProducto Como Cadena;
	Definir precioProducto Como Real;
	Escribir "Ingrese la cantidad de productos a registrar: ";
	Leer cantidad;
	Para i<-1 Hasta cantidad Hacer
		Escribir "Ingrese el nombre del producto ", i, ": ";
		Leer nombreProducto;
		Escribir "Ingrese la marca del producto ", i, ": ";
		Leer marcaProducto;
		Escribir "Ingrese la clasificación del producto ", i, ": ";
		Leer clasificacionProducto;
		Escribir "Ingrese el precio del producto ", i, ": ";
		Leer precioProducto;
		Escribir "Producto ", i, " registrado con éxito.";
	FinPara
FinProceso
