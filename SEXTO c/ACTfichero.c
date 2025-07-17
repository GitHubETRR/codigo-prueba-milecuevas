//hacer uno tipo fichero medico con historial de pacientes

#include <stdio.h>
#include <stdlib.h>
#define LIMITE 30

typedef struct pacientes
{
    char nombre[LIMITE];
    char apellido[LIMITE];
    int edad;
    int dni;
    char sexo[LIMITE];
    float altura;
    float peso;
    char obraSocial[LIMITE];
    int telEmergencia;
    struct pacientes *next;
}pacientes_t;

typedef enum
{
    SALIR,
    AGREGARPACIENTES,
    MOSTRARPACIENTES,
    BUSCARPACIENTES,
    MODIFICARPACIENTES,
    ELIMINARPACIENTES,
}opciones_t;

int bienvenida();
pacientes_t* agregarPacientes(pacientes_t *lista);
void mostrarPacientes(pacientes_t *lista);
void liberar (pacientes_t *lista);

int main()
{
    int opcion; 
    pacientes_t *lista = NULL;
    do
    {
        opcion=bienvenida();
        switch (opcion) 
        {
            case AGREGARPACIENTES:
                lista = agregarPacientes(lista);
                break;
            case MOSTRARPACIENTES:
                mostrarPacientes(lista);
                break;
            case BUSCARPACIENTES:
            {
                int dniBuscar;
                printf("Ingrese el dni del paciente a buscar:\n");
                scanf("%d", &dniBuscar);
                //buscarPaciente(lista, dniBuscar);
                break;
            }
            case MODIFICARPACIENTES:
            {
                break;
            }
            case ELIMINARPACIENTES:
                //funcion;
                break;
        }
    }while (opcion!=SALIR);
    liberar(lista);
    return 0;
}

int bienvenida()
{
    int opcion;
    printf("Bienvenido al archivo de pacientes!\n");
    printf("Por favor, ingrese:\n");
    printf("1 si quiere agregar un paciente\n");
    printf("2 si quiere mostrar un paciente\n");
    printf("3 si quiere buscar un paciente\n");
    printf("4 si quiere modificar pacientes\n");
    printf("0 si quiere salir\n");
    scanf("%d",&opcion);
    return opcion;
}

pacientes_t* agregarPacientes(pacientes_t *lista)
{
    pacientes_t *pacientes_ptr = (pacientes_t *)malloc(sizeof(pacientes_t));
    if(pacientes_ptr==NULL)
    {
        printf("No hay más memoria\n");
        return lista;
    }else{
        printf("ingrese el nombre del paciente:\n");
        scanf(" %s",pacientes_ptr->nombre);
        printf("ingrese el apellido del paciente:\n");
        scanf(" %s",pacientes_ptr->apellido);
        printf("ingrese la edad del paciente:\n");
        scanf("%d",&pacientes_ptr->edad);
        printf("ingrese el dni del paciente:\n");
        scanf("%d",&pacientes_ptr->dni);
        printf("ingrese el sexo del paciente:\n");
        scanf(" %s",pacientes_ptr->sexo);
        printf("ingrese la altura del paciente:\n");
        scanf("%f",&pacientes_ptr->altura);
        printf("ingrese el peso del paciente:\n");
        scanf("%f",&pacientes_ptr->peso);
        printf("ingrese la obra social del paciente:\n");
        scanf(" %s",pacientes_ptr->obraSocial);
        printf("ingrese un telefono en caso de emergencia:\n");
        scanf("%d",&pacientes_ptr->telEmergencia);
        printf("paciente agregado correctamente!\n\n");
        pacientes_ptr->next = lista;
        return pacientes_ptr;
    }
}

void mostrarPacientes(pacientes_t *lista)
{
    while (lista!=NULL)
    {
        printf("Nombre del paciente:%s\n",lista->nombre);
        printf("Apellido del paciente:%s\n",lista->apellido);
        printf("Edad del paciente:%d\n",lista->edad);
        printf("Dni del paciente:%d\n",lista->dni);
        printf("Sexo del paciente:%s\n",lista->sexo);
        printf("Altura del paciente:%f\n",lista->altura);
        printf("Peso del paciente:%f\n",lista->peso);
        printf("Obra social del paciente:%s\n",lista->obraSocial);
        printf("Telefono en caso de emergencia:%d\n\n",lista->telEmergencia);
        lista=lista->next;
    }
}

void liberar (pacientes_t *lista)
{
    pacientes_t *aux;
    while(lista!=NULL)
    {
        aux=lista;
        lista=lista->next;
        free(aux);
    }
}