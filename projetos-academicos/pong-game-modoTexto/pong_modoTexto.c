
/*gcc -o pong_modoTexto.exe pong_modoTexto.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/

#include <stdio.h>
#include <windows.h>
#include <Windows.h>
#include <time.h>

#include "conio_v3.2.4.h"
#include "console_v1.5.4.h"

#define TITULO "PONG______criador: Hiroshi"
#define DISTANCIA_BORDA 5

#define SHIFT 16
#define ALT 18

#define RETO_SENTIDO_DIREITO 1
#define RETO_SENTIDO_ESQUERDO 2
#define DIAG_CIMA_DIREITO1 3
#define DIAG_CIMA_DIREITO2 4
#define DIAG_CIMA_ESQUERDO1 5
#define DIAG_CIMA_ESQUERDO2 6
#define DIAG_BAIXO_DIREITO1  7
#define DIAG_BAIXO_DIREITO2 8
#define DIAG_BAIXO_ESQUERDO1 9 
#define DIAG_BAIXO_ESQUERDO2 10


#define VELOCIDADE_INICIAL 10
#define MOVIMENTO_BOLINHA 1

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
    int x, y;
    int direcao;
    int velocidade;
    int temp;
}BOLA;

typedef struct
{
    COORD PosicaoInicialJanela;
	COORD tamanhoInicialJanela;
	COORD tamanhoMaximoJanela;
	COORD fonte;
}MONITOR;

void inicio(RAQUETE1 *, RAQUETE2 *, MONITOR *, BOLA *);
void imprimirRaquete1(RAQUETE1 *);
void imprimirRaquete2(RAQUETE2 *);
void jogar(RAQUETE1 *, RAQUETE2 *, MONITOR *, BOLA *);
void moveRaquete1Baixo(RAQUETE1 *);
void moveRaquete1Cima(RAQUETE1 *);
void moveRaquete2Baixo(RAQUETE2 *);
void moveRaquete2Cima(RAQUETE2 *);
int validarMovimentoRaquete1Cima(RAQUETE1 *);
int validarMovimentoRaquete1Baixo(RAQUETE1 *, MONITOR *);
int validarMovimentoRaquete2Cima(RAQUETE2 *);
int validarMovimentoRaquete2Baixo(RAQUETE2 *, MONITOR *);

void imprimirBola(BOLA *);
void moveBola(BOLA *, MONITOR *, RAQUETE1 *, RAQUETE2 *);
void atualizaCoordenadas(BOLA *, int);
void atualizaSentido(BOLA *, MONITOR *, RAQUETE1 *, RAQUETE2 *);
void verificaVencedor(BOLA *, MONITOR *, RAQUETE1 *, RAQUETE2 *);

void mostrarInfo(RAQUETE1 *, RAQUETE2 *, MONITOR *);
void fim(RAQUETE1 *, RAQUETE2 *, MONITOR *);


int main(int argc, char *argv[])
{
    RAQUETE1 *raquete1, r1;
    RAQUETE2 *raquete2, r2;
    MONITOR *monitor, m;
    BOLA *bola, b;

    argc = argc;
	argv = argv;

    raquete1 = &r1;
    raquete2 = &r2;
    monitor = &m;
    bola = &b;

    clrscr();
    inicio(raquete1, raquete2, monitor, bola);
    imprimirRaquete1(raquete1);
    imprimirRaquete2(raquete2);
    imprimirBola(bola);
    jogar(raquete1, raquete2, monitor, bola);
    fim(raquete1, raquete2, monitor);
    
    return 0;
}

void inicio(RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor, BOLA *bola)
{
    setTituloConsole(TITULO);

    monitor->PosicaoInicialJanela = getPosicaoJanela();
	monitor->tamanhoInicialJanela = tamanhoJanelaConsole();
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela();

    setPosicaoJanela(0,0);
	setDimensaoJanela(monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y);

    monitor->tamanhoMaximoJanela.X = monitor->tamanhoMaximoJanela.X / 3 * 2;
    monitor->tamanhoMaximoJanela.Y = monitor->tamanhoMaximoJanela.Y / 3 * 2;
	monitor->fonte= getTamanhoFonteConsole();

    raquete1->x = DISTANCIA_BORDA;
    raquete1->y = monitor->tamanhoMaximoJanela.Y / 2;
    raquete1->ganhou = 0;

    raquete2->x = monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA ;
    raquete2->y = monitor->tamanhoMaximoJanela.Y / 2;
    raquete2->ganhou = 0;

    bola->x = monitor->tamanhoMaximoJanela.X / 2;
    bola->y = monitor->tamanhoMaximoJanela.Y / 2;
    srand(time(NULL));
    bola->direcao = rand()%9 + 1;
    bola->velocidade = VELOCIDADE_INICIAL;
    bola->temp = 0;

    gotoxy(monitor->tamanhoMaximoJanela.X / 2, monitor->tamanhoMaximoJanela.Y / 2);
    printf("ola! vamos jogar o jogo do PONG");
    gotoxy(monitor->tamanhoMaximoJanela.X / 2, monitor->tamanhoMaximoJanela.Y / 2 + 1);
    printf("digite o nome do jogador 1:");
    gotoxy(monitor->tamanhoMaximoJanela.X / 2, monitor->tamanhoMaximoJanela.Y / 2 + 2);
    fgets(raquete1->nome, 20, stdin);
    gotoxy(monitor->tamanhoMaximoJanela.X / 2, monitor->tamanhoMaximoJanela.Y / 2 + 3);
    printf("digite o nome do jogador 2:");
    gotoxy(monitor->tamanhoMaximoJanela.X / 2, monitor->tamanhoMaximoJanela.Y / 2 + 4);
    fgets(raquete2->nome, 20, stdin);

    clrscr();
    gotoxy(monitor->tamanhoMaximoJanela.X / 2, monitor->tamanhoMaximoJanela.Y / 2 + 5);
    printf("carregando...");
    Sleep(3000);

    setDimensaoJanela(monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y);
    setCursorStatus(DESLIGAR);

    textbackground(GREEN); /*definindo cor de fundo do mapa*/
	window(1, 1, monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y);
}

