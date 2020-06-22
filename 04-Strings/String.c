// Desarrollo de funciones GetLength - IsEmpty - Power 

#include "String.h"


size_t GetLength(char *str)
{ 
    size_t i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
} 

bool IsEmpty (char *str)
{
    return (str[0]=='\0');
}

char * Power (char *str, size_t power)
{
    size_t length = GetLength (str);
    size_t poweredLength = length * power;

    char *poweredString = malloc (sizeof (char) * power + 1);
    
    for (size_t i=0;i<poweredLength;i++)
    {
        poweredString [i] = str [i % length];
    }
    poweredString [poweredLength] = '\0';
    return poweredString;
}

char * CharInIt (char *fststr, int x)
{  
    while (*fststr != (char) x) {
        if (!*fststr++) {
            return NULL;
        }
    }
    return (char *)fststr;
}