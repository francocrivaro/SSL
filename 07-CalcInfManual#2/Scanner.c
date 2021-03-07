#include "Scanner.h"

Token GetNextToken(void)
{
    char carac;
    carac = getchar();

    //printf("caracter actual %c\n", carac);

    if (esConstante(carac))
    {
        cargarBuffer(carac);
        printf("Buffer cargado %d", carac);
        return CONSTANTE;
    }
    if (esOperadorSuma(carac))
    {
        return SUMA;
    }
    if (esOperadorMultiplicador(carac))
    {
        return MULTIPLICADOR;
    }
    if (esIdentificador(carac))
    {
        //cargarBuffer(carac);
        return IDENTIFICADOR;
    }
    if (esIgual(carac))
    {
        return ASIGNADOR;
    }
    if (esFDE(carac))
    {
        return FDE;
    }

    printf("ERROR LEXICO: El caracter ingresado no es un TOKEN\n");
    exit(1);
}

bool esConstante(char carac)
{
    return (isdigit(carac));
}

bool esOperadorSuma(char carac)
{
    return (carac == '+');
}

bool esOperadorMultiplicador(char carac)
{
    return (carac == '*');
}

bool esIdentificador(char carac)
{
    return (isalpha(carac));
}

bool esFDE(char carac)
{
    return (carac == '\n');
}

bool esIgual(char carac)
{
    return (carac == '=');
}

void cargarBuffer(char carac)
{
    Buffer[posicionEnBuffer] = carac;
    posicionEnBuffer++;
}

void vaciarBuffer(void)
{
    int a;
    for (a = 0; a < tamanioBuffer; a++)
    {
        Buffer[a] = 0;
    }
}

void verBuffer(void)
{
    int i;
    for (i = 0; i < tamanioBuffer; i++)
    {
        printf("Buffer tiene: %c\n", Buffer[i]);
    }
}

int valorBuffer()
{
    return atoi(Buffer);
}

//int main()
//{
//    int n = 0;
//    while (n < 4)
//    {
//        char c = getchar();
//        cargarBuffer(c);
//        n++;
//    }
//    verBuffer();
//    vaciarBuffer();
//    printf("buffer borrado\n");
//    verBuffer();
//}
//
//         //GetNextToken();
//        while (c != EOF)
//        {
//            cargarBuffer(c);
//            printf("Buffer tiene: %d\n", Buffer[5]);
//            i++;
//            vaciarBuffer();
//            printf("Buffer tiene: %d\n", Buffer[i]);
//            i--;
//            exit(0);
//        }
//}
//