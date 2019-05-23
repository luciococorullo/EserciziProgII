/* Scrivere una function C per la ricerca diretta di tutte le occorrenze di un pattern in un testo dove:
- il testo è memorizzato in un file;
- la lettura del file avviene “a pezzi” mediante un array-buffer;
- il pattern è definito in input (e costruito dinamicamente). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4

int ricerca(int,char *,FILE *);
int main(){
    char nomefile[15];
    char *pattern;
    FILE *fp;
    int strlen = 4;

    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", &nomefile);
    strcat(nomefile,".txt");

    if((fp = fopen(nomefile,"r"))==NULL){
        printf("Errore nell'apertura del file!");
        exit(1);
    }

    pattern = (char *)malloc(strlen);
    printf("Inserisci il pattern: ");
    fflush(stdin);
    gets(pattern);

    printf("Ho trovato %d corrispondenze.",ricerca(strlen,pattern,fp));

    fclose(fp);

    return 0;
}
int ricerca(int strlen,char *pattern,FILE *fp){

    char buffer[BUFSIZE];
    int j = 0;
    char *ch,*ultimi;
    char *null ="";
    int trovati = 0;
    

     while(!feof(fp))
    {

        *buffer = *null;
        fgets(buffer,BUFSIZE,fp);

        ch = strstr(buffer,pattern+j);
       
        while(ch!=0){
            trovati++;
            ch = strstr(ch+strlen-j,pattern);
            j = 0;
        }

        //controllo se ci sono corrispondenze su due buffer successivi
        j = strlen-1;
        ultimi = buffer+BUFSIZE-1-j;
        while(strncmp(pattern,ultimi,j)!=0 && j>0){
            j--;
            ultimi = buffer + BUFSIZE-1-j;
        }
    }
    return trovati;
}