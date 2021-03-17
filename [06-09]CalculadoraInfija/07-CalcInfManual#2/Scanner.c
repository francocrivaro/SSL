#include "Scanner.h"

Token GetNextToken(void)
{
    char carac;
    carac = getchar();

    if (esConstante(carac))
    {
        cargarBuffer(carac);
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
        cargarBuffer(carac);
        return IDENTIFICADOR;
    }
    if (esIgual(carac))
    {
        return ASIGNADOR;
    }
    if (esParentesisApertura(carac))
    {
        return PARENTESISAP;
    }
    if (esParentesisCierre(carac))
    {
        return PARENTESISCIER;
    }
    if (esFDE(carac))
    {
        return FDE;
    }

    printf("ERROR LEXICO: El caracter ingresado no es un TOKEN\n");
    exit(1);
}

bool esConstante(char carac)
{
    return (isdigit(carac));
}

bool esOperadorSuma(char carac)
{
    return (carac == '+');
}

bool esOperadorMultiplicador(char carac)
{
    return (carac == '*');
}

bool esIdentificador(char carac)
{
    return (isalpha(carac));
}

bool esFDE(char carac)
{
    return (carac == "\n");
}

bool esIgual(char carac)
{
    return (carac == '=');
}

bool esParentesisApertura(char carac)
{
    return (carac == '(');
}

bool esParentesisCierre(char carac)
{
    return (carac == ')');
}