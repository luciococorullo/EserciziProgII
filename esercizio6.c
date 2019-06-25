/*Scrivere una function C di conversione di un intero positivo da base 2 a base 10, mediante l’algoritmo
delle divisioni successive, che generi un array di caratteri contenenti le cifre decimali.*/

#include <stdio.h>
#include <math.h>

int summ(int []);
int main(){
    int array[] = {1,1,1,1,1,1,1,1};   //inizializzo l'array con i bit che voglio convertire in decimale

    printf("The number from base 2 to base 10 is: %d",summ(array));
    return 0;
}
int summ(int array[]){
    int i;
    int sum = 0;
    int k = 0;
    for ( i = 7; i >=0; i--){  //for che scorre all'incontrario sull'array

        if(array[i] == 1){
           array[i] = pow(2,k);  //calcolo il valore decimale di quel bit grazie alla potenza in base due della sua posizione
        }
        sum = sum + array[i];   //aggiorno il la somma di valori
        k++;                    //aumento la posizione
    }
    return sum;
}