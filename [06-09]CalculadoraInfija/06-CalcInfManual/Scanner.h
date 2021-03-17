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
bool esConstante(int);
bool esOperadorSuma(int);
bool esOperadorMultiplicador(int);
bool esIdentificador(int);
bool esFDE(int);
bool esIgual(int);

Token GetNextToken(void);