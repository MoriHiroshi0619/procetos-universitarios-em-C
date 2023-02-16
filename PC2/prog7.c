/* Código criado para ilustrar como usar a biblioteca graphics */
/* Data da codificação: 02/05/2022                             */
/* Linha que deve ser digitada para executar este código: gcc -o prog7.exe prog7.c graphics_v1.1.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror */
/* Observação: deve usar o "Console herdado" para não ter problemas de desenho decorrentes da alocação do buffer no novo Console */

#include <stdlib.h> 		/* Funções srand(), rand(). Constante NULL */
#include <time.h>

#include "conio_v3.2.4.h"   /* getch() */
#include "graphics_v1.1.h"  /* linha() */



/* Início do programa */
int main(int argc, char *argv[])
{
	int coordenadaX_CentroCirculo;
	int coordenadaY_CentroCirculo;
	int raioCirculo = 50;
	int posXCursor;
	int posYCursor;
	int x;
	int y;
	
	/* Artifício para silenciar warning */
	argc = argc;
	argv = argv;
	
    clrscr();
	

	
	coordenadaX_CentroCirculo = 500;
	coordenadaY_CentroCirculo = 200;
	
	/* Gerar uma posição aleatória na tela para o cursor */
	srand(time(NULL));
	x = rand() % 100;
	y = rand() % 30;
	
	gotoxy(1,2);
	printf("Pressione qualquer tecla para encerrar...");	
	do
	{
		circulo(coordenadaX_CentroCirculo, coordenadaY_CentroCirculo, raioCirculo, RGB(255, 0, 0));
		gotoxy( x , y ); /* Posicionar o cursor para o círculo "seguir" */
		
		Sleep(100);  /* pausar o programa 1/10 segundo */
		
		/* Assumindo uma fonte de tamanho 8x16 (8 pixels de largura por 16 pixels de altura) */
		posXCursor = wherex() * 8;
		posYCursor = wherey() * 16;

		/* Apagando o círculo desenhado na tela */
		circulo(coordenadaX_CentroCirculo, coordenadaY_CentroCirculo, raioCirculo, RGB(12, 12, 12));		
		
		/* Ajustando a nova posição do círculo */
		if (posXCursor > coordenadaX_CentroCirculo) 
			coordenadaX_CentroCirculo += 10;
        else 
			if (posXCursor < coordenadaX_CentroCirculo) 
				coordenadaX_CentroCirculo -= 10;					
		if (posYCursor > coordenadaY_CentroCirculo) 
			coordenadaY_CentroCirculo += 10;
		else
			if (posYCursor < coordenadaY_CentroCirculo) 
				coordenadaY_CentroCirculo -= 10;			
						
		if ( kbhit() )
		   break;
	}
	while ( 1 ); /* loop infinito */
	
		
	return 0; /* programa encerrou com sucesso */
	
} /* Fim do programa */


/* Exercício */
/* 1) Modifique o programa para que o usuário possa mover o cursor na tela enquanto o círculo continua a ir na direção do cursor */