void imprimirRaquete1(RAQUETE1 *raquete1)
{
    textcolor(RED);
    gotoxy(raquete1->x, raquete1->y);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 1);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 2);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 3);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 4);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 5);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 6);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 7);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 8);
    printf("%c",219);
    gotoxy(raquete1->x, raquete1->y + 9);
    printf("%c",219);
}

void imprimirRaquete2(RAQUETE2 *raquete2)
{
    textcolor(BLUE);
    gotoxy(raquete2->x, raquete2->y);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 1);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 2);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 3);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 4);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 5);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 6);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 7);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 8);
    printf("%c",219);
    gotoxy(raquete2->x, raquete2->y + 9);
    printf("%c",219);
}

void imprimirBola(BOLA *bola)
{
    textcolor(BLACK);
    gotoxy(bola->x, bola->y);
    printf("%c",254);
}

void moveBola(BOLA *bola, MONITOR *monitor, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
    atualizaSentido(bola, monitor, raquete1, raquete2);
    gotoxy(bola->x, bola->y);
    printf(" ");
    atualizaCoordenadas(bola, bola->direcao);
    textcolor(BLACK);
    gotoxy(bola->x, bola->y);
    printf("%c",254);
    verificaVencedor(bola, monitor, raquete1, raquete2);
}

void verificaVencedor(BOLA *bola, MONITOR *monitor, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
    if(bola->x <= 2)
    {
        raquete2->ganhou = 1;
    }

    if(bola->x >= monitor->tamanhoMaximoJanela.X - 2)
    {
        raquete1->ganhou = 1;
    }

}

