#include <stdio.h>

int main()
{
	FILE *archivo;
	int a,b,c;

	archivo = fopen("datos.txt", "r");

	if (archivo != NULL) {
		fscanf(archivo, "%d%d%d", &a, &b, &c);
		printf("Los valores son %d %d %d", a, b, c);
		fclose(archivo);
	} else {
		printf("No se pudo abrir");
	}
}
