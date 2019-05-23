/*  Confrontando i risultati con quelli delle relative funzioni del C, scrivere una function C che restituisca la
prima occorrenza di una sottostringa in una stringa senza usare strstr */

#include <stdio.h>
#include <string.h>

char *str(char [],char []);
int main(){
    char string[100];
    char substring[5];

    printf("Insert string: ");
    gets(string);

    printf("Insert substring: ");
    gets(substring);

    printf("Result strstr: %s\n",strstr(string,substring));
    printf("My result: %s",str(string,substring));

    return 0;
}
char *str(char string[],char substring[]){
    char occorrenza[100];
    for(short i=0;i<strlen(string)-strlen(substring);i = i + strlen(substring)){
        
        if(string[i] = substring[i]){
            occorrenza[i] = substring[i];
            return *occorrenza;
        }
    }
    return "No match";
}