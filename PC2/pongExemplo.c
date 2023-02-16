/*gcc pongExemplo.c -o pongExemplo.exe */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main()
{

    int x = 0, y = 0;
    int max_x, max_y, centro_y, centro_x;
    int ch;
    int tam_name = 0;
    char name[8] = "P O N G";
    WINDOW *win;
    WINDOW *win_home;

    initscr();                      //inicializa a tela stdscr
    noecho();                       //impede que as teclas digitadas aparecam na janela
    curs_set(FALSE);                //Abilita ou desabilita o uso do mouse na janela
    getmaxyx(stdscr, max_y, max_x); //verifica o tamanho da maximo da tela / tela principal

    win_home = newwin(0, 0, 0, 0); //Janela de apresentação
    getmaxyx(win_home, max_y, max_x);

    //-------------------------------Janela de apresentação------------------------------------------

    if (has_colors() == FALSE) //se o terminal n�o aceitar o uso de cores
    {
        endwin();
        printf("O seu terminal não suporta cores.");
        return 1;
    }

    start_color();                           //inicializando o uso das cores
    init_pair(1, COLOR_BLACK, COLOR_YELLOW); //definindo par de cores

    wbkgd(win_home, COLOR_PAIR(1)); //muda a cor do fundo da janela
    wrefresh(win_home);             //atualiza a tela

    tam_name = strlen(name);
    centro_x = ((max_x / 2) - (tam_name / 2));
    centro_y = max_y / 2;

    for (x = 0; x < max_x; x++) //linha
    {
        for (y = 0; y < max_y; y++) //coluna
        {
            mvwprintw(win_home, centro_y, centro_x, "P O N G");
            /*for(int n=1; n< 5; n++)//linha
            {
                mvwprintw(win_home, centro_y + 2, (centro_x-2) + n, "o");
                wrefresh(win_home);//atualiza a tela
                sleep(1);//tempo de duração da janela
            }*/
            wrefresh(win_home); //atualiza a tela
        }
    }
    sleep(2); //tempo de duração da janela
    // -------------------------------------------------------------------------

    win = newwin(0, 0, 0, 0);    //janela do jogo
    getmaxyx(win, max_y, max_x); //verifica o tamanho da janela

    char game[max_y][max_x]; //matriz do jogo

    //Bordas

    for (y = 0; y < max_y; y++) //colunas
    {
        for (x = 0; x < max_x; x++) //linhas
        {
            game[y][x] = ' ';
        }
    }

    for (y = 0; y < max_y; y++) //colunas
    {
        game[y][0] = 219;
        game[y][max_x - 1] = 219;
        if (y % 2 == 0)
        {
            game[y][max_x / 2] = 254;
        }
    }

    for (x = 0; x < max_x; x++) //linhas
    {
        game[0][x] = 219;
        game[max_y - 1][x] = 219;
    }

    //raquetes dos jogadores

    for (y = 0; y < 4; y++) //linhas
    {
        for (x = 0; x < 1; x++) //colunas
        {
            game[((max_y / 2) - 2) + y][2] = '|';         //coluna esquerda
            game[((max_y / 2) - 2) + y][max_x - 3] = '|'; //coluna direita
        }
    }
    wrefresh(win); //atualiza a tela

    //inicializa o jogo

    for (y = 0; y < max_y; y++) //linhas
    {
        for (x = 0; x < max_x; x++) //colunas
        {
            mvwprintw(win, y, x, "%c", game[y][x]);
            wrefresh(win);
        }
    }

    // ------------------------------mover a bolinha-------------------------------------------

    nodelay(win, TRUE); //PARA NÃO TRAVAR O PROGRAMA
    keypad(win, TRUE);

    int exit = 0;
    int boll_y = max_y / 2;
    int boll_x = max_x / 2;

    //barras
    int move_esquerda = 0;
    int move_direita = 0;
    int y_di = 0;
    int y_es = 0;

    //vence quem fez 3 pontos
    int player1 = 0;
    int player2 = 0;

    int quant_partida = 0;

    int inicia = 0; //quem inicia
    int lado = 0;
    srand(time(NULL));     //não repetir o valor
    inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
    // 0 = esquerda
    // 1 = direita
    lado = (rand() % 2);
    //0 = cima
    //1 = baixo

    //movendo a bolinha
    int cima_baixo = 0;       //cima = diminui | baixo = soma
    int direita_esquerda = 0; // esquerda = diminui | direita = soma

    while (quant_partida == 0)
    {
        ch = wgetch(win); //primeira :)

        //imprime a pontuação
        mvwprintw(win, 0, (max_x / 4), "  %d  ", player1);
        mvwprintw(win, 0, (max_x - (max_x / 4)), "  %d  ", player2);

        if (player1 != 3 && player2 != 3)
        {
            if (inicia == 0) //jogador esquerda
            {
                if (lado == 0) //cima
                {
                    if (cima_baixo > 0) //descer
                    {
                        cima_baixo = 1; //descer

                        if (boll_y != max_y - 2)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x--;
                            boll_y++;

                            if (boll_x == 0) //ponto para o jogador 2
                            {

                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (boll_x == max_x - 2) //ponto para o jogador 1
                            {

                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {

                                inicia = 1;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else //boll_y == max_y - 2
                        {
                            cima_baixo = -1; //sobe
                        }
                    }

                    if (cima_baixo <= 0) //sobe
                    {

                        cima_baixo = -1;

                        if (boll_y != 1)
                        {
                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x--;
                            boll_y--;

                            if (boll_x == 0) //marca ponto
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (boll_x == max_x - 2)
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {

                                inicia = 1;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else //boll_y == 1
                        {
                            cima_baixo = 1;
                        }
                    }
                }

                if (lado == 1) //baixo
                {

                    if (cima_baixo < 0) //sobe
                    {
                        cima_baixo = -1;

                        if (boll_y != 1)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x--;
                            boll_y--;

                            if (boll_x == 0) //marca ponto
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (boll_x == max_x - 2)
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {

                                inicia = 1;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else // boll_y == 1
                        {
                            cima_baixo = 1; //para descer
                        }
                    }
                    if (cima_baixo >= 0) //desce
                    {

                        cima_baixo = 1;

                        if (boll_y != max_y - 2)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x--;
                            boll_y++;

                            if (boll_x == 0) //marca ponto
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (boll_x == max_x - 2)
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {

                                inicia = 1;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else //boll_y == max_y - 2
                        {
                            cima_baixo = -1; //sobe
                        }
                    }
                }
            }
            // lado direito

            else // jogador direita inicia = 1
            {
                if (lado == 0) //cima
                {
                    if (cima_baixo > 0) //descer
                    {
                        cima_baixo = 1; //descer

                        if (boll_y != max_y - 2)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x++;
                            boll_y++;

                            if (boll_x == 0) //marca ponto
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (boll_x == max_x - 2)
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {

                                inicia = 0;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else //boll_y == max_y - 2
                        {
                            cima_baixo = -1; //sobe
                        }
                    }
                    if (cima_baixo <= 0) //sobe
                    {
                        cima_baixo = -1;

                        if (boll_y != 1)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x++;
                            boll_y--;

                            if (boll_x == 0) //marca ponto
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (boll_x == max_x - 2)
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {
                                inicia = 0;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else //boll_y == 1
                        {
                            cima_baixo = 1;
                        }
                    }
                }

                if (lado == 1) //baixo
                {
                    if (cima_baixo < 0) //sobe
                    {
                        cima_baixo = -1;

                        if (boll_y != 1)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x++;
                            boll_y--;

                            if (boll_x == 0) //marca ponto //1
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (boll_x == max_x - 2) 
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {
                                inicia = 0;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else // boll_y == 1
                        {
                            cima_baixo = 1; //para descer
                        }
                    }
                    if (cima_baixo >= 0) //desce
                    {

                        cima_baixo = 1;

                        if (boll_y != max_y - 2)
                        {

                            if (boll_x != max_x - 1 && boll_x != 0 && game[boll_y][boll_x] != '|')
                            {
                                game[boll_y][boll_x] = ' ';
                                mvwprintw(win, boll_y, boll_x, " ", game[boll_y][boll_x]);
                            }

                            boll_x++;
                            boll_y++;

                            if (boll_x == 0) //marca ponto
                            {
                                player2++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }
                            else if (boll_x == max_x - 2)
                            {
                                player1++;
                                boll_y = max_y / 2;
                                boll_x = max_x / 2;
                                lado = (rand() % 2);
                                inicia = (rand() % 2); //escolhe aleatoriamente um valor 0-1
                                cima_baixo = 0;
                            }

                            else if (game[boll_y][boll_x] == '|') //bolinha na barra
                            {

                                inicia = 0;
                                lado = (rand() % 2);
                                cima_baixo = 0;
                            }

                            else //boll_x != 0
                            {
                                mvwprintw(win, boll_y, boll_x, "o", game[boll_y][boll_x]);
                                usleep(110000);
                            }
                        }
                        else //boll_y == max_y - 2
                        {
                            cima_baixo = -1; //sobe
                        }
                    }
                }
            }

            //movendo as barras

            if (move_direita == 0)
            {
                y_di = (max_y / 2) - 2;
            }

            if (move_esquerda == 0)
            {
                y_es = (max_y / 2) - 2;
            }

            switch (ch)
            {

            //coluna direita
            case KEY_DOWN: //down

                if (game[max_y - 2][max_x - 3] == ' ')
                {
                    for (int j = 1; j <= 4; j++)
                    {
                        game[y_di][max_x - 3] = ' ';
                        mvwprintw(win, y_di, max_x - 3, " "); //coluna direita

                        mvwprintw(win, y_di + 4, max_x - 3, "|"); //coluna direita
                        game[y_di + j][max_x - 3] = '|';
                    }

                    y_di = y_di + 1;
                    move_direita = 1;
                }
                break;

            case KEY_UP: //up

                if (game[1][max_x - 3] == ' ')
                {
                    for (int j = 1; j <= 4; j++)
                    {

                        mvwprintw(win, y_di - 1, max_x - 3, "|"); //coluna direita
                        game[(y_di + 3) - j][max_x - 3] = '|';

                        game[y_di + 3][max_x - 3] = ' ';
                        mvwprintw(win, y_di + 3, max_x - 3, " "); //coluna direita
                    }

                    y_di = y_di - 1;
                    move_direita = 1;
                }
                break;

                //coluna esquerda

            case 119: //up (w)

                if (game[1][2] == ' ')
                {
                    for (int j = 1; j <= 4; j++)
                    {

                        mvwprintw(win, y_es - 1, 2, "|"); //coluna direita
                        game[(y_es + 3) - j][2] = '|';

                        game[y_es + 3][2] = ' ';
                        mvwprintw(win, y_es + 3, 2, " "); //coluna direita
                    }
                    y_es = y_es - 1;
                    move_esquerda = 1;
                }
                break;

            case 115: //down (s)

                if (game[max_y - 2][2] == ' ')
                {
                    for (int j = 1; j <= 4; j++)
                    {
                        game[y_es][2] = ' ';
                        mvwprintw(win, y_es, 2, " "); //coluna direita

                        mvwprintw(win, y_es + 4, 2, "|"); //coluna direita
                        game[y_es + j][2] = '|';
                    }

                    y_es = y_es + 1;
                    move_esquerda = 1;
                }

                break;

            case '\n':
                exit = 1;
            }
            wrefresh(win); //atualiza a tela 1
        }
        else
        {
            quant_partida = 1;
        }
        wrefresh(win); //atualiza a tela 1
    }
    wrefresh(win); //atualiza a tela 


  if (player1 == 3)
    {
        mvwprintw(win, centro_y, centro_x, "JOGADOR 1 GANHOU!"); //coluna direita
    }
    else
    {
        mvwprintw(win, centro_y, centro_x, "JOGADOR 2 GANHOU!"); //coluna direita
    }
    wrefresh(win); //atualiza a tela 1
        sleep(2); //tempo de duração da janela
   

    delwin(win); //fecha a janela
    endwin();    //Finaliza a janela criada, retornando a janela padr�o

    return 0;
}