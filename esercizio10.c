/* Scrivere una function C che, fissato il numero n di bit, calcoli la rappresentazione di un intero:
• per complemento a 2;
• eccesso B (B-biased). */
#include <stdio.h>
#include <math.h>

#define N 8
int comp2(int);
int biased(int);

int main(){
    int num = 4;
    int num2 = 0;
    printf("The number converted: %d\n",comp2(num));
    printf("The number in biased is: %d",biased(num2));
    return 0;
}
int comp2(int num){
    num = ~num;
    num = num + 1;
    return num;
}
int biased(int num){
    int b;
    b = pow(2,N-1)-1;
    return num+b;
}
