/*
Suponiendo que:
    typedef float acertijo;
    typedef acertijo * apAcertijo;
    apAcertijo a1, a2;

¿Cuáles de los siguientes enunciados serán posibles?
a) a1 = 1.1;
b) a1 = *1.1;
c) a1 = malloc(sizeof(float));
d) a1 = NULL;
e) *a1 = 1.1;
f) *a1 = malloc(sizeof(int));
g) a2 = a1;
h) a2 = *1.1;
i) a2 = *a1;

*/

#include <stdio.h>
#include <stdlib.h>

//Tipo de datos definidos por el programador
typedef float acertijo;
typedef acertijo * apAcertijo;

//Prototipo de funciones
void ejercicio5();

//Variables Globales
apAcertijo a1, a2;

//Funcion Principal
int main(void) {
    ejercicio5();
    return 0;
}

//Definicion de funciones
void ejercicio5() {

    //a1 = 1.1;
    printf("a) No es posible, porque a1 es una variable de tipo puntero y no puede almacenar valor flotante\n");

    //a1 = *1.1;
    printf("b) No es posible, porque 1.1 es solo un valor\n");

    a1 = malloc(sizeof(float));
    printf("c) Es posible. Reserva un espacio de memoria. Dicho espacio se encuentra en la direccion %p\n", a1);

    //a1 = NULL;
    printf("d) Es posible. En este caso (si ejecuto), pierdo la direccion almacenada en la sentencia anterior y quedaria nula\n");

    *a1 = 1.1; // e) Es posible. Resuelve *a1 y asigna el valor en el espacio reservado
    printf("e) Es posible. Resuelve la direccion almacenada en a1 y asigna el valor en el espacio de memoria reservado.");
    printf(" Su valor en este momento es: %.1f\n", *a1);

    //*a1 = malloc(sizeof(int)); //f) No es posible.
    printf("f) No es posible. *a1 apunta a un espacio de memoria de tipo flotante.\n");

    a2 = a1;
    printf("g) Es posible. Lo que hace es copiar la direccion de memoria de a1 en a2.\n");

    //a2 = *1.1; h) No es posible
    printf("h) No es posible. Es igual al punto b).\n");

    //a2 = *a1;  i) No es posible
    printf("i)No es posible. a2 puede almacenar direccion de memoria y *a1 esta almacenando un valor de tipo flotante");

}