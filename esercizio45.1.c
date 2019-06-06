/* Realizzare in C le funzioni per la gestione, mediante menù, delle strutture dati lista mediante lista
lineare dinamica e generica con [rispettivamente senza] nodo sentinella. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct structlista{
    int info;
    struct Nodo *link;
}nodo;
typedef nodo elemento;

typedef struct stacl
{
    int cnt;
    elemento *head;
}stack;

typedef enum{false,true} boolean;

void creaStack(stack *);
boolean vuoto(stack *);
void push(stack *,int);
int pop(stack *);

int main(){

    stack *q;

    int elem;
    int risposta=1;

    creaStack(&q);

    while(risposta!=0){
    printf("\n\nQuale operazione vuoi eseguire sullo stack?\n1.Inserire un elemento\n2.Eliminare un elemento\n0.Uscire.\n--->");
    scanf("%d",&risposta);
    

    switch (risposta)
    {
    case 1:

        printf("Inserisci l'elemento che vuoi inserire: ");
        scanf("%d",&elem);
        
        push(&q,elem);

        break;
    
    case 2:

        if(vuoto(&q)){
        printf("stack vuoto, impossibile rimuovere elemento.\n");
        break;
        }

        printf("Elemento rimosso.\n");
        pop(&q);

        break;
    
    default:
    return 0;
    }

}
return 0;
}

void creaStack(stack *q){

    q -> cnt = 0;
    q -> head = NULL;


}

int pop(stack *q){
    int info;
    elemento *p;

    info = q ->head ->info;
    p = q -> head;

    q->head = q->head ->link;
    q-> cnt--;
    free(p);

    return info;
}

void push(stack *q,int info){

    elemento *p;

    p = malloc(sizeof(elemento));
    p->info = info;

    p->link = q->head;
    q->head = p;

    q->cnt++;
}
boolean vuoto(stack *q){
    return ((boolean)(q->cnt == 0));
}