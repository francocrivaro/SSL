#include "Scanner.h"

bool EsOperando(Token);
bool EsOperador(Token);
bool EsID(Token);
bool EsCST(Token);
bool EsSUM(Token);
bool EsMULT(Token);
bool esIGUAL(Token);
bool esAPERTURAPARENT(Token);
bool esCIERREPARENT(Token);

void Parser(void);
void parseoInicial(Token, Token);
void parseoSecuencial(Token, Token);

void realizarOperacion(Token);

static int resultadoExpresion = 0;
static int contadorParentesis = 0;
