%{
    #include "Parser.h"
    void mostrarMensajeExito(int);
    static void yyerror(char const *s);
    static int yylex(void);
%}

%union 
{
    char string[30];
    int numero;
}

%token INICIAL
%token ASIGNADOR
%token <numero> CONSTANTE
%token <string> IDENTIFICADOR
%token SUMA MULTIPLICADOR
%token PARENTESISCIER
%token PARENTESISAP
%token <numero> FDE

%right ASIGNADOR
%right SUMA
%right MULTIPLICADOR

%type <numero> Parser
%type <numero> entrada
%type <numero> expresion

%start Parser

%%

Parser: entrada { printf("Fin de parser\n"); return 0;};

entrada: expresion FDE { mostrarMensajeExito($1); }
;

expresion: 
         CONSTANTE { $$=$1; }
        | IDENTIFICADOR { $$=valorDeIdentificador($1); }
        | expresion SUMA expresion { $$ = $1 + $3; }
        | expresion MULTIPLICADOR expresion { $$ = $1 * $3; }
        | PARENTESISAP expresion PARENTESISCIER { $$ = $2; }
        | IDENTIFICADOR ASIGNADOR expresion { cargarMemoria($1, $3); $$ = $3; }
        | IDENTIFICADOR SUMA expresion { $$ = valorDeIdentificador($1) + $3; }
        | IDENTIFICADOR MULTIPLICADOR expresion {$$ = valorDeIdentificador($1) * $3;}
;

%%

void yyerror(char const *s){
    printf("Expresion invalida: %s\n",s);
}

void mostrarMensajeExito(int resultadoExpresion){
    printf("La expresion ingresada es valida\n");
    printf("El resultado de la expresion evaluada es: %d\n", resultadoExpresion);

}

int yylex(void) {
    return GetNextToken();
}

void Parseo(){

    yyparse();
    return;

}