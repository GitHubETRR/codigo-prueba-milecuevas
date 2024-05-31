#include <stdio.h>

int main (void)
{
    int cat1;
    int cat2;
    printf("ingrese la medida de un cateto de su triangulo\n");
    scanf("%d",&cat1);
    printf("ingrese la medida del otro cateto\n");
    scanf("%d",&cat2);
    int area = (cat1 * cat2)/2;
    printf("el area de su triangulo es de %d\n",area);

    return 0;
}