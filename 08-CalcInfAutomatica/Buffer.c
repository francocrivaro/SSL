#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Buffer.h"
#include <ctype.h>

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

void cargarBuffer(char *c)
{
    strcpy(Buffer, c);
}

void vaciarBuffer(void)
{
    int i;
    for (i = 0; i < TAMANIO_BUFFER; i++)
    {
        Buffer[i] = '\0';
    }
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