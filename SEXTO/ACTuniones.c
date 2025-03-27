#include <stdio.h>

union{
    float valor;
    unsigned char bytes[4];
}var;


int main()
{
var.valor=24; //cálculos hechos
printf("%x\n",var.bytes[0]);
printf("%x\n",var.bytes[1]);
printf("%x\n",var.bytes[2]);
printf("%x\n",var.bytes[3]);
return 0;
}