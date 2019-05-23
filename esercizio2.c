#include <stdio.h>
#include <math.h>

/*Scrivere una function C:
char rotate(char ch, char n_bit)
per ruotare di n bit (n_bit), verso sinistra o verso destra (rispettivamente per n_bit<0 e per n_bit>0), il
contenuto di una variabile char mediante gli operatori bitwise. 
*/

char rotate(char,int);
void calc_bin(int);

int main(){

    char ch;
    int nBit;

    printf("Insert the letter: ");
    scanf("%c",&ch);

    printf("Insert the number of bits: ");
    scanf("%d",&nBit);
    
    printf("Result: ");
    int tmp = rotate(ch,nBit);
    calc_bin(tmp);

    return 0;
}

char rotate(char ch,int nBit){

    char mask1 = ch << nBit;
    char mask2 = ch >> nBit;

    ch = mask1 | mask2;

    return ch;
}

void calc_bin(int n){
    int k,c;
    for (c = 7; c >= 0; c--)
    {
        k = n >> c;
        
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    
    printf("\n");
}