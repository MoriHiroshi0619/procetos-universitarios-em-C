
/*
        LEMBRETES: 
                    -criar tela inicial com leitura de nome do jogador PS; salvar char nome[] na cobra;
                    -criar menu final com mensagem e score


*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>



#include "conio_v3.2.4.h"
#include "console_v1.5.4.h" 

#define TITULO "SNAKE_GAME__________________criador: Hiroshi"
#define TAMANHO_COBRA_INCIAL 10

#define BAIXO 40
#define DIREITA 39
#define CIMA 38
#define ESQUERDA 37


#define CORPO_COBRA 254/*111*/
#define CORPO_FRUTA 127


#define DIRECAO_CIMA 5
#define DIRECAO_BAIXO 6
#define DIRECAO_DIREITA 7
#define DIRECAO_ESQUERDA 8

#define DISNTANCIA_FRUTA_X 20
#define DISNTANCIA_FRUTA_Y 4

#define DISNTANCIA_OBSTACULOS 4
#define DISTANCIA_ENTRE_OBSTCULOS 12
#define TOTAL_OBSTACULOS 15

#define VELOCIDADE_INICIAL 25


typedef struct
{

    COORD pocisao_inicial;
    COORD tamanho_inicial;
    COORD maximo_janela;

}MONITOR;


typedef struct
{

    int x;
    int x2;
    int y;

}FRUTA;


typedef struct CORPO
{

    int x;
    int y;
    struct CORPO *proximo; /*vai apontar para o proximo no*/

}CORPO;


typedef struct
{

    CORPO *inicio; /*salvar sempre o inicio da lista*/
    int velocidade;
    int tamanho;
    int score;
    char nome[20];

}COBRA;


typedef struct
{
    int x, y;
}OBSTACULOS;

void inicio(MONITOR *, COBRA *);

void incrementar_cobra(COBRA *, int, int);

void desenhar_cobra(COBRA *);

void info(COBRA *, MONITOR *);

void jogar(COBRA *, MONITOR *, FRUTA *, OBSTACULOS *);

void desenhar_fruta(COBRA *, MONITOR *, FRUTA *);

void desenhar_obstaculos(COBRA *, MONITOR *, FRUTA *, OBSTACULOS *);

int verificar_colisao_borda(COBRA *, MONITOR *);

int validar_fruta(COBRA *, FRUTA *, MONITOR *);

int validar_obstaculos(COBRA *, FRUTA *, OBSTACULOS *, int, MONITOR *);

int verifcar_colisao_fruta(COBRA *, FRUTA *);

int verificar_colisao_obstaculo( COBRA *, OBSTACULOS *);

void fim(COBRA *, MONITOR *);


int main(int argc, char *argv[])
{

    MONITOR *monitor, m;
    FRUTA *fruta, f;
    COBRA cobra;
    OBSTACULOS obstaculo[TOTAL_OBSTACULOS];
    int i;
    int posicaoX_inicial;
    int posicaoY_inicial;

    argc = argc;
	argv = argv;

    monitor = &m;
    fruta = &f;
    /*inicializando ponteiro e tamanho da cobra(numero de nos)*/
    cobra.inicio = NULL; 
    cobra.tamanho = 0;

    clrscr();
    

    inicio(monitor, &cobra);

    posicaoX_inicial = (int)monitor->maximo_janela.X / 2;
    posicaoY_inicial = 1;

    for(i = 0 ; i < TAMANHO_COBRA_INCIAL ; i++)
    {
        incrementar_cobra(&cobra, posicaoX_inicial, posicaoY_inicial + i);
    }

    desenhar_cobra(&cobra);
    desenhar_fruta(&cobra, monitor, fruta);
    desenhar_obstaculos(&cobra,monitor, fruta, obstaculo);

    info(&cobra, monitor);

    jogar(&cobra, monitor, fruta, obstaculo);

    fim(&cobra, monitor);
    
    
    return 0;

}

