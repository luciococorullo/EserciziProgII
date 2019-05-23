/* Scrivere un programma C che crei un file binario “studenti1.dat” contenente le seguenti informazioni:
o cognome e nome (30c) c = char
o matricola (cccc/cccccc) [es. 0124/002345]
o numero degli esami superati (short)
o media pesata degli esami (float)
o crediti acquisiti (short).
Il file contiene le informazioni già ordinate per matricola. Scrivere una function C che, a partire da un file di
aggiornamento relativo ad un certo esame (per esempio, “esameProg2.dat”) contenente gli studenti che
l’hanno superato ed i relativi voti, crei il file “studenti2.dat” aggiornato. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char nomecognome[30];
        char matricola[11];
        short numesami;
        float media;
        short crediti;
    }Studente;

int main(){
    FILE *fp;
    char nomefile[15];
    char buffer[30];
    int fine = 0;

    
    
    Studente studente;

    printf(" Inserisci il nome del file: ");
    gets(nomefile);
    strcat(nomefile," .dat");

    if((fp=fopen(nomefile,"wb"))==NULL){
        printf("File non esistente!");
    }
    do{
    printf("Inserisci i dati dello studente.\n");

    printf("Inserisci nome e cognome: ");
    scanf("%s",&studente.nomecognome);

    printf("Inserisci la matricola: ");
    scanf("%s",&studente.matricola);

    printf("Inserisci il numero di esami dati: ");
    scanf("%d",&studente.numesami);

    printf("Inserisci media esami:");
    scanf("%f",&studente.media);

    printf("Inserisci il numero di crediti acquisiti: ");
    scanf("%d",&studente.crediti);

    fwrite(&studente,sizeof(studente),1,fp);

    printf("Vuoi inserire altro? si=1, no=0\n");
    scanf("%d",&fine);

    }while(!fine);
      
    fclose(fp);

    return 0;
}
