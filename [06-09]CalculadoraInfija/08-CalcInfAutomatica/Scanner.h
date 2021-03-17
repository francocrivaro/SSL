#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool funciones
#include <ctype.h>   //is digit, isalpha
#include <string.h>

typedef enum
{
    INICIAL,
    FDE,
    SUMA,
    MULTIPLICADOR,
    ASIGNADOR,
    IDENTIFICADOR,
    CONSTANTE,
    PARENTESISAP,
    PARENTESISCIER
} Token;

void Scanner(void);
void AnalizadorSintactico(void);
void esToken();
bool esConstante(char);
bool esOperadorSuma(char);
bool esOperadorMultiplicador(char);
bool esIdentificador(char);
bool esFDE(char);
bool esIgual(char);

bool esParentesisApertura(char);
bool esParentesisCierre(char);

Token GetNextToken(void);