void inicio(MONITOR *monitor, COBRA *cobra)
{

    int meiox;
    int meioy;

    monitor->pocisao_inicial = getPosicaoJanela();
    monitor->tamanho_inicial = tamanhoJanelaConsole();
    monitor->maximo_janela = MaxDimensaoJanela();

    setPosicaoJanela(0,0);
    setDimensaoJanela(monitor->maximo_janela.X, monitor->maximo_janela.Y);
    setTituloConsole(TITULO);
    
    

    meiox = monitor->maximo_janela.X / 2;
    meioy = monitor->maximo_janela.Y / 2;


    gotoxy(meiox - 13, meioy - 5);
    printf("BEM VINDOS AO SNAKE GAME !");
    gotoxy(meiox - 31, meioy - 1);
    printf("!!! utilize as setas de direcoes para movimentar a cobra no mapa !!!");
    gotoxy(meiox - 29, meioy);
    printf("!!! cuidado com os obstaculos '***' para evitar perder o jogo !!!");
    gotoxy(meiox - 27, meioy + 1);
    printf("!!! seu objetivo eh atingir o maximo de score possivel !!!");
    gotoxy(meiox - 21, meioy + 2);
    printf("por favor informe o nome do jogador:");
    gotoxy(meiox - 10, meioy + 3);
    fgets(cobra->nome, 20, stdin);

    clrscr();

    gotoxy(meiox- 10, meioy - 2);
    printf("!!! VAMOS AO JOGO !!!");
    gotoxy(meiox - 7, meioy);
    printf("carregando...");

    Sleep(3000);

    clrscr();

    cobra->score = 0;

    setCursorStatus(DESLIGAR);

}


void incrementar_cobra(COBRA *cobra, int x, int y)
{

    CORPO *novo; /*novo no*/
    novo = (CORPO *) malloc(sizeof(CORPO)); 
    novo->x = x; 
    novo->y = y;

    novo->proximo = cobra->inicio; 
    cobra->inicio = novo; 
    cobra->tamanho++;

}

void desenhar_cobra(COBRA *cobra)
{

    textcolor(MAGENTA);
    CORPO *inicio;
    inicio = cobra->inicio;
    while(inicio != NULL)
    {
        gotoxy(inicio->x, inicio->y);
        printf("%c",CORPO_COBRA);
        textcolor(GREEN);
        inicio = inicio->proximo;
    }

}


void desenhar_fruta(COBRA *cobra, MONITOR *monitor, FRUTA *fruta)
{

    textcolor(LIGHTGREEN);
    srand(time(NULL));

    gotoxy(fruta->x, fruta->y);
    printf(" ");
    gotoxy(fruta->x2, fruta->y);
    printf(" ");

    do
    {
        fruta->x = rand()% monitor->maximo_janela.X + 1;
        fruta->y = rand()% monitor->maximo_janela.Y + 1;
    }while(validar_fruta( cobra, fruta, monitor ));

    fruta->x2 = fruta->x + 1;

    gotoxy(fruta->x, fruta->y);
    printf("%c", CORPO_FRUTA);
    gotoxy(fruta->x2, fruta->y);
    printf("%c", CORPO_FRUTA);
    gotoxy(fruta->x, fruta->y);
    printf("%c", CORPO_FRUTA);
    gotoxy(fruta->x2, fruta->y);
    printf("%c", CORPO_FRUTA);
}

void desenhar_obstaculos(COBRA *cobra, MONITOR *monitor, FRUTA *fruta, OBSTACULOS obstaculo [])
{

    int i;
    textcolor(RED);
    srand(time(NULL));

    for( i = 0 ; i < TOTAL_OBSTACULOS ; i++ )
    {

        gotoxy(obstaculo[i].x, obstaculo[i].y);
        printf("   ");
        gotoxy(obstaculo[i].x, obstaculo[i].y + 1);
        printf("   ");
        gotoxy(obstaculo[i].x, obstaculo[i].y + 2);
        printf("   ");

        do
        {

            obstaculo[i].x = rand()%monitor->maximo_janela.X;
            obstaculo[i].y = rand()%monitor->maximo_janela.Y;
    
        }
        while(validar_obstaculos(cobra, fruta, obstaculo, i, monitor));

        gotoxy(obstaculo[i].x, obstaculo[i].y);
        printf("***");
        gotoxy(obstaculo[i].x, obstaculo[i].y + 1);
        printf("***");
        gotoxy(obstaculo[i].x, obstaculo[i].y + 2);
        printf("***");
        gotoxy(obstaculo[i].x, obstaculo[i].y);
        printf("***");
        gotoxy(obstaculo[i].x, obstaculo[i].y + 1);
        printf("***");
        gotoxy(obstaculo[i].x, obstaculo[i].y + 2);
        printf("***");
    }


}



