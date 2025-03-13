#include <stdio.h>

int main (void)
{
    int num,cifra1,cifra2,cifra3;
    printf("ingrese un número de 3 cifras\n");
    scanf("%d",&num);
    cifra3 = num%10;
    cifra2 = (num/10)%10;
    cifra1 = num/100;
    printf("las cifras por separado de su numero son:\n%d\n%d\n%d",cifra1,cifra2,cifra3);

    return 0;
    
}