/* Descrição: Identificar um clique do botão esquerdo do mouse */
 /* 15/03/2015 */

 /*gcc prog12.c console_v1.5.4.c -o prog12.exe -Wall -Werror -Wextra -pedantic*/

 /* Declaração dos arquivos cabeçalhos */
 #include <stdio.h>            /* função printf() */
 #include "console_v1.5.4.h"   /* função Evento() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Variável que armazenará o evento do mouse */
	EVENTO mouseEvent;
	
	/* Silenciar o warning relativo aos parâmetros não usados da função main() */
	argc = argc;
	argv = argv;

	/* Exibir uma mensagem na tela para saber o que o programa está esperando */
    printf( "\nAguardando o pressionamento do botao esquerdo do mouse..." );	
	
	/* Iniciar laço que fará a leitura dos eventos ocorridos */
	do
	{
		/* Armazenar o evento ocorrido */
		mouseEvent = Evento();
		/* Identificar se ocorreu algum evento do mouse */
        if ( mouseEvent.tipo_evento & MOUSE_EVENT ) 
		{
			/* Se for pressionado o botão esquerdo do mouse, imprimir na tela esse fato */
			if ( mouseEvent.mouse.botao_pressionado & BOTAO_ESQUERDO_PRESSIONADO )
			{
			     printf( "\nPressionado botao esquerdo do mouse, nas coordenadas: X = %d e Y = %d\n" , mouseEvent.mouse.posicao.X , mouseEvent.mouse.posicao.Y );				 
				 break;
			}
		}	
	}
	while(1); 
	
	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */

/* Exercícios:
   1) Faça um programa que faça com que seu programa encerre somente com a LIBERAÇÃO do pressionamento do botão esquerdo do mouse 
   2) Faça um programa que identifique o PRESSIONAMENTO do botão direito do mouse;
   3) Faça um programa que imprima na tela o PIXEL em que houve um CLIQUE com o botão direito do mouse;
   4) Faça um programa que identifique se a "roda de rolagem" do mouse foi girada PARA CIMA ou PARA BAIXOimprima na tela o pixel em que foi pressionado o botao e se as luzes das seguintes teclas estão acessas e/ou apagadas: CAPSLOCK e NUMLOCK
      Dica: veja como a função IdentificarEvento() faz a identificação desse tipo de evento
*/
