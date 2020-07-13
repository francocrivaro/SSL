#include <stdio.h>

#define In 1 /*en una palabra*/
#define Out 0 /*fuera de una palabra */ 

void contadorRecursivo (int, int);

    int nl, nw, nc, c;
    

int main(){
    nl = nw = nc = 0;
    c = 0;
    int state = Out;
    while ((c = getchar()) != EOF)
    {
        contadorRecursivo(Out, c);
    }
    printf("Cantidad de lineas: %d \n", nl);
    printf("Cantidad de palabras: %d \n", nw);
    printf("Cantidad de caracteres: %d \n", nc);
}


void contadorRecursivo (int state, int c){
    nc++;
    if (c == '\n'){
        nl++;
        } else if(c == ' ' || c == '\t'){
            nw++;
        } else if (state == Out){
            contadorRecursivo (In, c);
        } 
}