void atualizaSentido(BOLA *bola, MONITOR *monitor, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
    if(bola->y <= 2)
    {
        if(bola->direcao == DIAG_CIMA_DIREITO1)
        {
            bola->direcao = DIAG_BAIXO_DIREITO1;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO1)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO1;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao = DIAG_BAIXO_DIREITO2;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO2)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO2;
        }
    }

    if(bola->direcao == DIAG_BAIXO_ESQUERDO1 || bola->direcao == DIAG_BAIXO_DIREITO1)
    {
        if(bola->y + 1 > monitor->tamanhoMaximoJanela.Y)
        {
            if(bola->direcao == DIAG_BAIXO_ESQUERDO1)
            {
                bola->direcao = DIAG_CIMA_ESQUERDO1;
            }

            if(bola->direcao == DIAG_BAIXO_DIREITO1)
            {
                bola->direcao = DIAG_CIMA_DIREITO1;
            }
        }
    }

    if(bola->direcao == DIAG_BAIXO_ESQUERDO2 || bola->direcao == DIAG_BAIXO_DIREITO2)
    {
        if(bola->y + 2 > monitor->tamanhoMaximoJanela.Y)
        {
            if(bola->direcao == DIAG_BAIXO_ESQUERDO2)
            {
                bola->direcao = DIAG_CIMA_ESQUERDO2;
            }

            if(bola->direcao == DIAG_BAIXO_DIREITO2)
            {
                bola->direcao = DIAG_CIMA_DIREITO2;
            }
        }
    }


    /*colisao com as raquetes*/


    /*colisao superior 0 - 1 da raquete*/                                      /*0*/                      /*1*/
    if(bola->x <= DISTANCIA_BORDA + 2 && bola->x >=DISTANCIA_BORDA + 1 && bola->y >= raquete1->y && bola->y <= raquete1->y + 1)
    {
        if(bola->direcao == DIAG_BAIXO_ESQUERDO1 || bola->direcao == DIAG_BAIXO_ESQUERDO2)
        {
            bola->direcao = DIAG_BAIXO_DIREITO2;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO1 || bola->direcao == DIAG_CIMA_ESQUERDO2)
        {
            bola->direcao = DIAG_CIMA_DIREITO2;
        }

        if(bola->direcao == RETO_SENTIDO_ESQUERDO)
        {
            bola->direcao = DIAG_CIMA_DIREITO2;
        }

        imprimirRaquete1(raquete1);  
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }
    }
    
    /*colisao superior 2 - 3 da raquete*/         /*2*/                      /*3*/
    if(bola->x <= DISTANCIA_BORDA + 2 && bola->x >=DISTANCIA_BORDA + 1 && bola->y >= raquete1->y + 2 && bola->y <= raquete1->y + 3)
    {
        if(bola->direcao == DIAG_BAIXO_ESQUERDO1 || bola->direcao == DIAG_BAIXO_ESQUERDO2)
        {
            bola->direcao = DIAG_BAIXO_DIREITO1;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO1 || bola->direcao == DIAG_CIMA_ESQUERDO2)
        {
            bola->direcao = DIAG_CIMA_DIREITO1;
        }

        if(bola->direcao == RETO_SENTIDO_ESQUERDO)
        {
            bola->direcao = DIAG_CIMA_DIREITO1;
        }

        imprimirRaquete1(raquete1); 
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }          
    }

    /*colisao superior 4 - 5 da raquete*/ 
    if(bola->x <= DISTANCIA_BORDA + 2 && bola->x >=DISTANCIA_BORDA + 1 && bola->y >= raquete1->y + 4 && bola->y <= raquete1->y + 5)
    {
        if(bola->direcao == DIAG_BAIXO_ESQUERDO1 || bola->direcao == DIAG_BAIXO_ESQUERDO2)
        {
            bola->direcao = RETO_SENTIDO_DIREITO;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO1 || bola->direcao == DIAG_CIMA_ESQUERDO2)
        {
            bola->direcao =RETO_SENTIDO_DIREITO;
        }

        if(bola->direcao == RETO_SENTIDO_ESQUERDO)
        {
            bola->direcao =RETO_SENTIDO_DIREITO;
        }

        imprimirRaquete1(raquete1);  
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }          
    }

    /*colisao superior 6 - 7 da raquete*/ 
    if(bola->x <= DISTANCIA_BORDA + 2 && bola->x >=DISTANCIA_BORDA + 1 && bola->y >= raquete1->y + 6 && bola->y <= raquete1->y + 7)
    {
        if(bola->direcao == DIAG_BAIXO_ESQUERDO1 || bola->direcao == DIAG_BAIXO_ESQUERDO2)
        {
            bola->direcao =  DIAG_BAIXO_DIREITO1;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO1 || bola->direcao == DIAG_CIMA_ESQUERDO2)
        {
            bola->direcao = DIAG_CIMA_DIREITO1;
        }

        if(bola->direcao == RETO_SENTIDO_ESQUERDO)
        {
            bola->direcao = DIAG_BAIXO_DIREITO1;
        }

        imprimirRaquete1(raquete1);  
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }           
    }

    /*colisao superior 8 - 9 da raquete*/ 
    if(bola->x <= DISTANCIA_BORDA + 2 && bola->x >=DISTANCIA_BORDA + 1 && bola->y >= raquete1->y + 8 && bola->y <= raquete1->y + 9)
    {
        if(bola->direcao == DIAG_BAIXO_ESQUERDO1 || bola->direcao == DIAG_BAIXO_ESQUERDO2)
        {
            bola->direcao =  DIAG_BAIXO_DIREITO2;
        }

        if(bola->direcao == DIAG_CIMA_ESQUERDO1 || bola->direcao == DIAG_CIMA_ESQUERDO2)
        {
            bola->direcao = DIAG_CIMA_DIREITO2;
        }

        if(bola->direcao == RETO_SENTIDO_ESQUERDO)
        {
            bola->direcao = DIAG_BAIXO_DIREITO2;
        }

        imprimirRaquete1(raquete1); 
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }           
    }



    /*conferindo colisao da raquete 2*/

    /*colisao superior 0 - 1 da raquete*/
    if(bola->x >= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 2 && bola->x <= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 1 && bola->y >= raquete2->y && bola->y <= raquete2->y + 1)
    {
        if(bola->direcao == DIAG_BAIXO_DIREITO1 || bola->direcao == DIAG_BAIXO_DIREITO2)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO2;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO1 || bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao = DIAG_CIMA_ESQUERDO2;
        }

        if(bola->direcao == RETO_SENTIDO_DIREITO)
        {
            bola->direcao = DIAG_CIMA_ESQUERDO2;
        }

        imprimirRaquete2(raquete2); 
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }           
    }

    /*colisao superior 2 - 3 da raquete*/
    if(bola->x >= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 2 && bola->x <= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 1 && bola->y >= raquete2->y + 2 && bola->y <= raquete2->y + 3)
    {
        if(bola->direcao == DIAG_BAIXO_DIREITO1 || bola->direcao == DIAG_BAIXO_DIREITO2)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO1;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO1 || bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao = DIAG_CIMA_ESQUERDO1;
        }

        if(bola->direcao == RETO_SENTIDO_DIREITO)
        {
            bola->direcao = DIAG_CIMA_ESQUERDO1;
        }

        imprimirRaquete2(raquete2);  
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }            
    }

    /*colisao superior 2 - 3 da raquete*/
    if(bola->x >= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 2 && bola->x <= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 1 && bola->y >= raquete2->y + 2 && bola->y <= raquete2->y + 3)
    {
        if(bola->direcao == DIAG_BAIXO_DIREITO1 || bola->direcao == DIAG_BAIXO_DIREITO2)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO1;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO1 || bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao = DIAG_CIMA_ESQUERDO1;
        }

        if(bola->direcao == RETO_SENTIDO_DIREITO)
        {
            bola->direcao = DIAG_CIMA_ESQUERDO1;
        }

        imprimirRaquete2(raquete2);     
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }       
    }

    /*colisao superior 4 - 5 da raquete*/
    if(bola->x >= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 2 && bola->x <= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 1 && bola->y >= raquete2->y + 4 && bola->y <= raquete2->y + 5)
    {
        if(bola->direcao == DIAG_BAIXO_DIREITO1 || bola->direcao == DIAG_BAIXO_DIREITO2)
        {
            bola->direcao = RETO_SENTIDO_ESQUERDO;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO1 || bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao =RETO_SENTIDO_ESQUERDO;
        }

        if(bola->direcao == RETO_SENTIDO_DIREITO)
        {
            bola->direcao =RETO_SENTIDO_ESQUERDO;
        }

        imprimirRaquete2(raquete2);    
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }         
    }

    /*colisao superior 6 - 7 da raquete*/
    if(bola->x >= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 2 && bola->x <= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 1 && bola->y >= raquete2->y + 6 && bola->y <= raquete2->y + 7)
    {
        if(bola->direcao == DIAG_BAIXO_DIREITO1 || bola->direcao == DIAG_BAIXO_DIREITO2)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO1;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO1 || bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao =DIAG_CIMA_ESQUERDO1;
        }

        if(bola->direcao == RETO_SENTIDO_DIREITO)
        {
            bola->direcao =DIAG_BAIXO_ESQUERDO1;
        }

        imprimirRaquete2(raquete2);  
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        }          
    }

    /*colisao superior 8 - 9 da raquete*/
    if(bola->x >= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 2 && bola->x <= monitor->tamanhoMaximoJanela.X - DISTANCIA_BORDA - 1 && bola->y >= raquete2->y + 8 && bola->y <= raquete2->y + 9)
    {
        if(bola->direcao == DIAG_BAIXO_DIREITO1 || bola->direcao == DIAG_BAIXO_DIREITO2)
        {
            bola->direcao = DIAG_BAIXO_ESQUERDO2;
        }

        if(bola->direcao == DIAG_CIMA_DIREITO1 || bola->direcao == DIAG_CIMA_DIREITO2)
        {
            bola->direcao =DIAG_CIMA_ESQUERDO2;
        }

        if(bola->direcao == RETO_SENTIDO_DIREITO)
        {
            bola->direcao =DIAG_BAIXO_ESQUERDO2;
        }

        imprimirRaquete2(raquete2);  
        if(bola->velocidade != 2)
        {
            bola->velocidade--;
        } 
    }

}



