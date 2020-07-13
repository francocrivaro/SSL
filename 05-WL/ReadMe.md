## Trabajo Práctico: 05_WL.
#### Consiste en aplicar máquinas de estado (de diferentes maneras) para el procesamiento de texto. Además construir árboles de expresiones e implementaciones de Máquinas de Estado.

2b. Una máquina de estado es un áutomata finito determinístico. Una definición formal de un AFD

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


