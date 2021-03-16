#include "Parser.h"
#include "Memoria.h"

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
        switch (tokenActual)
        {
        case ASIGNADOR:
            tokenDeOperacion = ASIGNADOR;
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case IDENTIFICADOR:
            if (identificadorExisteEnMemoria(obtenerBuffer()))
            {
                parseoSecuencial(tokenAnterior, tokenActual);
            }
            else
            {
                parseoSecuencial(tokenAnterior, tokenActual);
            }
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
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case PARENTESISCIER:
            contadorParentesis--;
            //verBuffer(); //CUANDO ME ENTRA UN PARENTESIS, EL BUFFER ESTA CARGADO CON 0 ENTONCES ANULA LOS RESULTADOS
            parseoSecuencial(tokenAnterior, tokenActual);
            break;
        case FDE:
            if (asignacionEnProceso)
            {
                //asignacionEnProceso = false;
                cargarValorMemoria(resultadoExpresion);
            }
            printf("cantidad de parentesis %i\n", contadorParentesis);
            if (contadorParentesis != 0)
            {
                printf("Error Sintactico: cantidad distinta de parentesis de apertura y cierre\n");
                exit(1);
            }
            vaciarBuffer();
            break;
        default:
            break;
        }
    }
    printf("La expresion ingresada es valida\n");
    printf("El resultado de la expresion evaluada es: %d\n", resultadoExpresion);
    printf("En memoria quedo guardado, en posicion %i, el identificador %s, con valor %i\n", indiceMemoria, memoria[indiceMemoria].id, memoria[indiceMemoria].valor);
    resultadoExpresion = 0;
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
    if (esCIERREPARENT(tokenActual))
    {
        return;
    }
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
    char *idEnBuffer = obtenerBuffer();
    switch (tipoOperador)
    {
    case SUMA:
        if (esVariable(idEnBuffer))
        {
            if (identificadorExisteEnMemoria(idEnBuffer))
            {
                printf("valor del identificador guardado %i\n", valorDeIdentificador(idEnBuffer));
                resultadoExpresion += valorDeIdentificador(idEnBuffer);
                printf("resultadoExpr %i\n", resultadoExpresion);
            }
            else
            {
                printf("Error sintactico: el identificador no fue declarado previamente\n");
                exit(0);
            }
        }
        else
        {
            resultadoExpresion += valorBuffer();
        }
        vaciarBuffer();

        break;
    case MULTIPLICADOR:
        if (resultadoExpresion == 0)
        {
            resultadoExpresion = valorBuffer();
        }
        else
        {
            resultadoExpresion *= valorBuffer();
        }
        vaciarBuffer();
        break;
    case ASIGNADOR:
        printf("entro en case asignador\n");
        if (!asignacionEnProceso && !identificadorExisteEnMemoria(idEnBuffer))
        {
            cargarIdMemoria(obtenerBuffer());
            asignacionEnProceso = true;
            vaciarBuffer();
        }
        else
        {
            resultadoExpresion = valorBuffer();
        }
        break;
    default:
        vaciarBuffer();
        break;
    }
    printf("Resulatado %i, Token = %i\n", resultadoExpresion, tipoOperador);
}