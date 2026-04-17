#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas (char *V[]);

int main(){
    int i;
    char *V[4];
    for (i=0;i<5;i++){
        V[i]=(char *)malloc(50*sizeof(char));
        printf("Ingrese el nombre de la persona %d\n",i+1);
        gets(V[i]);
    }

    MostrarPersonas(V);

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