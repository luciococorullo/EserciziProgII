/* Realizzare in C le funzioni per la gestione, mediante menù, delle strutture dati coda mediante lista
lineare dinamica e generica con [rispettivamente senza] nodo sentinella. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct structlista{
    int info;
    struct Nodo *link;
}nodo;
typedef nodo elemento;

typedef struct queque
{
    int cnt;
    elemento *head;
    elemento *bottom;
}queque;

typedef enum{false,true} boolean;

void creaCoda(queque *);
boolean vuota(queque *);
void enqueque(queque *,int);
int dequeque(queque *);

int main(){

    queque *q;

    int elem;
    int risposta=1;

    creaCoda(&q);

    while(risposta!=0){
    printf("\n\nQuale operazione vuoi eseguire sulla queque?\n1.Inserire un elemento\n2.Eliminare un elemento\n0.Uscire.");
    scanf("%d",&risposta);
    

    switch (risposta)
    {
    case 1:

        printf("Inserisci l'elemento che vuoi inserire: ");
        scanf("%d",&elem);
        
        enqueque(&q,elem);

        break;
    
    case 2:
        printf("Elemento rimosso.\n");

        dequeque(&q);

        break;
    
    default:
    break;
    }

}
return 0;
}

void creaCoda(queque *q){

    q -> cnt = 0;
    q -> head = NULL;
    q -> bottom = NULL;

}

int dequeque(queque *q){
    int info;
    elemento *p;

    info = q ->head ->info;
    p = q -> head;

    q->head = q->head ->link;
    q-> cnt--;
    free(p);

    return info;
}

void enqueque(queque *q,int info){
    elemento *p;

    p = malloc(sizeof(elemento));
    p->info = info;

    p->link = NULL;

    if(!vuota(q)){
        q->bottom->link = p;
        q->bottom = p;
    }
    else{
        q->head = q->bottom = p;
    }
    q->cnt++;
}
boolean vuota(queque *q){
    return ((boolean)(q->cnt == 0));
}