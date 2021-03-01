#include "Scanner.h"

Token GetNextToken(void) {
    int carac;
    carac = getchar();

        if (esConstante(carac))
            return CONSTANTE;
            if (esOperadorSuma(carac))
                return SUMA;
                if (esOperadorMultiplicador(carac))
                    return MULTIPLICADOR;
                    if (esIdentificador(carac))
                        return IDENTIFICADOR;
                            printf("ERROR LEXICO: El caracter ingresado no es un TOKEN\n");
    }



bool esConstante(int carac){
    return (isdigit(carac));
}

bool esOperadorSuma(int carac){
    return (carac == '+');
}

bool esOperadorMultiplicador(int carac){
    return (carac == '*');
}

bool esIdentificador(int carac){
    return (isalpha(carac));
}