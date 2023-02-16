
/*gcc -o pong.exe pong.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/


/*
	LEMBRETES: criar funcao validar movimento para garantir que a raquete nao saia do limite do console;
				
*/

#include <stdio.h>
#include <Windows.h>
#include "conio_v3.2.4.h"
#include "graphics_v1.1.h"
#include "console_v1.5.4.h" 

#define TITULO "PONG___________criador: Hiroshi"
#define DISTANCIA_BORDA 60
#define DISTANCIA_SUPERIOR_INICIAL 20
#define COMPRIMENTO_RAQUETE 160	
#define LARGURA_RAQUETE 20
#define MOVIMENTO_RAQUETE 20

#define SHIFT 16
#define ALT 18
#define CIMA 38
#define BAIXO 40

typedef struct
{
	unsigned int x, y;
}RAQUETE1;

typedef struct
{
	COORD resolution;
	COORD tamanhoInicialJanela;
	COORD tamanhoMaximoJanela;
	COORD fonte;
}MONITOR;

void imprimirRaquete1(RAQUETE1 *, COLORREF);

void inicio(MONITOR *);
void jogar(RAQUETE1 *, COLORREF, COLORREF, MONITOR *);
void moveRaqueteBaixo(RAQUETE1 *, COLORREF, COLORREF);
void moveRaqueteCima(RAQUETE1 *, COLORREF, COLORREF);
int validarMovimentoCima(RAQUETE1 *);
int validarMovimentoBaixo(RAQUETE1 *, MONITOR *);

void mostrarInfo(RAQUETE1 *, MONITOR *);

int main (int argc, char *argv[])
{
	RAQUETE1 *raquete1, r;
	MONITOR *monitor, m;
	
	argc = argc;
	argv = argv;
	
	raquete1 = &r;
	monitor = &m;
	
	clrscr();
	inicio(monitor);
	
	imprimirRaquete1(raquete1, RGB(255, 0, 0));
	jogar(raquete1, RGB(255, 0, 0), RGB(12, 12, 12), monitor);
	return 0;
}

void inicio ( MONITOR *monitor )
{
	monitor->resolution = getResolucaoMonitor();
	monitor->tamanhoInicialJanela = getPosicaoJanela();
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela();
	monitor->fonte = getTamanhoFonteConsole();
	setTituloConsole(TITULO);
	setPosicaoJanela(0,0);
	setDimensaoJanela(monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y);
	setCursorStatus(DESLIGAR);
	setEstadoBarraTarefas(INVISIVEL);
}	

void mostrarInfo(RAQUETE1 *raquete1, MONITOR *monitor)
{
	gotoxy(30,5);
	printf("resolution.x = %d", monitor->resolution.X);
	gotoxy(30,6);
	printf("resolution.y = %d", monitor->resolution.Y);
	gotoxy(30,7);
	printf("tamanhoMaximoJanela.x = %d",monitor->tamanhoMaximoJanela.X);
	gotoxy(30,8);
	printf("tamanhoMaximoJanela.y = %d",monitor->tamanhoMaximoJanela.Y);
	gotoxy(30,9);
	printf("raquete1.x = %d 		",raquete1->x);
	gotoxy(30,10);
	printf("raquete1.y = %d         ",raquete1->y);
	gotoxy(30,12);
	printf("tamanho fonte.x = %d", monitor->fonte.X);
	gotoxy(30,13);
	printf("tamanho fonte.y = %d", monitor->fonte.Y);
}

void imprimirRaquete1(RAQUETE1 *raquete1, COLORREF cor)
{
	int i,j;
	raquete1->x = DISTANCIA_BORDA;
	raquete1->y = DISTANCIA_SUPERIOR_INICIAL;
	for(i=0;i<COMPRIMENTO_RAQUETE;i++)
	{
		for(j=0;j<LARGURA_RAQUETE;j++)
		{
			putpixel(raquete1->x + j, raquete1->y + i, cor);
		}
	}
}

void jogar(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto, MONITOR *monitor)
{
	EVENTO tecla;

	do
	{	
		mostrarInfo(raquete1, monitor);
		tecla = Evento();
		
        if ( tecla.tipo_evento & KEY_EVENT ) 
		{
			if(tecla.teclado.status_tecla == PRESSIONADA)
			{
				if(tecla.teclado.codigo_tecla == ALT && validarMovimentoBaixo(raquete1, monitor))
				{
					moveRaqueteBaixo(raquete1, vermelho, preto);
				}
				if(tecla.teclado.codigo_tecla == SHIFT && validarMovimentoCima(raquete1))
				{
					moveRaqueteCima(raquete1, vermelho, preto);
				}
				if(tecla.teclado.codigo_tecla == ESC)
				{ 
					setEstadoBarraTarefas(VISIVEL);
					break;
				}
			}
		}	
	}
	while(1); 
}

void moveRaqueteBaixo(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto)
{
	
	int i,j;
	for(i=0;i<MOVIMENTO_RAQUETE;i++)
	{
		for(j=0;j<LARGURA_RAQUETE;j++)
		{
			putpixel(raquete1->x + j, raquete1->y + i, preto);
		}
	}
	for(i=0;i<(MOVIMENTO_RAQUETE * 2);i++)
	{
		for(j=0;j<LARGURA_RAQUETE;j++)
		{
			putpixel(raquete1->x + j, (raquete1->y + COMPRIMENTO_RAQUETE) + i, vermelho);
		}
	}
	
	raquete1->y = raquete1->y + MOVIMENTO_RAQUETE;

}

void moveRaqueteCima(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto)
{
	int i,j;
	for(i=0;i<MOVIMENTO_RAQUETE;i++)
	{
		for(j=0;j<LARGURA_RAQUETE;j++)
		{
			putpixel(raquete1->x + j, (raquete1->y + COMPRIMENTO_RAQUETE + MOVIMENTO_RAQUETE) - i, preto);
		}
	}
	for(i=0;i<MOVIMENTO_RAQUETE;i++)
	{
		for(j=0;j<LARGURA_RAQUETE;j++)
		{
			putpixel(raquete1->x + j, raquete1->y - i, vermelho);
		}
	}

	
	raquete1->y = raquete1->y - MOVIMENTO_RAQUETE;
}

int validarMovimentoCima(RAQUETE1 *raquete1)
{
	int a = 1; /*valor verdade*/
	if(raquete1->y < DISTANCIA_SUPERIOR_INICIAL){
		a = 0;
	}
	return a;
}


int validarMovimentoBaixo(RAQUETE1 *raquete1, MONITOR *monitor)
{
	int a = 1;
	unsigned int prox = raquete1->y + MOVIMENTO_RAQUETE;
	if(prox >= (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y - (unsigned int)COMPRIMENTO_RAQUETE))
	{
		a = 0;
	}
	return a;
}

/*gcc -o pong.exe pong.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/