/* Simulare in C la gestione di una coda (queue) tramite array statico (può essere anche un array di struct)
creando le funzioni di manipolazione enqueue() [inserimento] e dequeue() [eliminazione]. Il programma
deve prevedere un menù che consenta di scegliere l’operazione da eseguire. Le informazioni NON vanno
spostate! */


#include <stdio.h>
#include <stdlib.h>

void enqueque(int,int [],int *);
void dequeque(int,int[],int *);

int main(){
    int queque[] = {0,0,0,0,0,0,0,0,0,0};
    short lunghezza = 10;

    short risposta = 7;
    int elemento;

    short *head = 9;
    short *bottom = -1;
    

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
        
        enqueque(elemento,queque,&bottom);

        break;
    
    case 2:
        printf("Elemento rimosso.\n");

        dequeque(0,queque,&head);
        break;
    
    case 3:

    printf("\nQueque: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",queque[i]);
    }
    default:
    break;
    }
    
    printf("Ora bottom punta a: %d\n",bottom);
    printf("Ora head punta a: %d\n",head);

    printf("\nQueque dopo le modifiche: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",queque[i]);
    }
    }
    

    return 0;
}
void enqueque(int elemento,int stack[],int *head){

   
   stack[++(*head)]=elemento;
    
}
void dequeque(int elemento,int stack[],int *head){
    
    stack[(*head)--]=elemento;

}