#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define LIMITE 100
#define NUM_PERS 7
#define NUM_HAB 4
#define OCUPADO 1
#define LIBRE 0
#define CARAC_LEVEL 5
#define NUM_ACCIONES 4

typedef struct {
    int numero;
    char nombre[LIMITE];
    int velocidad;
    int fuerza;
    int reflejos;
    float vida;
    float max_vida; 
    int ataque1;
    int ataque2;
    int ataque3;
    int defensa1;
    int defensa2;
    int defensa3;
} caracteristicas_t;

void imprimir(caracteristicas_t personaje);
caracteristicas_t levelear(caracteristicas_t personaje);
int calcular_habilidad(int habilidad, int porcentaje);
int elegir_porcentaje(int usados[]);
caracteristicas_t crear_oponente(caracteristicas_t personaje, caracteristicas_t jugador);
int accion_oponente(int mov_oponente[4], caracteristicas_t oponente, caracteristicas_t jugador);
int verificar_final(caracteristicas_t oponente, caracteristicas_t jugador);
int accion_jugador(caracteristicas_t oponente, caracteristicas_t jugador);

caracteristicas_t spiderman = {1, "Spiderman", 90, 70, 100, 100, 130, 1, 2, 3, 4, 5, 6};
caracteristicas_t batman = {2, "Batman", 100, 70, 100, 100, 130, 1, 2, 3, 4, 5, 6};
caracteristicas_t san_baumaro = {3, "San Baumaro", 100, 70, 100, 100, 130, 1, 2, 3, 4, 5, 6};
caracteristicas_t azuquita = {4, "Azuquita", 100, 70, 100, 100, 130, 1, 2, 3, 4, 5, 6};
caracteristicas_t flash = {5, "Flash", 100, 70, 100, 100, 130, 1, 2, 3, 4, 5, 6};
caracteristicas_t nikitox = {6, "Nikitox", 100, 70, 100, 100, 130, 1, 2, 3, 4, 5, 6};

caracteristicas_t oponente = {7, "nombre cambiable", 115, 70, 105, 120, 130, 1, 2, 3, 4, 5, 6};

int main() {
    int num_personaje;
    int mov_oponente[4] = {0, 1, 2, 3};
    int turno = rand() % 2; // 0 para jugador, 1 para oponente
    caracteristicas_t jugador;
    printf("¡Bienvenido al juego!\n\n");
    srand(time(NULL)); 
    printf("\033[37;4mElija su personaje:\033[0m\n\n");

    imprimir(spiderman);
    imprimir(batman);
    imprimir(san_baumaro);
    imprimir(azuquita);
    imprimir(flash);
    imprimir(nikitox);

    do{
        printf("Ingrese el numero del heroe elegido: ");
        scanf("%d", &num_personaje);
        switch (num_personaje) {
        case 1:
            printf("\nSeleccionaste a Spiderman\n");
            jugador = spiderman;
            jugador = levelear(jugador);
            break;
        case 2:
            printf("Seleccionaste a Batman\n");
            jugador = batman;
            jugador = levelear(jugador);
            break;
        case 3:
            printf("Seleccionaste a San Baumaro\n");
            jugador = san_baumaro;
            jugador = levelear(jugador);
            break;
        case 4:
            printf("Seleccionaste a Azuquita\n");
            jugador = azuquita;
            jugador = levelear(jugador);
            break;
        case 5:
            printf("Seleccionaste a Flash\n");
            jugador = flash;
            jugador = levelear(jugador);
            break;
        case 6:
            printf("Seleccionaste a Nikitox\n");
            jugador = nikitox;
            jugador = levelear(jugador);
            break;
        default:
            printf("Numero de personaje no valido\n");
            num_personaje = 0;
        }
    } while (num_personaje == 0);

    oponente = crear_oponente(oponente, jugador);
    printf("\nEste sera tu oponente: \n");
    imprimir(oponente);

    printf("\n-- Estadisticas iniciales: -- \n");
    printf("Jugador: %s, Vida: %.2f, Fuerza: %d, Velocidad: %d, Reflejos: %d \n", jugador.nombre, jugador.vida, jugador.fuerza, jugador.velocidad, jugador.reflejos);
    printf("Oponente: %s, Vida: %.2f, Fuerza: %d, Velocidad: %d, Reflejos: %d \n", oponente.nombre, oponente.vida, oponente.fuerza, oponente.velocidad, oponente.reflejos);

    while (jugador.vida > 0 && oponente.vida > 0) {
        if (turno == 0){
            printf("\nTu turno:\n");
            accion_jugador(oponente, jugador);

            if (verificar_final(jugador, oponente) == 1) {
                printf("Ganaste!\n");
                break;
            }
            turno = 1;
        }else{
            printf("\nTurno del oponente:\n");
            accion_oponente(mov_oponente, oponente, jugador);

            if (verificar_final(jugador, oponente) == 1) {
                printf("El oponente ganó!\n");
                break;
            }
            turno = 0;
        }
    }
    return 0;
}


