#include <stdio.h>

int main (void)
{
    int lado1;
    int lado2;
    printf("ingrese la medida de un lado del rectangulo\n");
    scanf("%d",&lado1);
    printf("ingrese la medida del otro lado\n");
    scanf("%d",&lado2);
    int area = lado1*lado2;
    int per = lado1*2 + lado2*2;
    printf("el area del rectangulo es de %d\n",area);
    printf("el perimetro del rectangulo es de %d\n",per);

    return 0; 
    
}