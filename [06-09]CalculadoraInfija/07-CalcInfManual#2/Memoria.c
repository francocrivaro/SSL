#include "Memoria.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void cargarIdMemoria(char *id)
{
    strcpy(memoria[indiceMemoria].id, id);
}

void cargarValorMemoria(int valor)
{
    memoria[indiceMemoria].valor = valor;
}

int valorDeIdentificador(char *identificador)
{
    int i;
    for (i = 0; i <= indiceMemoria; i++)
    {
        if ((strcmp(memoria[i].id, identificador) == 0))
        {
            return memoria[i].valor;
        }
    }
}

bool identificadorExisteEnMemoria(char *identificador)
{
    int i;
    for (i = 0; i <= indiceMemoria; i++)
    {
        if (strcmp(memoria[i].id, identificador) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
