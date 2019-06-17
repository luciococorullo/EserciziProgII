/* Scrivere function C per la costruzione di un grafo non orientato mediante liste di adiacenze: in input per
ogni nodo sono specificati quelli adiacenti. */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct nodo
{
    char dato;   
    struct nodo *next;
    struct nodo *punt;
}ADIACENZA;


void crea(ADIACENZA *[], int);
void inserisci(ADIACENZA *[], ADIACENZA **, int, int);
void stampa(ADIACENZA *);

int main()
{

int i,n;
ADIACENZA *grafo[SIZE]; 

printf("Inserire numero nodi: ");
scanf("%d",&n);
printf("");

crea(grafo,n);

printf("Liste di adiacenze: \n");

for (int i = 0; i < n; i++)
{
    stampa(grafo[i]);
}
    return 0;
}

void crea(ADIACENZA *grafo[SIZE], int num){

    ADIACENZA *head,*punt[SIZE];
    
    for(short i=0;i<num;i++){

        head = calloc (1,sizeof(ADIACENZA));

        head -> dato = (char)i+97;
        head->next = NULL;
        punt[i]=head;

        grafo[i]=head;
    }

    for(short i=0;i<num;i++){
        inserisci(grafo,&punt[i],i,num);
        printf("");
    }
}

void inserisci(ADIACENZA *grafo[SIZE],ADIACENZA **ppunt, int i, int num){

    int k = 0;
    char vertici;

    ADIACENZA *ptr;

    do{
        fflush(stdin);
        printf("Inserisci i vertici adiacenti di [%c] o premi 0 per uscire\n",i+97);
        scanf("%c",&vertici);

        if(vertici != '0'){

            ptr = calloc(1,sizeof(ADIACENZA));

            ptr -> punt = grafo[(short)vertici-97];

            ptr->next = (*ppunt)->next;
            (*ppunt)->next = ptr;
            *ppunt = ptr;

            k++;
        }
    }while(vertici != '0' && k<num);
}

void stampa(ADIACENZA *head)
{
    ADIACENZA *temp; /*puntatore alla struttura che scorre la componente del grafo */

    temp=head;
    printf("%c -> ",temp->dato); 
    if(temp->next == NULL) 
    printf("NULL\n");
    else
    {
    temp=temp->next;
    do{ 
    printf("%c -> ",temp->punt->dato);
    temp=temp->next;
    } while(temp!=NULL); 
    printf("NULL\n");
    }
    }