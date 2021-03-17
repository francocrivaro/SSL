## Calculadora Infija Trabajo Práctico

## Objetivo

  El trabajo práctico tiene como ejemplo construir una calculadora infija, iterando sobre diferentes implementaciones. Para su codificación, es necesaria la realización de un análisis léxico y un análisis sintáctico, para luego evaluar las expresiones. 


####  06-Calculadora Infija Manual
En "[06-CalcInfManual"](https://github.com/francocrivaro/SSL/tree/master/06-CalcInfManual), la primera iteración, se implementa un escáner y un parser manual. 
El Scanner toma caracteres ingresados por el usuario a través de la consola, y busca los Tokens, que pasa al Parser. El Parser, debe evaluar el orden en que ingresan esos Tokens, y determinar si la expresión es válida o no.
  
####  07-Calculadora Infija Manual
En ["07-CalcInfManual#2"](https://github.com/francocrivaro/SSL/tree/master/07-CalcInfManual#2),  se agranda el programa pudiendo recibir expresiones con paréntesis. En esta iteración las expresiones matemáticas son evaluables. Además, se pueden almacenar valores en variables, que se guardan en una memoria, para ser utilizadas en expresiones siguientes. 

#### 08-Calculadora Infija Automática - Iteración #1
En ["08-CalcInfAutomatica"](https://github.com/francocrivaro/SSL/tree/master/08-CalcInfAutomatica), se mantiene la implementación del Parser manual desarrollado en la iteración anterior, pero el Scanner es generado automáticamente por Flex (generador de analizador léxico rápido). 

#### 09-Calculadora Infija Automática - Iteración #2
En ["09-CalcInfAutomatica"](https://github.com/francocrivaro/SSL/tree/master/09-CalcInfAutomatica#2), se incluye la herramienta Bison/yacc (yet another compiler compiler) que genera un Parser automático, basándose en el análisis léxico generado por flex en la iteración anterior. 

#### Expresiones válidas para la calculadora
· 2+3		
· (2* 3)+4
· ab=5
·ab+6

Convenciones: La calculadora se ejecuta indefinidamente, hasta que el usuario quiera retirarse con un comando de EXIT en la consola.
Los identificadores tienen como máximo 6 caracteres.
Las constantes son dígitos numéricos.
Se pueden almacenar hasta 10 variables. 

## Gramática utilizada 
### Gramática léxica

	G = { {S,N,I,O}, {x= [0-9], y= [a-zA-z], z= {"=","+","*",")","(","\n"}, {S -> (xN | yI | O), N -> x, I -> y, O -> z}, S}

    [0-9]+		{ CONSTANTE;}
    [a-zA-z][a-zA-z]* 	{ IDENTIFICADOR;}
    
    "="  ASIGNADOR;
    "+"  SUMA;
    "*"  MULTIPLICADOR;
    ")"  PARENTESISCIER;
    "("  PARENTESISAP;
    "\n"  FDE;

### Gramática sintáctica

    <Parser> -> <entrada>
    <entrada> -> <expresion> <FDE> 
    <expresion> -> CONSTANTE
			    | IDENTIFICADOR
			    | <expresion> SUMA <expresion>
			    | <expresion> MULTIPLICADOR <expresion>
			    | PARENTESISAP <expresion> PARENTESISCIER
			    | IDENTIFICADOR ASIGNADOR <expresion>
			    | IDENTIFICADOR SUMA <expresion>
			    | IDENTIFICADOR MULTIPLICADOR <expresion>
