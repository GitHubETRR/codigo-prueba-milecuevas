#include <stdio.h>

int main(void)
{
    int num;
    printf("ingrese un número entero positivo de dos o más cifras\n");
    scanf("%d",&num);
    num = num%10;
    printf("la ultima cifra de su numero es %d",num);

    return 0;

}