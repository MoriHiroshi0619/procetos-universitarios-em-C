/* Passando valores via entrada padrão.
   Desse modo nÆo ‚ necess rio abrir um arquivo dentro do nosso programa,
   pois ele ‚ passado diretamente pelo SO

   Como deve ser executado este programa:
   - Criar um arquivo denominado "in2";
   - Salvar dentro desse arquivo os valores: 1 5 -1 3 7 
   - Digitar no prompt: "prog2 < in2"
*/

#include <stdio.h>   /* scanf(); printf() */


int main()
{
    int valor, i;

    for (i=0; i<5; i++)
    {
         scanf("%d", &valor);   /* Ler da entrada padrÆo */
         printf("%d ", valor);  /* Imprimir na sa¡da padrÆo */
    }
    return 0;
}
