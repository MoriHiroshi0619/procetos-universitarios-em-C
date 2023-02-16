/* Passando valores via entrada padrão.
   Desse modo nÆo ‚ necess rio abrir um arquivo dentro do nosso programa,
   pois ele ‚ passado diretamente pelo SO

   Como deve ser executado este programa:
   - Criar um arquivo denominado "in1";
   - Salvar dentro desse arquivo somente o caracter 'a';
   - Digitar no prompt: "prog1 < in1"
*/

#include <stdio.h>   /* scanf(); printf() */



int main()
{
    char valor;
   
    scanf("%c", &valor);  /* Ler da entrada padrÆo */
    printf("%c", valor);  /* Imprimir na sa¡da padrÆo */

    return 0;
}
