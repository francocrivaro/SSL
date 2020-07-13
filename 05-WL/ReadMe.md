## Trabajo Práctico: 05_WL.
#### Consiste en aplicar máquinas de estado (de diferentes maneras) para el procesamiento de texto. Además construir árboles de expresiones e implementaciones de Máquinas de Estado.
1. Árboles de expresión:
1.b Inicialización de contadores nl=nw=nc=0.
![maq-est](https://github.com/francocrivaro/SSL/blob/master/05-WL/arboles-de%20-expresion/arbol1-b.jpg)

	1.c Árbol de expresión para la expresión de control del segundo if: c = = ' ' || c = = '\n' || c == '\t'
	![maq-est-c](https://github.com/francocrivaro/SSL/blob/master/05-WL/arboles-de%20-expresion/arbol1-c.jpg)

2. Una máquina de estado es un áutomata finito determinístico. Una definición formal de un AFD
Se basa en una 5-upla (Q,Σ,T,q0,F)
Donde Q, conjunto finito de estados: Q= {In, Out}
Donde Σ, alfabeto de caracteres: Σ = {ASCii}
Donde T, funciones de transición: {
 - (In, c, In, ++nc),
 -  (In, ' ' | '\t', Out, (++nw; ++nc))
 - (In, '\n', Out, (++nc; ++nw; ++nl;)),
 - (In, ' ' | '\t', Out, (++nw; ++nc))
 - (Out, '\n', Out, (++nc; ++nw; ++nl)),
-   (Out, '\t' | ' ', Out, (++nc; ++nw;),
-   (Out, c, In, (++nc)),
}
Donde q0 es el estado inicial: q0 = In
Donde F es el conjunto finito de estados finales: F=Q.
##### Máquina de estado asociada al conteo de palabras, lineas y caracteres.
![maq-est](https://github.com/francocrivaro/SSL/blob/master/05-WL/arboles-de%20-expresion/maquinaDeEstado.jpg)

3. a.ii) Comparación de bibliografía vs. versión desarrollada en wl-1-enum-switch.c:


