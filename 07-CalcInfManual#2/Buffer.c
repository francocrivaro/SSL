#include "Buffer.h"

void cargarBuffer(char carac)
{
    Buffer[posicionEnBuffer] = carac;
    posicionEnBuffer++;
}

void vaciarBuffer(void)
{
    int i;
    for (i = 0; i < TAMANIO_BUFFER; i++)
    {
        Buffer[i] = '\0';
    }
    posicionEnBuffer = 0;
}

void verBuffer(void)
{
    printf("Buffer tiene: %s\n", Buffer);
}

int valorBuffer()
{
    return atoi(Buffer);
}

char *obtenerBuffer(void)
{
    return Buffer;
}

bool esVariable()
{
    int i;
    for (i = 0; i < strlen(Buffer); i++)
    {
        if (!isalpha(Buffer[i]))
            return false;
    }
    return true;
}