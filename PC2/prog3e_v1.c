#include<stdio.h> /* fscanf(); feof(); printf(); macro "stdin" */

/* Programa para ler uma quantidade indefinida de numeros inteiros
   do fluxo stdin.
   Como executar:
   - Crie um arquivo in contendo os seguintes valores: -1 3 45 -3 4
   - Digite no prompt de comando: prog3_v1 < in
   Observacao: caso haja um ESPACO EM BRANCO, um ENTER, ou um TAB, apos o ultimo valor inteiro
   (no caso do exemplo, depois do valor 4) entao, a leitura feita na linha do fscanf() gerara um 
   resultado diferente do que gostariamos que acontecesse. Isso porque ela vai deixar esse
   ESPACO EM BRANCO/ENTER/TAB para ser lido em um proxima execucao do laco while. Conclusao,
   sera  repetida a impressao do ultimo valor na tela (no caso, sera impresso duas vezes o valor 4). Ou seja, 
   ou se garante que o fluxo stdin nao terá nada apos o ultimo valor, ou entao, deve-se usar umas das outras versoes 
   de leitura disponiveis
*/
int main(int argc, char **argv)
{
    int valor;

    printf("Valores: ");
    while(!feof(stdin)) /* enquanto nao for encontrado o fim do fluxo de entrada */
    {
       fscanf(stdin, "%d", &valor); /* ler do fluxo de entrada, um valor inteiro. Eh o mesmo que se tivesse escrito: scanf("%d", &valor); */
       printf("%d ", valor);
    }

    return 0;
}