void imprimir(caracteristicas_t personaje) {
    printf("\033[34;1m%d %s\033[0m - Vida: %.2f, Velocidad: %d, Fuerza: %d, Reflejos: %d\n", personaje.numero, personaje.nombre, personaje.vida, personaje.velocidad, personaje.fuerza, personaje.reflejos);
    printf("Ataque 1: %d, Ataque 2: %d, Ataque 3: %d\n", personaje.ataque1, personaje.ataque2, personaje.ataque3);
    printf("Defensa 1: %d, Defensa 2: %d, Defensa 3: %d\n\n", personaje.defensa1, personaje.defensa2, personaje.defensa3);
}

caracteristicas_t levelear(caracteristicas_t personaje) {
    int porcentajes_usados[4] = {LIBRE};   
    int habilidades_mejoradas[4] = {LIBRE};
    int opcion, porcentaje;

    for (int i = 0; i < NUM_HAB; i++) {
        do {
            printf("\nElige una habilidad para mejorar:\n");
            printf("1. Velocidad\n2. Fuerza\n3. Reflejos\n4. Vida\n");
            scanf("%d", &opcion);

            if (opcion < 1 || opcion > NUM_HAB) {
                printf("Opcion no valida. Intenta de nuevo.\n");
                continue;
            }
            
            if (habilidades_mejoradas[opcion - 1] == OCUPADO) {
                printf("Esa habilidad ya ha sido mejorada.\n");
                opcion = 0; 
            }
        } while (opcion < 1 || opcion > NUM_HAB);
        porcentaje = elegir_porcentaje(porcentajes_usados); 

        switch (opcion) {
            case 1:
                personaje.velocidad = calcular_habilidad(personaje.velocidad, porcentaje);
                printf("Nueva Velocidad: %d\n", personaje.velocidad);
                break;
            case 2:
                personaje.fuerza = calcular_habilidad(personaje.fuerza, porcentaje);
                printf("Nueva Fuerza: %d\n", personaje.fuerza);
                break;
            case 3:
                personaje.reflejos = calcular_habilidad(personaje.reflejos, porcentaje);
                printf("Nuevos Reflejos: %d\n", personaje.reflejos);
                break;
            case 4:
                personaje.vida = calcular_habilidad(personaje.vida, porcentaje);
                printf("Nueva Vida: %.2f\n\n", personaje.vida);
                break;
            default:
                printf("Opcion no valida\n");
                i--; 
                continue;
        }

        habilidades_mejoradas[opcion - 1] = OCUPADO;
    }
    return personaje;
}

int calcular_habilidad(int habilidad, int porcentaje) {
    return habilidad + (habilidad * porcentaje / 100);
}

int elegir_porcentaje(int porcentajes_usados[]) {
    int porcentaje;

    while(1){
        printf("Elige el porcentaje de mejora (5, 10, 15 o 20): ");
        scanf("%d", &porcentaje);
        switch (porcentaje){
            case 5:
                if (!porcentajes_usados[0]) { porcentajes_usados[0] = OCUPADO; return 5; }
                break;
            case 10:
                if (!porcentajes_usados[1]) { porcentajes_usados[1] = OCUPADO; return 10; }
                break;
            case 15:
                if (!porcentajes_usados[2]) { porcentajes_usados[2] = OCUPADO; return 15; }
                break;
            case 20:
                if (!porcentajes_usados[3]) { porcentajes_usados[3] = OCUPADO; return 20; }
                break;
            default:
                printf("\nPorcentaje no valido.\n");
                continue;
        }
        printf("\nEse porcentaje ya ha sido utilizado.\n");
    }
}

caracteristicas_t crear_oponente(caracteristicas_t personaje, caracteristicas_t jugador) {
    const char villanos[NUM_PERS - 1][LIMITE] = {"Duende Verde", "Joker", "Thanas", "Misil", "Brain", "Lex Luthor"};
    int indice = rand() % (NUM_PERS - 1);
    float max_diferencia = 20.0; 

    personaje.velocidad = jugador.velocidad + (rand() % 21 - 10); // +- 10 alrededor del jugador
    personaje.fuerza = jugador.fuerza + (rand() % 21 - 10);
    personaje.reflejos = jugador.reflejos + (rand() % 21 - 10);
    personaje.vida = jugador.vida - max_diferencia + (rand() % (int)(2 * max_diferencia + 1)); 

    for (int i = 0; i < LIMITE; i++) {
        personaje.nombre[i] = '\0';
    }
    for (int i = 0; i < LIMITE && villanos[indice][i] != '\0'; i++) {
        personaje.nombre[i] = villanos[indice][i];
    }
    return personaje;
}

