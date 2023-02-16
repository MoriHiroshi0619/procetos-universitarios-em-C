#include <windows.h>
#include <time.h>

#include "conio_v3.2.4.h"
#include "graphics_v1.1.h"
#include "console_v1.5.4.h" 

#define DISTANCIA_SUPERIOR 20
#define DISTANCIA_HORIZONTAL 30
#define BARRA_X 20
#define BARRA_y 160
#define RAIO_BOLA 10


#define SHIFT 16
#define ALT 18

void imprimir_barra1(int *, int *);
void imprimir_barra2(int *, int *);
void imprimir_bola(int *, int *);

void jogo(int *, int *, int *, int, int *, int *, int *, int*, int);

int main(int argc, char *argv[])
{
    int barra1x, barra1y;
    int barra2x, barra2y;
    int bola_x, bola_y, bola_sentido;
    COORD maximo_janela;
    COORD fonte;
    int maximo_x;
    int maximo_y;

    argc = argc;
	argv = argv;

    maximo_janela = MaxDimensaoJanela();
    fonte = getTamanhoFonteConsole();

    barra1x = DISTANCIA_HORIZONTAL;
    barra1y = DISTANCIA_SUPERIOR;
    barra2x = (maximo_janela.X * fonte.X) - DISTANCIA_HORIZONTAL;
    barra2y = DISTANCIA_SUPERIOR;
    maximo_x = maximo_janela.X * fonte.X;
    maximo_y = maximo_janela.Y * fonte.Y;
    bola_x = maximo_x / 2;
    bola_y = maximo_y / 2;

    srand(time(NULL));
    bola_sentido = rand()%6 + 1;
    
    clrscr();
    setTituloConsole("PONG");
    setPosicaoJanela(0,0);
    setDimensaoJanela(maximo_janela.X, maximo_janela.Y);
    setCursorStatus(DESLIGAR);

    imprimir_barra1(&barra1x, &barra1y);
    imprimir_barra2(&barra2x, &barra2y);
    imprimir_bola(&bola_x, &bola_y);
    jogo(&bola_x, &bola_y, &bola_sentido, maximo_y, &barra1x, &barra1y, &barra2x, &barra2y, maximo_x);
    
    return 0;
}

void imprimir_barra1(int *barra1x, int *barra1y)
{
    linha(*barra1x, *barra1y, *barra1x + BARRA_X, *barra1y, RGB(255,255,255));
    linha(*barra1x, *barra1y, *barra1x, *barra1y + BARRA_y, RGB(255,255,255));
    linha(*barra1x + BARRA_X, *barra1y, *barra1x + BARRA_X, *barra1y + BARRA_y, RGB(255,255,255));
    linha(*barra1x, *barra1y + BARRA_y, *barra1x + BARRA_X, *barra1y + BARRA_y, RGB(255,255,255));
}

void imprimir_barra2(int *barra2x, int *barra2y)
{
    linha(*barra2x, *barra2y, *barra2x - BARRA_X, *barra2y, RGB(255,255,255));
    linha(*barra2x, *barra2y, *barra2x, *barra2y + BARRA_y, RGB(255,255,255));
    linha(*barra2x - BARRA_X, *barra2y, *barra2x - BARRA_X, *barra2y + BARRA_y, RGB(255,255,255));
    linha(*barra2x, *barra2y + BARRA_y, *barra2x - BARRA_X, *barra2y + BARRA_y, RGB(255,255,255));
}

void imprimir_bola(int *bola_x, int *bola_y)
{
    circulo(*bola_x, *bola_y, RAIO_BOLA, RGB(255,0,0));
}

