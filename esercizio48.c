/* Scrivere function C la costruzione e la visita “per livelli” di un albero qualsiasi
rappresentato mediante array: in input per ciascun nodo sonodati il grado ed i nodi figli  */

#define MAXNODI 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tipo{
    char dato[10];
    int grado;
    int p[2];
    };

struct tipo albero[MAXNODI];

int main(){

    
    printf("\nInserisci il contenuto del nodo radice --> ");
    scanf("%s",&albero[0].dato);
    printf("Inserisci il grado della radice --> ");
    scanf("%d",&albero[0].grado);
    printf("Fine livello.\n");
    crea();

    stampa();

return 0;
}

void crea(){

    int k,i=0,j=1;

    while(i!=MAXNODI){
        for(k=0;k<albero[i].grado;k++){

        printf("\nInserisci il %d figlio del nodo %s -> ", k+1,albero[i].dato);
        scanf("%s",albero[i+j+k].dato);

        printf("Inserisci il grado del %d figlio ->",k+1);
        scanf("%d",&albero[i+j+k].grado);
    	
        albero[i].p[k] = i+j+k;

        }
        j += k-1;
        i++;
        
    }
}
void stampa(){

    short i,j,livello = 0;
    short cnt = 1;
    for(i=0;i<MAXNODI;i++){
        cnt = cnt + albero[i].grado;
    }

    printf("\n\nVisita dell'albero per livelli:\n");
    j=0;
    for(i=0;i<cnt;i++){
        printf("%s -> ",albero[i].dato);
        
        livello = livello + albero[i].grado;
    }
    if (i == j)
    {
    printf("\n");
    j = j+livello;
    livello = 0;
    }
    

}