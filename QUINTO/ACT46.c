/*46.	Desarrollar un algoritmo que, ingrese un número entero entre 0 y 10 (validar este valor) 
y muestre por pantalla la tabla de multiplicar del número ingresado.*/
#include <stdio.h>

int main(){
int tabla,num;
    do{
        printf("ingrese un numero entre el 0 y el 10\n");
        scanf("%d",&tabla);
        if((tabla>0)&&(tabla<10)){
            for(num=0;num<=10;num++){
                printf("%dx%d=%d\n",tabla,num,num*tabla);
            }
        }else printf("Su numero ingresado no es correcto, intente nuevamente\n");
    }while((tabla<=0)||(tabla>=10));
    return 0;
}




