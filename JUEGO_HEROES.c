#include <stdio.h>
#define LIMITE 100
#define NUM_PERS 7
#define CARAC_LEVEL 5

typedef struct {
    int numero;
    char nombre[LIMITE];
    int velocidad;
    int fuerza;
    int reflejos;
    float vida;
    char ataque1[LIMITE];
    char ataque2[LIMITE];
    char ataque3[LIMITE];
    char defensa1[LIMITE];
    char defensa2[LIMITE];
    char defensa3[LIMITE];
} caracteristicas_t;

void imprimir(caracteristicas_t personaje);
caracteristicas_t levelear(caracteristicas_t personaje); 
caracteristicas_t spiderman = {1, "spiderman", 90, 100, 100, 100, "telarañas", "agilidad", "fuerza sobrehumana", "sentido aracnido", "telarañas", "resistencia"};
caracteristicas_t batman = {2, "batman", 100, 100, 100, 100, "ataque1", "ataque2", "ataque3", "defensa1", "defensa2", "defensa3"};
caracteristicas_t san_baumaro = {3, "san baumaro", 100, 100, 100, 100, "ataque1", "ataque2", "ataque3", "defensa1", "defensa2", "defensa3"};
caracteristicas_t azuquita = {4, "azuquita", 100, 100, 100, 100, "ataque1", "ataque2", "ataque3", "defensa1", "defensa2", "defensa3"};
caracteristicas_t flash = {5, "flash", 100, 100, 100, 100, "ataque1", "ataque2", "ataque3", "defensa1", "defensa2", "defensa3"};
caracteristicas_t nikitox = {6, "nikitox", 100, 100, 100, 100, "ataque1", "ataque2", "ataque3", "defensa1", "defensa2", "defensa3"};

int main() {
    int num_personaje;
    printf("Bienvenido al juego\n");
    printf("Elija su personaje\n\n");
    imprimir(spiderman);
    imprimir(batman);
    imprimir(san_baumaro);
    imprimir(azuquita);
    imprimir(flash);
    imprimir(nikitox);

    printf("Ingrese el numero del héroe elegido:\n");
    scanf("%d", &num_personaje);

    switch (num_personaje) {
        case 1:
            printf("Seleccionaste a Spiderman\n");
            spiderman = levelear(spiderman);  
            break;
        case 2:
            printf("Seleccionaste a Batman\n");
            batman = levelear(batman);
            break;
        case 3:
            printf("Seleccionaste a San Baumaro\n");
            san_baumaro = levelear(san_baumaro);
            break;
        case 4:
            printf("Seleccionaste a Azuquita\n");
            azuquita = levelear(azuquita);
            break;
        case 5:
            printf("Seleccionaste a Flash\n");
            flash = levelear(flash);
            break;
        case 6:
            printf("Seleccionaste a Nikitox\n");
            nikitox = levelear(nikitox);
            break;
        default:
            printf("Número de personaje no válido\n");
            break;
    }

    return 0;
}

void imprimir(caracteristicas_t personaje) {
    printf("Numero de personaje: %d\n", personaje.numero);
    printf("Nombre: %s\n", personaje.nombre);
    printf("Velocidad (1): %d\n", personaje.velocidad);
    printf("Fuerza (2): %d\n", personaje.fuerza);
    printf("Reflejos (3): %d\n", personaje.reflejos);
    printf("Vida (4): %f\n", personaje.vida);
    printf("Ataque1: %s\n", personaje.ataque1);
    printf("Ataque2: %s\n", personaje.ataque2);
    printf("Ataque3: %s\n", personaje.ataque3);
    printf("Defensa1: %s\n", personaje.defensa1);
    printf("Defensa2: %s\n", personaje.defensa2);
    printf("Defensa3: %s\n\n", personaje.defensa3);
}

caracteristicas_t levelear(caracteristicas_t personaje) {
    int nuevo_valor;
    //for(int i=1; i<CARAC_LEVEL; i++){
        printf("Ingrese el nuevo valor de Velocidad (Valor anterior: %d): ", personaje.velocidad);
        scanf("%d", &nuevo_valor);
        personaje.velocidad = nuevo_valor;
        printf("Velocidad actualizada correctamente, ahora es %d\n", personaje.velocidad);
    //}
    return personaje;  
}
