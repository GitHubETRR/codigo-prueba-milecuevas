/*57.	Desarrolle la función “mayorDeDos” que reciba dos enteros por parámetro y muestre por
pantalla al mayor de ellos. Luego modifíquela a “getMayorDeDos” para que devuelva el mayor como resultado.*/ 
#include <stdio.h>

int getMayorDeDos(int a, int b);

int main()
{
    int a,b,result;
    printf("ingrese un numero\n");
    scanf("%d",&a);
    printf("ingrese otro numero\n");
    scanf("%d",&b);
    result = getMayorDeDos (a,b);
    printf("el mayor de los dos es %d \n",result);
    return 0;
}

int getMayorDeDos(int a, int b){
    int mayor;
    if(a<b){
        mayor = b;
    }else{
        mayor = a;
    }
    return mayor;
    
}