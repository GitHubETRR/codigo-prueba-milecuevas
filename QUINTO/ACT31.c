#include <stdio.h>

int main (void)
{
    int num1;
    int num2;
    printf("ingrese un numero entero\n");
    scanf("%d",&num1);
    printf("ingrese otro numero entero\n");
    scanf("%d",&num2);
    if(num1==num2){
        printf("%d es igual que %d",num1,num2);
    }else{
        printf("%d es distinto de %d",num1,num2);
    }

    return 0;
}