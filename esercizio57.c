/* Scrivere function C per la costruzione di un grafo orientato mediante matrice di adiacenze: in input per
ogni nodo sono specificati quelli raggiungibili. Scegliendo in input un nodo, scrivere una function C che
restituisca il numero degli archi uscenti e quello degli archi entranti. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int main(){

    int nodi;
    int grafo[MAX][MAX];

    printf("Quanti nodi vuoi inserire? Max 7\n");
    scanf("%d",&nodi);

    for(short i=0;i<nodi;i++){
        for(short k=0;k<nodi;k++){
            grafo[i][k] = 0;
        }
    }

       for(short i=0;i<nodi;i++){
        for(short k=0;k<nodi;k++){
            printf("%d",grafo[i][k]);
        }
        printf("\n");
    }

    creaGrafo(grafo,nodi);

    printf("Il numero degli archi uscenti del nodo e' %d\n",gradoUscente(grafo,nodi));
    printf("Il numero degli archi entranti del nodo e' %d\n",gradoEntrante(grafo,nodi));



    for(short i=0;i<nodi;i++){
        for(short k=0;k<nodi;k++){
            printf("%d",grafo[i][k]);
        }
        printf("\n");
    }

    return 0;
}

void creaGrafo(int grafo[][MAX],int nodi){

    int ins,co;

    for(short i=0;i<nodi;i++){
        printf("A quale nodo vuoi collegare il nodo %d? Premi -2 per uscire \n",i);

        for(short k=0;k<nodi;k++){
            
            

            while(ins != -2){
                scanf("%d",&ins);
                grafo[i][ins] = 1; 
            }
            ins = 0;
            
        }
    }
}

int gradoUscente(int grafo[][MAX],int nodi){

    int nodo;
    int cont = 0;


    printf("Inserisci il nodo\n");
    scanf("%d",&nodo);

    for (short i = 0; i < nodi; i++)
    {
        if(i==nodo){
            for (short k = 0; k < nodi; k++)
            {
                if(grafo[i][k]==1){
                cont++;
                }
            }
            
        }
    }
    return cont;
}

int gradoEntrante(int grafo[][MAX],int nodi){

    int nodo;
    int cont = 0;


    printf("Inserisci il nodo\n");
    scanf("%d",&nodo);

    for (short k = 0; k < nodi; k++)
    {
        if(k==nodo){
            for (short i = 0; i < nodi; i++)
            {
                if(grafo[i][k]==1){
                cont++;
                }
            }
            
        }
    }
    return cont;
}