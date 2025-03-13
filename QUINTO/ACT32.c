#include <stdio.h>

int main (void)
{
    int num;
    printf("ingrese un numero\n");
    scanf("%d",&num);
    num = num%2;
    if(num==0){
        printf("su numero ingresado es par");
    }else{
        printf("su numero ingresado es impar");
    }

    return 0;
}