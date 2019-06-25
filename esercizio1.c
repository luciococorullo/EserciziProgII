/* Scrivere una function c che cambia il carattere in input da minuscolo a maiuscolo e viceversa automaticamente mediante gli operatori bitwise.  */


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

char upperLower(char ch){ //function che converte una lettera minuscola in una maiuscola
    int pot;

    pot = pow(2,5); //pot sará uguale a 32 ovvero il valore del quinto bit

    ch = ch | pot;  //effettuo una OR bit a bit in modo da cambiare il valore solo del quinto bit

    return ch;      //ritorno il carattere aggiornato
}

char lowerUpper(char ch){ //funcion che converte una lettera maiuscola in una minuscola
    int pot;

    pot = pow(2,5);
    ch = ch ^ pot;  //effettuo una XOR bit a bit del carattere in modo da cambiare solo il quinto bit

    return ch;
}
