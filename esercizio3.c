/*
 Scrivere una function C che, dopo aver estratto i bit da una variabile intera X (tipo char, short o
int) visualizzi i bit e poi ne calcoli il valore corrispondente dalla formula:
Val_X = b[n2n+ … + b[2+ b[2
+ b[2
dove b è l’array dei bit di X: bj
, per j=0, 1,…, n1 dal meno significativo al più significativo, (dove n=8 per il
tipo char, n=16 per il tipo short o n=32 per il tipo int). Confrontare il risultato Val_X con il valore
immesso per la variabile intera X dichiarata una volta signed ed un’altra unsigned. 
*/

#include <stdio.h>
#include <math.h>

void calcBin(int [], int);
int summ(int []);
int main(){
    int n = 5;
    int array[8];

    printf("Insert the decimal number: ");
    scanf("%d",&n);
    printf("\n");

    calcBin(array, n);

    printf("The number converted in binary is: ");

    for(int i=7; i>=0;i--){
    printf("%d", array[i]);
    }
    
    printf("\nThe decimal number is: %d\n", summ(array));
    return 0;
}

void calcBin(int array[], int n){
    int i,k;

    for ( i = 7; i >= 0; i--){
        k = n >> i;

        if (k & 1)
        array[i] = 1;
        else
        array[i] = 0;
    }

}

int summ(int array[]){
    int i, sum = 0;
    
    for ( i = 0; i <=7; i++){

        if(array[i] == 1){
           array[i] = pow(2,i);
        }
        sum = sum + array[i];
    
    }
    return sum;
}