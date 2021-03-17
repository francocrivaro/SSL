%{
#include "Buffer.h"
#include "Scanner.h"
//#undef YY_DECL
//#define YY_DECL Token GetNextToken(void)
//YY_DECL;
%}
%option noyywrap

%%

[0-9]+              {
                        cargarBuffer(yytext);
                        return CONSTANTE;
                    }

[a-zA-z][a-zA-z]*   {
                        cargarBuffer(yytext);
                        return IDENTIFICADOR; 
                    }


"=" return ASIGNADOR;

"+" return SUMA;

"*" return MULTIPLICADOR;

")" return PARENTESISCIER;

"(" return PARENTESISAP;

'\n' return FDE; 

. {
    printf("ERROR LEXICO: El caracter ingresado no es un TOKEN\n");
    return INICIAL;
}
%%

Token GetNextToken() 
{
    Token t = INITIAL;
    t = yylex();
    return t;
}