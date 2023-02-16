#ifndef _EXPRESSAOHEADER_ /*verificando se nao ha outro cabecario com o mesmo nome*/
#define _EXPRESSAOHEADER_ /*definindo o cabecario*/


#define TAMANHO_EXPRESSAO 1000 /*tamanho maximo aceito da expressao*/

/**/
typedef struct
{
    int topo; /*topo da pilha*/
    char vetor[TAMANHO_EXPRESSAO];
}PILHA;


typedef enum {FALHA, SUCESSO} MSG; /**/

/*funcao de empilhar elemento na pilha*/
MSG empilhar (PILHA *, char); 
/*procedimento que ira inicialiar topo e prencher com ' ' o vetor*/
void inicializar_pilha (PILHA *); 
/*funcao de desempilhar a pilha*/
MSG desempilhar (PILHA *);
/*procedimento especifico de desempilhar para os simbolos*/
void desempilhar_simbolo (PILHA *, char); 
/*procedimento que ira percorrer cada caracter e chamar demais funcoes e procedimentos para o processamento da expressao*/
void percorrer_expressao(PILHA *, char[], int *, PILHA *, PILHA *);
/*funcao que verifica se a pilha esta vazia ou nao */
int verifica_pilha_vazia (PILHA);
/*funcao que ira verificar se o caracter eh um dos caracteres validos (numeros, simbolos, operadores)*/
int verifica_caracter_valido(char);
/*funcao para verificar se logo apos o abrimento de um simbolo ja vem um fechamento (garante que tera algo)*/
int verificar_prox_simbolo (char, char);
/*funcao para verificar se logo apos o fechamento de um simbolo nao esta vindo um numero*/
int verificar_prox_simbolo_fecha (char);
/*funcao que verifica se logo apos um numero ja nao esta vindo um abrimento de simbolo*/
int verificar_prox_num (char);
/*procedimento que ira copiar a string auxiliar para a string principal sem os espacos*/
void expressao_sem_espaco(char[], char[]);
/*procedimento que ira mostrar o resultado*/
void resultado(int);

#endif