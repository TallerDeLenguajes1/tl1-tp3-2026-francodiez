#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modificaciones por el punto 4:Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
//usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.

void MostrarPersonas (char *V[], int cantidad);
char * BuscaNombrePorId (int id, char *V[], int cantidad);
char * BuscaNombrePorPalabra (char clave[], char *V[], int cantidad);

int main(){
    int i, id, opcion, cantidad;
    char *V[4],clave[50], *nombre;
    nombre=(char *)malloc(50*sizeof(char));

    do{
        printf("Ingrese la cantidad de nombres que va a ingresar: ");
        scanf("%d",&cantidad);
    } while (cantidad<=0); 
    fflush(stdin);

    for (i=0;i<cantidad;i++){
        V[i]=(char *)malloc(50*sizeof(char));
        printf("Ingrese el nombre de la persona %d\n",i+1);
        gets(V[i]);
    }
    fflush(stdin);

    MostrarPersonas(V,cantidad);

    do {
        puts("Ingrese una opcion para buscar el nombre de la persona:");
        puts("1-Buscar por id"); 
        puts("2-Buscar por una palabra clave");
        scanf("%d",&opcion);
    } while (opcion!=1 && opcion!=2);

    fflush(stdin);
    
    switch(opcion){
        case 1:
        puts("Ingrese id de la persona para recibir el nombre, del 1 al 5");
        scanf("%d",&id);
        nombre= BuscaNombrePorId(id,V,cantidad);
        puts(nombre);
        break;
        case 2:
        puts("Ingrese una palabra clave para buscar un nombre en la lista");
        gets(clave);
        nombre = BuscaNombrePorPalabra(clave,V,cantidad);
        puts(nombre);
        break;
    }

    for (i=0;i<5;i++){
        free(V[i]);
    }
    free (nombre);

    getchar();
    return 0;
}

void MostrarPersonas (char *V[], int cantidad){
    int i;
    puts("Lista de personas");
    for (i=0;i<cantidad;i++){
        puts(V[i]);
    }
}

char * BuscaNombrePorId (int id, char *V[], int cantidad){
    int i;
    id=id-1;
    if (id<0 || id>=cantidad){
        return ('\0');
    } else {
        for (i=0;i<cantidad;i++){
            if (id == i){
                return (V[i]);
            }
        }
    }
}

char * BuscaNombrePorPalabra(char clave[], char *V[], int cantidad){
    int i;
    for (i=0;i<cantidad;i++){
        if (strstr(V[i],clave) != NULL){
            return (V[i]);
        }
    }
    return "-1";
}