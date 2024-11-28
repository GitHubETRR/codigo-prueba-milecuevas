#include <stdio.h>

int main(void)
{
    int edad;
    printf("ingrese su edad\n");
    scanf("%d",&edad);
    int año = 2024 - edad;
    printf("usted nació en el anio %d ",año);

    return 0;
}
