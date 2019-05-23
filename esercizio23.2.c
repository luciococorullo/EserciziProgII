/* scrivere una function C che accetti in input il numero n e legga da tastiera n caratteri (uno alla volta)
costruendo la stringa che li contiene (parametro di output), senza usare strcat */
//allocazione dinamica

#include <stdio.h>
#include <string.h>

void stringcat(char *,int);

int main(){
    char *string;
    int n = 4;
    string = (char*)malloc(4+1);
    stringcat(string,n);
    printf("The string is: ");
    puts(string);
    return 0;
}

void stringcat(char *string,int n){
    
    for(short i=0;i<n;i++){
        printf("Insert a character: ");
        scanf("%c",&*(string+i));
        fflush(stdin);
       
    }

}