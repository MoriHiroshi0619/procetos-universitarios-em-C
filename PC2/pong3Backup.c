
/*gcc -o pong3.exe pong3.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h> /*strlen()*/
#include "conio_v3.2.4.h"
#include "graphics_v1.1.h"
#include "console_v1.5.4.h" 

#define TITULO "PONG_3___________criador: Hiroshi"
#define DISTANCIA_BORDA 60
#define DISTANCIA_SUPERIOR_INICIAL 20
#define COMPRIMENTO_RAQUETE 160	
#define LARGURA_RAQUETE 20
#define MOVIMENTO_RAQUETE 20
#define RAIO_BOLINHA 10
#define MOVIMENTO_BOLINHA 10
#define VELOCIDADE_BOLINHA_INICIAL 50 /*instrucoes pede 500 como valor inicial*/
#define DIMINUICAO_VELOCIDADE 50
#define COLISAO_BORDAS_RAQUETE 60
#define COLISAO_CENTRO_RAQUETE 40

#define LARGURA_BOTAO 50
#define COMPRIMENTO_BOTAO 70
#define MENSANGEM "jogar"

#define RETO_SENTIDO_DIREITO 1
#define RETO_SENTIDO_ESQUERDO 2
#define DIAG_CIMA_DIREITO 3
#define DIAG_CIMA_ESQUERDO 4
#define DIAG_BAIXO_DIREITO 5
#define DIAG_BAIXO_ESQUERDO 6

#define SHIFT 16
#define ALT 18

#define TEMPO_RAQUETE 10

typedef struct
{
	int x, y;
	int ganhou;
	char nome[20];
	
}RAQUETE1;

typedef struct
{
	int x, y;
	int ganhou;
	char nome[20];
	
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
    int cont; /*conta ate VELOCIDADE da bolinha para validar se pode atualizar o movimento da bolinha*/
}BOLINHA;

typedef struct
{
	int x, y;

}BOTAO;

void imprimirRaquete1(RAQUETE1 *, COLORREF);
void imprimirRaquete2(RAQUETE2 *, COLORREF);
void imprimirBolinha(BOLINHA *,  COLORREF);
void inicio(RAQUETE1 *, RAQUETE2 *, BOLINHA *, MONITOR *, BOTAO *);
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

void verificaVencedor(BOLINHA *, RAQUETE1 *, RAQUETE2 *, MONITOR *);
void fim(MONITOR *, RAQUETE1 *, RAQUETE2 *);




int main (int argc, char *argv[])
{
	RAQUETE1 *raquete1, r;
	RAQUETE2 *raquete2, r2;
	BOLINHA *bolinha, b;
	MONITOR *monitor, m;
	BOTAO *botao, botton;

	argc = argc;
	argv = argv;
	
	raquete1 = &r;
	raquete2 = &r2;
	bolinha = &b;
	monitor = &m;
	botao = &botton;

	clrscr();
	inicio(raquete1, raquete2, bolinha, monitor, botao);
	imprimirRaquete1(raquete1, RGB(255, 0, 0));
	imprimirRaquete2(raquete2, RGB(255, 0, 0));
	imprimirBolinha(bolinha, RGB(255, 0, 0));
	jogar(raquete1, raquete2, bolinha, RGB(255, 0, 0), RGB(12, 12, 12), monitor);
	fim(monitor, raquete1, raquete2);
	return 0;
}

