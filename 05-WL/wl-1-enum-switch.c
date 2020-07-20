#include <stdio.h>

typedef enum state{
    In, Out
} State;

int main(){
    State state = Out;
    
    int nl, nw, nc;
    nl = nw = nc = 0;

    int c;    
    while((c=getchar()) != EOF){
        ++nc;
        switch(c){
            case ' ' || '|t':
                nw++;
                state = In;
            break;
            case '\n':
            nl++;
            state = Out;
            break;   
            default:
            state = In; 
            break;
        }
    }
    printf("Cantidad de lineas: %d \n", nl);
    printf("Cantidad de palabras: %d \n", nw);
    printf("Cantidad de caracteres: %d \n", nc);
}
