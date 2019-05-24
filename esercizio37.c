/*  Simulare in C la gestione di una pila (stack) tramite array statico (può essere anche un array di struct)
creando le funzioni di manipolazione push() [inserimento] e pop() [eliminazione]. Il programma deve
prevedere un menù che consenta di scegliere l’operazione da esegui */

#include <stdio.h>
#include <stdlib.h>

void pop(int,int [],int *);
void push(int, int [],int *);


int main(){
    int stack[] = {0,0,0,0,0,0,0,0,0,0};
    short lunghezza = 10;

    short risposta = 7;
    int elemento;
    short *head = -1;
    

    printf("Stack prima delle modifiche: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",stack[i]);
    }

    while(risposta!=0){
    puts("\n\nQuale operazione vuoi eseguire sullo stack?\n1.Inserire un elemento in testa\n2.Eliminare un elemento dalla testa\n3.Visualizzare lo stack");
    scanf("%d",&risposta);
    
    switch (risposta)
    {
    case 1:

        printf("Inserisci l'elemento che vuoi inserire: ");
        scanf("%d",&elemento);
        
        push(elemento,stack,&head);

        break;
    
    case 2:
        printf("Elemento rimosso: ");

        pop(0,stack,&head);
        break;
    
    case 3:

    printf("\nStack: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",stack[i]);
    }
    default:
    break;
    }
    
    printf("Ora head punta a: %d",head);

    printf("\nStack dopo le modifiche: ");
    for(short i=0;i<lunghezza;i++){
        printf("%d ",stack[i]);
    }
    }
    

    return 0;
}
void push(int elemento,int stack[],int *head){

   
   stack[++(*head)]=elemento;
    
}
void pop(int elemento,int stack[],int *head){
    
    stack[(*head)--]=elemento;

}
