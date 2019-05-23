/*  Scrivere una function C che restituisca la matrice C prodotto righecolonne [vedi pdf delle dispense] di
due matrici rettangolari A e B le cui dimensioni sono stabilite in input (usare per tutte le matrici l’allocazione
dinamica e generarle come numeri reali random). C’è qualche preferenza nell’usare malloc() o calloc()
rispettivamente per A, B o C? Verificare se i tempi di esecuzione, per la sola allocazione e totali, sono gli
stessi.  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void matrice(int *,int *,int *,int,int,int);

int main(){
    int *matrixA;
    int *matrixB;
    int *matrixC;
    int m,n,p;
    

    srand(time(NULL));
    printf("Inserisci il numero di colonne delle matrice A: ");
    scanf("%d",&m);
    printf("Inserisci il numero di righe delle matrice A: ");
    scanf("%d",&p);
    printf("Inserisci il numero di righe della matrice B:");
    scanf("%d",&n);


    matrixA=(int *)calloc(m*p,m*p*sizeof(int));
    printf("Matrice A:\n");
     for(short i=0;i<p;i++){
        for(short j=0;j<m;j++){
            *(matrixA+i*m+j)=rand()*5/RAND_MAX;
            printf("%d\t",*(matrixA+i*m+j));
        }
        printf("\n");
    }

    matrixB=(int *)calloc(p*n,p*n*sizeof(int));
    printf("Matrice B:\n");
     for(short i=0;i<p;i++){
        for(short j=0;j<n;j++){
            *(matrixB+i*n+j)=rand()*5/RAND_MAX;
            printf("%d\t",*(matrixB+i*n+j));
        }
        printf("\n");
    }

    matrixC=(int *)calloc(m*m,m*m*sizeof(int));
    printf("Matrice C:\n");
    matrice(matrixA,matrixB,matrixC,n,m,p);
    return 0;
}
void matrice(int *matrixA,int *matrixB,int *matrixC,int n,int m,int p){
     for(short i=0;i<n;i++){
        for(short j=0;j<m;j++){
            *(matrixC+i*m+j)=*(matrixA+i*p+j)*(*(matrixB+i*p+j));
            printf("%d\t",*(matrixC+i*m+j));
        }
        printf("\n");
    }
}
