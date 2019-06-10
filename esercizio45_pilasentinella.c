/* Realizzare in C le funzioni per la gestione, mediante menù, delle strutture dati lista mediante lista
lineare dinamica e generica con nodo sentinella. */

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
void pop(stack *);
void stampa(stack *);


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

        pop(&q);
        printf("Elemento rimosso.\n");    //la function pop restituisce l'intero che rimuove dallo stack
        

        break;
    
    default:
    return 0;
    }

    
    stampa(&q);
}
return 0;
}

void creaStack(stack *q){

    stack *p;

    q -> cnt = 0;
    p = calloc(1,sizeof(stack)); 

    q ->head->info = 1;
    q->head = p;
    

}

void pop(stack *q){//elimina

    elemento *p;                  

    if(q->cnt>1){
    if(q->head!=NULL){

    p = q -> head -> link;

    if(p->link!=NULL){
    
    q->head->link = p ->link;     
    
    }else{
    q->head->link = NULL;
    }

    q-> cnt--;                     
    free(p); 
    }
    }                    
    	
}

void push(stack *q,int info){

    elemento *p;                     //dichiaro un nodo per il nuovo elemento

    p = calloc(1,sizeof(elemento));    //alloco memoria per il nuovo elemento
    
    p->info = info;                  //assegno il campo info del nuovo nodo all'informazione contenuta nella variabile presa in imput
    p->link = q->head->link;               //assegno al campo link del nuovo nodo il puntatore alla testa dello stack
    
    q->head->link = p;                     //sposto la testa dello stack alla nuova posizione

    q->cnt++;                        //aumento il contatore del numero di elementi
}


boolean vuoto(stack *q){
    return ((boolean)(q->cnt == 0));
}

void stampa(stack *q){

    elemento *ptr;

    ptr = q->head;

    printf("Lo stack contiene: \n");
    while(ptr->link != NULL){
        
        printf("Elemento %d\n",ptr->info);
        ptr = ptr -> link;
    }
}