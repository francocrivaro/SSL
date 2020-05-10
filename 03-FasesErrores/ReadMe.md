Trabajo Práctico: 03-FasesErrores. Consiste en identifiar las fases de traducción de sobre algun código en particular. 
 Autor: Franco Crivaro.
 Usuario de GitHub: francocrivaro. 
 Última actualización 10/05/2020.


Tarea 1:

Tarea 2: Secuencia de Pasos.
2.2. Comando ejecutado: gcc -E hello2.c > hello2.i
     Resultado o error: El archivo hello2.i no presenta errores en su etapa de preprocesamiento (dónde se incluyen archivos, directivas, y se      reemplazan comentarios).

2.4. La semántica de la primer línea de hello3.c refiere a una función de tipo int, que recibirá una cantidad variable de constantes de tipo char.

2.5. Comando ejecutado: gcc -E hello3.c > hello3.i
     Diferencias entre archivo hello3.c y hello3.i: el archivo .i incluye las definiciones "<built-in>" y "<command-line>".

2.6. Comando ejecutado: gcc -S hello3.c
     Se obtuvo el siguiente error: "expected declaration or statement at end of input".

2.7. Comando ejecutado: gcc -S hello4.c

2.8. El archivo hello4.s está en código assembler. 

2.9. Comando ejecutado: as -o hello4.o hello4.s 
     Resultado o error: archivo hello4.o generado (no es posible su lectura).
    
2.10. Comando ejecutado: gcc -o hello4 hello4.o
     Resultado o error: archivo ejecutable generado. Al correrlo, no se imprime exactamente lo esperado. 

2.11. Comando ejecutado: gcc -o hello5 hello5.c
     Resultado o error: archivo ejecutable generado. 

2.12. Comando ejecutado: ./hello5.exe 
     Resultado obtenido: se imprime correctamente el valor esperado. 

2.13. Comandos ejecutados: los mismos comandos que en los pasos anteriores.
     Resltado o eror: los resultados son los esperados.

2.14. Archivo hello7.c generado.

2.15. El archivo hello7.c compila de manera correcta ya que a la función printf se le pasa el valor específico de la variable i. 


