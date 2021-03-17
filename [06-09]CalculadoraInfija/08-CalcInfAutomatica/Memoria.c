#include "Memoria.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void cargarIdMemoria(char *id)
{
    strcpy(memoria[indiceMemoria].id, id);
    printf("cargado en memoria el id: %s\n", memoria[indiceMemoria].id);
}

void cargarValorMemoria(int valor)
{
    memoria[indiceMemoria].valor = valor;
    printf("cargado en memoria el valor: %i\n", memoria[indiceMemoria].valor);
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
            printf("El id ya estaba en memoria\n");
            return true;
        }
    }
    return false;
}
