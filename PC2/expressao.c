/* Programa: expressao bem formada.

Descricao: programa recebe como entrada no terminal uma expressao matematica e retorna se ela esta bem formada ou nao.

Programador: Anderson Hiroshi Mori Correia

RGM: 45380

Data da ultima modificacao: 06/09/2022 */

#include <stdio.h> /*printf(), fgets()*/
#include "expressaoHeader.h" /*inicializar_pilha(), expressao_sem_espaco(), percorrer_expressao(), resultado()*/ 
#include "conio_v3.2.4.h" /*clrscr()*/
int main(int argc, char *argv[])
{
    PILHA pilha_simbolos; /*pilha para empilhar os simbolos abre e fecha parentedes, chave etc */
    PILHA pilha_operandos; /*pilha para empilhar os operandos */
    PILHA pilha_operadores; /*pilha para empilhar os operados */
    int bem_formado = 1; /*variavel lofica que definira se a expressao esta ou nao bem definida*/
    char expressao[TAMANHO_EXPRESSAO]; /*string aonde sera salvo a expressao digitada sem os ' '*/
    char expressao_aux[TAMANHO_EXPRESSAO]; /*strinf auxiliar aonde sera salvo a expressao digitada pelo usuario*/
    
    /* Artificio para silenciar warning */
    argc = argc;
	argv = argv;


    clrscr(); /*limpando a tela*/
    inicializar_pilha(&pilha_simbolos); /*inicializando o topo e preenchendo tudo com ' '*/
    inicializar_pilha(&pilha_operadores); /*inicializando o topo e preenchendo tudo com ' '*/
    inicializar_pilha(&pilha_operandos); /*inicializando o topo e preenchendo tudo com ' '*/
    /*lendo a expressao do usuario */
    printf("digite uma expressao matematica: "); 
    fgets(expressao_aux, TAMANHO_EXPRESSAO, stdin);

    expressao_sem_espaco(expressao_aux, expressao); /*procedimento para passar a string auxiliar para a string principal sem os ' '*/
    /*procedimento aonde sera feito todo o processamento da expressao*/
    percorrer_expressao(&pilha_simbolos, expressao, &bem_formado, &pilha_operadores, &pilha_operandos);
    resultado(bem_formado); /*mostrando na tela o resultado para o usuario*/

    return 0; /* programa encerrou com sucesso */
}


/*gcc expressaoHeader.c conio_v3.2.4.c expressao.c -o expressao.exe -Wall -Werror -pedantic -Wextra*/



