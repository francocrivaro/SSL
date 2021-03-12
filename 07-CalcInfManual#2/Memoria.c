#include "Memoria.h"
#include <string.h>
#include <stdio.h>

void cargarIdMemoria(char *id)
{
    strcpy(memoria[indiceMemoria].id, id);
    printf("cargado en memoria: %s\n", memoria[indiceMemoria].id);
}

void cargarValorMemoria(int valor)
{
    printf("valor %i", valor);
    memoria[indiceMemoria].valor = valor;
    printf("cargado en memoria: %i\n", memoria[indiceMemoria].valor);
}