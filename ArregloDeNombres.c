#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas (char *V[]);
char * BuscaNombrePorId (int id, char *V[]);
char * BuscaNombrePorPalabra (char clave[], char *V[]);

int main(){
    int i, id;
    char *V[4],clave[50], *nombre;
    nombre=(char *)malloc(50*sizeof(char));
    for (i=0;i<5;i++){
        V[i]=(char *)malloc(50*sizeof(char));
        printf("Ingrese el nombre de la persona %d\n",i+1);
        gets(V[i]);
    }

    MostrarPersonas(V);

    puts("Ingrese id de la persona para recibir el nombre, del 1 al 5");
    scanf("%d",&id);
    nombre= BuscaNombrePorId(id,V);
    puts(nombre);

    fflush(stdin);
    puts("Ingrese una palabra clave para buscar un nombre en la lista");
    gets(clave);
    nombre = BuscaNombrePorPalabra(clave,V);
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

char * BuscaNombrePorId (int id, char *V[]){
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

char * BuscaNombrePorPalabra(char clave[], char *V[]){
    int i;
    for (i=0;i<5;i++){
        if (strstr(V[i],clave) != NULL){
            return (V[i]);
        }
    }
    return "-1";
}