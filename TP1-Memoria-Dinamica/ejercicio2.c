/*
Dadas las siguientes declaraciones:
    typedef int indice;
    typedef indice *apuntIndice;
    indice i;
    apuntIndice apuntI;

a) ¿Qué contiene apuntI?
b) Si a continuación de las líneas de código
anteriores, ejecutamos lo siguiente:

    int main() {
        apuntI = malloc(sizeof(int));
        *apuntI = 2;
        i = 4;
        return 0;
    }

- ¿Qué contendrá apuntI?
- ¿Qué contendrá *apuntI?
 */

#include <stdio.h>
#include <stdlib.h>

// tipo de datos definidos por el programador
typedef int indice;
typedef indice *apuntIndice;

// prototipo de funciones
void itemA();
void itemB();

// variables globales
indice i;
apuntIndice apuntI;

// funcion principal
int main(void)
{
    itemA();
    itemB();
    return 0;
}

void itemA()
{
    printf("\ncontenido 1: %p\n", apuntI);
    apuntI = NULL;
    printf("contenido 2: %p\n\n", apuntI);
}

void itemB()
{
    apuntI = malloc(sizeof(int));
    *apuntI = 2;
    i = 4;
    printf("El contenido de apuntl es: %p\n", apuntI);
    printf("El contenido de *apuntl es: %d\n", *apuntI);
}