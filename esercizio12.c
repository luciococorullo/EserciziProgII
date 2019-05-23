/* Scrivere una function C per visualizzare la rappresentazione binaria (s,e,m) di un numero float.
Verificare che il valore del numero ottenuto coincida con il dato iniziale. */
#include <stdio.h>

void extraction(long,char []);
int main(){
    char bit[32];
    union basic{float f; long l;}a;
    a.f = 3.2;


    extraction(a.l,bit);
    printf("Segno: %d",bit[0]);

    printf("\nEsponente: ");
    for(short i=1;i<=8;i++){
    printf("%d",bit[i]);
    }

    printf("\nMantissa: ");
    for(short i=9;i<32;i++){
    printf("%d",bit[i]);
    }

    printf("\n\nNumero completo in segno esponente e modulo:\n");
    for(short i=0;i<32;i++){
    printf("%d",bit[i]);
    }

    
}
void extraction(long num,char b[]){
    for(int i=31;i>=0;i--){
        b[i] = (char) (1 & num);
        num = num >> 1;
    }
}