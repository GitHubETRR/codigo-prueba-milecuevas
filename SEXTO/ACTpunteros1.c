#include <stdio.h>

void mostrar(int *);

int main()
{
    int var1;
    printf("ingrese un numero:\n");
    scanf("%d",&var1);
    mostrar(&var1);
    return 0;
}


void mostrar(int* var1)
{
    (*var1)++;
    printf("valor incrementado:%d\n",*var1);
}
