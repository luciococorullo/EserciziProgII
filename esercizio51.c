/*  Scrivere le function C per la visita (preorder, inorder e postorder) di un albero binario rappresentato
mediante array.  */


#include <stdio.h>
#include <stdlib.h>
#define MAX 10
 
int leaf(int[],int);
void visitaPreOrderRic(int[],int);
void visitaInOrderRic(int[],int);
void visitaPostOrderRic(int[],int);
 
int main()
{
    int tree[MAX] = {-1,0,2,3,4,5,6,-1,-1,9};
 
    
    printf("\nPREORDER\n");
    visitaPreOrderRic(tree,1);
    
 
    
    printf("\nINORDER\n");
    visitaInOrderRic(tree,1);
    
 
    
    printf("\nPOSTORDER\n");
    visitaPostOrderRic(tree,1);
    
 
    return 0;
}
 
 
void visitaPreOrderRic(int tree[], int i)
{
    if(tree[i] != -1)
    printf("\n*   NODO->%d  *\n",tree[i]); 
 
 
    if(leaf(tree, i))
        {
        return;
        }
        else{
            visitaPreOrderRic(tree,i*2);   //sinistra
            visitaPreOrderRic(tree,i*2+1); //destra
        }
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
 
void visitaPostOrderRic(int tree[], int i)
{
    if(leaf(tree, i))
        {
 
        if(tree[i] != -1)
        printf("\n*   NODO->%d  *\n",tree[i]); 

 
        return;
        }
        else{
            visitaPostOrderRic(tree,i*2);
            visitaPostOrderRic(tree,i*2+1);
 
            if(tree[i] != -1)
            printf("\n*   NODO->%d  *\n",tree[i]); 
            }
}
 
int leaf(int tree[], int i)
{
    if(2*i < MAX || 2*i+1 < MAX)
        return 0;
    else
        return 1;
}