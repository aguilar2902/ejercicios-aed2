/*
   Desarrollar un programa para la gestión de las ventas de un supermercado mediante la implementación
de una pila. Cada nodo deberá contener los siguientes datos asociados a un producto: código del producto,
código de rubro, cantidad, precio unitario y descripción. Además de programar todas las operaciones
básicas, se solicita:
a) Escribir una función que calcule y retorne el monto total recaudado.
b) Implementar un menú principal que contenga todas las operaciones disponibles.
 */

 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char tString[20] ;

typedef struct datosProd{
	long int codProd;
	long int codRubro;
	int cant;
	float precioUnit;
	tString desc;
}tDatosProd;

typedef struct pilaProductos{
	tDatosProd producto;
	struct pilaProductos * siguiente;
}tPilaDatos;

tPilaDatos * pila;

void iniciarPila();
bool pilaVacia(tPilaDatos * );
tDatosProd ingresarDatos();
void push(tDatosProd);
void pop();
tDatosProd obtenerCima(tPilaDatos *);
void mostrarCima(tDatosProd);
void recorrerPila(tPilaDatos *);

float montoTotal(tPilaDatos *);
void menu();

int main(){
	iniciarPila();
	menu();
	return 0;
}

void iniciarPila(){
	pila = NULL;
	printf("Pila inicializada!\n");
}

bool pilaVacia(tPilaDatos *pPila){
	return(pPila==NULL);
}

tDatosProd ingresarDatos(){
	tDatosProd auxProd;
	printf("\nIngrese codigo del producto: ");
	scanf("%d", &auxProd.codProd);
	printf("\nIngrese codigo de rubro: ");
	scanf("%d", &auxProd.codRubro);
	printf("\nIngrese cantidad: ");
	scanf("%d", &auxProd.cant);
	printf("\nIngrese precio unitario: ");
	scanf("%f", &auxProd.precioUnit);
	printf("\nIngrese descripcion: ");
	fflush(stdin);
	gets(auxProd.desc);

	return auxProd;
}


void push(tDatosProd pProducto){
	tPilaDatos * nuevoNodo = (tPilaDatos *) malloc(sizeof(tPilaDatos));

	nuevoNodo->producto = pProducto;

	if(pilaVacia(pila)){
		nuevoNodo->siguiente = NULL;
	}else{
		nuevoNodo->siguiente = pila;
	}

	pila = nuevoNodo;
}

void pop(){
	if(pilaVacia(pila)){
		printf("\n\nPila vacia!");
	}else{
		tPilaDatos * nuevoNodo = pila;

		pila = pila->siguiente;

		free(nuevoNodo);
		nuevoNodo = NULL;
	}
}

tDatosProd obtenerCima(tPilaDatos *pPila){
	if(!pilaVacia(pPila)){
		return(pPila->producto);
	}
}

void recorrerPila(tPilaDatos *pPila){
	if(pilaVacia(pPila)){
		printf("\n\nPila vacia!");
	}else{
		tPilaDatos * auxPila = pPila;

		printf("\n ------------ DATOS PRODUCTOS ------------");
		while(pPila!=NULL){
			printf("\n\nCodigo producto: %d", pPila->producto.codProd);
			printf("\nCodigo rubro: %d", pPila->producto.codRubro);
			printf("\nCantidad: %d", pPila->producto.cant);
			printf("\nPrecio unitario: %.2f", pPila->producto.precioUnit);
			printf("\nDescripcion: %s", pPila->producto.desc);

			pPila = pPila->siguiente;
		}
	}
}

float montoTotal(tPilaDatos *pPila){
	float montoTotal = 0;
		tPilaDatos * auxPila = pPila;
	while(pPila!=NULL){
		montoTotal = montoTotal + (float)pPila->producto.cant * pPila->producto.precioUnit;
		pPila = pPila->siguiente;
	}
	return montoTotal;

}

void menu(){
	int opcion;

	printf("\n------------ OPCIONES DISPONIBLES ------------");
	printf("\n1 - Apilar");
	printf("\n2 - Desapilar");
	printf("\n3 - Obtener cima");
	printf("\n4 - Visualizar elementos");
	printf("\n5 - Conocer monto total");
	printf("\n0 - Salir");
	printf("\nSeleccione una opcion: ");
	scanf("%d", &opcion);

	switch(opcion){
		case 1:
			push(ingresarDatos());
			menu();
			break;
		case 2:
			pop();
			menu();
			break;
		case 3:
			mostrarCima(obtenerCima(pila));
			menu();
			break;
		case 4:
			recorrerPila(pila);
			menu();
			break;
		case 5:
			if(pila!=NULL){
				printf("Monto total: %.2f", montoTotal(pila));
			}else{
				printf("\n\nPila vacia!");
			}
			menu();
			break;
		default:
			break;
	}
}

void mostrarCima(tDatosProd pCima){
	if(pilaVacia(pila)){
		printf("\n\nPila vacia!");
	}else{
		printf("\n\nCodigo producto: %d", pCima.codProd);
		printf("\nCodigo rubro: %d", pCima.codRubro);
		printf("\nCantidad: %d", pCima.cant);
		printf("\nPrecio unitario: %.2f", pCima.precioUnit);
		printf("\nDescripcion: %s", pCima.desc);
	}
}