void jogo(int *bola_x, int *bola_y, int *bola_sentido, int maximo_y, int *barra1x, int *barra1y, int *barra2x, int *barra2y, int maximo_x)
{
    EVENTO teclado;

    do
    {

        /*verifica se tem um vencedor*/
        if(*bola_x < 0)
        {
            break;
        }
        if(*bola_x >  maximo_x)
        {
            break;
        }


        /*apago a bola*/
        circulo(*bola_x, *bola_y, RAIO_BOLA, RGB(12,12,12));


        /*verificar colisao superior*/
        if(*bola_y < RAIO_BOLA * 2)
        {
            if(*bola_sentido == 5)
            {
                *bola_sentido = 3;
            }
            else
            {
                *bola_sentido = 4;
            }
        }

        /*verifico colisao inferior*/
        if(*bola_y > maximo_y)
        {
            if(*bola_sentido == 3)
            {
                *bola_sentido = 5;
            }
            else
            {
                *bola_sentido = 6;
            }
        }



        /*colisao borda de cima barra 1*/
        if(*bola_x <= *barra1x + BARRA_X && *bola_x > *barra1x && *bola_y >= *barra1y && *bola_y <= *barra1y + 60)
        {
            *bola_sentido = 5;
        }

        /*colisao borda do meio barra 1*/
        if(*bola_x <= *barra1x + BARRA_X && *bola_x > *barra1x && *bola_y >= *barra1y + 60 && *bola_y <= *barra1y + 100)
        {
            *bola_sentido = 1;
        }

        /*colisao borda de baixo barra 1*/
        if(*bola_x <= *barra1x + BARRA_X && *bola_x > *barra1x && *bola_y >= *barra1y + 100 && *bola_y <= *barra1y + 160)
        {
            *bola_sentido = 3;
        }

        /*colisao borda de cima barra 2*/
        if(*bola_x >= *barra2x - BARRA_X && *bola_x < *barra2x && *bola_y >= *barra2y && *bola_y <= *barra2y + 60)
        {
            *bola_sentido = 6;
        }

        /*colisao borda do meio barra 2*/
        if(*bola_x >= *barra2x - BARRA_X && *bola_x < *barra2x && *bola_y >= *barra2y + 60 && *bola_y <= *barra2y + 100)
        {
            *bola_sentido = 2;
        }


        /*colisao borda de baixo barra 2*/
        if(*bola_x >= *barra2x - BARRA_X && *bola_x < *barra2x && *bola_y >= *barra2y + 100 && *bola_y <= *barra2y + 160)
        {
            *bola_sentido = 4;
        }




        switch (*bola_sentido)
        {
            case 1: /*->*/
                *bola_x = *bola_x + 10; 
                break;
            case 2: /*<-*/
                *bola_x = *bola_x - 10; 
                break;
            case 3: /**/
                *bola_x = *bola_x + 10;
                *bola_y = *bola_y + 10; 
                break;
            case 4: /**/
                *bola_x = *bola_x - 10;
                *bola_y = *bola_y + 10;
                break;
            case 5: /**/
                *bola_x = *bola_x + 10;
                *bola_y = *bola_y - 10;
                break;
            case 6: /**/
                *bola_x = *bola_x - 10;
                *bola_y = *bola_y - 10;
                break;
            default :
                break;
        }  

        circulo(*bola_x, *bola_y, RAIO_BOLA, RGB(255,0,0));


        if(hit(KEYBOARD_HIT))
        {
            teclado = Evento();
            if(teclado.teclado.status_tecla == PRESSIONADA)
            {
                if(teclado.teclado.status_teclas_controle & LEFT_ALT_PRESSED && *barra1y <= maximo_y - BARRA_y)
                {
                    linha(*barra1x, *barra1y, *barra1x + BARRA_X, *barra1y, RGB(12,12,12));
                    linha(*barra1x, *barra1y, *barra1x, *barra1y + BARRA_y, RGB(12,12,12));
                    linha(*barra1x + BARRA_X, *barra1y, *barra1x + BARRA_X, *barra1y + BARRA_y, RGB(12,12,12));
                    linha(*barra1x, *barra1y + BARRA_y, *barra1x + BARRA_X, *barra1y + BARRA_y, RGB(12,12,12));

                    *barra1y = *barra1y + 20;

                    imprimir_barra1(barra1x, barra1y);
                }
                else if(teclado.teclado.status_teclas_controle & SHIFT_ESQUERDO_PRESSIONADO && *barra1y >= DISTANCIA_SUPERIOR)
                {
                    linha(*barra1x, *barra1y, *barra1x + BARRA_X, *barra1y, RGB(12,12,12));
                    linha(*barra1x, *barra1y, *barra1x, *barra1y + BARRA_y, RGB(12,12,12));
                    linha(*barra1x + BARRA_X, *barra1y, *barra1x + BARRA_X, *barra1y + BARRA_y, RGB(12,12,12));
                    linha(*barra1x, *barra1y + BARRA_y, *barra1x + BARRA_X, *barra1y + BARRA_y, RGB(12,12,12));

                    *barra1y = *barra1y - 20;

                    imprimir_barra1(barra1x, barra1y);
                }

                if(teclado.teclado.status_teclas_controle & SHIFT_DIREITO_PRESSIONADO && *barra2y <= maximo_y - BARRA_y)
                {
                    linha(*barra2x, *barra2y, *barra2x - BARRA_X, *barra2y, RGB(12,12,12));
                    linha(*barra2x, *barra2y, *barra2x, *barra2y + BARRA_y, RGB(12,12,12));
                    linha(*barra2x - BARRA_X, *barra2y, *barra2x - BARRA_X, *barra2y + BARRA_y, RGB(12,12,12));
                    linha(*barra2x, *barra2y + BARRA_y, *barra2x - BARRA_X, *barra2y + BARRA_y, RGB(12,12,12));

                    *barra2y = *barra2y - 20;

                    imprimir_barra2(barra2x, barra2y);
                }
                else if(teclado.teclado.status_teclas_controle & RIGHT_ALT_PRESSED && *barra2y >= DISTANCIA_SUPERIOR)
                {
                    linha(*barra2x, *barra2y, *barra2x - BARRA_X, *barra2y, RGB(12,12,12));
                    linha(*barra2x, *barra2y, *barra2x, *barra2y + BARRA_y, RGB(12,12,12));
                    linha(*barra2x - BARRA_X, *barra2y, *barra2x - BARRA_X, *barra2y + BARRA_y, RGB(12,12,12));
                    linha(*barra2x, *barra2y + BARRA_y, *barra2x - BARRA_X, *barra2y + BARRA_y, RGB(12,12,12));

                    *barra2y = *barra2y + 20;

                    imprimir_barra2(barra2x, barra2y);
                }

                if(teclado.teclado.codigo_tecla == ESC)
                {
                    break;
                }
            }
        }

    Sleep(10);
    } while (1);
    clrscr(); 
}



/*gcc -o medina.exe medina.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/