#include "Scanner.h"

bool EsOperando(Token);
bool EsOperador(Token);
bool EsID(Token);
bool EsCST(Token);
bool EsSUM(Token);
bool EsMULT(Token);
bool esIGUAL(Token);

void Parser(void);
void parseoInicial(Token, Token);
void parseoContinuo(Token, Token);