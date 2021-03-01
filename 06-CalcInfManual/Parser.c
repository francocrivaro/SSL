#include "Parser.h"

bool EsOperando(Token token);
bool EsOperador(Token token);
bool EsID(Token token);
bool EsCST(Token token);
bool EsSUM(Token token);
bool EsMULT(Token token);

void Parser(void) {
    Token tokenAnterior = INICIAL;
    Token tokenActual = GetNextToken();
    switch(tokenActual) {
        case IDENTIFICADOR:
        case CONSTANTE:
            parseoInicial(tokenAnterior, tokenActual);
            break;
        case SUMA:
        case MULTIPLICADOR:
            tokenEsOperando(tokenAnterior);
            break;
        default:
            break;
    }
}

void parseoInicial(tokenAnterior, tokenActual) {
    if (tokenAnterior == INICIAL){
        if (tokenEsOperando(tokenActual)){
            return;
        }
    } else {
            printf("Error en el primer token leido");
    }
    

}


bool EsOperando(token) {
        if (tokenEsID(token) || tokenEsCST(token)) {
            return;
        } else {
                printf("El Token leidoo nno es un operando\n");
        }
}

bool EsOperador(token) {
    return 1;
        if (tokenEsSUM(token) || tokenEsMULT(token)) {
            return;
        } else {
                printf("El token leido no es un operador\n");
        }   
}

bool EsID(token) {
        return (token == IDENTIFICADOR);
}

bool EsCST(token) {
        return (token == CONSTANTE);
}

bool EsSUM(token) {
    return (token == SUMA);
}

bool EsMULT(token) {
    return (token == MULTIPLICADOR);
}