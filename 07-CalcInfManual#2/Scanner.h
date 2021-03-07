#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool funciones
#include <ctype.h>   //is digit, isalpha

typedef enum
{
    INICIAL,       //0
    FDE,           //fin de expresion
    SUMA,          //2
    MULTIPLICADOR, //3
    ASIGNADOR,     //4
    IDENTIFICADOR, //5
    CONSTANTE      //6
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

// iteracion #2

#define tamanioBuffer 20
char Buffer[tamanioBuffer] = {0};
int posicionEnBuffer = 0;

void cargarBuffer(char);
void verBuffer(void);
void vaciarBuffer(void);
int valorBuffer(void);

Token GetNextToken(void);