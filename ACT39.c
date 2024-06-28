#include <stdio.h>

int main(void)
{
    int nota;
    printf("ingrese la calificacion entera de un alumno\n");
    scanf("%d",&nota);
    if(nota==10){
        printf("el alumno obtuvo un sobresaliente");
    }if((nota==9)||(nota==8)){
        printf("el alumno obtuvo un distinguido");
    }if((nota==7)||(nota==6)){
        printf("el alumno obtuvo un bueno");
    }if((nota==5)||(nota==4)){
        printf("el alumno obtuvo un aprobado");
    }if((nota==3)||(nota==2)||(nota==1)){
        printf("el alumno obtuvo un desaprobado");
    }
    return 0;
}
