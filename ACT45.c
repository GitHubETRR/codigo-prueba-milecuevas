#include <stdio.h>

int main()
{
    int veces,num;
    for(veces=0;veces<10;veces++){
        printf("ingrese un numero entero\n");
        scanf("%d",&num);
        if(num>=0){
            printf("su numero ingresado es positivo\n");
        }
    }
}
