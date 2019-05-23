/* A partire dalla matrice A(mXn), del tipo sotto indicato, allocata per righe
o staticamente,
o dinamicamente
visualizzarne gli elementi per colonne
Gli elementi ai,j della matrice sono tali che le unità indicano la colonna e le decine indicano la riga cui
 l'elemento appartiene.   */

 #include <stdio.h>
 #include <stdlib.h>
 #define M 4
 #define N 6

 int main(){
    int matrix[M][N] = {{11,12,13,14,15,16},
                        {21,22,23,24,25,26},
                        {31,32,33,34,35,36},
                        {41,42,43,44,45,46}};
                        
    int *mat;

    printf("Matrice statica per colonne:\n");
    for(short i=0;i<N;i++){
        for(short j=0;j<M;j++){
            printf("%d\t",matrix[j][i]);
        }
        printf("\n");
    }

    mat = (char *)calloc(M*N,M*N*sizeof(int));
    printf("Matrice dinamica per colonne:\n");
    for(short i=0;i<N;i++){
        for(short j=0;j<M;j++){
            printf("%d\t",*(mat+i*M+j));
        }
        printf("\n");
    }
    return 0;
 }