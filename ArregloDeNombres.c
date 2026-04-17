#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas (char *V[]);
char * BuscarNombre (char clave[], char *V[]);

int main(){
    int i;
    char *V[4],clave[50], *nombre;
    nombre=(char *) malloc(50 * sizeof(char));
    for (i=0;i<5;i++){
        V[i]=(char *)malloc(50*sizeof(char));
        printf("Ingrese el nombre de la persona %d\n",i+1);
        gets(V[i]);
    }

    MostrarPersonas(V);

    puts("Ingrese una palabra clave para buscar un nombre en la lista");
    gets(clave);
    nombre = BuscarNombre(clave,V);
    puts(nombre);

    for (i=0;i<5;i++){
        free(V[i]);
    }

    getchar();
    return 0;
}

void MostrarPersonas (char *V[]){
    int i;
    puts("Lista de personas");
    for (i=0;i<5;i++){
        puts(V[i]);
    }
}

char * BuscarNombre (char clave[], char *V[]){
    int i;
    for (i=0;i<5;i++){
        if (strstr(V[i],clave) != NULL){
            return (V[i]);
        }
    }
    return "-1";
}