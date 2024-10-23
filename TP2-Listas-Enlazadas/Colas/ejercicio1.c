/*
	En la recepci�n de un banco, la recepcionista entrega un ticket con el n�mero de
	atenci�n a cada persona.
	El sistema almacena los siguientes datos de cada turno: n�mero de turno, nombre del cliente
	y motivo (1.transacci�n 2. consulta).
	Adem�s de las operaciones b�sicas para el manejo de la cola con punteros, se solicita
	disponer de:
		a) una funci�n que devuelva la cantidad de personas que est�n esperando un turno para
		realizar una �transacci�n�
		b) una funci�n que devuelva la cantidad de personas que est�n esperando un turno para
		realizar una �consulta�
		c) un listado que permita visualizar el orden, nombre y motivo de cada persona en la cola.
		d) Implementar un men� principal que contenga todas las operaciones disponibles.

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString [50];


typedef struct {
	int numTurno;
	tString nombre;
	tString apellido;
	int motivo;
} tDatosCliente;


typedef struct nodo{
	tDatosCliente datosCliente;
	struct nodo *siguiente;
}tNodo;


typedef struct {
	tNodo * inicio;
	tNodo * final;
} tCola;

tCola cola;

void inicializarCola();
bool colaVacia();
tDatosCliente ingresarCliente();
void insertarCola (tDatosCliente);
void desencolarCola();
void contarTransacciones();
void contarConsultas();
void mostrarCola();
void menu();

int main (){
	tDatosCliente auxCliente;

	inicializarCola();
	menu();
	return 0;
}


void inicializarCola(){
	cola.inicio = NULL;
	cola.final = NULL;
}


bool colaVacia(){
	return(cola.inicio == NULL && cola.final == NULL);
}


tDatosCliente ingresarCliente(){
	tDatosCliente auxCliente;

	printf("Ingrese \n");
	printf("\tnumero de turno: ");
	scanf("%d",&auxCliente.numTurno);

	printf("\tNombre del cliente: ");
	scanf("%s",&auxCliente.nombre);

	printf("\tApellido del cliente: ");
	scanf("%s",&auxCliente.apellido);

	printf("\tMotivo del turno (1.transaccion 2.consulta): ");
	scanf("%d",&auxCliente.motivo);

	return auxCliente;
}

void insertarCola (tDatosCliente pDatosCliente){
	tNodo *nuevoNodo;
	nuevoNodo = (tNodo *) malloc (sizeof(tNodo));
	nuevoNodo-> datosCliente = pDatosCliente;
	nuevoNodo-> siguiente = NULL;

	if(colaVacia()){
		cola.inicio = nuevoNodo;
		cola.final = nuevoNodo;
	}else{
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}
}

void desencolarCola(){
	  if (colaVacia()) {
        printf("La cola esta vacia!\n");
        return;
    }
	tNodo* temp = cola.inicio;
    cola.inicio = cola.inicio -> siguiente;
     if (cola.inicio == NULL) {
        cola.final = NULL;
    }
    printf("Cliente desencolado: Turno %d, Nombre: %s %s\n", temp->datosCliente.numTurno, temp->datosCliente.nombre, temp->datosCliente.apellido);
    free(temp);
}

void contarTransacciones(){
	tNodo *actual = cola.inicio;
    int contador = 0;
    while (actual != NULL) {
        if (actual->datosCliente.motivo == 1) {
            contador++;
        }
        actual = actual->siguiente;
    }
    printf("Clientes esperando por transaccion: %d\n", contador);
}

void contarConsultas(){
	 tNodo *actual = cola.inicio;
    int contador = 0;
    while (actual != NULL) {
        if (actual->datosCliente.motivo == 2) {
            contador++;
        }
        actual = actual->siguiente;
    }
    printf("Clientes esperando por consulta: %d\n", contador);
}

void mostrarCola(){
	  tNodo *actual = cola.inicio;
    if (colaVacia()) {
        printf("La cola esta vacia\n");
        return;
    }

    printf("Lista de clientes en la cola:\n");
    while (actual != NULL) {
        printf("Turno: %d, Nombre: %s %s, Motivo: %d\n",
               actual->datosCliente.numTurno,
               actual->datosCliente.nombre,
               actual->datosCliente.apellido,
               actual->datosCliente.motivo);
        actual = actual->siguiente;
    }
}

void menu(){
	 int opcion;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Insertar cliente en la cola\n");
        printf("2. Desencolar cliente\n");
        printf("3. Contar clientes para transacciin\n");
        printf("4. Contar clientes para consulta\n");
        printf("5. Mostrar cola\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                insertarCola(ingresarCliente());
                break;
            case 2:
                desencolarCola();
                break;
            case 3:
                contarTransacciones();
                break;
            case 4:
                contarConsultas();
                break;
            case 5:
                mostrarCola();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 6);
}