int accion_oponente(int mov_oponente[4], caracteristicas_t oponente, caracteristicas_t jugador){
    int nro_accion = 0;
    //nro_accion = rand() % NUM_ACCIONES;
    switch (nro_accion) { 
    case 0:
        if (oponente.vida > 0) {
            printf("\nEl oponente ataca.\n");
            jugador.vida -= oponente.fuerza;
            if (jugador.vida < 0) jugador.vida = 0; 
            printf("Recibiste %d puntos de dano. \nTu vida restante: %.2f\n", oponente.fuerza, jugador.vida);
            verificar_final(oponente, jugador);
        }
        break;
    case 1: /*cuenta mal*/
        if (oponente.vida < oponente.max_vida) { 
            printf("\nEl oponente se defendio.\n");
            float valor_defensa = rand() % 11 + 10; 
            printf("\nvalor_defensa: %2.f", valor_defensa);
            oponente.vida += valor_defensa;
            printf("\noponente.vida: %2.f", oponente.vida);
            //if (oponente.vida > oponente.max_vida) oponente.vida = oponente.max_vida; 
            //printf("\nEl oponente gano %.2f puntos de vida. \nVida restante del oponente: %.2f\n", valor_defensa, oponente.vida);
        } else {
            printf("\nEl oponente intento defenderse, pero no lo atacaron.\n");
            nro_accion = rand() % (NUM_HAB - 1);
        }
        break;
    case 2:
        if (oponente.vida < oponente.max_vida) { 
            printf("\nEl oponente decide curarse.\n");
            int valor_curacion_oponente = rand() % 11 + 10; 
            oponente.vida += valor_curacion_oponente;
            if (oponente.vida > oponente.max_vida) oponente.vida = oponente.max_vida;
            printf("El oponente se curo %d puntos. Vida restante del oponente: %.2f\n", valor_curacion_oponente, oponente.vida);
        } else {
            printf("\nEl oponente intento curarse, pero su vida ya esta completa.\n");
            nro_accion = rand() % (NUM_HAB - 1);
        }
        break;
    case 3:
        printf("\nEl oponente usa un poder especial.\n");
        jugador.vida -= oponente.reflejos;
        if (jugador.vida < 0) jugador.vida = 0;
        printf("El poder especial del oponente te hizo %d de dano. Tu vida restante: %.2f\n", oponente.reflejos, jugador.vida);
        verificar_final(oponente, jugador);
        break;
    }
}

int accion_jugador(caracteristicas_t oponente, caracteristicas_t jugador){
    int eleccion = 0;
    printf("\n--- Elegi que queres hacer ---\n");
    printf("1. Atacar.\n");
    printf("2. Defender.\n");
    printf("3. Curarte.\n");
    printf("4. Usar un poder.\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &eleccion);
    switch (eleccion) {
    case 1: 
        printf("\nAtaque!\n");
        oponente.vida -= jugador.fuerza;
        if (oponente.vida < 0) oponente.vida = 0; 
        printf("Le quitaste %d puntos de vida al oponente. La vida restante del oponente: %.2f\n", jugador.fuerza, oponente.vida);
        if (verificar_final(jugador, oponente)) break;
        break;
    case 2: 
        if (jugador.vida != jugador.max_vida){
            printf("\nDecidiste defenderte.\n"); 
            float valor_defensa_jugador = rand() % 11 + 10; 
            jugador.vida += valor_defensa_jugador;
            if (jugador.vida > jugador.max_vida) jugador.vida = jugador.max_vida; 
            printf("Ganaste %.2f puntos de vida. \nTu vida restante: %.2f\n", valor_defensa_jugador, jugador.vida);
        }else{
            printf("\nNo puedes defenderte, tu vida ya esta completa.\n");
        }
        break;
    case 3: 
        if (jugador.vida != jugador.max_vida) {
            printf("\nDecidiste curarte\n");
            int valor_curacion_jugador = rand() % 11 + 10;  
            jugador.vida += valor_curacion_jugador;
            if (jugador.vida > jugador.max_vida) jugador.vida = jugador.max_vida;
            printf("Te curaste %d puntos. Tu vida restante: %.2f\n", valor_curacion_jugador, jugador.vida);
        } else {
            printf("\nNo puedes curarte, tu vida ya esta completa.\n");
            }
            break;
        case 4: 
            printf("\nUsaste un poder especial.\n");
            oponente.vida -= jugador.reflejos;
            if (oponente.vida < 0) oponente.vida = 0;
            printf("Tu poder especial hizo %d de dano al oponente. La vida restante del oponente: %.2f\n", jugador.reflejos, oponente.vida);
            if (verificar_final(jugador, oponente)) break;
            break;
        default:
            printf("Opcion no valida. Intenta de nuevo.\n");
    }
}

int verificar_final(caracteristicas_t jugador, caracteristicas_t oponente) {
    if (jugador.vida <= 0) {
        printf("Tu personaje ha muerto.\n");
        return 1;
    } else if (oponente.vida <= 0) {
        printf("El oponente ha muerto.\n");
        return 1; 
    }
    return 0; 
}