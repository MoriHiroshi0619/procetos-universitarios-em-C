/*gcc prog12Exe.c console_v1.5.4.c -o prog12Exe.exe -Wall -Werror -Wextra -pedantic*/
/* Exercícios:
   1) Faça um programa que faça com que seu programa encerre somente com a LIBERAÇÃO do pressionamento do botão esquerdo do mouse 
*/
/*
 #include <stdio.h>          
 #include "console_v1.5.4.h"  
 
int main( int argc , char **argv )
{
	
	EVENTO mouseEvent;
	
	argc = argc;
	argv = argv;
    printf( "\nAguardando o pressionamento do botao esquerdo do mouse..." );	
	
	do
	{

		mouseEvent = Evento();
        if ( mouseEvent.tipo_evento & MOUSE_EVENT ) 
		{
			
			if ( mouseEvent.mouse.botao_clicou & BOTAO_ESQUERDO_LIBERADO )
			{
			     printf( "\nPressionado botao esquerdo do mouse, nas coordenadas: X = %d e Y = %d\n" , mouseEvent.mouse.posicao.X , mouseEvent.mouse.posicao.Y );				 
				 break;
			}
		}	
	}
	while(1); 
	
	return 0;
	
}
*/


/*
   2) Faça um programa que identifique o PRESSIONAMENTO do botão direito do mouse;
*/

/*
 #include <stdio.h>          
 #include "console_v1.5.4.h"  
 
int main( int argc , char **argv )
{
	
	EVENTO mouseEvent;
	
	argc = argc;
	argv = argv;
    printf( "\nAguardando o pressionamento do botao esquerdo do mouse..." );	
	
	do
	{

		mouseEvent = Evento();
        if ( mouseEvent.tipo_evento & MOUSE_EVENT ) 
		{
			
			if ( mouseEvent.mouse.botao_pressionado & BOTAO_DIREITO_PRESSIONADO )
			{
			     printf( "\nPressionado botao esquerdo do mouse, nas coordenadas: X = %d e Y = %d\n" , mouseEvent.mouse.posicao.X , mouseEvent.mouse.posicao.Y );				 
				 break;
			}
		}	
	}
	while(1); 
	
	return 0;
	
}
*/

/*
   3) Faça um programa que imprima na tela o PIXEL em que houve um CLIQUE com o botão direito do mouse;
*/

/*gcc prog12Exe.c console_v1.5.4.c conio_v3.2.4.c -o prog12Exe.exe -Wall -Werror -Wextra -pedantic*/

/*primeiro utilizando bib conio pra imprimir um caracter no lugar*/
/*
 #include <stdio.h>          
 #include "console_v1.5.4.h"  
 #include "conio_v3.2.4.h"   
 
int main( int argc , char **argv )
{
	
	EVENTO mouseEvent;
	
	argc = argc;
	argv = argv;
    printf( "\nAguardando o pressionamento do botao esquerdo do mouse..." );	
	
	do
	{

		mouseEvent = Evento();
        if ( mouseEvent.tipo_evento & MOUSE_EVENT ) 
		{
			
			if ( mouseEvent.mouse.botao_pressionado & BOTAO_DIREITO_PRESSIONADO )
			{
			    printf( "\nPressionado botao esquerdo do mouse, nas coordenadas: X = %d e Y = %d\n" , mouseEvent.mouse.posicao.X , mouseEvent.mouse.posicao.Y );
				gotoxy(mouseEvent.mouse.posicao.X, mouseEvent.mouse.posicao.Y);
				printf("0");
				break;
			}
		}	
	}
	while(1); 
	
	return 0;
	
}
*/

#include <stdio.h>          
#include "console_v1.5.4.h" 
#include "graphics_v1.1.h"
 
int main( int argc , char **argv )
{
	
	EVENTO mouseEvent;
	int i;
	argc = argc;
	argv = argv;
    printf( "\nAguardando o pressionamento do botao esquerdo do mouse..." );	
	
	do
	{

		mouseEvent = Evento();
        if ( mouseEvent.tipo_evento & MOUSE_EVENT ) 
		{
			if ( mouseEvent.mouse.botao_pressionado & BOTAO_DIREITO_PRESSIONADO )
			{
			    printf("\nPressionado botao esquerdo do mouse, nas coordenadas: X = %d e Y = %d\n",mouseEvent.mouse.posicao.X , mouseEvent.mouse.posicao.Y);
				for(i=0;i<30;i++)
				{
					putpixel((mouseEvent.mouse.posicao.X * 1000) + i, mouseEvent.mouse.posicao.Y * 1000, RGB(255, 0, 0));
				}
				break;
			}
		}	
	}
	while(1); 
	return 0;
	
}

/*gcc -o prog12Exe.exe prog12Exe.c graphics_v1.1.c console_v1.5.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/


/*
   4) Faça um programa que identifique se a "roda de rolagem" do mouse foi girada PARA CIMA ou PARA BAIXOimprima na tela o pixel em que foi pressionado o botao e se as luzes das seguintes teclas estão acessas e/ou apagadas: CAPSLOCK e NUMLOCK
      Dica: veja como a função IdentificarEvento() faz a identificação desse tipo de evento
*/