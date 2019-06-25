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
    int sub = 0;            //inizializzo il risultato della sottrazione a 0
    int prestito = 1;       //inizializzo il valore del prestito a 1 per entrare nel ciclo

    if(op1<op2){            //verifico che la sottrazione sia possibile nell'insieme dei numeri interi
    printf("Error!");
    return 0;
    }else{

    while(prestito>0){               //fino a quando c'é un prestito
    
        sub = op1 ^ op2;             //XOR bit a bit tra gli operandi
        prestito = ~op1&op2;         //calcolo il prestito facendo la AND bit a bit tra l'operando 2 e l'operando 1 negato, ovvero invertito di tutti i bit
        prestito = prestito << 1;   //shifto il prestito di 1 bit a sinistra
        op1 = sub;                  //per il prossimo ciclo l'operando uno sará il valore della sottrazione
        op2 = prestito;             //per il prossimo ciclo l'operando due sará il prestito della sottrazione precedente
    }
    return sub;
    }
}
