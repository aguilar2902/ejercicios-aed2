/*
Suponiendo que:
    char * eso
a) Es posible llamar a *eso = malloc(sizeof(int)); ?
b) Y llamar a eso = malloc(sizeof(int));?
c) Explíquelo.
*/

#include <stdio.h>
#include <stdlib.h>

// prototipado
// void opcion1();
void opcion2();

// variables globales
char *eso;

// funcion principal
int main(void)
{
    // invocacion de funciones
    // opcion1();
    opcion2();
    return 0;
}

/*
El punto "a" NO es posible realizar, debido a que "eso" es una variable de tipo puntero que apuntaría a una variable de tipo char(cuando se reserva el espacio de memoria).
En este caso, a "*eso", le pedimos que resuelva el espacio de memoria (que no tiene) y que ahi guarde la direccion de memoria del nuevo espacio que se esta reservando(que tampoco puede guardar, ya que dicha variable es de tipo "char")
cuando la variable
 */
// definicion de funciones
void opcion1()
{
    *eso = malloc(sizeof(int));
    printf("Lo que contiene donde apunta eso es: %c \n", *eso);
    printf("La direccion donde apunta eso es: %p \n", eso);
}

/*
En el punto "b" si es posible. Lo que hacemos es reservar un espacio de memoria de 4 bits(tamaño que un "int") y la direccion de memoria lo guarda en la variable de tipo puntero "eso"
*/
void opcion2()
{
    eso = malloc(sizeof(int));
    printf("\nLo que contiene donde apunta eso es: %c \n", *eso);
    printf("La direccion donde apunta eso es: %p \n", eso);
}