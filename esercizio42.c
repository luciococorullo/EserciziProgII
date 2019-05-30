/*  Realizzare la gestione di una lista lineare mediante menù (visualizzazione mediante visita, inserimento
in testa, inserimento in mezzo, eliminazione in testa, eliminazione in mezzo) implementando la lista lineare
con una struttura autoriferente dinamica. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct structlista{
    int info;
    struct Nodo *link;
}nodo;
typedef nodo *lista;

void creaLista(lista *);
void insTesta(lista *,int);
void eliTesta(lista *);
void insMezzo(int,lista *);
void eliMezzo(lista *);
void visitaLista(lista);

int main(){
    
    lista *lis; //definisco una lista

    creaLista(&lis); //la inizializzo a NULL 
    printf("Lista creata\n");

    int elem,elem2;
    int risp = 1;
    
    while(risp != 0){
        printf("---------\nQuale operazione vuoi eseguire sulla lista?\n");
        printf("1.Visita lista\n2.Inserimento in testa\n3.Eliminazione in testa\n4.Inserimento in mezzo\n5.Eliminazione in mezzo\n0.Esci\n");
        scanf("%d",&risp);

        switch (risp)
        {
        case 1:

        visitaLista(lis);

        break;
        
        case 2:

        printf("Che numero vuoi inserire? ");
        scanf("%d",&elem);
        insTesta(&lis,elem);
        printf("Elemento inserito!\n");
        break;

        case 3:
        printf("Elemento in testa eliminato!");
        eliTesta(&lis);
        break;

        case 4:

        printf("Che numero vuoi inserire? ");
        scanf("%d",&elem2);
        insMezzo(elem2,&lis);

        break;

        case 5:

        printf("Elemento in mezzo eliminato!");
        eliMezzo(&lis);

        break;

        default:
        break;
        }
    }
    return 0;
}

void creaLista(lista *lis){
    *lis = NULL;
}

void insTesta(lista *lis,int elem){
    lista tmp;

    tmp = malloc(sizeof(lista));

    tmp->info = elem;
    tmp->link = *lis;

    *lis = tmp;
}

void eliTesta(lista *lis){

    lista tmp;

    if(*lis != NULL){
        tmp = *lis;
        *lis = (*lis)->link;
        free(tmp);
    }
}

void visitaLista(lista lis)
{
  if(lis == NULL){
    printf("Lista vuota!\n");
  }
  else{
    printf("%d --> ", lis->info);
    visitaLista(lis->link);
  }
}

void insMezzo(int elem, lista *lis)
{
    lista tmp;

    tmp = calloc(1,sizeof(lista));

    tmp->info = elem;
    tmp -> link = (*lis)->link;

    (*lis)->link = tmp;
    lis = tmp;
}

void eliMezzo(lista *lis){

    lista tmp;

    tmp = (*lis)-> link;
    (*lis)->link = tmp ->link;
    free(tmp);
}

