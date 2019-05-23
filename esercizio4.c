/*Scrivere una function C per estrarre dalla variabile intera X i k bit più significativi (k) o meno
significativi (k), dove X e k sono i parametri di input, usando:
1) Una maschera.
2) L’operatore di shift (>> o <<).
3) Il prodotto o la divisione per potenze di 2.
Scrivere una function per ognuna delle metodologie precedenti. */

#include <stdio.h>
#include <math.h>
#define Z 8-(+k)

int mask(int,int);
int shift(int,int);

void calcBin(int [],int);

int main(){
    int x,k;
    int array[8];
    int tmps[8];
    int tmpm[8];

    int tmp1,tmp2;
   

    printf("Insert the decimal number: ");
    scanf("%d",&x);
    printf("\nInsert the number of bits that you wanna extract (max 8)\nUse - if you wanna see the less significative: ");
    scanf("%d",&k);
    printf("\n");

    if(k!=0){
    
    tmp1 = shift(x,k);
    printf("Showing %d bit with shift: ",k);
    calcBin(tmps,tmp1);
    if(k>0){
    for(int i=k-1;i>=0;i--){
    printf("%d",tmps[i]);
    }
    } else{
    
    int z = k * -1;
    for(int i=7;i>=(8-z);i--){
    printf("%d",tmps[i]);
    }
    }
    printf("\n");

    tmp2 = mask(x,k);
    printf("Showing %d bit with mask: ",k);
    calcBin(tmpm,tmp2);

    if(k>0){
    for(int i=7;i>=(Z);i--){
    printf("%d",tmpm[i]);
    }
    }else{
    int z = k * -1;
    for(int i=z-1;i>=0;i--){
    printf("%d",tmpm[i]);
    }
    }
    
    }
    printf("\nOriginal number: ");
    calcBin(array,x);
    for(int i=7;i>=0;i--){
    printf("%d",array[i]);
    }


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

int shift(int x,int k){
    if(k>0){
    return x>>Z;
    }

    else{
    int z;
    z = 8 -(k *-1);
    return x<<z;
    }
}

int mask(int x,int k){
    int mask;
    if(k>0){
    mask = 1 >> k;
    mask = mask - 1;
    mask = mask << (Z);
    }else{
    mask = 1 >> k;
    mask = mask - 1;
    }
    return x&mask;
}

