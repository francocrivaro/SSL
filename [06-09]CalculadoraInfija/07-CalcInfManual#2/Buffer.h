#include <stdbool.h> // bool funciones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANIO_BUFFER 6

static char Buffer[TAMANIO_BUFFER] = {0};
static int posicionEnBuffer = 0;

void cargarBuffer(char);
char *obtenerBuffer(void);
void verBuffer(void);
void vaciarBuffer(void);
int valorBuffer(void);

bool esVariable();