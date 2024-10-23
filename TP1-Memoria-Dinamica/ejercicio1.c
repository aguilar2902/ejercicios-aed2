/*
Completar el gráfico, en función de cada consiga. Luego escribir un programa, que contenga una función
por ítem en la que se declaren cada una de las variables de tipo puntero, se asigne el valor que se indica
en cada caso al dato referenciado, y se visualicen tanto las direcciones como el dato referenciado. Puede
utilizar asignación estática o dinámica.

a) Una variable puntero ubicada en la dirección 0050 contiene un apuntador a la dirección 0051, la
cual contiene el dato ‘Maria Acosta’

b) Una variable puntero ubicada en la dirección 0075 contiene un apuntador a la dirección 00150, la
cual contiene el dato 20.5

c) Una variable puntero ubicada en la dirección 0092 contiene un apuntador a la dirección 0099, la
cual contiene el dato True

d) Una variable puntero ubicada en la dirección 0125 contiene un apuntador a la dirección 00132, la
cual contiene el dato 7350

e) Una variable puntero ubicada en la dirección 0023 contiene un apuntador a la dirección 0099, la
cual contiene el dato ‘z’
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Tipo de datos definidos por el programador
typedef char tString[25];

// Prototipado de funciones
void itemA();
void itemB();
void itemC();
void itemD();
void itemE();

// variables globales
tString *apuntCadena;
float *apuntFlotante;
bool *apuntBooleano;
int *apuntInt;
char *apuntChar;

// Funcion principal
int main(void)
{
    // invocacion de funciones
    itemA();
    itemB();
    itemC();
    itemD();
    itemE();
    return 0;
}

// Definicion de funciones
void itemA()
{
    apuntCadena = (tString *)malloc(sizeof(tString));
    strcpy((*apuntCadena), "Maria Acosta");

    printf("\n\t----- ITEM A -----\n");
    printf("El contenido de la variable apuntada es: %s\n", *apuntCadena);
    printf("La direccion de la variable apuntada es: %p\n", apuntCadena);
    printf("La direccion de la variable puntero es: %p\n\n", &apuntCadena);
}

void itemB()
{
    apuntFlotante = (float *)malloc(sizeof(float));
    *apuntFlotante = 20.5;

    printf("\t----- ITEM B -----\n");
    printf("El contenido de la variable apuntada es: %.1f \n", *apuntFlotante);
    printf("La direccion de variable apuntada es: %p\n", apuntFlotante);
    printf("La direccion de la variable puntero es: %p\n\n", &apuntFlotante);
}

void itemC()
{
    apuntBooleano = (bool *)malloc(sizeof(bool));
    *apuntBooleano = true;

    printf("\t----- ITEM C -----\n");
    printf("el valor almacenado es: %d\n", *apuntBooleano);
    printf("La direccion de variable apuntada es: %p\n", apuntBooleano);
    printf("La direccion de la variable puntero es: %p\n\n", &apuntBooleano);
}

void itemD()
{
    apuntInt = (int *)malloc(sizeof(int));
    *apuntInt = 7350;

    printf("\t----- ITEM D -----\n");
    printf("El contenido de la variable apuntada es: %d\n", *apuntInt);
    printf("La direccion de variable apuntada es: %p\n", apuntInt);
    printf("La direccion de la variable puntero es: %p\n\n", &apuntInt);
}

void itemE()
{
    apuntChar = (char *)malloc(1);
    *apuntChar = 'z';

    printf("\t----- ITEM E -----\n");
    printf("El contenido de la variable apuntada es: %c \n", *apuntChar);
    printf("La direccion de variable apuntada es: %p\n", apuntChar);
    printf("La direccion de la variable puntero es: %p\n\n", &apuntChar);
}