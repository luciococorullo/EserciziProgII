/* Scrivere delle function C per calcolare rispettivamente l’epsilon macchina del tipo float, del tipo
double e del tipo long double, visualizzando ad ogni passo i singoli bit. Confrontare i risultati ottenuti
con i valori delle variabili predefinite FLT_EPSILON, DBL_EPSILON e LDBL_EPSILON. */

#include <stdio.h>
float eps(float);
double eps1(double);
long double eps2(long double);

int main(){
    float a = 1;
    double b = 1;
    long double c = 1;
    printf(" epsilon macchina float: %e --- %e.\n",eps(a),__FLT_EPSILON__);
    
    printf(" epsilon macchina double: %e --- %e.\n",eps1(b),__DBL_EPSILON__);
    
    printf(" epsilon macchina long double: %e --- %e.\n",eps2(c),__LDBL_EPSILON__);
    return 0;
}
float eps(float num){
    int eps = 0;
    while(num+1>1){
        num = num/2;
        eps++;
    }
    printf("Posso dividere un float %d volte,",eps-1);
    return 2.0f*num;
}

double eps1(double num){
    int eps = 0;                                             
    while(num+1>1){
        num = num/2;
        eps++;
    }
    printf("Posso dividere un double %d volte,",eps-1);
    return 2.0f*num;
}

long double eps2(long double num){
    int eps = 0;                                             
    while(num+1>1){
        num = num/2;
        eps++;
    }
    printf("Posso dividere un long double %d volte,",eps-1);
    return 2.0f*num;
}