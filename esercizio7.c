/*Ripetere l’esercizio precedente nel caso che l’input sia una stringa di caratteri contenenti i bit del
numero.*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int conversion(char []);

int main(){
    char string[] = {0,1,0,1};
    printf("Il numero convertito: %d",conversion(string));
    return 0;
}

int conversion(char string[]){
    int i;
    int sum = 0;
    int k = 0;
    for ( i = 3; i >=0; i--){

        if(string[i] == 1){
           string[i] = pow(2,k);
        }
        sum = sum + string[i];
        k++;
    }
    return sum;
}