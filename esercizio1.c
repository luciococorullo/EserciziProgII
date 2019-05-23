#include <stdio.h>
#include<math.h>

char upperLower(char);
char lowerUpper(char);

int main(){

    char ch;
    printf("Insert letter: ");
    scanf("%c",&ch);
    printf("lower letter: %c\n",upperLower(ch));
    printf("upper letter: %c\n",lowerUpper(ch));
    return 0;
}

char upperLower(char ch){
    int pot;

    pot = pow(2,5);
    ch = ch | pot;

    return ch;
}

char lowerUpper(char ch){
    int pot;

    pot = pow(2,5);
    ch = ch ^ pot;

    return ch;
}
