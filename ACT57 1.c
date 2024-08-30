/*57.	Desarrolle la función “mayorDeDos” que reciba dos enteros por parámetro y muestre por
pantalla al mayor de ellos. Luego modifíquela a “getMayorDeDos” para que devuelva el mayor como 
resultado.*/ 
#include <stdio.h>

void mayorDeDos(int a, int b);

int main()
{
    int a,b;
    printf("ingrese un numero\n");
    scanf("%d",&a);
    printf("ingrese otro numero\n");
    scanf("%d",&b);
    mayorDeDos (a,b);
    return 0;
}

void mayorDeDos(int a, int b){
    if(a<b){
        printf("%d",b);
    }else{
        printf("%d",a);
    }
    
}