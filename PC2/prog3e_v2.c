#include<stdio.h> /* fscanf(); printf(); macro EOF */

/* Programa para ler uma quantidade indefinida de numeros inteiros
   do fluxo stdin.
   Como executar:
   - Crie um arquivo in contendo os seguintes valores: -1 3 45 -3 4
   - Digite no prompt de comando: prog3_v2 < in
   Observacao 1: esta versao ja não exige que apos o ultimo valor nao possa ter nenhum
   ESPACO EM BRANCO, ENTER ou TAB
   Observacao 2: utilizacao da macro EOF, que nada mais eh do que a existência de uma linha
   #define EOF (-1) no arquivo "stdio.h". Esse eh normalmente o indicador de final de arquivo, ou fluxo   
   Observacao 3: note que se a entrada contiver algum caracter que nao represente um numero, o programa entra em loop.
                               Ex. in1: 45 -1 a 34
                                saida: 45 -1 -1 -1 -1 ...	
						            
*/
int main(int argc, char **argv)
{
    int valor;

    printf("Valores: ");

/* leio do fluxo stdin enquanto nao for lido o codigo de EOF (End Of File) */
    while (fscanf(stdin, "%d", &valor) != EOF)
           printf("%d ", valor);


    return 0;
}