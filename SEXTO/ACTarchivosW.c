#include <stdio.h>

int main()
{
    char nombre[10];
    char apellido[10];
    printf("Ingrese su nombre:\n");
    scanf("%s", nombre);
    printf("Ingrese su apellido:\n");
    scanf("%s", apellido);
    printf("Nombre completo ingresado: %s %s",nombre,apellido);

    FILE *archivo = fopen("datos.txt", "w");
    fprintf(archivo, "%s\n", nombre);
    fprintf(archivo, "%s\n", apellido);
    fclose(archivo);
    return 0;
}
