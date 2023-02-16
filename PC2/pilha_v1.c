/* Implementacao da operacao PUSH usando variaveis globais */

#include <stdio.h>  /* printf() */
#include <stdlib.h> /* atoi() */

/* Numero de elementos maximo que a pilha vai armazenar */
#define TAMANHO_DA_PILHA 3


/* Definicao dos tipos utilizados pelo programa */
typedef enum {CHEIA, SUCESSO} Msg;
typedef int vetor[TAMANHO_DA_PILHA];

/* Declaracao da funcao que empilha um elemento */
Msg Push(int);

/* Variaveis globais do programa */
vetor Pilha;   /* declaracao da pilha */
int numero_elementos_na_pilha = 0; /* definicao do num elementos que ja estao armazenados na pilha */

int main(int argc, char *argv[])
{
    int numero_elementos = argc - 1;
    int i = 1, elemento;

	argc = argc;
	argv = argv;
	
    while (numero_elementos--)
    {
           elemento = atoi(argv[i++]);
           if(Push(elemento)) printf("Valor %i empilhado com sucesso!\n", elemento);
           else printf("Pilha cheia! Valor %i nao empilhado!\n", elemento);
    }
	
	return 0;
}

Msg Push(int elemento)
{
    if (numero_elementos_na_pilha == TAMANHO_DA_PILHA) return CHEIA;
    else
    {
       Pilha[numero_elementos_na_pilha] = elemento;
       numero_elementos_na_pilha++;
       return SUCESSO;
    }

}