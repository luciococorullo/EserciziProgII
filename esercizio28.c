/* Utilizzando per le stringhe
o l’allocazione statica
o l’allocazione dinamica
scrivere una function C che elimini tutte le occorrenze di una data sottostringa in una stringa col minimo
numero di spostamenti di blocchi di memoria.  */

#include <stdio.h>
#include <string.h>

void canc(char *,char*,char *);
int main(){
    char *string;
    char *substring;
    char *second;

    int n = 10;
    int m = 2;
    int k = 2;

    string = (char *)malloc(n-1);
    substring = (char *)malloc(m-1);
    second = (char *)malloc(k-1);

    puts("Inserisci stringa: ");
    gets(string);
    puts("Inserisci sottostringa: ");
    gets(substring);
    puts("Inserisci seconda sottostringa: ");
    gets(second);

    canc(string,substring,second);
    puts(string);
    return 0;
}
void canc(char *string,char *substring,char *second){
    int n = strlen(string);
    int m = strlen(substring);
    int k = strlen(second);

    for(int i=0;i<=n;i=i+m){
        if(*(string+i)==*substring){
        *(string+i) = *second;
    }
    }
}