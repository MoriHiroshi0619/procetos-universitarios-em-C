
#include <string.h>  /* strlen() */
#include <stdio.h>   /* printf() */

#define ERRO 0  /* indicar que ocorreu um erro */

int main(int argc, char **argv)
{
  
	if (strlen(argv[1]) > 1)
    {
        printf("   --> ERRO em prog1: O parametro digitado deve ter 1 caracter somente! Ex.: prog1 A");
        return(ERRO);
    }
    else
    {
        printf("   --> Dentro de prog1. Valor parametro passado via linha de comando: %i", *argv[1]);
        return(*argv[1]);
    }
}
