#include <stdio.h>

int main(){
    char string [] = "ciao";
    puts(string);
    *string = 'm';
    puts(string);
    return 0;
}

//questo codice stampa prima la stringa ciao e poi la stringa miao.