#include <stdio.h>

void contadorRecursivo (int);

int main(){
    int nl, nw, nc, c;
    nl = nw= nc= 0;
    c = 0;

    while ((c = getchar()) != EOF)
    {
        contadorRecursivo(c);
    }
}


/*void contadorRecursivo (c){
    c = 0;
    nc++;
    if (c == '\n'){
        nl++;
        } else if(c == ' ' || c == '\t'){
            nw++;
            n++;
        }
}*/