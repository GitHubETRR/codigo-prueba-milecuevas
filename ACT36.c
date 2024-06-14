#include <stdio.h>  

int main(void)
{
    int corto = 1500;
    int largo = 2000;
    int viaje,peso;
    printf("ingrese 1 si su envio es de larga distancia\n");
    printf("ingrese 2 si su envio es de corta distancia\n");
    scanf("%d",&viaje);
    printf("ingrese el peso de su paquete\n");
    scanf("%d",&peso);
    if(viaje==1){
        if(peso>20){
            int CostPesoL = ((peso - 20)/5)*800;
            int CostTotal = CostPesoL + largo;
            printf("su costo total de envio es de %d\n",CostTotal);
        }else{
            printf("su costo total de envio es de %d\n",largo);
        }
    }else{
        if(peso>20){
            int CostPesoC = (peso - 20)*800;
            int CostTotal = CostPesoC + corto;
            printf("su costo total de envio es de %d\n",CostTotal);
        }else{
            printf("su costo total de envio es de %d\n",corto);
        }
    }  
    return 0;                 
}                