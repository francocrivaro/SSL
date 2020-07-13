## Analisis Comparativo entre tipo de dato String en lenguaje C y en lenguaje Haskell.

  

**Análisis en C:**

  

En el lenguaje C, no existe string como tal para manejar texto. En su lugar, se utilizan arreglos de Chars. Aunque el lenguaje acepta cadenas escritas en formato de String tales como "Hello, world" (caracteres encerrados entre comillas dobles), en lenguaje C estos se interpretan como una concatenación de cada caracter, siendo así ['H','e','l','l','o','','w','o','r','l','d']. Además, cada arreglo o cadena, finaliza con un operador '\0', que indica el fin de la misma.

  

Es preciso notar además, que para poder operar de strings se depende de la inclusión de bibliotecas estándar que importen funciones. El lenguaje C por si sólo no puede interpretar los strings. La más general: <string.h>.

  

Utiliza el alfabeto UTF-8, un formato de codificación de caracteres Unicode que utiliza símbolos de longitud variable.

  

Con respecto a la locacion de memoria, ésta se puede reservar tanto de manera dinámica, es decir en tiempo de ejecución (es variable y puede ser liberada manualmente), o de manera estática, declarando una variable primitiva de cualquier tipo (no es variable ni liberable manualmente).

Además, la memoria se separa en regiones. Cuando una variable se define como estática, esta se almacenará en el segmento de datos y vivirá durante toda la ejecución del programa. Por otro lado, cuando se utiliza una función y ésta es la que trae variables a definir, se definen en el "stack", donde se almacenan temporalmente hasta finalizado el uso de la función y luego se libera ese espacio de memoria. Las variables definidas de manera dinámica se almacenan en el "heap", teniendo la memoria utilizada que ser liberada por el programador.

  

Con respecto a la mutabilidad de una variable, ésta siempre será mutable a menos que el programador así lo indique, declarando la variable como constante, colocando como prefijo "const".

  

Incluyendo la libreria estándar <string.h> puede ser considerado un String como "First Class Citizen", ya que la librería aporta funciones que permiten cumplir con los requisitos necesarios, como las de comparación e igualdad.

Además los strings, interpretados como cadenas de chars, pueden ser enviados a como parámetros a cualquier funcion enviando el puntero inicial de la cadena.

Para poder devolver una cadena de chars, una función debe almacenar el resultado de la misma de manera dinámica, y así retornar el puntero al espacio de memoria donde se haya almacenado. De otra manera, lo puede devolver utilizando al libreria antes mencionada.

  

**Análisis en Haskell:**

  

En Haskell, el String aparece como dato primitivo, es igual de operable que los demás (int, booleano, float). También su sintaxis es escribir el string separado entre comillas dobles. Haskell interpreta a un String como un sinónimo a una cadena de chars, siendo indistinta su evaluación.String.

  

El tipo String ya es parte de la biblioteca propia de Haskell, aunque se pueden aprovechar más importando librerías tales como Data.Strings.

Todas las variables son inmutables, indefectiblemente de si son creadas de manera estática o dinámica. Haskell en lugar de modificar una variable, crea otra nueva aplicando las modificaciones necesarias, descartando (si es posible) la anterior. Ésto conlleva a que se genere mucho residuo en memoria, necesitando de un eficiente "Garbaje Collector".

  

Un tipo de dato String, en Haskell, puede ser pasado como parámetro a una función, un resultado de tal, o ser sujeto de una asignación de definición, por lo tanto, cumple con todos los requisitos para ser "First Class Citizen".

  

Los Strings son pasados y recibidos como cualquier tipo de dato numérico, sin necesidad de punteros al principio o fin de la cadena.

Expresión matemática de las funciones desarrolladas en "String.c":
