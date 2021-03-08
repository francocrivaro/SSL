#include "Parser.h"

void Parser(void)
{
    Token tokenAnterior = INICIAL;
    Token tokenActual = GetNextToken();
    Token tokenDeOperacion = INICIAL;

    parseoInicial(tokenAnterior, tokenActual);

    while (tokenActual != FDE)
    {
        tokenAnterior = tokenActual;
        tokenActual = GetNextToken();
        printf("resultadoExpresion antes de recibir siguiente token: %i\n", resultadoExpresion);
        switch (tokenActual)
        {
        case IDENTIFICADOR:
        case CONSTANTE:
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case SUMA:
            tokenDeOperacion = SUMA;
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case MULTIPLICADOR:
            tokenDeOperacion = MULTIPLICADOR;
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case PARENTESISAP:
            contadorParentesis++;
            //printf("suma de un parentesis abierto\n");
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case PARENTESISCIER:
            contadorParentesis--;
            //printf("un parentesis restado\n");
            //cargarBuffer(); CUANDO ME ENTRA UN PARENTESIS, EL BUFFER ESTA CARGADO CON 0 ENTONCES ANULA LOS RESULTADOS
            realizarOperacion(tokenDeOperacion);
            break;
        case FDE:
            printf("cantidad de parentesis %i\n", contadorParentesis);
            //realizarOperacion(tokenDeOperacion);
            if (contadorParentesis != 0)
            {
                printf("Error Sintactico: cantidad distinta de parentesis de apertura y cierre\n");
                exit(1);
            }
            //realizarOperacion(tokenDeOperacion);
            break;
        default:
            break;
        }
        printf("resultadoExpresion antes de recibir siguiente token: %i\n", resultadoExpresion);
    }
    printf("La expresion ingresada es valida\n");
    printf("El resultado de la expresion evaluada es: %d", resultadoExpresion);
}

void parseoInicial(Token tokenAnterior, Token tokenActual)
{
    if (tokenAnterior == INICIAL)
    {
        if (esAPERTURAPARENT(tokenActual))
        {
            printf("suma de un parentesis abierto\n");
            contadorParentesis++;
            return;
        }
        else if (EsOperando(tokenActual))
        {
            return;
        }
        else
        {
            printf("El primer token leido no fue un operando o un parentesis.\nLa expresion es invalida");
            exit(0);
        }
    }
}

void parseoSecuencial(Token tokenAnterior, Token tokenActual)
{
    if (EsOperando(tokenAnterior) && EsOperador(tokenActual))
    {
        realizarOperacion(tokenActual);
        return;
    }
    else if (EsOperador(tokenAnterior) && EsOperando(tokenActual))
    {
        realizarOperacion(tokenAnterior);
        return;
    }
    else if (EsOperando(tokenAnterior) && EsOperando(tokenActual))
    {
        return;
    }
    else if (EsOperador(tokenAnterior) && EsOperador(tokenActual))
    {
        printf("Error sintactico: dos operandores consecutivos");
        exit(1);
    }
    else if (esAPERTURAPARENT(tokenAnterior) && EsOperador(tokenActual))
    {
        printf("Error sintactico: parentesis de apertura y operador consecutivos");
        exit(1);
    }
    else if (EsOperador(tokenAnterior) && esCIERREPARENT(tokenActual))
    {
        printf("Error sintactico: operador y parentesis de cierre consecutivos");
        exit(1);
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

bool esAPERTURAPARENT(Token token)
{
    return (token == PARENTESISAP);
}

bool esCIERREPARENT(Token token)
{
    return (token == PARENTESISCIER);
}

void realizarOperacion(Token tipoOperador)
{
    switch (tipoOperador)
    {
    case SUMA:
        resultadoExpresion += valorBuffer();
        //printf("en buffer:%i\n", valorBuffer());
        break;
    case MULTIPLICADOR:
        if (resultadoExpresion == 0)
        {
            printf("ENTRE EN MULTI:%i\n", valorBuffer());
            resultadoExpresion = valorBuffer();
        }
        else
        {
            printf("ENTRE EN MULTIplicacion:%i\n", valorBuffer());
            resultadoExpresion *= valorBuffer();
            printf("resultado de expresion dentro de realizar operacion:%i\n", resultadoExpresion);
        }
        break;
    default:
        //printf("no se aplico ninguna operacion\n");
        break;
    }
    vaciarBuffer();
}