/* Simulare in C la gestione di una coda (queue) tramite array statico circolare (può essere anche un array
di struct) creando le funzioni di manipolazione enqueue() [inserimento] e dequeue() [eliminazione]. Il
programma deve prevedere un menù che consenta di scegliere l’operazione da eseguire.
 */


#include <stdio.h>
#include <stdlib.h>

void enqueque(int,int [],int *,int,int);
void dequeque(int,int[],int *,int,int);

int main(){
    int queque[] = {0,0,0,0,0,0};
    short lunghezza = 6;

    short risposta = 7;
    int elemento;
    int numElem = 0;

    short *head = 0;

    

    
    

    printf("Queque prima delle modifiche: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",queque[i]);
    }

    while(risposta!=0){
    puts("\n\nQuale operazione vuoi eseguire sulla queque?\n1.Inserire un elemento\n2.Eliminare un elemento\n3.Visualizzare il contenuto\n0.Uscire.");
    scanf("%d",&risposta);
    
    switch (risposta)
    {
    case 1:

        printf("Inserisci l'elemento che vuoi inserire: ");
        scanf("%d",&elemento);
        
        
        enqueque(elemento,queque,&head,numElem,lunghezza);
        numElem++;

        break;
    
    case 2:
        printf("Elemento rimosso.\n");

        dequeque(0,queque,&head,numElem,lunghezza);
        numElem--;
        break;
    
    case 3:

    printf("\nQueque: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",queque[i]);
    }
    default:
    break;
    }

    printf("\nQueque dopo le modifiche: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",queque[i]);
    }
    }
    

    return 0;
}
void enqueque(int elemento,int queque[],int *head,int numelementi,int n){
    
    int bottom = ((*head) + numelementi);
   
    bottom = bottom % n;

    if(numelementi < n){

    queque[bottom] = elemento;
    
    }else
    printf("Overload!\n");
    
}

void dequeque(int elemento,int queque[],int *head,int numelementi,int n){
    int val;

    if(numelementi > 0){
        val = ++(*head);
        val = val % n;
        queque[val] = elemento;
    }else
    printf("Overflow!\n");
    

}