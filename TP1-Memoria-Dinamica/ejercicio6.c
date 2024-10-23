/*
¿Qué salida tiene el siguiente programa?

    #include <stdio.h>
    #include <stdlib.h>
    typedef char *apuntadorC;
    apuntadorC a1, a2;
    int main() {
        a1 = malloc(sizeof(char));
        a2 = malloc(sizeof(char));
        *a1 = 'A';
        *a2 = 'B';
        printf("%c \n", *a1);
        printf("%c \n", *a2);
        return 0;
    }


 */

#include <stdio.h>
#include <stdlib.h>

typedef char *apuntadorC;

apuntadorC a1, a2;

int main()
{
    a1 = malloc(sizeof(char));
    a2 = malloc(sizeof(char));
    *a1 = 'A';
    *a2 = 'B';
    printf("%c \n", *a1);
    printf("%c \n", *a2);
    return 0;
}

/*
Cada variable de tipo puntero guarda una direccion de memoria de un espacio reservado (linea 30 y 31 respectivamente)
luego, (linea 32 y 33) resolvemos esa direccion de memoria y guardamos un caracter en cada espacio de memoria
Al final, imprimimos los resultados por consola
*/