/* PROGRAMA para criar duas pilhas usando somente um £nico vetor.
   Sem usar uma variavel para controlar a quantidade de elementos
   armazenados nas pilhas.
   -> Usando SOMENTE duas funções */

#include <stdio.h>

#define NUMERO_DE_PILHAS 2
#define VALOR_INICIAL_PILHA_1 -1
#define VALOR_INICIAL_PILHA_2 2
#define TAMANHO_VETOR VALOR_INICIAL_PILHA_2

typedef struct {
               int topos[NUMERO_DE_PILHAS];
               int vetor[TAMANHO_VETOR];
               } PILHAS;


void Inserir(PILHAS *, int);
void Retirar(PILHAS *, int);

void (*ponteiro[4])(PILHAS *, int) = {Inserir, Inserir, Retirar, Retirar};



int main(int argc, char **argv)
{
   int opcao;
   PILHAS pilhas = { {VALOR_INICIAL_PILHA_1, VALOR_INICIAL_PILHA_2},
                     {0, 0}};  /* acrescentada para não dar warning em decorrência da inclusão da opção -Wextra */   
   /* para silenciar os warnings da inclusão da opção -Wextra */
   argc = argc;
   argv = argv;
   
   for(;;)
   {
       printf("\n\n\n");
       printf("1 - INSERIR NA PILHA 1\n");
       printf("2 - INSERIR NA PILHA 2\n");
       printf("3 - RETIRAR DA PILHA 1\n");
       printf("4 - RETIRAR DA PILHA 2\n");
       printf("Outro valor - SAIR\n");
       printf("Opcao: ");
       scanf("%i", &opcao);

       if (opcao < 1 || opcao > 4) break;
       (*ponteiro[opcao-1])(&pilhas, !(opcao%2));
   }
   return 0;
}

void Inserir(PILHAS *pilha, int qual_pilha)
{
   int incremento_topo = qual_pilha? +1: -1;

   if (pilha->topos[qual_pilha] == pilha->topos[!qual_pilha] + incremento_topo)
       printf("\nPILHA CHEIA\n\n");

   else
   {
      pilha->topos[qual_pilha] = pilha->topos[qual_pilha] - incremento_topo;
      printf("Digite um numero inteiro: ");
      scanf("%i", &pilha->vetor[pilha->topos[qual_pilha]]);
      printf("\nELEMENTO ARMAZENADO COM SUCESSO NA PILHA %i.", qual_pilha + 1);
   }
   
}

void Retirar(PILHAS *pilha, int qual_pilha)
{
   int VALOR_INICIAL = qual_pilha? VALOR_INICIAL_PILHA_2: VALOR_INICIAL_PILHA_1;
   int incremento_topo = qual_pilha? +1: -1;


   if (pilha->topos[qual_pilha] == VALOR_INICIAL)
       printf("\nPILHA VAZIA\n\n");
   else
   {
      printf("\nRetirado o elemento %i da PILHA %i.", pilha->vetor[pilha->topos[qual_pilha]], qual_pilha + 1);
      pilha->topos[qual_pilha] = pilha->topos[qual_pilha] + incremento_topo;
   }
}

