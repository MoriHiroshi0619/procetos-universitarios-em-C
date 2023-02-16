/* Implementacao da operacao PUSH usando passagem de parametro
   e armazenando a qtde de elementos existentes na pilha na pr¢pria pilha,
   na ultima posicao do vetor */

#include <stdio.h>  /* printf() */
#include <stdlib.h> /* atoi() */

/* Numero de elementos maximo que a pilha vai armazenar */
#define TAMANHO_DO_VETOR 3
#define TAMANHO_DA_PILHA TAMANHO_DO_VETOR - 1


/* Definicao dos tipos utilizados pelo programa */
typedef enum {CHEIA, SUCESSO} Msg;
typedef int vetor[TAMANHO_DA_PILHA];

/* Declaracao da funcao que empilha um elemento */
Msg Push(vetor, int);


int main(int argc, char *argv[])
{
    int numero_elementos = argc - 1;
    int i = 1, elemento;
    vetor Pilha;

	argc = argc;
	argv = argv;

    Pilha[TAMANHO_DA_PILHA] = 0; /* inicializar dizendo que tem 0 elementos na pilha */
    while (numero_elementos--)
    {
           elemento = atoi(argv[i++]);
           if(Push(Pilha, elemento)) printf("Valor %i empilhado com sucesso!\n", elemento);
           else printf("Pilha cheia! Valor %i nao empilhado!\n", elemento);
    }
	return 0;
}

Msg Push(vetor Pilha, int elemento)
{
    int topo;
    if (Pilha[TAMANHO_DA_PILHA] == TAMANHO_DA_PILHA) return CHEIA;
    else
    {
       Pilha[TAMANHO_DA_PILHA]++;
       topo = Pilha[TAMANHO_DA_PILHA] - 1;
       Pilha[topo] = elemento;
       return SUCESSO;
    }

}