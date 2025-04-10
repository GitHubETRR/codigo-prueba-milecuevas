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
    agregarPiloto,//0
    mostrarPiloto,//1
    buscarPiloto,//2
    modificarPiloto,//3
    eliminarPiloto,//4
}opciones_t

int inicio();


int main()
{
    do
    {
        opción=inicio();
    } while (opción!=salir);
    
}

int inicio()
{
    int opcion;
    printf("Bienvenido! Este programa es una base de datos de los pilotos de F1\n");
    printf("Ingrese:\n");
    printf("(1):Para agregar un piloto \n");
    printf("(2):Mostrar un piloto\n");
    printf("(3):Buscar un piloto\n");
    printf("(4):Modificar los puntos de los campeonatos\n");
    printf("(5):Eliminar un piloto\n");
    printf("(0):Salir\n");
    scanf("%d",&opcion);
    return opcion;
}

void agregarPiloto()
{
    pilotos_t *piloto_ptr = (pilotos_t *)malloc(sizeof(pilotos_t));
    if (piloto_ptr == NULL) {
        printf("No hay más memoria\n");
        return;
    }else
    {
        printf("ingrese el nombre del piloto:\n");
        scanf("%s",piloto_ptr->nombre);
        printf("ingrese el apellido del piloto:\n");
        scanf("%s",piloto_ptr->apellido);
        printf("ingrese el númeor del auto del piloto:\n");
        scanf("%d",piloto_ptr->numAuto);
        printf("ingrese la escudería del piloto:\n");
        scanf("%d",piloto_ptr->escuderia);
        printf("ingrese los puntos en el campeonato de pilotos:\n");
        scanf("%d",piloto_ptr->puntCampPilotos);
        printf("ingrese los puntos en el campeonato de constructores:\n");//a revisar
    }
    
}
