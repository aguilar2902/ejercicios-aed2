/*
El departamento de alumnado necesita trabajar con los datos de los alumnos de la materia AEDII, para
ello implementa una lista simplemente enlazada, donde cada nodo guarda el número de libreta
universitaria y el nombre del alumno. Se pide crear las funciones necesarias para:
a) Generar la lista.
b) Insertar el primer alumno (nodo) de la lista.
c) Insertar alumnos al principio de la lista.
d) Eliminar el primer alumno de la lista.
e) Insertar un alumno en una determinada posición dentro de la lista.
f)
Eliminar un alumno de una determinada posición de la lista.
g) Visualizar todos los datos de los alumnos que están en la lista.
Además, crear una función que retorne la cantidad de alumnos que contiene la lista e implementar un
menú principal que contenga todos los ítems anteriormente solicitados.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TITULO "GESTION DE ALUMNOS AEDII"

/*Tipos de datos personalizados*/
typedef char tString[50];
typedef struct
{
    int libreta;
    tString nombre;
} tAlumno;

typedef struct nodo
{
    tAlumno alumno;
    struct nodo *siguiente;
} tListaAlumnos;

/*Variables globales*/
tListaAlumnos *listaAlumnos;

/*Prototipos de funciones*/
void inicializarLista(tListaAlumnos *);
bool listaVacia(tListaAlumnos *);
void ingresarAlumno(tAlumno);
void insertarPrimerAlumno(tAlumno);
void insertarAlumnoAdelante(tAlumno);
void eliminarAlumno();
void insertarAlumnoEnK(int, tAlumno);
void eliminarAlumnoEnK(int);
void visualizarListaAlumnos(tListaAlumnos *);
int totalAlumnos(tListaAlumnos *);
void menu();

/* Funcion principal */
int main()
{
    inicializarLista(listaAlumnos);
    menu();
    return 0;
}

/*Definicion de funciones*/
void inicializarLista(tListaAlumnos *pLista)
{
    pLista = NULL;
}

bool listaVacia(tListaAlumnos *pLista)
{
    return pLista == NULL;
}

void ingresarAlumno(tAlumno pAlumno)
{
    if (listaVacia(listaAlumnos))
    {
        insertarPrimerAlumno(pAlumno);
    }
    else
    {
        insertarAlumnoAdelante(pAlumno);
    }
}

void insertarPrimerAlumno(tAlumno pAlumno)
{
    tListaAlumnos *nuevoNodo;
    nuevoNodo = malloc(sizeof(tListaAlumnos));
    nuevoNodo->alumno = pAlumno;
    nuevoNodo->siguiente = NULL;
    listaAlumnos = nuevoNodo;
    printf("\nPrimer alumno insertado!\n");
}
void insertarAlumnoAdelante(tAlumno pAlumno)
{
    tListaAlumnos *nuevoNodo;
    nuevoNodo = malloc(sizeof(tListaAlumnos));
    nuevoNodo->alumno = pAlumno;
    nuevoNodo->siguiente = listaAlumnos;
    listaAlumnos = nuevoNodo;
    printf("\nAlumno insertado!\n");
}
void eliminarAlumno()
{
    tListaAlumnos *nodoASuprimir;
    nodoASuprimir = listaAlumnos;
    listaAlumnos = nodoASuprimir->siguiente;
    free(nodoASuprimir);
    nodoASuprimir = NULL;
    printf("\nAlumno eliminado!\n");
}

void insertarAlumnoEnK(int pK, tAlumno pAlumno)
{
    tListaAlumnos *nuevoNodo, *aux;
    int i;
    aux = listaAlumnos;
    nuevoNodo = malloc(sizeof(tListaAlumnos));
    nuevoNodo->alumno = pAlumno;
    if (!listaVacia(listaAlumnos))
    {
        for (i = 1; i < pK - 1; i++)
        {
            aux = aux->siguiente;
        }
    }
    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    printf("\nAlumno insertado en la posicion %d correctamente\n", pK);
}

void eliminarAlumnoEnK(int pK)
{
    tListaAlumnos *aux, *nodoASuprimir;
    nodoASuprimir = malloc(sizeof(tListaAlumnos));
    aux = listaAlumnos;
    int i;
    for (i = 1; i < pK - 1; i++)
    {
        aux = aux->siguiente;
    }
    nodoASuprimir = aux->siguiente;
    aux->siguiente = nodoASuprimir->siguiente;
    free(nodoASuprimir);
    nodoASuprimir = NULL;
    printf("\nEl alumno de la posicion %d se ha quitado correctamente\n", pK);
}

void visualizarListaAlumnos(tListaAlumnos *pLista)
{
    tListaAlumnos *aux;
    aux = pLista;
    if (!listaVacia(pLista))
    {
        while (aux != NULL)
        {
            printf("Libreta: %6d | Alumno: %s \n", aux->alumno.libreta, aux->alumno.nombre);
            aux = aux->siguiente;
        }
    }
    else
    {
        printf("\nNo hay nada para mostrar. Lista vacia!\n");
    }
}
int totalAlumnos(tListaAlumnos *pLista)
{
    tListaAlumnos *aux;
    int total = 0;
    aux = pLista;
    if (!listaVacia(pLista))
    {
        total = 1;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
            total++;
        }
        return total;
    }
}

void menu()
{
    printf("\n\t\t*** %s ***", TITULO);
    printf("\n\t-----------------------------------------------\n");
    int opcion = 1;
    while (opcion != 0)
    {
        printf("\n");
        printf("Opcion 1: Cargar un alumno al sistema");
        printf("\nOpcion 2: Ingresar un alumno en una ubicacion personalizada");
        printf("\nOpcion 3: Eliminar ultimo alumno ingresado");
        printf("\nOpcion 4: Eliminar alumno de una posicion personalizada");
        printf("\nOpcion 5: Visualizar lista de alumnos cargados");
        printf("\nOpcion 6: Visualizar total de alumnos");
        printf("\nOpcion 0: Salir");
        printf("\n\n*OPCION ELEGIDA: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            tAlumno alumno;
            printf("\nIngrese el num de libreta del alumno: ");
            scanf("%d", &alumno.libreta);
            printf("Ingrese el nombre y apellido del alumno: ");
            fflush(stdin);
            scanf("%[^\n]s", alumno.nombre);
            ingresarAlumno(alumno);
            break;
        }
        case 2:
        {
            tAlumno alumno;
            int k;
            printf("\nIngrese la posicion de la lista en la que desea agregar al alumno: ");
            scanf("%d", &k);
            printf("Ingrese el num de libreta del alumno: ");
            scanf("%d", &alumno.libreta);
            printf("\nIngrese el nombre del alumno: ");
            fflush(stdin);
            scanf("%[^\n]s", alumno.nombre);
            insertarAlumnoEnK(k, alumno);
            break;
        }
        case 3:
        {
            eliminarAlumno();
            break;
        }
        case 4:
        {
            int k;
            printf("\nIngrese la posicion de la lista de acuerdo al alumno que desea quitar: ");
            scanf("%d", &k);
            eliminarAlumnoEnK(k);
            break;
        }
        case 5:
        {
            printf("\n*** Listado de Alumnos ***");
            printf("\n---------------------------\n");
            visualizarListaAlumnos(listaAlumnos);
            break;
        }
        case 6:
        {
            printf("\n\t***En la lista hay un total de %d alumno/s almacenado/s ***\n", totalAlumnos(listaAlumnos));
            break;
        }
        case 0:
        {
            printf("\nPrograma finalizado!");
            break;
        }
        default:
            printf("\nOpcion no valida. Reintente.\n");
        }
    }
}