/* PROGRAMA para criar duas pilhas usando somente um £nico vetor.
   Sem usar uma variavel para controlar a quantidade de elementos
   armazenados nas pilhas.
   -> Utilização de 4 funções: Inserir1, Inserir2, Retirar1, Retirar2
   OBSERVAÇÃO: usa ponteiros para funções na sua construção.   */

#include <stdio.h>

#define NUMERO_DE_PILHAS 2
#define VALOR_INICIAL_PILHA_1 -1
#define VALOR_INICIAL_PILHA_2 2
#define TAMANHO_VETOR VALOR_INICIAL_PILHA_2

typedef struct {
               int topos[NUMERO_DE_PILHAS];
               int vetor[TAMANHO_VETOR];
               } PILHAS;


void Inserir1(PILHAS *);
void Inserir2(PILHAS *);
void Retirar1(PILHAS *);
void Retirar2(PILHAS *);

void (*ponteiro[4])(PILHAS *) = {Inserir1, Inserir2, Retirar1, Retirar2}; /* vetor ponteiros para fun‡äes */


int main(int argc, char **argv)
{
   int opcao;
   PILHAS pilhas = {{VALOR_INICIAL_PILHA_1, VALOR_INICIAL_PILHA_2},
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

       (*ponteiro[opcao-1])(&pilhas);       
   }
   return 0;
}

void Inserir1(PILHAS *pilha)
{
   if ( pilha->topos[0] == pilha->topos[1] - 1)
        {
         printf("\nPILHA CHEIA\n\n");
        }
   else
   {
      printf("Digite um numero inteiro: ");
      scanf("%i", &pilha->vetor[++pilha->topos[0]]);
      printf("\nELEMENTO ARMAZENADO COM SUCESSO NA PILHA 1");
   }
   
}

void Inserir2(PILHAS *pilha)
{
   if ( pilha->topos[1] == pilha->topos[0] + 1) 
         printf("\nPILHA CHEIA\n\n");
   else
   {
      printf("Digite um numero inteiro: ");
      scanf("%i", &pilha->vetor[--pilha->topos[1]]);
      printf("\nELEMENTO ARMAZENADO COM SUCESSO NA PILHA 2");
   }
   
}

void Retirar1(PILHAS *pilha)
{
   if ( pilha->topos[0] == VALOR_INICIAL_PILHA_1) 
         printf("\nPILHA VAZIA\n\n");
   else
   {
      printf("\nRetirado o elemento %i da PILHA 1.", pilha->vetor[pilha->topos[0]--]); 
   }
}

void Retirar2(PILHAS *pilha)
{
   if ( pilha->topos[1] == VALOR_INICIAL_PILHA_2) 
         printf("\nPILHA VAZIA\n\n");
   else
   {
      printf("\nRetirado o elemento %i da PILHA 2.", pilha->vetor[pilha->topos[1]++]); 
   }

}
