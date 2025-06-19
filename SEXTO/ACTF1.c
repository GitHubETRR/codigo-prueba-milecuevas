//hacer algo con estructuras, vectores y funciones con datos de los pilotos de f1 
#include <stdio.h>
#include <stdlib.h>
#define LIMITE 50

typedef struct pilotos{
    char nombre[LIMITE];
    char apellido[LIMITE];
    int numAuto;
    char escuderia[LIMITE];
    int puntCampPilotos;
    //int puntCampConstr;
    struct pilotos *next;
}pilotos_t;

typedef enum{
    SALIR,//0
    AGREGARPILOTOS,//1
    MOSTRARPILOTOS,//2
    BUSCARPILOTOS,//3
    MODIFICARPILOTOS,//4
    ELIMINARPILOTOS,//5
}opciones_t;

int inicio();
pilotos_t* agregarPiloto(pilotos_t *lista);
void mostrarPiloto(pilotos_t *lista);
void liberar (pilotos_t *lista);
void buscarPiloto(pilotos_t *lista, int numeroBuscar);
void modificarPuntos(pilotos_t *lista, int numeroMod);

int main()
{
    int opción; 
    pilotos_t *lista = NULL;
    do
    {
        opción=inicio();
        switch (opción) 
        {
            case AGREGARPILOTOS:
                lista = agregarPiloto(lista);
                break;
            case MOSTRARPILOTOS:
                mostrarPiloto(lista);
                break;
            case BUSCARPILOTOS:
                int numeroBuscar;
                printf("Ingrese el número de auto a buscar:\n");
                scanf("%d", &numeroBuscar);
                buscarPiloto(lista, numeroBuscar);
                break;
            case MODIFICARPILOTOS:
                int numeroMod;
                printf("Ingrese el número de auto del piloto a modificar:\n");
                scanf("%d", &numeroMod);
                modificarPuntos(lista, numeroMod);
                break;
            case ELIMINARPILOTOS:
                //funcion;
                break;
        }
    }while (opción!=SALIR);
    liberar(lista);
    return 0;
}

    int inicio()
    {
    int opcion;
    printf("Bienvenido! Este programa es una base de datos de los pilotos de F1\n");
    printf("Ingrese:\n");
    printf("(1):Para agregar un piloto \n");
    printf("(2):Mostrar pilotos\n");
    printf("(3):Buscar un piloto\n");
    printf("(4):Modificar los puntos de los campeonatos\n");
    printf("(5):Eliminar un piloto\n");
    printf("(0):SALIR\n");
    scanf("%d",&opcion);
    return opcion;
    }

pilotos_t * agregarPiloto(pilotos_t * lista)
    {
    pilotos_t *piloto_ptr = (pilotos_t *)malloc(sizeof(pilotos_t));
    if (piloto_ptr == NULL) {
        printf("No hay más memoria\n");
        return lista;
    }else{
        printf("ingrese el nombre del piloto:\n");
        scanf("%s",piloto_ptr->nombre);
        printf("ingrese el apellido del piloto:\n");
        scanf("%s",piloto_ptr->apellido);
        printf("ingrese el número del auto del piloto:\n");
        scanf("%d",&piloto_ptr->numAuto);
        printf("ingrese la escudería del piloto:\n");
        scanf("%s",piloto_ptr->escuderia);
        printf("ingrese los puntos en el campeonato de pilotos:\n");
        scanf("%d",&piloto_ptr->puntCampPilotos);
        //printf("ingrese los puntos en el campeonato de constructores:\n");
        printf("Piloto agregado correctamente!\n\n");
        piloto_ptr->next = lista;
        return piloto_ptr;
        }
    }
    
void mostrarPiloto(pilotos_t *lista)
    {
        while (lista != NULL)
        {
        printf("Nombre: %s\n", lista->nombre);
        printf("Apellido: %s\n",lista->apellido);
        printf("Número de auto: %d\n", lista->numAuto);
        printf("Escudería: %s\n", lista->escuderia);
        printf("Puntos campeonato de pilotos: %d\n\n", lista->puntCampPilotos);
        //printf("Puntos campeonato de constructores: %d\n\n", lista->puntCampConstr);
        lista = lista->next;
        }
    }

void buscarPiloto(pilotos_t *lista, int numeroBuscar)
{
    while (lista != NULL)
    {
        if (lista->numAuto == numeroBuscar)
        {
            printf("Piloto encontrado:\n\n");
            printf("Nombre: %s\n", lista->nombre);
            printf("Apellido: %s\n", lista->apellido);
            printf("Número de auto: %d\n", lista->numAuto);
            printf("Escudería: %s\n", lista->escuderia);
            printf("Puntos campeonato de pilotos: %d\n\n", lista->puntCampPilotos);
        }
        lista = lista->next;
    }
}

void modificarPuntos(pilotos_t *lista, int numeroMod)
{
    while (lista != NULL)
    {
        if (lista->numAuto == numeroMod)
        {
            printf("Piloto encontrado:\n");
            printf("Nombre: %s %s\n", lista->nombre, lista->apellido);
            printf("Puntos actuales: %d\n", lista->puntCampPilotos);
            printf("Ingrese los nuevos puntos del campeonato: ");
            scanf("%d", &lista->puntCampPilotos);
            printf("Puntos actualizados\n\n");
            return;
        }
        lista = lista->next;
    }
}

void liberar (pilotos_t *lista)
{
    pilotos_t *aux;
    while(lista!=NULL)
    {
        aux=lista;
        lista=lista->next;
        free(aux);
    }
}
