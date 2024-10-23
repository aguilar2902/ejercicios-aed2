/*

EJERCICIO 2
Modificar el ejercicio 1 para que se puedan realizar todas las operaciones básicas para el manejo de una
lista enlazada:
a) Generar o inicializar la lista.
b) Función para determinar si una lista está vacía.
c) Insertar el primer producto (nodo) de la lista.
d) Insertar un producto al principio de la lista.
e) Eliminar el primer producto de la lista.
f) Insertar un producto en una determinada posición dentro de la lista.
g) Eliminar un producto de una determinada posición de la lista.
h) Visualizar todos los datos de los productos que están en la lista.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Tipo de datos definido por el programador
typedef char tString[50];

typedef struct
{
    int codProducto;
    tString descripcion;
    float precioUnit;
} tProductos;

typedef struct nodoProducto
{
    tProductos producto;
    struct nodoProducto *siguiente;
} tListaProductos;

// prototipo de funciones
void inicializarLista();
bool listaVacia(tListaProductos *);
tProductos agregarProducto();
void insertarProducto();
void insertarProductoPredeterminado();
void insertarProductoEnPosicionDefinida();
void insertarProductoAlInicio();
void insertarPrimerProducto();
void insertarProductoFinal();
void eliminarProducto();
void eliminarPrimerNodo();
void eliminarProductoEnPosicionDefinida();
void listarProductos();
void menu();

// variables globales
tListaProductos *listaProductos;

int main()
{
    tProductos ingresoProducto;

    inicializarLista();
    menu();
    return 0;
}

void inicializarLista()
{
    listaProductos = NULL;
    printf("La lista de productos fue inicializada.\n");
}

bool listaVacia(tListaProductos *pListaProductos)
{
    return (pListaProductos == NULL);
}

tProductos agregarProducto()
{
    tProductos productoIngresado;

    printf("\nIngrese el codigo del producto: ");
    scanf("%d", &productoIngresado.codProducto);

    printf("\nIngrese la descripcion: ");
    scanf("%s", &productoIngresado.descripcion);

    printf("\nIngrese el precio unitario: ");
    scanf("%f", &productoIngresado.precioUnit);

    return productoIngresado;
}

// insercion de datos a la lista
void insertarProducto()
{
    int opcion;

    printf("\n\t\t ***** MENU INSERTAR PRODUCTO *****\n");
    printf("1 - Ingresar producto de forma predeterminada\n");
    printf("2 - Ingresar producto en una posicion definida\n");
    printf("3 - Ingresar producto al principio de la lista\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        insertarProductoPredeterminado();
        break;
    case 2:
        insertarProductoEnPosicionDefinida();
        break;
    case 3:
        insertarProductoAlInicio();
        break;

    default:
        printf("El numero ingresado no se encuentra en las opciones");
        break;
    }
}

void insertarProductoPredeterminado()
{
    if (listaVacia(listaProductos))
    {
        insertarPrimerProducto();
    }
    else
    {
        insertarProductoFinal();
    }
}

void insertarProductoEnPosicionDefinida()
{
    int posicion;
    tListaProductos *productoAux;
    tListaProductos *nuevoProducto;

    productoAux = listaProductos;

    printf("Ingrese la posicion donde quieres guardar el producto: ");
    scanf("%d", &posicion);

    if (listaVacia(listaProductos))
    {
        printf("\nEl producto no se puede ingresar en dicha posicion debido a que no hay elementos en la lista\n");
        insertarProducto();
    }

    for (int i = 1; i < (posicion - 1); i++)
    {
        productoAux = productoAux->siguiente;
    }

    nuevoProducto = (tListaProductos *)malloc(sizeof(tListaProductos));
    nuevoProducto->producto = agregarProducto();
    nuevoProducto->siguiente = productoAux->siguiente;
    productoAux->siguiente = nuevoProducto;
    printf("Producto insertado correctamente en la posicion %d\n", posicion);
}

void insertarProductoAlInicio()
{
    tListaProductos *nuevoProducto;
    nuevoProducto = (tListaProductos *)malloc(sizeof(tListaProductos));
    nuevoProducto->producto = agregarProducto();
    nuevoProducto->siguiente = listaProductos;
    listaProductos = nuevoProducto;
    printf("\nProducto insertado al inicio de la lista.\n");
    menu();
}

void insertarPrimerProducto()
{
    tListaProductos *nuevoProducto;
    nuevoProducto = (tListaProductos *)malloc(sizeof(tListaProductos));
    nuevoProducto->producto = agregarProducto();
    nuevoProducto->siguiente = NULL;
    listaProductos = nuevoProducto;
    printf("\nPrimer producto insertado.\n");
    menu();
}

void insertarProductoFinal()
{
    tListaProductos *productoAux;
    tListaProductos *nuevoProducto;
    productoAux = listaProductos;

    while (productoAux->siguiente != NULL)
    {
        productoAux = productoAux->siguiente;
    }

    nuevoProducto = (tListaProductos *)malloc(sizeof(tListaProductos));
    nuevoProducto->producto = agregarProducto();
    nuevoProducto->siguiente = NULL;
    productoAux->siguiente = nuevoProducto;
    printf("\nNuevo producto insertado al final de la lista.\n");
    menu();
}

// eliminacion de datos a la lista
void eliminarProducto()
{
    int opcion;

    printf("\n\t\t ***** MENU ELIMINAR PRODUCTO *****\n");
    printf("1 - Eliminar el primer producto de la lista\n");
    printf("2 - Eliminar un producto definido de la lista\n");
    printf("3 - volver al menu\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        eliminarPrimerNodo();
        break;
    case 2:
        eliminarProductoEnPosicionDefinida();
        break;
    case 3:
        menu();
        break;
    default:
        printf("El numero ingresado no se encuentra en las opciones");
        break;
    }
}

void eliminarPrimerNodo()
{
    tListaProductos *productoAux;

    productoAux = listaProductos;
    listaProductos = productoAux->siguiente;
    printf("\nEl primer producto eliminado correctamente.\n");
    free(productoAux);
}

void eliminarProductoEnPosicionDefinida()
{
    int posicion;
    tListaProductos *productoAux;
    tListaProductos *productoEliminar;

    productoAux = listaProductos;

    printf("Ingrese la posicion donde quieres guardar el producto: ");
    scanf("%d", &posicion);

    if (listaVacia(listaProductos))
    {
        printf("\nEl producto no se puede ingresar en dicha posicion debido a que no hay elementos en la lista\n");
        insertarProducto();
    }

    for (int i = 1; i < (posicion - 1); i++)
    {
        productoAux = productoAux->siguiente;
    }

    productoEliminar = productoAux->siguiente;
    productoAux->siguiente = productoEliminar->siguiente;
    printf("producto Eliminado correctamente: %s\n", productoEliminar->producto.descripcion);
    free(productoEliminar);
}

// visualizacion de datos a la lista
void listarProductos()
{
    printf("\n\t\t***** LISTA DE PRODUCTOS *****\n");

    tListaProductos *listaDeProductos;

    listaDeProductos = listaProductos;

    while (listaDeProductos != NULL)
    {
        printf("%d-%s\n", listaDeProductos->producto.codProducto, listaDeProductos->producto.descripcion);
        listaDeProductos = listaDeProductos->siguiente;
    }
    menu();
}

void menu()
{
    int dato;

    while (dato != 4)
    {

        printf("\n\t\t ***** MENU *****\t\t\n");
        printf("1 - Insertar Producto\n");
        printf("2 - Eliminar Producto\n");
        printf("3 - Mostrar la lista de productos\n");
        printf("4 - Salir del programa\n");
        printf("Ingrese la opcion que requiera: ");
        scanf("%d", &dato);

        switch (dato)
        {
        case 1:
            insertarProducto();
            break;
        case 2:
            eliminarProducto();
            break;
        case 3:
            listarProductos();
            break;
        case 4:
            printf("Fin del programa");
            exit(0);
            break;
        default:
            printf("El numero ingresado no forma parte de las opciones");
            break;
        }
    }
}