void inicio (RAQUETE1 *raquete1, RAQUETE2 *raquete2, BOLINHA *bolinha, MONITOR *monitor, BOTAO *botao )
{
	EVENTO clique;
	int mouseX;
	int mouseY;
	setTituloConsole(TITULO);
	monitor->resolution = getResolucaoMonitor();
	monitor->PosicaoInicialJanela = getPosicaoJanela();
	monitor->tamanhoInicialJanela = tamanhoJanelaConsole();
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela();
	monitor->fonte= getTamanhoFonteConsole();
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 10, monitor->tamanhoInicialJanela.Y / 2 - 4);
	printf("bem vindos !!");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 15, monitor->tamanhoInicialJanela.Y / 2 - 3);
	printf("esse eh o jogo do pong!!");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 25, monitor->tamanhoInicialJanela.Y / 2 - 2);
	printf("seu objetivo eh fazer um GOL no seu adversario.");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 22, monitor->tamanhoInicialJanela.Y / 2 - 1);
	printf("o primeiro que marcar um GOL ganha o jogo !!");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 35, monitor->tamanhoInicialJanela.Y / 2);
	printf("utilize a tecla shift_direito para mover para cima a raquete da direita");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 35, monitor->tamanhoInicialJanela.Y / 2 + 1);
	printf("utilize a tecla alt_direito para mover para baixo a raquete da direita");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 35, monitor->tamanhoInicialJanela.Y / 2 + 2);
	printf("utiliza a tecla shift_esquerdo para mover para cima a raquete da esquerda");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 35, monitor->tamanhoInicialJanela.Y / 2 + 3);
	printf("utiliza a tecla alt_esquerdo para mover para baixo a raquete da esquerda ");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 20, monitor->tamanhoInicialJanela.Y / 2 + 4);
	printf("por favor digite o nome do jogador numero 1:");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 20, monitor->tamanhoInicialJanela.Y / 2 + 5);
	fgets(raquete1->nome, 20, stdin);
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 20, monitor->tamanhoInicialJanela.Y / 2 + 6);
	printf("por favor digite o nome do jogador numero 2");
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 20, monitor->tamanhoInicialJanela.Y / 2 + 7);
	fgets(raquete2->nome, 20, stdin);
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 10, monitor->tamanhoInicialJanela.Y / 2 + 8);
	printf("vamos ao jogo!!");
	setCursorStatus(DESLIGAR);

	/*clique.mouse.posicao.X > botao.x && clique.mouse.posicao.X < botao.x + COMPRIMENTO_BOTAO && clique.mouse.posicao.Y > botao.y && clique.mouse.posicao.Y < botao.y + LARGURA_BOTAO*/
	botao->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X / 2) - COMPRIMENTO_BOTAO + 20;
	botao->y = (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y / 2) + (monitor->fonte.Y * 10);
	
	
	linha(botao->x, botao->y, botao->x, botao->y + LARGURA_BOTAO, RGB(255, 0, 0));
	linha(botao->x, botao->y, botao->x + COMPRIMENTO_BOTAO, botao->y, RGB(255, 0, 0));
	linha(botao->x, botao->y + LARGURA_BOTAO, botao->x + COMPRIMENTO_BOTAO, botao->y + LARGURA_BOTAO, RGB(255, 0, 0));
	linha(botao->x + COMPRIMENTO_BOTAO, botao->y, botao->x + COMPRIMENTO_BOTAO, botao->y + LARGURA_BOTAO, RGB(255, 0, 0));
	
	
	gotoxy(botao->x / monitor->fonte.X + 2 , botao->y / monitor->fonte.Y + 2);
	printf("%s",MENSANGEM);
	do
	{
		clique = Evento();
		if(clique.tipo_evento & MOUSE_EVENT)
		{
			if( clique.mouse.botao_pressionado & BOTAO_ESQUERDO_PRESSIONADO )
			{
				mouseX = clique.mouse.posicao.X * monitor->fonte.X;
				mouseY = clique.mouse.posicao.Y * monitor->fonte.Y;
				if(mouseX > botao->x && mouseX < botao->x + COMPRIMENTO_BOTAO && mouseY > botao->y && mouseY < botao->y + LARGURA_BOTAO)
				{
					break;
				}
			}
		}

		if(clique.tipo_evento & KEY_EVENT)
		{
			if(clique.teclado.status_tecla == PRESSIONADA)
			{
				if(clique.teclado.codigo_tecla == ENTER)
				{
					break;
				}
			}
		}
	}while(1);
	
	
	clrscr();
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 5, monitor->tamanhoInicialJanela.Y / 2);
	printf("carregando...");
	Sleep(300); /*nao ta carregando nada, soh pra o programa mais dahorinha kkkk*/
	
	setPosicaoJanela(0,0);
	setDimensaoJanela(monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y);
	setEstadoBarraTarefas(INVISIVEL);
	
	raquete1->x = DISTANCIA_BORDA;
	raquete1->y = DISTANCIA_SUPERIOR_INICIAL;
	
	
	raquete2->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X) - DISTANCIA_BORDA;
	raquete2->y = DISTANCIA_SUPERIOR_INICIAL;
	

	bolinha->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X) / 2;
	bolinha->y = (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y) / 2;
	
	clrscr();
}


