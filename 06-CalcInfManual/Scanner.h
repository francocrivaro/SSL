#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool funciones
#include <ctype.h> //is digit, isalpha

typedef enum {
    SUMA,
    MULTIPLICADOR,
    ASIGNACION,
    IDENTIFICADOR,
    CONSTANTE,
    INICIAL
} Token;

Token tokenEncontrado;

void Scanner(void);
void AnalizadorSintactico(void);
void esToken();
bool esConstante(int);
bool esOperadorSuma(int);
bool esOperadorMultiplicador(int);
bool esIdentificador(int);

Token GetNextToken(void);