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
    printf("\n\nQuale operazione vuoi eseguire sulla queque?\n1.Inserire un elemento\n2.Eliminare un elemento\n0.Uscire.\n--->");
    scanf("%d",&risposta);
    

    switch (risposta)
    {
    case 1:

        printf("Inserisci l'elemento che vuoi inserire: ");
        scanf("%d",&elem);
        
        enqueque(&q,elem);

        break;
    
    case 2:

        if(vuota(&q)){
        printf("Coda vuota, impossibile rimuovere elemento.\n");
        break;
        }

        printf("Elemento %d rimosso.\n",dequeque(&q));
        
        break;
    
    default:
    break;
    }

}
return 0;
}

void creaCoda(queque *q){

    q -> cnt = 0;               //inizializzo a 0 il contatore del numero di elementi nella coda
    q -> head = NULL;           //visto che la coda é vuota sia la testa che il fondo punteranno a null
    q -> bottom = NULL;

}

int dequeque(queque *q){

    int info;                    //dichiaro una variabile intera che restituiro alla fine della funzione
    elemento *p;                 //dichiaro un nuovo nodo

    info = q ->head ->info;      //metto il contenuto dell'elemento in testa nella variabile info
    p = q -> head;               //assegno al puntatore p la posizione in testa della coda

    q->head = q->head ->link;    //riposiziono la testa della coda alla nuova posizione
    q-> cnt--;                   //decremento il contatore del numero di elementi
    free(p);                     //libero la memoria precedentemente allocata durante l'enqueque

    return info;                 //ritorno il valore rimosso
}

void enqueque(queque *q,int info){

    elemento *p;                    //dichiaro un nuovo elemento

    p = malloc(sizeof(elemento));   //alloco spazio per il nuovo elemento
    p->info = info;                 //assegno al campo info del nuovo nodo il valore della varibile info che voglio inserire nella coda

    p->link = NULL;                 //assegno al puntatore del prossimo elemento il valore NULL visto che sto operando alla fine della coda

    if(!vuota(q)){                  //se la coda non é vuota
        q->bottom->link = p;        //
        q->bottom = p;              //inserisco l'elemento in posizione bottom
    }
    else{
        q->head = q->bottom = p;    //se la coda é vuota la coda sará nella stessa posizione della testa e poi potremmo aggiungere l'elemento
    }
    q->cnt++;                       //aumento il contatore del numero di elementi
}


boolean vuota(queque *q){
    return ((boolean)(q->cnt == 0));
}