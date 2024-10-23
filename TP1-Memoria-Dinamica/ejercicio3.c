/*
Después de ejecutarse el siguiente código:
    typedef int cosa;
    typedef cosa *apuntadorACosa;
    cosa c, cc;
    apuntadorACosa apuntC, apuntCC;
    int main() {
        apuntC = NULL;
        apuntCC = malloc(sizeof(int));
        return 0;
    }

¿Qué contienen las siguientes variables?
a) apuntC
b) apuntCC
c) c
d) cc
e) *apuntC
f) *apuntCC

*/

#include <stdio.h>
#include <stdlib.h>

// declaracion de variables definidas por programador
typedef int cosa;
typedef cosa *apuntadorACosa;

// declaracion de variables globales de tipo "cosa" (int)
cosa c, cc;

// declaracion de dos punteros de tipo "apuntadorACosa"
apuntadorACosa apuntC, apuntCC;

int main(void)
{
    apuntC = NULL;
    apuntCC = malloc(sizeof(int));
    printf("contenido de apuntC: %d \n", apuntC);
    printf("contenido de apuntCC: %d \n", apuntCC);
    printf("contenido de c: %d \n", c);
    printf("contenido de cc: %d \n", cc);
    // la linea 45 da un error porque dicha variable no apunta a nada, por lo cual no puede mostrar ningun resultado
    // printf("contenido de variable donde apunta apuntC: %d \n", *apuntC);
    printf("contenido de variable donde apunta apuntCC: %d \n", *apuntCC);

    return 0;
}