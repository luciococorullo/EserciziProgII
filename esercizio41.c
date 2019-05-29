/*Simulare in C la gestione delle camere di un albergo mediante liste lineari rappresentate su un array di
struct: i principali campi sono le “informazioni” (numero di camera, cliente, etc.) ed i “link” (puntatori ai
nodi della lista). [Suggerimento: L’array di struct corrisponde alla memoria in cui allocare la lista delle camere libere
(ListaLibera) e la lista delle camere occupate (ListaDati). È necessario creare prima la ListaLibera,
inizializzando l’array dei link in modo che ogni componente punti alla componente successiva. Ogni nodo da inserire nella
ListaDati, quando una camera viene assegnata ad un cliente, è prelevato dalla testa della ListaLibera ed
inserito nella testa della ListaDati; mentre il nodo da eliminare dalla ListaDati, quando una particolare camera
viene liberata, è restituito alla ListaLibera (in testa) per poter essere riutilizzato in seguito */


#include <stdio.h>
#include <stdlib.h>

struct Nodo{

    int num;
    struct Nodo *link;

};


void visita(struct Nodo []);

int main(){

    struct Nodo libera[] = {{100,&libera[1]},{101,&libera[2]},{102,&libera[3]},{103,&libera[4]},{104,NULL}};
    struct Nodo dati[5];


    int occupate = 0;

    printf("Le stanze libere sono:\n");
    visita(libera+occupate);

    int risp = 9;

    while(risp!=0){

    printf("Vuoi occupare una stanza? 1=si,0=no\n");
    scanf("%d",&risp);

    if(risp==0)
    break;
    
    gestione(libera,dati);
    occupate++;

    printf("Stanza numero %d occupata!",libera[occupate-1].num);
    }

    printf("Le stanze attualmente libere sono:\n");
    visita(libera+occupate);
return 0;
}
void visita(struct Nodo lista[]){


    while(lista != NULL){
        printf("Stanza numero:\t%d\n",lista->num);
        lista = lista->link;
    }
}
void gestione(struct Nodo listalibera[], struct Nodo listadati[]){

    listadati->num = listalibera->num;

    listalibera->num = 0;

    listadati->link = listalibera->link;

    listalibera->link = NULL;

    listalibera = listalibera->link;

}
