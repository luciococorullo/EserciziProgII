/* Scrivere una function C per eseguire la sottrazione aritmetica* binaria (*: cioè primo operando
maggiore del secondo) di due numeri naturali p e q (p, q, p−q∈) mediante gli operatori bitwise */
#include <stdio.h>

int binarysub(int,int);
int main(){
    int op1;
    int op2;

    printf("Insert the first number: ");
    scanf("%d",&op1);
    printf("\nInsert the second number: ");
    scanf("%d",&op2);
    
    printf("\n---\nThe sub is: %d",binarysub(op1,op2));
}
int binarysub(int op1,int op2){
    int sub = 0;
    int prestito = 1;

    if(op1<op2){
    printf("Error!");
    return 0;
    }else{

    while(prestito>0){
        sub = op1 ^ op2;
        prestito = ~op1&op2;
        prestito = prestito << 1;
        op1 = sub;
        op2 = prestito;
    }
    return sub;
    }
}
