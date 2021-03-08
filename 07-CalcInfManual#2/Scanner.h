#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool funciones
#include <ctype.h>   //is digit, isalpha

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

// iteracion #2

#define TAMANIO_BUFFER 6
static char Buffer[TAMANIO_BUFFER] = {0};
static int posicionEnBuffer = 0;

static void cargarBuffer(char);
void verBuffer(void);
void vaciarBuffer(void);
int valorBuffer(void);

Token GetNextToken(void);