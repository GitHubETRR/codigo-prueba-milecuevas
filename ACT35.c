#include <stdio.h>

int main (void)
{
    int num;
    printf("ingrese un numero de 4 digitos\n");
    scanf("%d",&num);
    int num1 = num/1000;
    int num2 = num1/10;
    int num3 = (num%100)/10;
    int num4 = (num%100)%10;  
    if(num1==num4 && num3==num2);{
        printf("su numero ingresado es capicua\n");
    }else{
        printf("su numero ingresado no es capicua\n")
    }
        

}