/* Descrição: Ler uma tecla específica do teclado */
 /* 14/03/2015 */
 
 /*
*/

/*gcc prog11.c console_v1.5.4.c -o prog11.exe -Wall -Werror -Wextra -pedantic*/

/*
				Exemplo: EVENTO e;
				         e = Evento();
						 if (e.tipo_evento & KEY_EVENT)
						 {
						     if (e.teclado.status_teclas_controle & CAPSLOCK_ON) printf("A luz da tecla CAPSLOCK está acessa");
						 }
 */
/*
 #include <stdio.h>            
 #include "console_v1.5.4.h"   
 

int main(int argc, char **argv)
{
	
	EVENTO keyEvent;
	
	
	argc = argc;
	argv = argv;
		
		keyEvent = Evento();
		
        if( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			if(keyEvent.teclado.status_teclas_controle & CAPSLOCK_ON)
			{
				printf("capslock ligada");
			}
			else
			{
				printf("capslock desligada");
			}
		}
	return 0;
}
*/

 /* Fim do programa */


/* Exercícios:
   1) Faça um programa que imprima na tela o código de todas as teclas que o usuário pressionar e somente encerre ao ser pressionada a tecla ESC;
*/

/*
#include <stdio.h>  
#include "console_v1.5.4.h"

int main(int argc, char **argv)
{
	EVENTO keyEvent;

	argc = argc;
	argv = argv;

	do
	{	
		
		keyEvent = Evento();
		
        if ( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			 printf("\n%ld",keyEvent.teclado.codigo_tecla);
			
			 
			 if ( keyEvent.teclado.codigo_tecla == ESC )
			 {
			      printf( "\nPressionada tecla de encerramento ESC\n" );
				  break;
			 }
		}	
	}
	while(1); 
	
	return 0;
}
*/
/*

 #include <stdio.h>            
 #include "console_v1.5.4.h"   
 

int main(int argc, char **argv)
{
	
	EVENTO keyEvent;
	
	
	argc = argc;
	argv = argv;
	

	do
	{	
		
		keyEvent = Evento();
		
        if ( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			if(keyEvent.teclado.status_tecla == LIBERADA)
			{
				printf("\n%ld",keyEvent.teclado.codigo_tecla);
			}

			 
			 if ( keyEvent.teclado.codigo_tecla == ESC )
			 {
			      printf( "\nPressionada tecla de encerramento ESC\n" );
				  break;
			 }
		}	
	}
	while(1); 
	
	
	

	return 0;
	
}
*/

/*
   2) Faça um programa que faça com que seu programa encerre somente com a LIBERAÇÃO do pressionamento da tecla F12 
*/


#include <stdio.h>            
#include "console_v1.5.4.h"   
 

int main(int argc, char **argv)
{
	
	EVENTO keyEvent;
	
	
	argc = argc;
	argv = argv;
	

	do
	{	
		
		keyEvent = Evento();
		
        if ( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			if(keyEvent.teclado.status_tecla == PRESSIONADA)
			{
				printf("\n%ld",keyEvent.teclado.codigo_tecla);
			}
			if ( (keyEvent.teclado.codigo_tecla == ESC) &&  (keyEvent.teclado.status_tecla == LIBERADA))
			{
			    printf( "\nPressionada tecla de encerramento ESC\n" );
				break;
			 }
		}	
	}
	while(1); 
	
	return 0;
}



/*
   3) Faça um programa que imprima na tela se as luzes das seguintes teclas estão acessas e/ou apagadas: CAPSLOCK e NUMLOCK
*/  

/*
 #include <stdio.h>            
 #include "console_v1.5.4.h"   
 

int main(int argc, char **argv)
{
	
	EVENTO keyEvent;
	
	
	argc = argc;
	argv = argv;
		
		keyEvent = Evento();
		
        if( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			if(keyEvent.teclado.status_teclas_controle & CAPSLOCK_ON)
			{
				printf("capslock ligada");
			}
			else
			{
				printf("capslock desligada");
			}
		}
	return 0;
}
*/

/* 
   4) Faça um programa que imprima na tela se as luzes das seguintes teclas estão PRESSIONADAS ou NÃO: SHIFT ESQUERDO, SHIFT DIREITO, CTRL ESQUERDO, CTRL DIREITO, ALT ESQUERDO
*/

/*
   5) ADVANCED: a) Explique quais os códigos que são gerados ao pressionar a tecla ALT GR.
			    b) Faça um programa que identifique o pressionamento da tecla ALT GR (nos teclados que esta tecla existir).
*/






/*ex diversos: imprime mensagem de pressionado uma vez so. sem ficar imprimindo varia vezes enquanto pressionada*/
/*
#include <stdio.h>            
#include "console_v1.5.4.h"   
 

int main(int argc, char **argv)
{
	
	EVENTO keyEvent;
	int status;     /
	
	argc = argc;
	argv = argv;
	

	do
	{	
		
		keyEvent = Evento();
        if ( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			if(keyEvent.teclado.status_tecla == PRESSIONADA)
			{	
				if(status == 1)
				{
					continue;
				}
				printf("\n%ld precionada",keyEvent.teclado.codigo_tecla);
				status = 1; 

			}
			if(keyEvent.teclado.status_tecla == LIBERADA)
			{
				printf("\n%ld liberou",keyEvent.teclado.codigo_tecla);
				status = 0; 
			}

			if ( (keyEvent.teclado.codigo_tecla == ESC) &&  (keyEvent.teclado.status_tecla == LIBERADA))
			{
			    printf( "\nPressionada tecla de encerramento ESC\n" );
				break;
			 }
		}	
	}
	while(1); 
	
	return 0;
}*/