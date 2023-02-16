
/*gcc -o pong2.exe pong2.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/


/*
	LEMBRETES: 
				trocar funcao kbhit() da conio pelo hit(type_event) da console;
*/

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "conio_v3.2.4.h"
#include "graphics_v1.1.h"
#include "console_v1.5.4.h" 

#define TITULO "PONG___________criador: Hiroshi"
#define DISTANCIA_BORDA 60
#define DISTANCIA_SUPERIOR_INICIAL 20
#define COMPRIMENTO_RAQUETE 160	
#define LARGURA_RAQUETE 20
#define MOVIMENTO_RAQUETE 20
#define RAIO_BOLINHA 10
#define MOVIMENTO_BOLINHA 10
#define VELOCIDADE_BOLINHA_INICIAL 50 /*instrucoes pede 500 como valor inicial*/
#define COLISAO_BORDAS_RAQUETE 60
#define COLISAO_CENTRO_RAQUETE 40


#define RETO_SENTIDO_DIREITO 1
#define RETO_SENTIDO_ESQUERDO 2
#define DIAG_CIMA_DIREITO 3
#define DIAG_CIMA_ESQUERDO 4
#define DIAG_BAIXO_DIREITO 5
#define DIAG_BAIXO_ESQUERDO 6

#define SHIFT 16
#define ALT 18


typedef struct
{
	int x, y;
}RAQUETE1;

typedef struct
{
	int x, y;
}RAQUETE2;

typedef struct
{
	COORD resolution;
	COORD PosicaoInicialJanela;
	COORD tamanhoInicialJanela;
	COORD tamanhoMaximoJanela;
	COORD fonte;
}MONITOR;

typedef struct
{
	int x, y;
	int direcao;
	int velocidade;
}BOLINHA;

void imprimirRaquete1(RAQUETE1 *, COLORREF);
void imprimirRaquete2(RAQUETE2 *, COLORREF);
void imprimirBolinha(BOLINHA *,  COLORREF);
void inicio(RAQUETE1 *, RAQUETE2 *, BOLINHA *, MONITOR *);
void jogar(RAQUETE1 *, RAQUETE2 *, BOLINHA *,  COLORREF, COLORREF, MONITOR *);
void moveRaquete1Baixo(RAQUETE1 *, COLORREF, COLORREF);
void moveRaquete1Cima(RAQUETE1 *, COLORREF, COLORREF);
void moveRaquete2Baixo(RAQUETE2 *, COLORREF, COLORREF);
void moveRaquete2Cima(RAQUETE2 *, COLORREF, COLORREF);
void moveBolinha(BOLINHA *,  MONITOR *, COLORREF, COLORREF, RAQUETE1 *, RAQUETE2 *);
void atualizaCoordenadas(BOLINHA *, int);
void atualizaSentido(BOLINHA *, MONITOR *, RAQUETE1 *, RAQUETE2 *);
int validarMovimentoRaquete1Cima(RAQUETE1 *);
int validarMovimentoRaquete1Baixo(RAQUETE1 *, MONITOR *);
int validarMovimentoRaquete2Cima(RAQUETE2 *);
int validarMovimentoRaquete2Baixo(RAQUETE2 *, MONITOR *);
int colisaoSuperiorRaquete1(BOLINHA *, RAQUETE1 *);
int colisaoSuperiorRaquete2(BOLINHA *, RAQUETE2 *);
int colisaoCentroRaquete1(BOLINHA *, RAQUETE1 *);
int colisaoCentroRaquete2(BOLINHA *, RAQUETE2 *);
int colisaoInferiorRaquete1(BOLINHA *, RAQUETE1 *);
int colisaoInferiorRaquete2(BOLINHA *, RAQUETE2 *);

void mostrarInfo(RAQUETE1 *, RAQUETE2 *, MONITOR *);

