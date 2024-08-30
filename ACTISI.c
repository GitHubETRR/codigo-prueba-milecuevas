/*1.Definir cuatro vectores para almacenar los datos de los productos:
Cada vector debe tener una capacidad de 100 elementos.

-codigos (vector de enteros): Almacena los códigos de los productos.
-nombres (vector de strings): Almacena los nombres de los productos.
-cantidades (vector de enteros): Almacena las cantidades en inventario de cada producto.
-precios (vector de flotantes): Almacena los precios por unidad de cada producto.

2.Implementar un menú de opciones que permita al usuario realizar las siguientes operaciones:
-Agregar un producto al inventario.
-Mostrar todos los productos en el inventario.
-Buscar un producto por su código y mostrar sus detalles.
-Modificar la cantidad de un producto existente.
-Eliminar un producto del inventario.

3.Para cada operación del menú, implementa funciones específicas que realicen las siguientes tareas:
-AgregarProducto: Solicita los datos del nuevo producto y los almacena en los vectores correspondientes.
-MostrarProductos: Recorre los vectores e imprime los detalles de todos los productos.
-BuscarProducto: Recibe un código de producto y devuelve su posición en los vectores (o indica si no existe).
-ModificarCantidad: Permite modificar la cantidad en inventario de un producto existente.
-EliminarProducto: Elimina un producto de los vectores de inventario, ajustando los demás elementos para evitar espacios vacíos.

4.Utiliza ciclos para navegar a través de los vectores en las funciones necesarias (por ejemplo, para mostrar todos los productos o buscar un producto específico).

5.Manejo de strings: Asegúrate de que las operaciones de búsqueda y comparación de nombres de productos sean correctas (puedes utilizar funciones de la biblioteca estándar como strcmp).

6.Condiciones de finalización: El programa debe continuar ejecutándose hasta que el usuario seleccione la opción de salir.*/

#include <stdio.h>
#define LIMITE 100

typedef struct{
    char nombre[LIMITE];
    int codigos[LIMITE];
    int cantidades[LIMITE];
    float precios[LIMITE];
}producto_t;

int Bienvenida();
producto_t AgregarProducto();
void MostarProducto(producto_t[]);
void BuscarProducto(producto_t[], int);
int ModificarCantidad(producto_t[], int);
int EliminarProducto(producto_t[], int);




int main(){
    int opcion;
    opcion=Bienvenida();
    do{
        switch (opcion){
        case 1:
            AgregarProducto();
        break;
        
        case 2:
            /* code */
        break;
        
        case 3:
            /* code */
        break;
        
        case 4:
            /* code */
        break;
        
        case 5:
            /* code */
        break;
        
        default:
        break;
    }
    } while (opcion!=0);
    
    
    
}

int Bienvenida(){

    int opcion;
    printf("Este programa gestiona un inventario de productos de una tienda\n");
    printf("Ingrese:\n");
    printf("(1):Para agregar un producto \n");
    printf("(2):Mostras los productos\n");
    printf("(3):Buscar un producto\n");
    printf("(4):Modificar la cantidad de un producto\n");
    printf("(5):Eliminar un producto\n");
    printf("(0):Salir\n");
    scanf("%d",&opcion);
    return opcion;
}

producto_t AgregarProducto(){
    producto_t producto;
    int i;
    for (i=0;i<LIMITE;i++){
        if (producto.cantidades[i]==0){
            printf("Ingrese el nombre del producto: ");
            scanf("%s",&producto.nombre[i]);
            printf("Ingrese la cantidad del producto: ");
            scanf("%d",&producto.cantidades[i]);
            printf("Ingrese el codigo del producto: ");
            scanf("%d",&producto.codigos[i]);
            printf("Ingrese el precio del producto: ");
            scanf("%d",&producto.precios[i]);
            return producto;
            }
        }
}

void MostarProducto(producto_t Producto[]){
    int i;
    for (i=0;i<LIMITE;i++){
        if (Producto.cantidades[i]!=0){
            printf("Nombre: %s\n",Producto.nombre[i]);
            printf("Cantidad: %d\n",Producto.cantidades[i]);
            printf("Precio: %f\n",Producto.precio[i]);
            printf("Codigo:%d",Producto.codigo[i]);
        }
    }
}