void imprimirRaquete1(RAQUETE1 *raquete1, COLORREF cor)
{
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, cor);
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	raquete1->ganhou = 0; /*assumi que ainda nao venceu o jogo*/
}

void imprimirRaquete2(RAQUETE2 *raquete2, COLORREF cor)
{
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, cor);
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	raquete2->ganhou = 0; /*assumi que ainda nao houve vencedor*/
}


void imprimirBolinha(BOLINHA *bolinha, COLORREF cor)
{
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, cor);
	srand(time(NULL));
	bolinha->direcao = rand()%5 + 1;
	bolinha->velocidade = VELOCIDADE_BOLINHA_INICIAL;
	bolinha->cont = 0;
}

void moveBolinha(BOLINHA *bolinha, MONITOR *monitor, COLORREF vermelho, COLORREF preto, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{

	atualizaSentido(bolinha, monitor, raquete1, raquete2);
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, preto);
	atualizaCoordenadas(bolinha, bolinha->direcao);
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, vermelho);
	verificaVencedor(bolinha, raquete1, raquete2, monitor);
}

void verificaVencedor(BOLINHA *bolinha, RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor) 
{
	if(bolinha->x < 0)
	{
		raquete2->ganhou = 1;
	}
	if(bolinha->x > (monitor->tamanhoMaximoJanela.X * monitor->fonte.X))
	{
		raquete1->ganhou = 1;
	}
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
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}
	
	if(colisaoSuperiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_CIMA_ESQUERDO;
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}

	if(colisaoCentroRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = RETO_SENTIDO_DIREITO;
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}
	
	if(colisaoCentroRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = RETO_SENTIDO_ESQUERDO;
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}
	
	if(colisaoInferiorRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = DIAG_BAIXO_DIREITO;
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}
	
	if(colisaoInferiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_BAIXO_ESQUERDO;
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}
	
	if(colisaoSuperiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_CIMA_ESQUERDO;
		if(bolinha->velocidade - 50 > 0)
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE;
		}
	}
}

int colisaoSuperiorRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{
	int a = 0; 
	int i;
	
	for(i=0;i<COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x < raquete1->x + LARGURA_RAQUETE) && bolinha->x >= raquete1->x && (bolinha->y == raquete1->y + i))
		{
			a = 1;
		}
	}
	return a;
}

int colisaoSuperiorRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{
	int a = 0;
	int i ;
	
	for(i=0;i<COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x > raquete2->x - LARGURA_RAQUETE) && bolinha->x < raquete2->x && (bolinha->y == raquete2->y + i))
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
	for(i=0;i<=COLISAO_CENTRO_RAQUETE;i++)
	{
		if((bolinha->x < raquete1->x + LARGURA_RAQUETE) && bolinha->x >= raquete1->x && (bolinha->y == (raquete1->y + COLISAO_BORDAS_RAQUETE) + i))
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
	
	for(i=0;i<=COLISAO_CENTRO_RAQUETE;i++)
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE) && bolinha->x < raquete2->x && (bolinha->y == (raquete2->y + COLISAO_BORDAS_RAQUETE) + i))
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
	
	for(i=0;i<=COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE) && bolinha->x >= raquete1->x && (bolinha->y == (raquete1->y + COLISAO_BORDAS_RAQUETE + COLISAO_CENTRO_RAQUETE) + i))
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
	
	for(i=0;i<=COLISAO_BORDAS_RAQUETE;i++)
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE) && bolinha->x < raquete2->x && (bolinha->y == (raquete2->y + COLISAO_BORDAS_RAQUETE + COLISAO_CENTRO_RAQUETE) + i))
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
        if(raquete1->ganhou || raquete2->ganhou)
		{
			break;
		}
		if(bolinha->cont >= bolinha->velocidade)
		{
			moveBolinha(bolinha, monitor, vermelho, preto, raquete1, raquete2);
			bolinha->cont = 0;
		}
		/*moveBolinha(bolinha, monitor, vermelho, preto, raquete1, raquete2);
		  tecla = Evento();*/
		if(hit(KEYBOARD_HIT))
        {
        	tecla = Evento();   
            if ( tecla.tipo_evento & KEY_EVENT ) 
            {
                /*raquete1 para baixo apenas*/
                if((tecla.teclado.status_teclas_controle & LEFT_ALT_PRESSED)&& validarMovimentoRaquete1Baixo(raquete1, monitor))
                {
                    moveRaquete1Baixo(raquete1, vermelho, preto);
                }                    /*raquete1 para cima apenas*/
                else
					 if((tecla.teclado.status_teclas_controle & SHIFT_ESQUERDO_PRESSIONADO)&& validarMovimentoRaquete1Cima(raquete1))
                	 {
                    moveRaquete1Cima(raquete1, vermelho, preto);
                	 }
					 else
					  
                /*raquete2 para cima apenas*/
                if((tecla.teclado.status_teclas_controle & SHIFT_DIREITO_PRESSIONADO)&& validarMovimentoRaquete2Cima(raquete2))
                {
                    moveRaquete2Cima(raquete2, vermelho, preto);
                }                     /*raquete2 para baixo apenas*/
            	else if((tecla.teclado.status_teclas_controle & RIGHT_ALT_PRESSED) && validarMovimentoRaquete2Baixo(raquete2, monitor))
                {
                    moveRaquete2Baixo(raquete2, vermelho, preto);
                } 
                    
                /**/
                if(tecla.teclado.codigo_tecla == F12)
                { 
                    break;
                }                
            }
        }
		Sleep(1);
		bolinha->cont = bolinha->cont + 10;

		
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


void fim(MONITOR *monitor, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
	clrscr();
	setEstadoBarraTarefas(VISIVEL);
	setDimensaoJanela(monitor->tamanhoInicialJanela.X, monitor->tamanhoInicialJanela.Y);
	setPosicaoJanela(monitor->PosicaoInicialJanela.X, monitor->PosicaoInicialJanela.Y);
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela();
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 8, monitor->tamanhoInicialJanela.Y / 2);
	printf("o jogo terminou");
	if(raquete1->ganhou)
	{
		gotoxy((monitor->tamanhoInicialJanela.X / 2) - 12, (monitor->tamanhoInicialJanela.Y / 2) + 1);
		printf("o vencedor foi %s", raquete1->nome);
	}
	else 
		if (raquete2->ganhou)
	{
		gotoxy((monitor->tamanhoInicialJanela.X / 2) - 12, (monitor->tamanhoInicialJanela.Y / 2) + 1);
		printf("o vencedor foi %s", raquete2->nome);
	}
	else
	{
		gotoxy((monitor->tamanhoInicialJanela.X / 2) - 13, (monitor->tamanhoInicialJanela.Y / 2) + 1);
		printf("Que pena, sem vencedores");
	}

	Sleep(3);
	setCursorStatus(LIGAR);
}
/*gcc -o pong3Backup.exe pong3Backup.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/