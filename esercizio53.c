/* Scrivere function C iterativa per la costruzione di un albero binario di ricerca rappresentato mediante
array. */


#include <stdio.h>
#include <stdlib.h>
#define MAX 10
 
int leaf(int[],int);
void visitaPreOrderRic(int[],int);
void visitaInOrderRic(int[],int);
void visitaPostOrderRic(int[],int);
 
int main()
{
    int tree[MAX] = {-1,1,2,3,4,5,-1,7,8,9};

    printf("\nINORDER\n");
    visitaInOrderRic(tree,1);
    
    return 0;
}
 
void visitaInOrderRic(int tree[], int i)
{
    if(leaf(tree, i))
        {
 
        if(tree[i] != -1)
        printf("\n*   NODO->%d  *\n",tree[i]); 

 
        return;
        }
        else{
            visitaInOrderRic(tree,i*2);
 
            if(tree[i] != -1)
            printf("\n*   NODO->%d  *\n",tree[i]); 

 
            visitaInOrderRic(tree,i*2+1);
            }
}

int leaf(int tree[], int i)
{
    if(2*i < MAX || 2*i+1 < MAX)
        return 0;
    else
        return 1;
}