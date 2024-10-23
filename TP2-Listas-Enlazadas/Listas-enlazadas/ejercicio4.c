/*
*Un Instituto médico realiza una encuesta sobre nutrición. Para procesar los datos de los encuestados
requiere un sistema, que implemente una lista enlazada. Para ello se capturan los siguientes datos: código
de sexo (F. Femenino, M. Masculino), código de rango de edad (01. Menor de 15 años, 02. Entre 15 y 30
años, 03. Más de 30 años), peso y altura. El sistema debe calcular el IMC (índice de masa corporal) antes
de insertar un elemento en la lista, y almacenar la clasificación del IMC (string) como parte contenida de
cada nodo.
 * FORMULA del IMC = kg /m^2
 * Peso Bajo (Mujeres < 20, varones < 19)
 * Peso Normal (Mujeres <26, varones < 25)
 * Sobrepeso (Mujeres > 25, varones > 24)
 *
* Se solicita realizar las funciones necesarias para que los usuarios del sistema puedan obtener los
siguientes informes:
a) La cantidad total de encuestados.
b) El promedio de pesos de las personas de peso bajo, que sean menores de 15 años.
c) Un listado de los datos correspondientes a las personas que tienen sobrepeso.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char tString[15];

typedef struct datosPersona{
	char codSexo;
	int codRangoEdad;
	float peso;
	float altura;
	tString clasifIMC;
}tDatosPersona;

typedef struct lista{
	tDatosPersona persona;
	struct lista * siguiente;
}tLista;

tLista * lista;

void iniciarLista();
bool listaVacia(tLista *);

tDatosPersona ingresarDatos();

void insertarNodo(tDatosPersona);
void insertarPrimer(tDatosPersona);
void insertarAdelante(tDatosPersona);
void insertarPosK(tDatosPersona);

void eliminarPrimer();
void eliminarPosK(tLista *);

void visualizarEncuestados(tLista *);
void menu();

int cantEncuestados(tLista *);
float promPesoBajo(tLista *);
void listaSobrepeso(tLista *);

int main(){
	iniciarLista();
	menu();
	return 0;
}

void menu(){

	int opcion;
	printf("\n\n***** OPCIONES DISPONIBLES *****");
	printf("\n1 - Insertar encuestado");
	printf("\n2 - Eliminar primer encuestado");
	printf("\n3 - Insertar encuestado en posicion K");
	printf("\n4 - Eliminar encuestado en posicion K");
	printf("\n5 - Visualizar lista de encuestados");
	printf("\n6 - Cantidad de encuestados");
	printf("\n7 - Promedio de peso bajo menores a 15 a�os");
	printf("\n8 - Encuestados con sobrepeso");
	printf("\n0 - Salir");

	printf("\nSeleccione una opcion: ");
	scanf("%d", &opcion);

	switch(opcion){
		case 1:
			printf("\nOpcion elegida: Insertar encuestado");
			insertarNodo(ingresarDatos());
			menu();
			break;
		case 2:
			printf("\nOpcion elegida: Eliminar encuestado");
			eliminarPrimer();
			menu();
			break;
		case 3:
			printf("\nOpcion elegida: Insertar encuestado en posicion K");
			insertarPosK(ingresarDatos());
			menu();
			break;
		case 4:
			printf("\nOpcion elegida: Eliminar encuestado en posicion K");
			eliminarPosK(lista);
			menu();
			break;
		case 5:
			printf("\nOpcion elegida: Visualizar lista");
			visualizarEncuestados(lista);
			menu();
			break;
		case 6:
			printf("\nOpcion elegida: Ver cantidad de encuestados");
			printf("\nCantidad de encuestados: %d", cantEncuestados(lista));
			menu();
			break;
		case 7:
			printf("\nOpcion elegida: Promedio de peso bajo menores a 15 anios");
			printf("\nPromedio de personas con peso bajo: %.2f", promPesoBajo(lista));
			menu();
			break;
		case 8:
			printf("\nOpcion elegida: Encuestados con sobrepeso");
			listaSobrepeso(lista);
			menu();
			break;
		default:
			printf("\nOpcion elegida: Salir");
			break;
	}
}

void iniciarLista(){
	lista = NULL;

	printf("Lista inicializada!");
}


bool listaVacia(tLista *pLista){
	return(pLista==NULL);
}

tDatosPersona ingresarDatos(){
	tDatosPersona auxPersona;

	printf("\nIngrese codigo de sexo, F-Femenino, M-Masculino: ");
	fflush(stdin);
	scanf("%c", &auxPersona.codSexo);

	printf("\n\nIngrese codigo de rango de edad:");
	printf("\n1. Menor de 15 anios");
	printf("\n2. Entre 15 y 30 anios");
	printf("\n3. Mayor de 30 anios");
	printf("\nCodigo: ");
	scanf("%d", &auxPersona.codRangoEdad);


	printf("\n\nIngrese peso: ");
	scanf("%f", &auxPersona.peso);

	printf("\n\nIngrese altura (metros): ");
	scanf("%f", &auxPersona.altura);

	float IMC = (auxPersona.peso)/(auxPersona.altura * auxPersona.altura);

	switch(auxPersona.codSexo){
		case 'M':
			if(IMC<19){
				strcpy(auxPersona.clasifIMC, "Peso bajo");
			}
			else if(IMC>=19 && IMC<=24){
				strcpy(auxPersona.clasifIMC, "Peso normal");
			}
			else{
				strcpy(auxPersona.clasifIMC, "Sobrepeso");
			}
			break;
		case 'F':
			if(IMC<20){
				strcpy(auxPersona.clasifIMC, "Peso bajo");
			}else if(IMC>=20 && IMC<=25){
				strcpy(auxPersona.clasifIMC, "Peso normal");
			}else{
				strcpy(auxPersona.clasifIMC, "Sobrepeso");
			}
			break;
	}

	return auxPersona;
}

void insertarNodo(tDatosPersona pPersona){
	if(lista==NULL){
		insertarPrimer(pPersona);
	}else{
		insertarAdelante(pPersona);
	}
}
void insertarPrimer(tDatosPersona pPersona){
	tLista * nuevoNodo = (tLista *) malloc(sizeof(tLista));

	lista = nuevoNodo;

	nuevoNodo->persona = pPersona;
	nuevoNodo->siguiente = NULL;
}

void insertarAdelante(tDatosPersona pPersona){
	tLista * nuevoNodo = (tLista *) malloc(sizeof(tLista));

	nuevoNodo->persona = pPersona;
	nuevoNodo->siguiente = lista;

	lista = nuevoNodo;
}

void insertarPosK(tDatosPersona pPersona){
	int pos;
	int i;
	printf("\nPosicion a insertar: ");
	scanf("%d", &pos);

	if(pos==1){
		insertarNodo(ingresarDatos());
	}else{
		tLista * auxLista = lista;

		tLista * nuevoNodo = (tLista *) malloc(sizeof(tLista));

		for(i=1; i<pos-1; i++)
		{
			auxLista = auxLista->siguiente;
		}

		nuevoNodo = auxLista->siguiente;

		auxLista->siguiente = nuevoNodo;
	}
}

void eliminarPrimer(){
	if(listaVacia(lista)){
		printf("\n***** LISTA VACIA *****");
	}else{
		tLista * nodoSuprimir = lista;

		lista = lista->siguiente;

		free(nodoSuprimir);
		nodoSuprimir = NULL;
	}
}

void eliminarPosK(tLista * pLista){
	if(listaVacia(lista)){
		printf("\n***** LISTA VACIA *****");
	}else{
		int pos;
		int i;
		printf("\nPosicion a eliminar: ");
		scanf("%d", &pos);

		if(pos==1){
			eliminarPrimer();
		}else{
			tLista * auxLista = pLista;

			tLista * nodoSuprimir;
			for(i=1; i<pos-1; i++)
			{
				auxLista = auxLista->siguiente;
			}

			nodoSuprimir = auxLista->siguiente;

			auxLista->siguiente = nodoSuprimir->siguiente;

			free(nodoSuprimir);
			nodoSuprimir = NULL;
		}
	}
}

void visualizarEncuestados(tLista * pLista){
	if(listaVacia(lista)){
		printf("\n***** LISTA VACIA *****");
	}
	else{
		tLista *auxLista = pLista;
		printf("\n\n***** DATOS ENCUESTADOS *****\n");
		while(auxLista!=NULL){
			printf("\nSexo: %c", auxLista->persona.codSexo);

			switch(auxLista->persona.codRangoEdad){
				case 1:
					printf("\nRango de edad: menor de 15 anios");
					break;
				case 2:
					printf("\nRango de edad: entre 15 y 30 anios");
					break;
				case 3:
					printf("\nRango de edad: mayor a 30 anios");
					break;
			}

			printf("\nPeso: %.2f", auxLista->persona.peso);
			printf("\nAltura: %.2f", auxLista->persona.altura);
			printf("\nClasificacion IMC: %s\n", auxLista->persona.clasifIMC);

			auxLista = auxLista->siguiente;
		}
	}
}

float promPesoBajo(tLista * pLista){
	int personasPesoBajo = 0;
	int cantEncuestados = 0;

	tLista *auxLista = pLista;

	while(auxLista!=NULL){
		cantEncuestados++;
		if(strcmp(auxLista->persona.clasifIMC, "Peso bajo")==0){
			personasPesoBajo++;

		}
		auxLista = auxLista->siguiente;
	}

	return ((float)personasPesoBajo/cantEncuestados)*100;
}
void listaSobrepeso(tLista * pLista){
	tLista *auxLista = pLista;

	while(auxLista!=NULL){
		if(strcmp(auxLista->persona.clasifIMC, "Sobrepeso")==0){
			printf("\nSexo: %c", auxLista->persona.codSexo);

			switch(auxLista->persona.codRangoEdad){
				case 1:
					printf("\nRango de edad: menor de 15 anios");
					break;
				case 2:
					printf("\nRango de edad: entre 15 y 30 anios");
					break;
				case 3:
					printf("\nRango de edad: mayor a 30 anios");
					break;
			}

			printf("\nPeso: %.2f", auxLista->persona.peso);
			printf("\nAltura: %.2f", auxLista->persona.altura);
			printf("\nClasificacion IMC: %s\n", auxLista->persona.clasifIMC);
		}
		auxLista = auxLista->siguiente;
	}

}

int cantEncuestados(tLista * pLista){
	tLista * auxLista = pLista;
	int cantPersonas = 0;
	while(auxLista!=NULL)
	{
		cantPersonas++;
		auxLista = auxLista->siguiente;
	}
	return cantPersonas;
}