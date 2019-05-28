/* Simulare in C l’algoritmo di visita di una lista lineare già memorizzata mediante un array statico di
struct (come nella tabella in basso) in cui il primo campo contiene l’informazione ed il secondo contiene il
link al nodo successivo (in questo caso il link è l’indice di una componente dell’array). Memorizzando
nell’array i dati come mostrato nella figura che segue, l’output del programma consiste nell’elenco di nomi
ordinato alfabeticamente */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{

    char nome[20];
    struct Nodo *p;

}nodo;

void visita(nodo []);
int main(){

    nodo lista[] = {{"Anna",&lista[5]},{"Mario",&lista[8]},{"Giuseppe",&lista[6]},{"Angela",&lista[0]},{"Valeria",NULL},{"Fabrizio",&lista[7]},{"Marianna",&lista[1]},{"Giovanni",&lista[2]},{"Patrizia",&lista[10]},{"Valentina",&lista[4]},{"Sara",&lista[9]}};

    printf("Lista: \n");
    visita(lista);
    
    return 0;
}
void visita(nodo lista[]){

    lista = lista + 3;

    while(lista != NULL){
        printf("Nome: %s\n",lista->nome);
        lista = lista->p;
    }   
}