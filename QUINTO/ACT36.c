#include <stdio.h>  
#define CORTA_DIST 1
#define LARGA_DIST 2
#define COSTO_VCORTO 1500
#define COSTO_VLARGO 2000
int main(void)
{
    int viaje,peso;
    printf("ingrese 1 si su envio es de larga distancia\n");
    printf("ingrese 2 si su envio es de corta distancia\n");
    scanf("%d",&viaje);
    printf("ingrese el peso de su paquete\n");
    scanf("%d",&peso);
    if(viaje==CORTA_DIST){
        if(peso>20){
            int CostPesoL = ((peso - 20)/5)*800;
            int CostTotal = CostPesoL + COSTO_VLARGO;
            
            printf("su costo total de envio es de %d\n",CostTotal);
        }else{
            printf("su costo total de envio es de %d\n",COSTO_VLARGO);
        }
    }else{
        if(peso>20){
            int CostPesoC = (peso - 20)*800;
            int CostTotal = CostPesoC + COSTO_VCORTO;
            printf("su costo total de envio es de %d\n",CostTotal);
        }else{
            printf("su costo total de envio es de %d\n",COSTO_VCORTO);
        }
    }  
    return 0;                 
}                