#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas (char *V[]);
char * BuscarNombre (int id, char *V[]);

int main(){
    int i, id;
    char *V[4], *nombre;
    nombre=(char *)malloc(50*sizeof(char));
    for (i=0;i<5;i++){
        V[i]=(char *)malloc(50*sizeof(char));
        printf("Ingrese el nombre de la persona %d\n",i+1);
        gets(V[i]);
    }

    MostrarPersonas(V);

    puts("Ingrese id de la persona para recibir el nombre, del 1 al 5");
    scanf("%d",&id);
    nombre= BuscarNombre(id,V);
    puts(nombre);

    for (i=0;i<5;i++){
        free(V[i]);
    }
    free (nombre);

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

char * BuscarNombre (int id, char *V[]){
    int i;
    id=id-1;
    if (id<0 || id>4){
        return ('\0');
    } else {
        for (i=0;i<5;i++){
            if (id == i){
                return (V[i]);
            }
        }
    }
}