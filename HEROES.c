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

int main()
{
    printf("LARA HACE ESTO(PRESENTACION SPIDERMAN)\n");
    imprimir(spiderman);

    return 0;
}

void imprimir(caracteristicas_t spiderman)
{
    printf("Nombre:%s\n",spiderman.nombre);
    printf("Velocidad:%d\n",spiderman.velocidad);
    printf("Fuerza:%d\n",spiderman.fuerza);
    printf("Reflejos:%d\n",spiderman.reflejos);
    printf("Vida:%f\n",spiderman.vida);
    printf("Poder 1:%s\n",spiderman.poderes1);
    printf("Poder 2:%s\n",spiderman.poderes2);
    printf("Poder 3:%s\n",spiderman.poderes3);
}