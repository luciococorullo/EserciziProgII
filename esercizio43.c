//A partire dalla versione ricorsiva di costruzione di una lista in C, scriverne la versione iterativa.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct structlista{
    char info;
    struct Nodo *link;
}nodo;
typedef nodo *lista;

int main(){

    lista *lis;

    char stringa[] = "Hello World!";
    short i = 0;

    creaLista(&lis);

    while(stringa[i] != '\0'){
        ins(&lis,stringa[i]);
        i++;
    }

    visitaLista(lis);

    return 0;
}
void visitaLista(lista lis)
{
  if(lis == NULL){
    printf("Lista vuota!\n");
  }
  else{
    printf("%c\t", lis->info);
    visitaLista(lis->link);
  }
}

void creaLista(lista *lis){
    *lis = NULL;
}

void ins(lista *lis,int elem){
    lista tmp;

    tmp = malloc(sizeof(lista));

    tmp->info = elem;
    tmp->link = *lis;

    *lis = tmp;
}