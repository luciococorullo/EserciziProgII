/* Conoscendo la rappresentazione degli interi in C, riscrivere la function C per l’addizione aritmetica
binaria di due interi mediante gli operatori bitwise (vedi esercizio 8.) nel caso gli operandi siano interi con
segno.
Se l’operazione da implementare deve essere l’addizione algebrica (cioè deve valere anche per gli interi
negativi rappresentati per complemento a 2), quale accorgimento va usato nella traduzione in C dell’algoritmo
... e perché. */
#include <stdio.h>

int binarysum(int,int);
int main(){
    int op1;
    int op2;

    printf("Insert the first number: ");
    scanf("%d",&op1);
    printf("\nInsert the second number: ");
    scanf("%d",&op2);

    printf("\n---\nThe sum is: %d",binarysum(op1,op2));


}
int binarysum(int op1,int op2){
    int sum = 0;
    int rip = 1;
    while(rip>0){
        sum = op1 ^ op2;
        rip = op1 & op2;
        rip = rip << 1;
        op1 = sum;
        op2 = rip;
    }
    return sum;
}