int main (int argc, char *argv[])
{
	RAQUETE1 *raquete1, r;
	RAQUETE2 *raquete2, r2;
	BOLINHA *bolinha, b;
	MONITOR *monitor, m;
	
	argc = argc;
	argv = argv;
	
	raquete1 = &r;
	raquete2 = &r2;
	bolinha = &b;
	monitor = &m;
	
	clrscr();
	inicio(raquete1, raquete2, bolinha, monitor);
	imprimirRaquete1(raquete1, RGB(255, 0, 0));
	imprimirRaquete2(raquete2, RGB(255, 0, 0));
	imprimirBolinha(bolinha, RGB(255, 0, 0));
	jogar(raquete1, raquete2, bolinha, RGB(255, 0, 0), RGB(12, 12, 12), monitor);
	return 0;
}

void inicio (RAQUETE1 *raquete1, RAQUETE2 *raquete2, BOLINHA *bolinha, MONITOR *monitor )
{
	monitor->resolution = getResolucaoMonitor();
	monitor->PosicaoInicialJanela = getPosicaoJanela();
	monitor->tamanhoInicialJanela = tamanhoJanelaConsole();
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela();
	monitor->fonte= getTamanhoFonteConsole();
	setTituloConsole(TITULO);
	setPosicaoJanela(0,0);
	setDimensaoJanela(monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y);
	setCursorStatus(DESLIGAR);
	setEstadoBarraTarefas(INVISIVEL);
	
	
	raquete1->x = DISTANCIA_BORDA;
	raquete1->y = DISTANCIA_SUPERIOR_INICIAL;
	
	raquete2->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X) - DISTANCIA_BORDA;
	raquete2->y = DISTANCIA_SUPERIOR_INICIAL;
	
	bolinha->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X) / 2;
	bolinha->y = (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y) / 2;
}

void mostrarInfo(RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor)
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
	printf("raquete1.x = %d			",raquete1->x);
	gotoxy(30,10);
	printf("raquete1.y = %d         ",raquete1->y);
	gotoxy(30,11);
	printf("raquete2.x = %d			",raquete2->x);
	gotoxy(30,12);
	printf("raquete2.y = %d 		",raquete2->y);
	gotoxy(30,13);
	printf("tamanho fonte.x = %d", monitor->fonte.X);
	gotoxy(30,14);
	printf("tamanho fonte.y = %d", monitor->fonte.Y);
}

void imprimirRaquete1(RAQUETE1 *raquete1, COLORREF cor)
{
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, cor);
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, cor);
}

void imprimirRaquete2(RAQUETE2 *raquete2, COLORREF cor)
{
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, cor);
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, cor);
}


void imprimirBolinha(BOLINHA *bolinha, COLORREF cor)
{
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, cor);
	srand(time(NULL));
	bolinha-> direcao = rand()%5 + 1;
	bolinha->velocidade = VELOCIDADE_BOLINHA_INICIAL;
}

void moveBolinha(BOLINHA *bolinha, MONITOR *monitor, COLORREF vermelho, COLORREF preto, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
	do
	{
	
		circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, preto);
		atualizaCoordenadas(bolinha, bolinha->direcao);
		circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, vermelho);
		atualizaSentido(bolinha, monitor, raquete1, raquete2);
		Sleep(bolinha->velocidade);
		if(kbhit())
		{
			break;
		}
	}
	while(1);
}

void atualizaCoordenadas(BOLINHA *bolinha, int sentido)
{
	if(sentido == RETO_SENTIDO_DIREITO)
	{
		bolinha->x = bolinha->x + MOVIMENTO_BOLINHA;
	}
	if(sentido == RETO_SENTIDO_ESQUERDO)
	{
		bolinha->x = bolinha->x - MOVIMENTO_BOLINHA;
	}
	if(sentido == DIAG_CIMA_DIREITO)
	{
		bolinha->x = bolinha->x + MOVIMENTO_BOLINHA;
		bolinha->y = bolinha->y - MOVIMENTO_BOLINHA;
	}
	if(sentido == DIAG_CIMA_ESQUERDO)
	{
		bolinha->x = bolinha->x - MOVIMENTO_BOLINHA;
		bolinha->y = bolinha->y - MOVIMENTO_BOLINHA;
	}
	if(sentido == DIAG_BAIXO_DIREITO)
	{
		bolinha->x = bolinha->x + MOVIMENTO_BOLINHA;
		bolinha->y = bolinha->y + MOVIMENTO_BOLINHA;
	}
	if(sentido == DIAG_BAIXO_ESQUERDO)
	{
		bolinha->x = bolinha->x - MOVIMENTO_BOLINHA;
		bolinha->y = bolinha->y + MOVIMENTO_BOLINHA;
	}
}


