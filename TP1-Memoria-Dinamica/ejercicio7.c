/*
Dadas las siguientes definiciones y declaraciones

    typedef int * tpEntero;
    typedef char * tpCaracter;
    tpEntero p1, p2;
    tpCaracter q1, q2, q3;

¿Cuál será la salida de los siguientes fragmentos de código?

a)  p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    *p1 = 5;
    *p2 = *p1 + 20;
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);

b)  p2 = malloc(sizeof(int));
    *p2 = 2;
    *p2 = pow(*p2,2);
    p1 = malloc(sizeof(int));
    *p1 = fmod(*p2,3);
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);

c)  q1 = malloc(sizeof(char));
    q2 = malloc(sizeof(char));
    q3 = malloc(sizeof(char));
    *q1 = 'Y';
    *q2 = (*q1) - 1;
    *q3 = (*q1) + 1;
    printf("*q1 igual a %c, *q2 igual a %c, q3 igual a %c\n", *q1, *q2, *q3);
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Variables definidas por el programador
typedef int *tpEntero;
typedef char *tpCaracter;

// Prototipado de funciones
void puntoA();
void puntoB();
void puntoC();

// Variables Globales
tpEntero p1, p2;
tpCaracter q1, q2, q3;

// Funcion principal
int main(void)
{
    // Invocacion de funciones
    puntoA();
    puntoB();
    puntoC();
    return 0;
}

// Definicion de funciones
void puntoA()
{
    // reservo espacio de memoria (4 bytes) y la direccion de memoria guardo en p1 y p2 respectivamente
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));

    // resuelvo la direccion de memoria almacenada en p1 y guardo el valor asignado
    *p1 = 5;

    // resuelvo p1, utilizo el valor para sumarle 20. Luego resuelvo p2 para guardar el resultado
    *p2 = *p1 + 20;

    printf("------- PUNTO 7a -------\n");
    printf("*p1 es igual a %d, *p2 es igual a %d\n\n", *p1, *p2);
}

void puntoB()
{
    // reservo espacio de memoria (4bytes) y guardo su direccion en p2
    p2 = malloc(sizeof(int));
    // resuelvo *p2 y almaceno el valor asignado
    *p2 = 2;

    // realizo la potencia resolviendo *p2 y la guardo en la misma direccion
    *p2 = pow(*p2, 2);

    // reservo espacio de memoria (4bytes) y guardo su direccion en p1
    p1 = malloc(sizeof(int));

    // realizo la operacion resto resolviendo *p2 para la operacion y guardo el resultado resolviendo *p1
    *p1 = fmod(*p2, 3);

    printf("------- PUNTO 7b -------\n");
    printf("*p1 es igual a %d, *p2 es igual a %d\n\n", *p1, *p2);
}

void puntoC()
{

    // reservo los espacios de memoria y almaceno las direcciones en sus respectivas variables
    q1 = malloc(sizeof(char));
    q2 = malloc(sizeof(char));
    q3 = malloc(sizeof(char));

    // resuelve *q1 y asigna el caracter en dicho espacio de memoria
    *q1 = 'Y';

    /*Al tener una operacion matematica, resuelve *q1 y el valor almacenado lo transforma momentaneamente a su valor en el codigo ASCCI,
     *realiza la operacion y al resolver *q2, guarda el caracter que corresponde al valor obtenido (dentro del codigo ASCCI)
     */
    *q2 = (*q1) - 1;
    *q3 = (*q1) + 1;
    printf("------- PUNTO 7c -------\n");
    printf("*q1 igual a %c, *q2 igual a %c, *q3 igual a %c\n\n", *q1, *q2, *q3);
}