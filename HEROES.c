#include <stdio.h>
#define LIMITE 100

typedef struct{
    char nombre[LIMITE];
    int velocidad;
    int fuerza;
    int reflejos;
    float vida;
    char ataque1[LIMITE];
    char ataque2[LIMITE];
    char ataque3[LIMITE];
}caracteristicas_t;

void imprimir(caracteristicas_t);
caracteristicas_t spiderman = {"spiderman", 90, 100, 90, 90, "telarañas", "sentido aracnido", "fuerza sobrehumana"};
caracteristicas_t duende_verde = {"duende verde", 90, 80, 70, 80, "granadas", "planeador", "curación regenerativa"};
caracteristicas_t batman = {"batman", 100, 100, 100, 100, ""}

int main(){
    printf("PRESENTACION SPIDERMAN\n");
    imprimir(spiderman);
    printf("PRESENTACION DUENDE VERDE\n");
    imprimir(duende_verde);
    return 0;
}
void imprimir(caracteristicas_t personaje){
    printf("Nombre:%s\n",personaje.nombre);
    printf("Velocidad:%d\n",personaje.velocidad);
    printf("Fuerza:%d\n",personaje.fuerza);
    printf("Reflejos:%d\n",personaje.reflejos);
    printf("Vida:%f\n",personaje.vida);
    printf("Poder/armadura 1:%s\n",personaje.poderes1);
    printf("Poder/armadura 2:%s\n",personaje.poderes2);
    printf("Poder/armadura 3:%s\n\n",personaje.poderes3);
}