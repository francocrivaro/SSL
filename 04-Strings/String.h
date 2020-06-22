// Prototipos de las funciones desarrolladas en "String.c"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Precondiciones y poscondiciones:
La funcion GetLength recibe como parametro una cadena de Chars, que debe finalizar en '\0' para poder ser evaluada, es decir, el programa debe leer
completamente la cadena para determinar su longitud.
Como poscondicion, retorna un valor de tipo int, (numero entero) que se corresponde con la cantidad de caracteres presentes en la cadena recibida
como argumento.
*/ 
size_t GetLength (char str[]);

/* Precondiciones y poscondiciones: 
La funcion IsEmpty recibe una cadena de Chars, que debe contener '\0' para ser evaluada.
Como poscondicion, retorna un valor booleano, correspondiente a si la cadena es vacía, es decir, no contiene ningún caracter distinto a '\0'.
*/
bool IsEmpty (char str[]);

/* Precondiciones y poscondiciones:
La funcion Power recibe como parametro una cadena de chars y un numero; con el fin de devolver una cadena de chars concatenando la cadena recibida
numero de veces que se haya indicado.  
*/

char * Power (char *str, size_t power);

/* Precondiciones y poscondiciones:
La funcion CharInIt toma como parametro una cadena de chars y un int (que convertira a un char) y devuelve un puntero apuntando al caracter hayado o a NULL
si el mismo no se encontraba en la cadena.
*/
char * CharInIt (char * str, int x);    