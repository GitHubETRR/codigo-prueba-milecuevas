#include <stdio.h>

int main (void)
{
    float cat1;
    float cat2;
    printf("ingrese la medida de un cateto de su triangulo\n");
    scanf("%f",&cat1);
    printf("ingrese la medida del otro cateto\n");
    scanf("%f",&cat2);
    float area = (cat1 * cat2)/2;
    printf("el area de su triangulo es de %f\n",area);

    return 0;

}