void atualizaSentido(BOLINHA *bolinha, MONITOR *monitor, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
	if(bolinha->y < RAIO_BOLINHA) /*colisao com borda superior*/
	{
		if(bolinha->direcao == DIAG_CIMA_DIREITO) /*se a bolinha tiver vindo do lado direito*/
		{
			bolinha->direcao = DIAG_BAIXO_DIREITO; /*inverteu no mesmo sentido so que para baixo*/
		}
		else /*se nao veio pela direita, so pode ter vindo pela esquerda*/
		{
			bolinha->direcao = DIAG_BAIXO_ESQUERDO; /*inverteu no mesmo sentido so que para baixo*/
		}
	}
	
	if((unsigned int)bolinha->y > (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y - (unsigned int)RAIO_BOLINHA))/*colisao com borda inferior*/
	{
		if(bolinha->direcao == DIAG_BAIXO_ESQUERDO) /*se a bolinha tiver vindo do lado direito*/
		{
			bolinha->direcao = DIAG_CIMA_ESQUERDO; /*inverteu no mesmo sentido so que para cima*/
		}
		else /*se nao veio pela direita, so pode ter vindo pela esquerda*/
		{
			bolinha->direcao = DIAG_CIMA_DIREITO; /*inverteu no mesmo sentido so que para cima*/
		}
	}
	
	if(colisaoSuperiorRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = DIAG_CIMA_DIREITO;
	}
	
	if(colisaoSuperiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_BAIXO_ESQUERDO;
	}
	
	if(colisaoCentroRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = RETO_SENTIDO_DIREITO;
	}
	
	if(colisaoCentroRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = RETO_SENTIDO_ESQUERDO;
	}
	
	if(colisaoInferiorRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = DIAG_BAIXO_DIREITO;
	}
	
	if(colisaoInferiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_BAIXO_ESQUERDO;
	}
}

int colisaoSuperiorRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{
	int a = 0; 
	int i;
	
	for(i=0;i<COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE) && (bolinha->y == raquete1->y + i))
		{
			a = 1;
		}
	}
	return a;
}

int colisaoSuperiorRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{
	int a = 0; 
	int i;
	
	for(i=0;i<COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE) && (bolinha->y == raquete2->y + i))
		{
			a = 1;
		}
	}
	return a;
}

int colisaoCentroRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{
	int a;
	int i;
	for(i=0;i<COLISAO_CENTRO_RAQUETE;i++)
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE) && (bolinha->y == (raquete1->y + COLISAO_BORDAS_RAQUETE) + i))
		{
			a = 1;
		}
	}
	return a;
	
}

int colisaoCentroRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{
	int a = 0; 
	int i;
	
	for(i=0;i<COLISAO_CENTRO_RAQUETE;i++)
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE) && (bolinha->y == (raquete2->y + COLISAO_BORDAS_RAQUETE) + i))
		{
			a = 1;
		}
	}
	return a;
	
}
int colisaoInferiorRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{
	int a = 0; 
	int i;
	
	for(i=0;i<COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE) && (bolinha->y == (raquete1->y + COLISAO_BORDAS_RAQUETE + COLISAO_CENTRO_RAQUETE) + i))
		{
			a = 1;
		}
	}
	return a;
	
}

int colisaoInferiorRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{
	int a = 0; 
	int i;
	
	for(i=0;i<COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE) && (bolinha->y == (raquete2->y + COLISAO_BORDAS_RAQUETE + COLISAO_CENTRO_RAQUETE) + i))
		{
			a = 1;
		}
	}
	return a;
}