void info(COBRA *cobra, MONITOR *monitor)
{
    int meiox;

    meiox = monitor->maximo_janela.X / 2;
    textcolor(WHITE);

    gotoxy(meiox - 4, 1);
    printf("score = %d", cobra->score);

}

void jogar(COBRA *cobra, MONITOR *monitor, FRUTA *fruta, OBSTACULOS *obstaculo)
{
    EVENTO tecla;
    int novo_X;
    int novo_y;
    int antigo_x;
    int antigo_y;

    int primeiro_x;
    int primeiro_y;

    int direcao = 6; /*definindo direcao iniciao como para baixo*/

    int conta_velocidade = 0;
    cobra->velocidade = VELOCIDADE_INICIAL;
    

    
    do
    {
        timeBeginPeriod(1);
        info(cobra, monitor);

        if( verificar_colisao_borda( cobra, monitor ) )
        {
            break;
        }

        if( verificar_colisao_obstaculo ( cobra, obstaculo))
        {
            break;
        }

        if( verifcar_colisao_fruta ( cobra, fruta) )
        {

            incrementar_cobra(cobra, primeiro_x, primeiro_y);
            desenhar_fruta(cobra, monitor, fruta);
            desenhar_obstaculos(cobra, monitor, fruta, obstaculo);

            cobra->score = cobra->tamanho - TAMANHO_COBRA_INCIAL;

            if(cobra->velocidade >= 4)
            {
                cobra->velocidade = cobra->velocidade - 2;
            }
            
            
        }

        if(hit(KEYBOARD_HIT))
        {
            tecla = Evento();
        
            if ( tecla.tipo_evento & KEY_EVENT ) 
            {

                

                if(tecla.teclado.codigo_tecla == BAIXO && tecla.teclado.status_tecla == LIBERADA)
                {
                    if(direcao == DIRECAO_CIMA)
                    {
                        continue;
                    }
                    direcao = DIRECAO_BAIXO;
                }

                if(tecla.teclado.codigo_tecla == CIMA && tecla.teclado.status_tecla == LIBERADA)
                {
                    if(direcao == DIRECAO_BAIXO)
                    {
                        continue;
                    }
                    direcao = DIRECAO_CIMA;
                }

                if(tecla.teclado.codigo_tecla == DIREITA && tecla.teclado.status_tecla == LIBERADA)
                {
                    if(direcao == DIRECAO_ESQUERDA)
                    {
                        continue;
                    }
                    direcao = DIRECAO_DIREITA;
                }

                if(tecla.teclado.codigo_tecla == ESQUERDA && tecla.teclado.status_tecla == LIBERADA)
                {
                    if(direcao == DIRECAO_DIREITA)
                    {
                        continue;
                    }
                    direcao = DIRECAO_ESQUERDA;
                }

                if (tecla.teclado.codigo_tecla == ESC)
                {
                    break;
                }

            }
        }

        if(conta_velocidade >= cobra->velocidade)
        {

            
            
            if(direcao == DIRECAO_BAIXO)
            {
                
                textcolor(MAGENTA);
                CORPO *inicio;
                inicio = cobra->inicio;
                while(inicio != NULL)
                {
                    gotoxy(inicio->x, inicio->y);
                    printf(" ");
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }


                inicio = cobra->inicio;
                textcolor(MAGENTA);
                
                
                novo_X = inicio->x;
                novo_y = inicio->y + 1;

                primeiro_x = inicio->x;
                primeiro_y = inicio->y;
        
                    
                while(inicio != NULL)
                {

                    gotoxy(novo_X, novo_y);
                    printf("%c", CORPO_COBRA);

                    antigo_x = inicio->x;
                    antigo_y = inicio->y;
                            
                    inicio->x = novo_X;
                    inicio->y = novo_y;

                    novo_X = antigo_x;
                    novo_y = antigo_y;
                            
                    inicio = inicio->proximo;

                    textcolor(GREEN);
                }

            }


            if(direcao == DIRECAO_DIREITA)
            {
              


                textcolor(MAGENTA);
                CORPO *inicio;
                inicio = cobra->inicio;
                while(inicio != NULL)
                {
                    gotoxy(inicio->x, inicio->y);
                    printf(" ");
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }


                inicio = cobra->inicio;
                textcolor(MAGENTA);
                
                novo_X = inicio->x + 2;
                novo_y = inicio->y;
        

                primeiro_x = inicio->x;
                primeiro_y = inicio->y;
                    
                while(inicio != NULL)
                {

                    gotoxy(novo_X, novo_y);
                    printf("%c", CORPO_COBRA);

                    antigo_x = inicio->x;
                    antigo_y = inicio->y;
                            
                    inicio->x = novo_X;
                    inicio->y = novo_y;

                    novo_X = antigo_x;
                    novo_y = antigo_y;
                            
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }

            }


            if(direcao == DIRECAO_CIMA)
            {
               


                textcolor(MAGENTA);
                CORPO *inicio;
                inicio = cobra->inicio;
                while(inicio != NULL)
                {
                    gotoxy(inicio->x, inicio->y);
                    printf(" ");
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }


                inicio = cobra->inicio;
                textcolor(MAGENTA);
                    
                novo_X = inicio->x;
                novo_y = inicio->y - 1;
            

                primeiro_x = inicio->x;
                primeiro_y = inicio->y;
                        
                while(inicio != NULL)
                {

                    gotoxy(novo_X, novo_y);
                    printf("%c", CORPO_COBRA);

                    antigo_x = inicio->x;
                    antigo_y = inicio->y;
                                
                    inicio->x = novo_X;
                    inicio->y = novo_y;

                    novo_X = antigo_x;
                    novo_y = antigo_y;
                                
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }

            }


            if(direcao == DIRECAO_ESQUERDA)
            {
               


                textcolor(MAGENTA);
                CORPO *inicio;
                inicio = cobra->inicio;
                while(inicio != NULL)
                {
                    gotoxy(inicio->x, inicio->y);
                    printf(" ");
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }


                inicio = cobra->inicio;
                textcolor(MAGENTA);
                
                novo_X = inicio->x - 2;
                novo_y = inicio->y;
        

                primeiro_x = inicio->x;
                primeiro_y = inicio->y;

                    
                while(inicio != NULL)
                {

                    gotoxy(novo_X, novo_y);
                    printf("%c", CORPO_COBRA);

                    antigo_x = inicio->x;
                    antigo_y = inicio->y;
                            
                    inicio->x = novo_X;
                    inicio->y = novo_y;

                    novo_X = antigo_x;
                    novo_y = antigo_y;
                            
                    inicio = inicio->proximo;
                    textcolor(GREEN);
                }

            }

            conta_velocidade = 0;
        }

    
    Sleep(1);
    conta_velocidade++; 
    
    }while(1);
    timeEndPeriod(1);
}