void atualizaCoordenadas(BOLA *bola, int sentido)
{
    if(sentido == RETO_SENTIDO_DIREITO)
	{
		bola->x = bola->x + MOVIMENTO_BOLINHA * 2;
	}

	if(sentido == RETO_SENTIDO_ESQUERDO)
	{
		bola->x = bola->x - MOVIMENTO_BOLINHA * 2;
	}

	if(sentido == DIAG_CIMA_DIREITO1)
	{
		bola->x = bola->x + MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y - MOVIMENTO_BOLINHA;
	}

    if(sentido == DIAG_CIMA_DIREITO2)
	{
		bola->x = bola->x + MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y - MOVIMENTO_BOLINHA * 2;
	}

	if(sentido == DIAG_CIMA_ESQUERDO1)
	{
		bola->x = bola->x - MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y - MOVIMENTO_BOLINHA;
	}

    if(sentido == DIAG_CIMA_ESQUERDO2)
	{
		bola->x = bola->x - MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y - MOVIMENTO_BOLINHA * 2;
	}


	if(sentido == DIAG_BAIXO_DIREITO1)
	{
		bola->x = bola->x + MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y + MOVIMENTO_BOLINHA;
	}

    if(sentido == DIAG_BAIXO_DIREITO2)
	{
		bola->x = bola->x + MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y + MOVIMENTO_BOLINHA * 2;
	}


	if(sentido == DIAG_BAIXO_ESQUERDO1)
	{
		bola->x = bola->x - MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y + MOVIMENTO_BOLINHA;
    }

    if(sentido == DIAG_BAIXO_ESQUERDO2)
	{
		bola->x = bola->x - MOVIMENTO_BOLINHA * 2;
		bola->y = bola->y + MOVIMENTO_BOLINHA * 2;
    }
}

