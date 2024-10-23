/*
La registración a un evento de informática se realiza a través de la inscripción online mediante un
formulario web. Para ello se registran los datos de los inscriptos en una pila con los siguientes datos: DNI,
Nombre y Apellido, e-mail, Código de Categoría (01-Estudiantes 02-Profesionales 03-Público en general)
y Monto Abonado. El valor de la inscripción es de $200 para los estudiantes y $350 para profesionales y el
público en general, valor que se abona al momento de la inscripción (tener en cuenta esto al momento de
apilar inscriptos). Realizar las funciones necesarias para obtener:
a) la cantidad de Profesionales que se inscribieron al evento, y el porcentaje que representan sobre
el total de inscriptos
b) el monto recaudado de inscriptos de la categoría Estudiantes
c) el total recaudado en concepto de inscripciones
Tener en cuenta que se deben realizar las operaciones básicas necesarias para la manipulación de la pila con
punteros.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char tString[50];

typedef struct datosInscriptos{
	long int DNI;
	tString nombreApellido;
	tString email;
	int codCategoria;
	int montoAbonado;
}tDatos;

typedef struct pila{
	tDatos inscripto;
	struct pila * siguiente;
}tPila;

tPila * pila;

void iniciarPila();
bool pilaVacia(tPila *);

void push(tDatos);
tDatos ingresarDatos();
void pop();

tDatos obtenerCima(tPila *);
void mostrarCima(tDatos);
void recorrerPila(tPila *);


void cantYporcentajeProf(tPila *);
void montoEstudiantes(tPila *);
void montoTotal(tPila *);

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

bool pilaVacia(tPila *pPila){
	return(pPila==NULL);
}

void menu(){
	int opcion;

	printf("--------------- OPCIONES DISPONIBLES ---------------");
	printf("\n1 - Apilar");
	printf("\n2 - Desapilar");
	printf("\n3 - Obtener cima");
	printf("\n4 - Recorrer pila");
	printf("\n5 - Cantidad y porcentaje de profesionales");
	printf("\n6 - Monto categoria estudiantes");
	printf("\n7 - Monto total recaudado");

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
			if(!pilaVacia(pila)){
				mostrarCima(obtenerCima(pila));
			}else{
				printf("\nPila vacia!");
			}
			menu();
			break;
		case 4:
			recorrerPila(pila);
			menu();
			break;
		case 5:
			cantYporcentajeProf(pila);
			menu();
			break;
		case 6:
			montoEstudiantes(pila);
			menu();
			break;
		case 7:
			montoTotal(pila);
			menu();
			break;
		default:
			break;
	}
}

tDatos ingresarDatos(){
	tDatos auxInscripto;
	printf("\n\nIngrese DNI: ");
	scanf("%d", &auxInscripto.DNI);


	printf("\nIngrese nombre y apellido: ");
	fflush(stdin);
	gets(auxInscripto.nombreApellido);

	printf("\nIngrese email: ");
	fflush(stdin);
	gets(auxInscripto.email);

	printf("\n\nIngrese codigo de categoria: ");
	printf("\n1 - Estudiante");
	printf("\n2 - Profesional");
	printf("\n3 - Publico general");
	printf("\nCategoria: ");
	scanf("%d", &auxInscripto.codCategoria);

	if(auxInscripto.codCategoria==1){
		auxInscripto.montoAbonado=200;
	}else{
		auxInscripto.montoAbonado=350;
	}
	return auxInscripto;
}

void push(tDatos pInscripto){
	tPila *nuevoNodo = (tPila *) malloc(sizeof(tPila));

	nuevoNodo->inscripto = pInscripto;

	if(pila==NULL){
		nuevoNodo->siguiente=NULL;
	}else{
		nuevoNodo->siguiente=pila;
	}

	pila = nuevoNodo;
}

void pop(){
	tPila *nodoSuprimir = pila;

	pila = pila->siguiente;
	free(nodoSuprimir);
	nodoSuprimir = NULL;
}

tDatos obtenerCima(tPila *pPila){
	return(pPila->inscripto);
}

void mostrarCima(tDatos pInscripto){
	printf("\n----------------- CIMA -----------------");
	printf("\t\nDNI: %d", pInscripto.DNI);
	printf("\t\nNombre y apellido: %s", pInscripto.nombreApellido);
	printf("\t\nEmail: %s", pInscripto.email);
	printf("\t\nCodigo de categoria: %d", pInscripto.codCategoria);
	printf("\t\nMonto abonado: %d\n", pInscripto.montoAbonado);
}

void recorrerPila(tPila *pPila){
	if(pilaVacia(pPila)){
		printf("\nPila vacia!");
	}else{
		tPila *auxPila = pPila;
		printf("\n----------------- INSCRIPTOS -----------------\n");
		while(auxPila!=NULL){
			printf("\t\nDNI: %d\n\n", auxPila->inscripto.DNI);
			printf("\t\nNombre y apellido: %s", auxPila->inscripto.nombreApellido);
			printf("\t\nEmail: %s", auxPila->inscripto.email);
			printf("\t\nCodigo categoria: %d", auxPila->inscripto.codCategoria);
			printf("\t\nMonto abonado: %d\n\n", auxPila->inscripto.montoAbonado);
			auxPila = auxPila->siguiente;
		}
	}
}


void cantYporcentajeProf(tPila * pPila){
	int cantInsc = 0;
	int cantProf = 0;
	float porcentajeProf = 0;

	tPila *auxPila = pPila;
	while(pPila!=NULL){
		cantInsc++;
		if(pPila->inscripto.codCategoria==2){
			cantProf++;
		}
		pPila = pPila->siguiente;
	}

	porcentajeProf=((float)cantProf/cantInsc)*100;

	printf("\n----------------- PROFESIONALES -----------------");
	printf("\nCantidad de profesiones inscriptos: %d\n", cantProf);
	printf("\nPorcentaje que representan del total: %.2f%%\n\n", porcentajeProf);
}

void montoEstudiantes(tPila *pPila){
	int montoEst = 0;
	tPila *auxPila = pPila;
	while(pPila!=NULL){
		if(pPila->inscripto.codCategoria==1){
			montoEst = montoEst + pPila->inscripto.montoAbonado;
		}
		pPila = pPila->siguiente;
	}

	printf("\nMONTO RECAUDADO CATEGORIA ESTUDIANTE: %d\n\n", montoEst);
}

void montoTotal(tPila *pPila){
	int montoTotal = 0;
	tPila *auxPila = pPila;
	while(pPila!=NULL){
		montoTotal = montoTotal + pPila->inscripto.montoAbonado;
		pPila = pPila->siguiente;
	}

	printf("\nMONTO TOTAL RECAUDADO: %d\n\n", montoTotal);
}