int  verificar_colisao_borda(COBRA *cobra, MONITOR *monitor)
{
    int a = 0;
    CORPO *inicio;
    inicio = cobra->inicio;

    if(inicio->x <= 1)
    {
        a = 1;
    }

    if(inicio->x >= monitor->maximo_janela.X)
    {
        a = 1;
    }

    if(inicio->y <= 1)
    {
        a = 1;
    }

    if(inicio->y >= monitor->maximo_janela.Y)
    {
        a = 1;
    }


    return a;

}

int validar_fruta(COBRA *cobra, FRUTA *fruta, MONITOR *monitor)
{

    int a = 0;

    CORPO *inicio;
    inicio = cobra->inicio;

    while(inicio != NULL)
    {

        if(fruta->x >= inicio->x - 20 && fruta->x <= inicio->x + 20 && fruta->y >= inicio->y - 20 && fruta->y <= inicio->y + 20)
        {
            a = 1;
        }
        
        inicio = inicio->proximo;

    }

    if(fruta->x <= DISNTANCIA_FRUTA_X)
    {
        a = 1;
    }

    if(fruta->x >= monitor->maximo_janela.X - DISNTANCIA_FRUTA_X)
    {
        a = 1;
    }

    if(fruta->y < DISNTANCIA_FRUTA_Y)
    {
        a = 1;
    }

    if(fruta->y > monitor->maximo_janela.Y - DISNTANCIA_FRUTA_Y)
    {
        a = 1;
    }

    return a;
}


int verifcar_colisao_fruta (COBRA *cobra, FRUTA *fruta)
{

    int a = 0;
    CORPO *inicio;
    inicio = cobra->inicio;

    if(inicio->x == fruta->x && inicio->y == fruta->y)
    {
        a = 1;
    }

    if(inicio->x == fruta->x2 && inicio->y == fruta->y)
    {
        a = 1;
    }



    return a;

}

