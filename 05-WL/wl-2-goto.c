#include <stdio.h>

int main(){

    int c;

Out:
    switch (c = getchar ()){
        case ' ':
        case '\n':
        case '\t':
        case '.':
        case ',':
        case ';': 
            putchar('\n');
            goto Out;
        case EOF: goto EndMain;
        default:
        {
            goto In;
        }
    }

In: 
{
    putchar(c);
    goto Out;
}

EndMain:
{
    return 0;
}





}
