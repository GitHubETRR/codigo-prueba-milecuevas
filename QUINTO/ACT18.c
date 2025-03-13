#include <stdio.h>

int main(void)
{
    const float PI = 3.141592654;
    int radio;
    printf("ingrese el radio de su circunferencia\n");
    scanf("%d",&radio);
    float area = PI*radio*radio;
    printf("el area de su circunferencia es de %f\n",area);

    return 0;
}