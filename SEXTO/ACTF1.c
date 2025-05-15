//hacer algo con estructuras, vectores y funciones con datos de los pilotos de f1 
#include <stdio.h>
#include <stdlib.h>
#define LIMITE 50

typedef struct{
    char nombre[LIMITE];
    char apellido[LIMITE];
    int numAuto;
    char escuderia[LIMITE];
    int puntCampPilotos;
    int puntCampConstr;//revisar
    struct pilotos *next;
}pilotos_t;

typedef enum{
    salir,
    agregarPilotos,//0
    mostrarPilotos,//1
    buscarPilotos,//2
    modificarPilotos,//3
    eliminarPilotos,//4
}opciones_t;

int inicio();
pilotos_t* agregarPiloto(pilotos_t *lista);
void mostrarPilotos(pilotos_t *lista);

int main()
{
    int opción; 
    pilotos_t *lista = NULL;

    do
    {
        opción=inicio();
        switch (opción) 
        {
            case agregarPilotos:
                lista = agregarPiloto(lista);
                break;
            case mostrarPilotos:
                mostrarPilotos(lista);
                break;
        }
    }while (opción!=salir);
    return 0;
}
 
    int inicio()
    {
    int opcion;
    printf("Bienvenido! Este programa es una base de datos de los pilotos de F1\n");
    printf("Ingrese:\n");
    printf("(1):Para agregar un piloto \n");
    printf("(2):Mostrar un piloto\n");
    printf("(3):Buscar un piloto\n");//REVISAR
    printf("(4):Modificar los puntos de los campeonatos\n");
    printf("(5):Eliminar un piloto\n");
    printf("(0):Salir\n");
    scanf("%d",&opcion);
    return opcion;
    }

pilotos_t * agregarPiloto(pilotos_t * lista){
    pilotos_t *piloto_ptr = (pilotos_t *)malloc(sizeof(pilotos_t));
    if (piloto_ptr == NULL) {
        printf("No hay más memoria\n");
        return lista;
    }else{
        printf("ingrese el nombre del piloto:\n");
        scanf("%s",piloto_ptr->nombre);
        printf("ingrese el apellido del piloto:\n");
        scanf("%s",piloto_ptr->apellido);
        printf("ingrese el númeor del auto del piloto:\n");
        scanf("%d",&piloto_ptr->numAuto);
        printf("ingrese la escudería del piloto:\n");
        scanf("%s",piloto_ptr->escuderia);
        printf("ingrese los puntos en el campeonato de pilotos:\n");
        scanf("%d",&piloto_ptr->puntCampPilotos);
        printf("ingrese los puntos en el campeonato de constructores:\n");//REVISAR
        printf("Piloto agregado correctamente!\n\n");
        piloto_ptr->next = lista;
        return piloto_ptr;
    }
    
void mostrarPilotos(pilotos_t *lista){
        while (lista != NULL){
        printf("Nombre: %s\n", lista->nombre);
        printf("Apellido: %s\n",lista->apellido);
        printf("Número de auto: %d\n", lista->numAuto);
        printf("Escudería: %s\n", lista->escuderia);
        printf("Puntos campeonato de pilotos: %d\n", lista->puntCampPilotos);
        printf("Puntos campeonato de constructores: %d\n", lista->puntCampConstr);//REVISAR
        lista = lista->next;;
        }
    }
}
