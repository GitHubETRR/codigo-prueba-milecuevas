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
#include <stdlib.h>
#define LIMITE 100
#define VACIO 0

typedef struct{
    char nombre[LIMITE];
    int codigo;
    int cantidad;
    float precio;
}producto_t;

typedef enum{
    SALIR,
    AGREGAR_PRODUCTO,
    MOSTRAR_PRODUCTOS,
    BUSCAR_PRODUCTO,
    MODIFICAR_CANTIDAD,
    ELIMINAR_PRODUCTO,
}opcion_t;

int Bienvenida();
void AgregarProducto(producto_t[],int);
void MostrarProducto(producto_t[]);
void BuscarProducto(producto_t [], int);
int ModificarCantidad(producto_t[], int);
int EliminarProducto(producto_t[], int);

int main(){
    opcion_t opcion;
    int cantProductos=0;
    int buscar_codigo;
    producto_t productos[LIMITE]={0};
   
    do{
        opcion=Bienvenida();
        switch (opcion){
            case AGREGAR_PRODUCTO:
                AgregarProducto(productos,cantProductos);
            break;
           
            case MOSTRAR_PRODUCTOS:
                MostrarProducto(productos);
            break;
           
            case BUSCAR_PRODUCTO:
                printf("Ingrese el codigo del producto que quiere buscar");
                scanf("%d",&buscar_codigo);
                BuscarProducto(productos,buscar_codigo);
            break;
           
            case MODIFICAR_CANTIDAD:
                /* code */
            break;
           
            case ELIMINAR_PRODUCTO:
                /* code */
            break;
           
            default:
            break;
        }
    } while (opcion!=SALIR);    
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
    system("clear");
    return opcion;
}

void AgregarProducto(producto_t productos[],int indice){
    int i;
    for(i=0;(i<LIMITE) && (productos[i].codigo!=VACIO) ;i++);
    if(i!=LIMITE){
        printf("Ingrese por favor el nombre del producto\n");
        scanf("%s",productos[i].nombre);
        printf("Ingrese el codigo de producto\n");
        scanf ("%d",&(productos[i].codigo));
        printf("Producto agregado correctamente en la posicion %d\n",i);
       
    }else{
        printf("No hay mas lugar\n");
    }
   
}

void MostrarProducto(producto_t productos[]){
    for(int i=0;i<LIMITE;i++){
        if(productos[i].codigo!=VACIO){
            printf("Nombre del producto: %s\n",productos[i].nombre);
            printf("Codigo del producto: %d\n",productos[i].codigo);

        }
       
    }
   
}

void BuscarProducto(producto_t productos[],int codigo_buscar){
   
}
