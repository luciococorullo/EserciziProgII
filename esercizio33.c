/* Scrivere una function C che legga, mediante una variabile “buffer” di 200char, un file testo e lo
visualizzi sullo schermo 40 char per riga e 25 righe per ogni schermata, fermandosi finché non viene premuto
un tasto per continuare. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 200

int main(){
    char nomefile[15];
    
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", &nomefile);
    strcat(nomefile,".txt");

    func(nomefile);
   
    return 0;
}
void func(char nomefile[]){
    FILE *fp;
    char buffer[BUFFSIZE];
    int i=0,x;

    fp=fopen(nomefile, "r");

    if(fp==NULL)
    {
        printf("Il file non e' stato aperto correttamente\n" );
        return 0;
    }
    while(!feof(fp))
    {
        fgets(buffer,40, fp);
        
        i++;
        if(i%25==0)
        {
            printf("\nPremi 1 per continuare: ");
            scanf(" %d",&x);
        }
        printf("%s\n", buffer);
        
    }
    fclose(fp);
}
