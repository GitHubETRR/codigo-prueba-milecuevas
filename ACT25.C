#include <stdio.h>

int main(void)
{
    const int sb = 4500;
    int horas,years;
    printf("ingrese la cantidad de horas trabajadas\n");
    scanf("%d",&horas);
    printf("hace cuantos años trabajas en esta empresa\n");
    scanf("%d",&years);
    int sn = sb*horas; /*sn=sueldo neto*/
    int snp = sn+(sn*0.02*years); /*snp=sueldo neto con plus*/
    printf("su sueldo neto es de %d",snp); 

    return 0;

}