#include "Parser.h"

int main(void)
{
    static int contadorExpresiones;
    static int nroIteracionesMaximas = 5;
    for (contadorParentesis = 0; contadorExpresiones <= nroIteracionesMaximas; contadorExpresiones++)
    {
        printf("Ingresar expresion; \n");
        Parser();
    }
}