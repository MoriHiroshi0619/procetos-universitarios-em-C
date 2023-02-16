#include<stdio.h> /* fscanf(); printf(); macro EOF */

#define QTDE_ELEMENTOS_LIDOS 1

/* Programa para ler uma quantidade indefinida de numeros inteiros
   do fluxo stdin.
   Como executar:
   - Crie um arquivo in contendo os seguintes valores: -1 3 45 -3 4
   - Digite no prompt de comando: prog3_v3 < in
   Observacao 1: esta versao ja não exige que apos o ultimo valor nao possa ter nenhum
   ESPACO EM BRANCO, ENTER ou TAB
   Observacao 2: neste programa eh utilizado o conceito do valor de que a funcao fscanf() e scanf() retornam. 
   Ambas retornam a quantidade de elementos que conseguiram ler. Caso nao tenham conseguido ler nada, entao a condicao
   do laco WHILE fica falsa e, consequentemente, ele eh encerrado.
   Observacao 3:  nao eh possivel colocar somente a expressao fscanf(stdin, "%d", &valor) como condicao do laco WHILE porque:
   - Caso seja lido algum elemento, essa expressao retornará o valor 1.  Logo, a condicao do laco eh avaliada como verdadeira;
   - Caso seja encontrado um EOF, apos o ultimo valor, essa expressao retornara o valor EOF (valor -1) . Logo, a condicao do laco eh avaliada como verdadeira;  
   Observacao 4: note que se a entrada contiver algum caracter que nao represente um numero, o programa encerra no ultimo numero lido.
                          Ex. in1: 45 -1 a 34
                                saida: 45 -1						  
*/
int main(int argc, char **argv)
{
    int valor;

    printf("Valores: ");

/* leio do fluxo stdin enquanto tiver sido possivel ler 1 valor do fluxo.
   Note que o valor de retorno de fscanf() ‚ a quantidade de elementos que foram lidos, ou EOF. */
    while (fscanf(stdin, "%d", &valor) == QTDE_ELEMENTOS_LIDOS)
	{
           printf("%d ", valor);
    }

    return 0;
}