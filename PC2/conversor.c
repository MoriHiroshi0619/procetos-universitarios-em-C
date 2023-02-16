#include <stdio.h> 
#include "conversor_header.h" /*inicializar_pilha(), expressao_sem_espaco(), percorrer_expressao(), resultado()*/ 
#include "conio_v3.2.4.h"
int main(int argc, char *argv[])
{
    int opcao;

    argc = argc;
	argv = argv;

    opcao = perguntar();
    printf("opcao digitada = %d", opcao);

    return 0; 
}


/* gcc conversor.c conio_v3.2.4.c conversor.c -o expressao.exe -Wall -Werror -pedantic -Wextra */