int validar_obstaculos(COBRA *cobra, FRUTA *fruta, OBSTACULOS obstaculo[], int j, MONITOR *monitor)
{

    int i;
    int a = 0;
    int difx;
    int dify;
    CORPO *inicio;
    inicio = cobra->inicio;
    for( i = 0 ; i < j; i++ )
    {
        difx = 0;
        dify = 0;

        if(obstaculo[j].x >= obstaculo[i].x)
        {
            difx = obstaculo[j].x - obstaculo[i].x;
        }
        else
        {
            difx = obstaculo[i].x - obstaculo[j].x; 
        }

        if(obstaculo[j].y >= obstaculo[i].y)
        {
            dify = obstaculo[j].y - obstaculo[i].y;
        }
        else
        {
            dify = obstaculo[i].y - obstaculo[j].y;
        }

        if(difx <= DISTANCIA_ENTRE_OBSTCULOS && dify <= DISTANCIA_ENTRE_OBSTCULOS)
        {
            a = 1;
        }
        
    }

    if(obstaculo[j].x <= DISNTANCIA_OBSTACULOS)
    {
        a = 1;
    }

    if(obstaculo[j].x >= monitor->maximo_janela.X - DISNTANCIA_OBSTACULOS)
    {
        a = 1;
    }

    if(obstaculo[j].y <= DISNTANCIA_OBSTACULOS)
    {
        a = 1;
    }

    if(obstaculo[j].y >= monitor->maximo_janela.Y - DISNTANCIA_OBSTACULOS)
    {
        a = 1;
    }
    

    while(inicio != NULL)
    {
        difx = 0;
        dify = 0;

        if(obstaculo[j].x >= inicio->x)
        {
            difx = obstaculo[j].x - inicio->x;
        }
        else
        {
            difx = inicio->x - obstaculo[j].x;
        }

        if(obstaculo[j].y >= inicio->y)
        {
            dify = obstaculo[j].y - inicio->y;
        }
        else
        {
            dify = inicio->y - obstaculo[j].y;
        }

        if(difx <= DISTANCIA_ENTRE_OBSTCULOS && dify <= DISTANCIA_ENTRE_OBSTCULOS)
        {
            a = 1;
        }

        inicio = inicio->proximo;
    }

    difx = 0;
    dify = 0;

    if(obstaculo[j].x >= fruta->x)
    {
        difx = obstaculo[j].x - fruta->x;
    }
    else
    {
        difx = fruta->x - obstaculo[j].x;
    }

    if(obstaculo[j].y >= fruta->y)
    {
        dify = obstaculo[j].y - fruta->y;
    }
    else
    {
        dify = fruta->y - obstaculo[j].y;
    }


    if(difx <= DISTANCIA_ENTRE_OBSTCULOS && dify <= DISTANCIA_ENTRE_OBSTCULOS)
    {
        a = 1;
    }

    return a;

}


int verificar_colisao_obstaculo(COBRA *cobra, OBSTACULOS *obstaculo)
{
    int a = 0;

    int i;
    int x, y;

    CORPO *inicio;
    inicio = cobra->inicio;

    for( i = 0 ; i < TOTAL_OBSTACULOS ; i++)
    {

        for( x = 0 ; x < 3 ; x++ )
        {
            
            for( y = 0 ; y < 3; y++ )
            {

                if( inicio->x == obstaculo[i].x + x && inicio->y == obstaculo[i].y + y)
                {
                    a = 1;
                }

            }

        }

    }
    

    return a;
}



void fim (COBRA *cobra, MONITOR *monitor)
{
    int meiox;
    int meioy;

    clrscr();

    meiox = monitor->maximo_janela.X / 2;
    meioy = monitor->maximo_janela.Y / 2;

    gotoxy(meiox - 9, meioy);
    printf("FIM DE JOGO !");
    gotoxy(meiox - 8, meioy - 2);
    printf("score = %d", cobra->score);

    Sleep(3000);

}



/*gcc -o cobrinha_v1.exe cobrinha_v1.c console_v1.5.4.c conio_v3.2.4.c -Wall -pedantic -Wextra -Werror*/





/*gcc -o cobrinha_v1.exe cobrinha_v1.c console_v1.5.4.c conio_v3.2.4.c -Wall -Wextra -Werror -lwinmm*/