#include <stdio.h>

int main (void)
{
    int num1,num2;
    printf("ingrese un numero\n");
    scanf("%d",&num1);
    printf("ingrese otro numero\n");
    scanf("%d",&num2);
    int num3 = num1 + num2;
    int num4 = num3%2;
    if(num4==0){
        printf("la suma de sus numeros ingresados da como resultado un numero par\n");
    }else{
        printf("la suma de sus numeros ingresados da como resultado un numero impar\n");
    }
}