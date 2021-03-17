%{
    #include "Scanner.h"
%}

%option noyywrap
%%

[0-9]+              {
                        yylval.numero=atoi(yytext);
                        return CONSTANTE;
                    }
[a-zA-z][a-zA-z]*   {
                        strcpy(yylval.string, yytext);   
                        return IDENTIFICADOR; 
                    }
"="             return ASIGNADOR;
"+"             return SUMA;
"*"             return MULTIPLICADOR;
")"             return PARENTESISCIER;
"("             return PARENTESISAP;
"\n"            return FDE; 
.               {
                    printf("ERROR LEXICO: El caracter ingresado no es un TOKEN\n");
                    return INICIAL;
                }
%%

int GetNextToken(){
    return yylex();
}