#include <stdio.h>
#define LIMITE 100

typedef struct{
    char nombre[LIMITE];
    int velocidad;
    int fuerza;
    int reflejos;
    float vida;
    char poderes1[LIMITE];
    char poderes2[LIMITE];
    char poderes3[LIMITE];
}caracteristicas_t;

void imprimir(caracteristicas_t);

caracteristicas_t spiderman = {"spiderman", 100, 100, 100, 100, "muñequeras", "sentido aracnido", "se aferra a la mayoría de las superficies"};
caracteristicas_t duende_verde = {"duende verde", 100, 100, 100, 100, "granadas", "planeador", "curación regenerativa"};
int main()
{
    printf("PRESENTACION SPIDERMAN\n");
    imprimir(spiderman);
    printf("PRESENTACION DUENDE VERDE\n");
    imprimir(duende_verde);
    return 0;
}

void imprimir(caracteristicas_t personaje)
{
    printf("Nombre:%s\n",personaje.nombre);
    printf("Velocidad:%d\n",personaje.velocidad);
    printf("Fuerza:%d\n",personaje.fuerza);
    printf("Reflejos:%d\n",personaje.reflejos);
    printf("Vida:%f\n",personaje.vida);
    printf("Poder/armadura 1:%s\n",personaje.poderes1);
    printf("Poder/armadura 2:%s\n",personaje.poderes2);
    printf("Poder/armadura 3:%s\n\n",personaje.poderes3);
}