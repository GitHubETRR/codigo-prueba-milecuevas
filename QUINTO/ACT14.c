#include <stdio.h>

int main(void)
{
    int ang1;
    int ang2;
    printf("ingrese un angulo del triangulo\n");
    scanf("%d",&ang1);
    printf("ingrese el segundo angulo del triangulo\n");
    scanf("%d",&ang2);
    int ang3 = 180 - ang1 - ang2;
    printf("el angulo restante es %d",ang3);

    return 0;
}