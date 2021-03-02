#include "Scanner.h"

Token GetNextToken(void)
{
    int carac;
    carac = getchar();

    //printf("caracter actual %c\n", carac);

    if (esConstante(carac))
    {
        return CONSTANTE;
    }
    if (esOperadorSuma(carac))
    {
        return SUMA;
    }
    if (esOperadorMultiplicador(carac))
    {
        return MULTIPLICADOR;
    }
    if (esIdentificador(carac))
    {
        return IDENTIFICADOR;
    }
    if (esIgual(carac))
    {
        return ASIGNADOR;
    }
    if (esFDE(carac))
    {
        return FDE;
    }

    printf("ERROR LEXICO: El caracter ingresado no es un TOKEN\n");
    exit(1);
}

bool esConstante(int carac)
{
    return (isdigit(carac));
}

bool esOperadorSuma(int carac)
{
    return (carac == '+');
}

bool esOperadorMultiplicador(int carac)
{
    return (carac == '*');
}

bool esIdentificador(int carac)
{
    return (isalpha(carac));
}

bool esFDE(int carac)
{
    return (carac == '\n');
}

bool esIgual(int carac)
{
    return (carac == '=');
}