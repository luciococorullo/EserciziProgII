/*Scrivere due function C di conversione di un intero positivo (int) da base 10 a base 2 mediante
l’algoritmo delle divisioni successive realizzato rispettivamente:
• Usando gli operatori di quoziente e resto della divisione intera;
• Usando gli operatori bitwise.*/

#include<stdio.h>
#include<math.h>

void conversion(int,int,int []);
void convBit(int [],int);

int main(){
    int num;
    int base;

    int result[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int result1[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    printf("Insert the decimal number: ");
    scanf("%d", &num);
    printf("\nInsert the base: ");
    scanf("%d",&base);

    conversion(num,base,result);

    printf("\nConverted number in base %d (using divisions): ",base);
    for(int i=0;i<=15;i++){
    printf("%d", result[i]);
    }

    printf("\n\nBinary number (using bitwise): ");
    convBit(result1,num);
    for(int i=15;i>=0;i--){
    printf("%d", result1[i]);
    }
    
    return 0;
}
void conversion(int num,int base,int result[]){
    int i = 15;
    while(num>0){
        result[i]=num%base;
        num = num / base;
        i--;
    }
}
void convBit(int array[], int n){
    int i,j;

    for ( i = 15; i >= 0; i--){
        j = n >> i;

        if (j & 1)
        array[i] = 1;
        else
        array[i] = 0;
    }
}

