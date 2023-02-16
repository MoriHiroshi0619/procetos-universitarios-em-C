/* Implementacao da operacao PUSH usando passagem de parametro
   e usando uma estrutura para representar uma pilha. */

#include <stdio.h>  /* printf() */
#include <stdlib.h> /* atoi() */

/* Numero de elementos maximo que a pilha vai armazenar */
#define TAMANHO_DA_PILHA 3


/* Definicao dos tipos utilizados pelo programa */
typedef enum {CHEIA, SUCESSO} Msg;
typedef int vetor[TAMANHO_DA_PILHA];

struct tipo_pilha{
                  int topo;
                  vetor vetor_elementos;
                 };
               

/* Declaracao da funcao que empilha um elemento */
Msg Push(struct tipo_pilha *, int);


int main(int argc, char *argv[])
{
    int numero_elementos = argc - 1;
    int i = 1, elemento;
    struct tipo_pilha Pilha;
	
	argc = argc;
	argv = argv;


    Pilha.topo = 0; /* inicializar com a 1¦ posicao que se pode armazenar um elemento */
    while (numero_elementos--)
    {
           elemento = atoi(argv[i++]);
           if(Push(&Pilha, elemento)) printf("Valor %i empilhado com sucesso!\n", elemento);
           else printf("Pilha cheia! Valor %i nao empilhado!\n", elemento);
    }
	return 0;
}

Msg Push(struct tipo_pilha *Pilha, int elemento)
{
    int topo = Pilha->topo;
    if (topo == TAMANHO_DA_PILHA) return CHEIA;
    else
    {
       Pilha->vetor_elementos[topo] = elemento;
       Pilha->topo++;
       return SUCESSO;
    }

}