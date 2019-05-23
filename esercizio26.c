/* Usando l’allocazione dinamica e le funzioni C per manipolare le stringhe, scrivere una function C che
restituisca il numero totale delle occorrenze di una sottostringa in una stringa e
o [liv.1] ne visualizzi la posizione di tutte le occorrenze trovate.
o [liv.2] restituisca in un array la posizione di tutte le occorrenze trovate.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *string;
    char *substring;
    int occ[100];
    int n = 6;
    int m = 1;

    string = (char *)malloc(n+1);
    substring = (char *)malloc(m+1);

    printf("Insert string: ");
    gets(string);

    printf("Insert substring: ");
    gets(substring);


    printf("Numero di occorrenze: %d\n",func(string,substring,occ));
    for(short i=0;i<func(string,substring,occ);i++){
    printf("E'stata trovata un'occorrenza nella posizione %d\n",occ[i]+1);
    }
    return 0;
}
int func(char *string,char *substring,int occ[]){
    int n = strlen(string);
    int m = strlen(substring);

    int k = 0;
    int occorrenze = 0;

    for(int i=0;i<=n;i++){
        if(*(string+i)==*substring){
        occorrenze++;
        
        occ[k]=i;
        k++;
        }
    }
    return occorrenze;
}
