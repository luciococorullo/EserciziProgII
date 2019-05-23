/* scrivere una function C che restituisca la concatenazione di due stringhe (parametri di input) senza usare
strcat(...). È a scelta restituire la concatenazione delle due stringhe in una terza variabile (parametro di
output o function stessa) oppure nella prima delle due variabili di input.  */
//allocazione statica


#include <stdio.h>
#include <string.h>

void stringcat(char *,char *,char *);

int main(){
    char string1[4];
    char string2[6];
    char string[10];
    
    int n = 4;
    int m = 6;


    printf("Insert the first string: ");
    gets(string1);
    fflush(stdin);
    printf("Insert the second string: ");
    gets(string2);
    fflush(stdin);
    
    
    stringcat(string1,string2,string);

    printf("The string is: ");
   
    puts(string);
    return 0;
}

void stringcat(char *string1,char *string2,char *string){
    int n,m;
    int i=0;
    n = strlen(string1);
    m = strlen(string2);

    
    while(i<n){
        string[i] = string1[i];
        i++;
    }
        while(i<=m+n){
        string[i] = string2[i-n];
        i++;
        }
}