void jogar(RAQUETE1 *raquete1, RAQUETE2 *raquete2,BOLINHA *bolinha, COLORREF vermelho, COLORREF preto, MONITOR *monitor)
{
	
	EVENTO tecla;
	
	do
	{	
		mostrarInfo(raquete1, raquete2,  monitor);
		moveBolinha(bolinha, monitor, vermelho, preto, raquete1, raquete2);
		tecla = Evento();
			
        if ( tecla.tipo_evento & KEY_EVENT ) 
		{
			if(tecla.teclado.status_tecla == PRESSIONADA)
			{
				/*raquete1 para baixo apenas*/
				if((tecla.teclado.codigo_tecla == ALT && tecla.teclado.status_teclas_controle & LEFT_ALT_PRESSED)&& validarMovimentoRaquete1Baixo(raquete1, monitor))
				{
					moveRaquete1Baixo(raquete1, vermelho, preto);
				}
				/*raquete1 para cima apenas*/
				if((tecla.teclado.codigo_tecla == SHIFT && tecla.teclado.status_teclas_controle & SHIFT_ESQUERDO_PRESSIONADO)&& validarMovimentoRaquete1Cima(raquete1))
				{
					moveRaquete1Cima(raquete1, vermelho, preto);
				} 
				/*raquete2 para cima apenas*/
				if((tecla.teclado.codigo_tecla == SHIFT && tecla.teclado.status_teclas_controle & SHIFT_DIREITO_PRESSIONADO)&& validarMovimentoRaquete2Cima(raquete2))
				{
					moveRaquete2Cima(raquete2, vermelho, preto);
				} 
				/*raquete2 para baixo apenas*/
				if((tecla.teclado.codigo_tecla == ALT && tecla.teclado.status_teclas_controle & RIGHT_ALT_PRESSED) && validarMovimentoRaquete2Baixo(raquete2, monitor))
				{
					moveRaquete2Baixo(raquete2, vermelho, preto);
				} 
				
				/**/
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

void moveRaquete1Baixo(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto)
{
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, preto);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, vermelho);
	
	raquete1->y = raquete1->y + MOVIMENTO_RAQUETE;
	
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, vermelho);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	
}
void moveRaquete1Cima(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto)
{
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	
	raquete1->y = raquete1->y - MOVIMENTO_RAQUETE;
	
	linha(raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, vermelho);
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, vermelho);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, vermelho);
	
}
void moveRaquete2Baixo(RAQUETE2 *raquete2, COLORREF vermelho, COLORREF preto)
{
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, preto);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, vermelho);
	
	raquete2->y = raquete2->y + MOVIMENTO_RAQUETE;
	
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, vermelho);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);

}
void moveRaquete2Cima(RAQUETE2 *raquete2, COLORREF vermelho, COLORREF preto)
{
	
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	
	
	raquete2->y = raquete2->y - MOVIMENTO_RAQUETE;
	
	
	linha(raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, vermelho);
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, vermelho);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, vermelho);

}
int validarMovimentoRaquete1Cima(RAQUETE1 *raquete1)
{
	int a = 1; /*valor verdade*/
	if(raquete1->y < DISTANCIA_SUPERIOR_INICIAL)
	{
		a = 0;
	} 
	return a;
}
int validarMovimentoRaquete1Baixo(RAQUETE1 *raquete1, MONITOR *monitor)
{
	int a = 1;
	unsigned int proxRaquete1 = raquete1->y + MOVIMENTO_RAQUETE;
	if(proxRaquete1 >= (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y - (unsigned int)COMPRIMENTO_RAQUETE))
	{
		a = 0;
	}

	return a;
}
int validarMovimentoRaquete2Cima(RAQUETE2 *raquete2)
{
	int a = 1; /*valor verdade*/
	if(raquete2->y < DISTANCIA_SUPERIOR_INICIAL)
	{
		a = 0;
	} 
	return a;
}
int validarMovimentoRaquete2Baixo(RAQUETE2 *raquete2, MONITOR *monitor)
{
	int a = 1;
	unsigned int proxRaquete2 = raquete2->y + MOVIMENTO_RAQUETE;
	if(proxRaquete2 >= (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y - (unsigned int)COMPRIMENTO_RAQUETE))
	{
		a = 0;
	}

	return a;
}

/*gcc -o pong2.exe pong2.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/