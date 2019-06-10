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
        printf("Elemento inserito!\n");

        break;
    
    case 2:

        if(vuoto(&q)){
        printf("Stack vuoto, impossibile rimuovere elemento!\n");
        break;
        }

        printf("Elemento %d rimosso.\n",pop(&q));    //la function pop restituisce l'intero che rimuove dallo stack
        

        break;
    
    default:
    return 0;
    }

}
return 0;
}

void creaStack(stack *q){

    q -> cnt = 0;         //azzerro il campo contatore dello stack
    q -> head = NULL;     //assegno al campo head il puntatore a NULL poiché la lista é vuota


}

int pop(stack *q){

    int info;                     //dichiaro un elemento intero
    elemento *p;                  //dichiaro un puntatore a nodo p 

    info = q ->head ->info; 	  //assegno ad info il campo info dell'elemento in testa alla struct
    p = q -> head;                //assegno al puntatore la posizione della testa dello stack

    q->head = q->head ->link;     //sposto la testa dello stack
    q-> cnt--;                    //decremento il contatore del numero di elementi 
    free(p);                      //libero la memoria precedentemente allocata con la funzione push

    return info;                   //ritorno il campo info dell'elemento rimosso per visualizzare quale elemento é stato rimosso
}

void push(stack *q,int info){

    elemento *p;                     //dichiaro un nodo per il nuovo elemento

    p = malloc(sizeof(elemento));    //alloco memoria per il nuovo elemento
    
    p->info = info;                  //assegno il campo info del nuovo nodo all'informazione contenuta nella variabile presa in imput
    p->link = q->head;               //assegno al campo link del nuovo nodo il puntatore alla testa dello stack
    
    q->head = p;                     //sposto la testa dello stack alla nuova posizione

    q->cnt++;                        //aumento il contatore del numero di elementi
}


boolean vuoto(stack *q){
    return ((boolean)(q->cnt == 0));
}