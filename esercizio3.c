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
    int n;
    int array[8];

    printf("Insert the decimal number: ");
    scanf("%d",&n);
    printf("\n");

    calcBin(array, n);

    printf("The number converted in binary is: ");

    for(int i=7; i>=0;i--){
    printf("%d", array[i]);
    }
    
    printf("\nThe decimal number is: %d\n", calcDec(array));
    return 0;
}

void calcBin(int array[], int n){
    int i,k;

    for ( i = 7; i >= 0; i--){      
        k = n >> i;         //shifto di i bit i bit di n nella variabile k

        if (k & 1)
        array[i] = 1;       //se il bit é a 1 devo inserirlo nell'array
        else
        array[i] = 0;       
    }

}

int calcDec(int array[]){
    int sum = 0;       
    
    for (short i = 0; i <=7; i++){

        if(array[i] == 1){    //se il bit é 1 devo contarlo
           array[i] = pow(2,i); //quindi calcolo il suo valore in base alla posizione 
        }
        sum = sum + array[i];   //e lo aggiungo alla somma
    
    }
    return sum;         //in fine ritorno la somma dei valori dei singoli bit, cioé il valore decimale del numero 
}