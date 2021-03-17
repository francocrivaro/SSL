#include "Parser.h"

void Parser(void)
{
    Token tokenAnterior = INICIAL;
    Token tokenActual = GetNextToken();

    parseoInicial(tokenAnterior, tokenActual);
    //printf("parseo inicial exitoso\n");

    while (tokenActual != FDE)
    {
        tokenAnterior = tokenActual;
        tokenActual = GetNextToken();
        //printf("tokenAnterior: %i \n", tokenAnterior);
        //printf("tokenActual: %i \n", tokenActual);
        //printf("----------ciclo--------\n");
        switch (tokenActual)
        {
        case IDENTIFICADOR:
        case CONSTANTE:
            parseoContinuo(tokenAnterior, tokenActual);
            break;
        case SUMA:
        case MULTIPLICADOR:
            parseoContinuo(tokenAnterior, tokenActual);
            break;
        default:
            break;
        }
    }
    printf("La expresion ingresada es valida\n");
}

void parseoInicial(Token tokenAnterior, Token tokenActual)
{
    if (tokenAnterior == INICIAL)
    {
        if (EsOperando(tokenActual))
        {
            return;
        }
        else
        {
            printf("El primer token leido no fue un operando\nLa expresion es invalida");
            exit(0);
        }
    }
}

void parseoContinuo(Token tokenAnterior, Token tokenActual)
{
    if (EsOperando(tokenAnterior) && EsOperador(tokenActual))
    {
        return;
    }
    else if (EsOperador(tokenAnterior) && EsOperando(tokenActual))
    {
        return;
    }
    else if (EsOperando(tokenAnterior) && EsOperando(tokenActual))
    {
        return;
    }
    else if (EsOperador(tokenAnterior) && EsOperador(tokenActual))
    {
        printf("Error lexico: dos operandores consecutivos");
        exit(0);
    }
}

bool EsOperando(Token token)
{
    return (EsID(token) || EsCST(token));
}

bool EsOperador(Token token)
{
    return (EsSUM(token) || EsMULT(token) || esIGUAL(token));
}

bool EsID(Token token)
{
    return (token == IDENTIFICADOR);
}

bool EsCST(Token token)
{
    return (token == CONSTANTE);
}

bool EsSUM(Token token)
{
    return (token == SUMA);
}

bool EsMULT(Token token)
{
    return (token == MULTIPLICADOR);
}

bool esIGUAL(Token token)
{
    return (token == ASIGNADOR);
}