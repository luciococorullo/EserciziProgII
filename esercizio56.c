/* Scrivere function C per la costruzione di un grafo non orientato mediante matrice di adiacenze: in input
per ogni nodo sono specificati quelli adiacenti. Scegliendo in input un nodo, scrivere una function C che
restituisca il suo grado */


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

    printf("Il grado del nodo e' %d\n",grado(grafo,nodi));



    for(short i=0;i<nodi;i++){
        for(short k=0;k<nodi;k++){
            printf("%d",grafo[i][k]);
        }
        printf("\n");
    }

    return 0;
}

void creaGrafo(int grafo[][MAX],int nodi){

    int ins;

    for(short i=0;i<nodi;i++){
        printf("A quale nodo vuoi collegare il nodo %d? Premi -2 per uscire \n",i);

        for(short k=0;k<nodi;k++){
            
            

            while(ins != -2){
                scanf("%d",&ins);
                grafo[i][ins] = 1; 

            }
            
        }
    }
}

int grado(int grafo[][MAX],int nodi){

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