/* Scrivere function C la costruzione e la visita “per livelli” di un albero qualsiasi
rappresentato mediante array: in input per ciascun nodo sonodati il grado ed i nodi figli  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    struct tipo{
        char dato[10];
        int grado;
    };

    struct tipo albero[30];
    
    int corr = 0;
    int size,i,livello;
    int mancano = 1;
    int da_acq = 0;
    int ultimo = 0;

    //inizializzo l'albero a 0
    for(i = 0;i<=10;i++){
        strcpy(albero[i].dato,"0");
    }

    do{
        printf("Inserisci il nodo:\nDato: ");
        scanf("%s",albero[corr].dato);
        printf("\nGrado del nodo: ");
        scanf("%d",&albero[corr].grado);
        printf("\n");

        //incremento gli elementi da acquisire aggiungendo i nuovi
        da_acq = da_acq + albero[corr].grado;
        corr++;
        mancano--;

        if(mancano==0){
            printf("\nFine livello\n");
            mancano = da_acq;
            da_acq = 0;
        }

    }while(mancano!=0);
    size = corr;

    //stampa del vettore
    for(i=0;i<=corr-1;i++){
        printf("%s ->%d\n",albero[i].dato,albero[i].grado);
    }

    printf("\n---Stampa per livelli---\n");

    corr = 0; mancano = 1; da_acq = 0; livello = 1; ultimo = 0;
    printf("Livello numero 1\n");

    do{
        printf("\nNodo: \n");
        printf("Dato = %s \n",albero[corr].dato);
        printf("Grado = %d\n",albero[corr].grado);

        da_acq = da_acq+albero[corr].grado;
        corr++;
        mancano--;

        if(mancano==0){
            livello++;
            printf("\n----Livello numero %d\n",livello);
            mancano = da_acq;
            da_acq = 0;
        }
    }while(mancano!=0);

    printf("Addio puttane!!!!!!");
    return 0;
}