void mostrarInfo(RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor)
{
    textcolor(BLACK);
    gotoxy(monitor->tamanhoMaximoJanela.X / 5 - 5, 1);
    printf("%s",raquete1->nome);
    gotoxy(monitor->tamanhoMaximoJanela.X / 5 * 4, 1);
    printf("%s",raquete2->nome);
    gotoxy(monitor->tamanhoMaximoJanela.X / 2 - 10, 1);
    printf("aperte ESC para sair");
}


void jogar(RAQUETE1 *raquete1 , RAQUETE2 *raquete2, MONITOR *monitor, BOLA *bola)
{
    EVENTO tecla;
    do
    {
        mostrarInfo(raquete1, raquete2, monitor);
        if(bola->temp >= bola->velocidade)
        {
            mostrarInfo(raquete1, raquete2, monitor);
            moveBola(bola, monitor, raquete1, raquete2);
            bola->temp = 0;
        }

        if(raquete1->ganhou || raquete2->ganhou)
        {
            break;
        }

        if(hit(KEYBOARD_HIT))
        {
            tecla = Evento();
            if( tecla.tipo_evento & KEY_EVENT )
            {
                
                    if((tecla.teclado.status_teclas_controle & SHIFT_ESQUERDO_PRESSIONADO) && validarMovimentoRaquete1Cima(raquete1))
                    {
                        moveRaquete1Cima(raquete1);
                    }
                    else
                        if((tecla.teclado.status_teclas_controle & LEFT_ALT_PRESSED) && validarMovimentoRaquete1Baixo(raquete1, monitor))
                        {
                            moveRaquete1Baixo(raquete1);
                        }

                    if((tecla.teclado.status_teclas_controle & SHIFT_DIREITO_PRESSIONADO) && validarMovimentoRaquete2Cima(raquete2))
                    {
                        moveRaquete2Cima(raquete2);
                    }
                    else
                        if((tecla.teclado.status_teclas_controle & RIGHT_ALT_PRESSED)&& validarMovimentoRaquete2Baixo(raquete2, monitor))
                        {
                            moveRaquete2Baixo(raquete2);
                        }
                
                    if(tecla.teclado.codigo_tecla == ESC)
                    {
                        break;
                    }
                
            }
        }
        bola->temp = bola->temp + 1;
        Sleep(1);
    }while(1);
}

