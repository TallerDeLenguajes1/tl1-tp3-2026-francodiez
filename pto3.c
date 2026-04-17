#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;

float costoTotal(Producto producto);
void mostrar(Cliente cliente[], int numClientes, float total[]);

int main(){
    srand(time(NULL));
    int numClientes,i,j, random;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    float precioProducto, totalCliente[5];
    Cliente *clientes;
    do{
        puts("Ingrese la cantidad de clientes (hasta 5)");
        scanf("%d",&numClientes);
        fflush(stdin);
    } while (numClientes<1 || numClientes>5); //por condicion de tarea
    clientes=(Cliente *) malloc(numClientes*sizeof(Cliente));

    for(i=0;i<numClientes;i++){
        totalCliente[i]=0;
        clientes[i].ClienteID=i+1;
        clientes[i].NombreCliente=(char *) malloc(50 * sizeof(char));
        puts("Ingrese el nombre del cliente");
        fflush(stdin);
        gets(clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir=1 + rand()%(5);
        clientes[i].Productos=(Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for(j=0;j<clientes[i].CantidadProductosAPedir;j++){
            clientes[i].Productos[j].ProductoID=j+1;
            clientes[i].Productos[j].Cantidad=1 + rand()%10;
            random=rand()%5; //porque va de 0 a 4 en el arreglo
            clientes[i].Productos[j].TipoProducto= TiposProductos[random]; //para que de un valor cualquiera del arreglo
            clientes[i].Productos[j].PrecioUnitario= 10 + rand()%91; //100-10+1
            precioProducto= costoTotal(clientes[i].Productos[j]); //por enunciado
            totalCliente[i]=totalCliente[i] + precioProducto;
        }
    }

    mostrar(clientes,numClientes,totalCliente);
    
    for(i=0;i<numClientes;i++){
        free(clientes[i].Productos);
        free(clientes[i].NombreCliente);
    }
    free(clientes);
    getchar();
    return 0;
}


float costoTotal(Producto producto){
    return (producto.Cantidad * producto.PrecioUnitario);
}

void mostrar(Cliente cliente[], int numClientes, float total[]){
    int i,j;
    for(i=0;i<numClientes;i++){
        printf("\nCliente ID:%d\n",cliente[i].ClienteID);
        printf("Nombre del cliente:%s\n",cliente[i].NombreCliente);
        printf("Productos a pedir:%d\n",cliente[i].CantidadProductosAPedir);
        for(j=0;j<cliente[i].CantidadProductosAPedir;j++){
            printf("\nProducto ID:%d\n",cliente[i].Productos[j].ProductoID);
            printf("Cantidad:%d\n",cliente[i].Productos[j].Cantidad);
            printf("Precio Unitario:%.2f\n",cliente[i].Productos[j].PrecioUnitario);
            fflush(stdin);
            printf("Tipo de Producto:%s\n",cliente[i].Productos[j].TipoProducto);
        }
        printf("\nTotal a pagar por el cliente:%.2f\n",total[i]);
    }
}