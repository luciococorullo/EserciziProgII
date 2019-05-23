/* scrivere una function C che accetti in input il numero n e legga da tastiera n caratteri (uno alla volta)
costruendo la stringa che li contiene (parametro di output), senza usare strcat */

#include <stdio.h>
void stringcat(char [],int);

int main(){
    char string[4];
    int n = 4;
    stringcat(string,n);
    printf("la stringa e': ");
    puts(string);
    return 0;
}

void stringcat(char string[],int n){
    
    for(short i=0;i<n;i++){
        printf("Inserisci il carattere della stringa: ");
        scanf("%c",&string[i]);
        fflush(stdin);
        printf("\n");
    }

}