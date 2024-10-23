/*
Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un
producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo,
y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos
del primer nodo almacenado.
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

// variables globales
tListaProductos *listaProductos;

int main()
{
    tProductos ingresoProducto;
    tListaProductos *nuevoProducto;

    ingresoProducto.codProducto = 1;
    strcpy(ingresoProducto.descripcion, "lavarropas");
    ingresoProducto.precioUnit = 5.64;

    nuevoProducto = (tListaProductos *)malloc(sizeof(tProductos));
    nuevoProducto->producto = ingresoProducto;
    nuevoProducto->siguiente = NULL;

    printf("\nid del producto: %d \n", nuevoProducto->producto.codProducto);
    printf("\ndescripcion: %s \n", nuevoProducto->producto.descripcion);
    printf("\nprecio unitario: %.2f ", nuevoProducto->producto.precioUnit);
    return 0;
}