void moveRaquete1Baixo(RAQUETE1 *raquete1)
{
    textcolor(RED);
    gotoxy(raquete1->x, raquete1->y);
    printf(" ");

    raquete1->y = raquete1->y + 1;

    gotoxy(raquete1->x, raquete1->y + 9);
    printf("%c",219);
}

void moveRaquete1Cima(RAQUETE1 *raquete1)
{
    textcolor(RED);
    
    gotoxy(raquete1->x, raquete1->y + 9);
    printf(" ");

    raquete1->y = raquete1->y - 1;

    gotoxy(raquete1->x, raquete1->y);
    printf("%c",219);
    
}

int validarMovimentoRaquete1Cima(RAQUETE1 *raquete1)
{
    int a = 1;

    if(raquete1->y < 2)
    {
        a = 0;
    }

    return a;
}

int validarMovimentoRaquete1Baixo(RAQUETE1 *raquete1, MONITOR *monitor)
{
    int a = 1;

    if(raquete1->y + 10 > monitor->tamanhoMaximoJanela.Y)
    {
        a = 0;
    }

    return a;
}

void moveRaquete2Baixo(RAQUETE2 *raquete2)
{
    textcolor(BLUE);
    gotoxy(raquete2->x, raquete2->y);
    printf(" ");

    raquete2->y = raquete2->y + 1;
    
    gotoxy(raquete2->x, raquete2->y + 9);
    printf("%c",219);
}


void moveRaquete2Cima(RAQUETE2 *raquete2)
{
    textcolor(BLUE);
    gotoxy(raquete2->x, raquete2->y + 9);
    printf(" ");

    raquete2->y = raquete2->y - 1;

    gotoxy(raquete2->x, raquete2->y);
    printf("%c",219);
}


int validarMovimentoRaquete2Cima(RAQUETE2 *raquete2)
{
    int a = 1;

    if(raquete2->y < 2)
    {
        a = 0;
    }

    return a;
}

int validarMovimentoRaquete2Baixo(RAQUETE2 *raquete2, MONITOR *monitor)
{
    int a = 1;

    if(raquete2->y + 10 > monitor->tamanhoMaximoJanela.Y)
    {
        a = 0;
    }

    return a;
}


void fim(RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor)
{
    clrscr();
    
    if(raquete1->ganhou)
    {
        gotoxy(monitor->tamanhoMaximoJanela.X / 2 - 20, monitor->tamanhoMaximoJanela.Y / 2);
        printf("o ganhador foi o jogador %s", raquete1->nome);
    }
    else if(raquete2->ganhou)
    {
        gotoxy(monitor->tamanhoMaximoJanela.X / 2 - 20, monitor->tamanhoMaximoJanela.Y / 2);
        printf("o ganhador foi o jogador %s", raquete2->nome);
    }
    else
    {
        gotoxy(monitor->tamanhoMaximoJanela.X / 2 - 20, monitor->tamanhoMaximoJanela.Y / 2);
        printf("que pena, nao houve ganhador!");
    }

    Sleep(3000);
    textbackground(WHITE);
    textcolor(BLACK);
    setCursorStatus(LIGAR);
    setDimensaoJanela(monitor->tamanhoInicialJanela.X, monitor->tamanhoInicialJanela.Y); 

}
/*gcc -o pong_modoTexto.exe pong_modoTexto.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/