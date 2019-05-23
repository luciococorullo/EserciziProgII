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