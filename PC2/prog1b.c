#include <stdio.h> /* printf() */
#include <limits.h> /* constante INT_MAX*/

/* Funcao main:
-  recebe dois parametros. Notar que o parametro env não foi colocado pois não é standard C.
- retornar o maior valor possível. 
 - o inteiro retornado será impresso pelo arquivo  teste1b.bat    
*/
int main(int argc, char **argv)
{
    int i;

    i = INT_MAX; /* deve usar a constante definida em limits por questões de portabilidade */
    printf("Retornando o valor %i para o SO...\n", i);	
    printf("FIM DO PROG1B");
    return i;
}

/* Algumas constantes definidas na biblioteca limits.h:
     #define INT_MAX		2147483647 
     #define INT_MIN		(-INT_MAX-1)
*/