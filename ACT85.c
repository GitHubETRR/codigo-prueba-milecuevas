/*85.	Escribe un programa que almacene, en un vector con dimensión 10, los 10 primeros números
de la Quiniela. El ingreso de los datos será indicando posición-numero, de modo que puedo 
ingresar la posición 5 antes que la posición 2.*/

#include <stdio.h>
#define TAMANO_VECTOR 10

int main()
{
    int i,a,valor,posicion;
    int QUINIELA[TAMANO_VECTOR];
    for(i=0;i<10;i++){
        printf("ingrese un numero\n");
        scanf("%d",&valor);
        printf("ingrese la posicion para almacenarlo\n");
        scanf("%d",&posicion);
        QUINIELA[posicion] = valor;
    }
    for(a=0;a<TAMANO_VECTOR;a++){
            printf("vector[%d]=%d\n",a,QUINIELA[a]);
    }
    return 0;
}