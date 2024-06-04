Proceso showTotalsells
	Definir Registro Como Entero;
	Definir ventasTotales Como Real;
	
	Para i<-0 Hasta Registro Hacer
		ventasTotales <- ventasTotales + i;
	FinPara
	
	Escribir "Las ventas totales es igual a: ", ventasTotales;
FinProceso
