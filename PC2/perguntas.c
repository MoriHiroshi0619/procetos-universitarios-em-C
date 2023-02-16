/*						PERGUNTAS E TESTES ALEATORIOA					*/


/*ex utilizando ponteiros para passar como parametro
objetivo: passagem por referencia.
problemas: nao consigo passar um vetor de strcut, so um strcut/
*/
#include <stdio.h>
#include <stdlib.h>
#include "conio_v3.2.4.h"
#include <time.h>
#include <Windows.h>

#define linha1 30
#define coluna1 5
#define linha2 80
#define coluna2 20

/*gcc conio_v3.2.4.c perguntas.c -o perguntas.exe -Wall -Werror -pedantic -Wextra*/

typedef struct{
    int x, y;
}OBSTACULOS;

void criarObstaculo(OBSTACULOS *);
void janela();
int main(int argc, char *argv[])
{
	OBSTACULOS *cord;
	OBSTACULOS cordenadas;
	
	cord = &cordenadas;
	
	argc = argc;
	argv = argv;
	
	clrscr();
	
	janela();
	criarObstaculo(cord);
		
	textcolor(RED);
	gotoxy(cordenadas.x, cordenadas.y-1);
	printf("ultima impresao de obstaculos");
	return 0;
}

void janela()
{
	textbackground(WHITE);
	window(linha1, coluna1, linha2, coluna2);
}


void criarObstaculo(OBSTACULOS *cordenadas)
{
	int i;
	textcolor(BLACK);
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		cordenadas->x = rand()%49 + 1;
		cordenadas->y = rand()%14 + 1;
		gotoxy(cordenadas->x, cordenadas->y);
		printf("*");
		gotoxy(cordenadas->x, cordenadas->y+1);
		printf("*");
		gotoxy(cordenadas->x, cordenadas->y+2);
		printf("*");
	}
}




/*
porque essa 

*/

int validarObstaculos(OBSTACULOS cordenadas[], int j)
{
	int i;
	for(i=0;i<j;i++)
	{
		if(cordenadas[j].x == cordenadas[i].x && cordenadas[j].y == cordenadas[i].y)
		{
			return 1;
		}else
		{
			return 0;
		}
		
	}	
}
