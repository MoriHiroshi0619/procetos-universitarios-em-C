#include <stdio.h> /* printf() */

/* Funcao main:
-  recebe dois parametros. Notar que o parametro env não foi colocado pois não é standard C.
- retorna um inteiro qualquer, no caso o valor 2. 
  No gcc são reservados 4 bytes para o tipo inteiro. 
*/
int main(int argc, char **argv)
{
    int i;

    i = 2; 

    printf("Retornando o valor %i para o SO...\n", i);
    printf("FIM DO PROG1A");
	
    return i;
}

