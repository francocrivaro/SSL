#include <stdbool.h>
#define TAMANIO_MEMORIA 10

struct MemoriaAsignaciones
{
    char id[10];
    int valor;
} memoria[TAMANIO_MEMORIA];

void cargarIdMemoria(char *);
static int indiceMemoria;
void cargarValorMemoria(int);
bool identificadorExisteEnMemoria(char *);
int valorDeIdentificador(char *);

void cargarMemoria(char *, int);