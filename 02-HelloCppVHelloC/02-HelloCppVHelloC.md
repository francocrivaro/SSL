**"Hello, World!" en Lenguaje C:**
    #include <stdio.h>

    main( ) {
        printf("Hello, World!\n");
    } 

---------------

**"Hello, World!" en Lenguaje C++:**
    #include <iostream>

    using namespace std;

    int main() {
        cout << "Hello World!" << endl;
        return 0;
    }
    
----------------

**Tabla comparativa:**

|  | _Lenguaje C_ | _Lenguaje C++_ | _Conclusion_
| :-------- | :-------: | --------: |
| _Léxica_ | Operadores: "printf" y "/n" | Operadors: "cout" y "endl" | Ambos utilizan operadores de igual funcionalidad, pero de distinta léxica.
| _Sintáctica_ | printf - mensaje - \n | cout - mensaje - endl | La secuencia de símbolos para formar la frase es la misma, es decir operador - frase - operador. 
| _Semántica_ | | | Al ser sintácticamente muy parecidos, la semántica entonces también lo es.