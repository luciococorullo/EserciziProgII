/* Scrivere una function C per eseguire l’addizione aritmetica binaria di due numeri naturali p e q (p,q∈) mediante gli operatori bitwise. */
#include <stdio.h>

int binarysum(int,int);
int main(){
    unsigned int op1;
    unsigned int op2;

    printf("Insert the first number: ");
    scanf("%d",&op1);
    printf("\nInsert the second number: ");
    scanf("%d",&op2);
    
    printf("\n---\nThe sum is: %d",binarysum(op1,op2));

    return 0;

}
int binarysum(int op1,int op2){

    int sum = 0;            //inizializzo la somma a 0
    int rip = 1;            //inizializzo il riporto a 1 per entrare nel while
    
    
    while(rip>0){           //fino a che c'é riporto
        sum = op1 ^ op2;    //XOR bit a bit tra gli operandi
        rip = op1 & op2;    //calcolo il riporto con la AND bit a bit
        rip = rip << 1;     //shifto il riporto di 1
        op1 = sum;          //per il prossimo ciclo la somma sará l'operando 1
        op2 = rip;          //per il prossimo ciclo il riporto sará l'operando due cosi da sommarlo alla somma calcolata in precedenza
    }
    return sum;
}