#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define ACIMA 72
#define ABAIXO 80
#define ESC 27

void SetColor(int ForgC)//  FUN�AO PARA MUDAR AS CORES
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void HideCursor()//ESCONDE O CURSOR
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void posicao(int linha,int coluna)//   FUN�AO BASE PARA COLOCAR AS COISAS NOS LUGARES
{
    COORD p={linha,coluna};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
void bola(int x, int y)// IMPRIME A BOLA
{
    posicao(x,y);
    SetColor(15);
    printf("%c", 254);
}
void apagabola(int x, int y)// APAGA A BOLA ANTES DE ATUALIZAR A POSI�AO DELA
{
    posicao(x,y);
    printf(" ");
}
void jogador1_baixo(int linha_j1, int cor)// MOVE JOGADOR 1 PARA BAIXO
{
    int limiteinf=17;
    SetColor(cor);
    posicao(1, linha_j1-1);
    printf(" ");

    posicao(1,linha_j1);
    printf("%c", 178);

    posicao(1, linha_j1+1);
    printf("%c", 178);

    posicao(1, linha_j1+2);
    printf("%c", 178);

    if(linha_j1<limiteinf)
    {
    
        posicao(1, linha_j1+3);
        printf(" ");
    }
}
void jogador1_cima(int linha_j1, int cor)// MOVE JOGADOR 1 PARA CIMA
{
    int limitesup=1;
    SetColor(cor);
    posicao(1,linha_j1);
    printf("%c", 178);

    posicao(1, linha_j1+1);
    printf("%c", 178);

    posicao(1, linha_j1+2);
    printf("%c", 178);

    posicao(1, linha_j1+3);
    printf(" ");
    if(linha_j1>limitesup)
    {
        posicao(1, linha_j1-1);
        printf(" ");
    }
}
void jogador2_baixo(int linha_j2, int cor)// MOVE JOGADOR 2 PARA BAIXO
{
    int limiteinf=17;
    SetColor(cor);
    posicao(58, linha_j2-1);
    printf(" ");

    posicao(58,linha_j2);
    printf("%c", 178);

    posicao(58, linha_j2+1);
    printf("%c", 178);

    posicao(58, linha_j2+2);
    printf("%c", 178);
    if(linha_j2<limiteinf)
    {
        posicao(58, linha_j2+3);
        printf(" ");
    }
}
void jogador2_cima(int linha_j2, int cor)// MOVE JOGADOR 2 PARA CIMA
{
    int limitesup=1;
    SetColor(cor);
    posicao(58,linha_j2);
    printf("%c", 178);

    posicao(58, linha_j2+1);
    printf("%c", 178);

    posicao(58, linha_j2+2);
    printf("%c", 178);

    posicao(58, linha_j2+3);
    printf(" ");
    if(linha_j2>limitesup)
    {
        posicao(58, linha_j2-1);
        printf(" ");
    }
}
void placar (int ponto1, int ponto2, int cor1, int cor2)// IMPRIME O PLACAR NA PARTE INFERIOR
{
    posicao(15, 22);
    SetColor(15);
    printf("PLACAR:          -   ");
    posicao(27, 22);
    SetColor(cor1);
    printf("%d", ponto1);
    posicao(37, 22);
    SetColor(cor2);
    printf("%d", ponto2);
}
void imprimir_pong(int cor)//IMPRIME O "PONG" DO COME�O - DESNECESSARIO MAS FIZ PARA FICAR BONITINHO KKKKKKK
{
        int linha=3, coluna=15, c, l;
    SetColor(cor);
    ////////////////////     P    //////////////////////
    posicao(coluna, linha);
    printf("%c",201);
    for(c=coluna+1;c<coluna+8;c++)
    {
        posicao(c,linha);
        printf("%c",205);
    }
    for(l=linha+1;l<linha+3;l++)
    {
        posicao(coluna, l);
        printf("%c", 186);
    }
    posicao(coluna, linha+3);
    printf("%c",204);
    for(c=coluna+1;c<coluna+8;c++)
    {
        posicao(c,linha+3);
        printf("%c",205);
    }
    for(l=linha+4;l<linha+7;l++)
    {
        posicao(coluna, l);
        printf("%c", 186);
    }
    posicao(coluna+8, linha);
    printf("%c",187);
    posicao(coluna+8, linha+3);
    printf("%c",188);
    for(l=linha+1;l<linha+3;l++)
    {
        posicao(coluna+8, l);
        printf("%c", 186);
    }
    ///////////////////     0      ///////////////
    posicao(coluna+10, linha);
    printf("%c",201);
    for(l=linha+1;l<linha+6;l++)
    {
        posicao(coluna+10, l);
        printf("%c", 186);
    }
    for(l=linha+1;l<linha+6;l++)
    {
        posicao(coluna+18, l);
        printf("%c", 186);
    }
    posicao(coluna+10, linha+6);
    printf("%c", 200);
    for(c=coluna+11;c<coluna+18;c++)
    {
        posicao(c,linha);
        printf("%c",205);
    }
    for(c=coluna+11;c<coluna+18;c++)
    {
        posicao(c,linha+6);
        printf("%c",205);
    }
    posicao(coluna+18,linha);
    printf("%c",187);
    posicao(coluna+18,linha+6);
    printf("%c",188);
///////////////////////     N       ///////////
    posicao(coluna+20, linha);
    printf("%c",201);
    for(l=linha+1;l<linha+7;l++)
    {
        posicao(coluna+20, l);
        printf("%c", 186);
    }
    for(l=linha+1;l<linha+7;l++)
    {
        posicao(coluna+29, l);
        printf("%c", 186);
    }
    posicao(coluna+29, linha);
    printf("%c",187);
    for(c=coluna+21;c<coluna+29;c++)
    {
        posicao(c,linha);
        printf("%c",205);
    }
////////////////////    G    //////////////////
    posicao(coluna+31, linha);
    printf("%c",201);
    for(l=linha+1;l<linha+6;l++)
    {
        posicao(coluna+31, l);
        printf("%c", 186);
    }
    posicao(coluna+31, linha+6);
    printf("%c",200);
    for(c=coluna+32;c<coluna+39;c++)
    {
        posicao(c,linha+6);
        printf("%c",205);
    }
    posicao(coluna+39,linha+6);
    printf("%c",188);
    for(l=linha+5;l>linha+3;l--)
    {
        posicao(coluna+39, l);
        printf("%c", 186);
    }
    for(c=coluna+36;c<coluna+39;c++)
    {
        posicao(c,linha+3);
        printf("%c",205);
    }
    posicao(coluna+39,linha+3);
    printf("%c",187);
    for(c=coluna+32;c<coluna+40;c++)
    {
        posicao(c,linha);
        printf("%c",205);
    }
}
void imprimir_gol(int coluna, int linha, int cor)// IMPRIME O AVISO DE "GOL" QUANDO TEM GOL -- DESNECESSARIO MAS FIZ PARA FICAR BONITINHO KKKKKKK
{
    posicao(20,7);
    SetColor(cor);
    printf("%c", 201);

   for(coluna=21;coluna<26;coluna++)
    {
        posicao(coluna,7);
        printf("%c",205);
    }

    for(linha=8;linha<13;linha++)
    {
        posicao(20, linha);
        printf("%c", 186);
    }

    posicao(20, 13);
    printf("%c", 200);

    for(coluna=21;coluna<25;coluna++)
    {
        posicao(coluna,13);
        printf("%c",205);
    }
    posicao(25,13);
    printf("%c", 188);
    posicao(25,12);
    printf("%c", 186);
    posicao(25,11);
    printf("%c", 187);
    posicao(24,11);
    printf("%c", 205);
    /////////////////     O   /////////// ///////////
    posicao(27,7);
    printf("%c", 201);

    for(coluna=28;coluna<33;coluna++)
    {
        posicao(coluna,7);
        printf("%c",205);
    }
    for(linha=8;linha<13;linha++)
    {
        posicao(27, linha);
        printf("%c", 186);
    }
    posicao(27,13);
    printf("%c",200);

    for(coluna=28;coluna<33;coluna++)
    {
        posicao(coluna,13);
        printf("%c",205);
    }
    for(linha=8;linha<13;linha++)
    {
        posicao(33, linha);
        printf("%c", 186);
    }
    posicao(33, 7);
    printf("%c", 187);
    posicao(33, 13);
    printf("%c", 188);

    ////////////////   L   ////////////////

    for(linha=7;linha<13;linha++)
    {
        posicao(35, linha);
        printf("%c", 186);
    }
    posicao(35,13);
    printf("%c",200);

    for(coluna=36;coluna<41;coluna++)
    {
        posicao(coluna,13);
        printf("%c",205);
    }
}
void imprimir_campo(int coluna)//IMPRIME O CAMPO
{
    for(coluna=0;coluna<60;coluna++)//Parte de cima
    {
        posicao(coluna,0);
        SetColor(14);
        printf("%c",219);
    }

    for(coluna=0;coluna<60;coluna++)//Parte de baixo
    {
        posicao(coluna, 20);
        SetColor(14);
        printf("%c",219);
    }
    posicao(61,2);
    SetColor(15);
    printf("ESC - sair");//AVISOS NO CANTO DA TELA
    posicao(61,4);
    printf("R   - recomecar");//AVISOS NO CANTO DA TELA
}
void cores()//PALHETA DE CORES PARA O MENU DE SELE�AO DE CORES DOS JOGADORES
{
    posicao(2, 10);
    printf("Digite o respectivo numero da cor...\n\n");
    SetColor(9);
    printf("\n\n\t9");
    SetColor(10);
    printf("\t10");
    SetColor(11);
    printf("\t11");
    SetColor(12);
    printf("\t12");
    SetColor(13);
    printf("\t13");
    SetColor(14);
    printf("\t14");
    SetColor(15);
    printf("\t15");
}
main ()
{
   int linha, coluna, linha_j1=10, linha_j2=10, tecla,velocidade, fim=2, limiteinf=20, limitesup=0, x, y, direcaoy=-1, direcaox=-1, ponto1=0, ponto2=0, restart=2, cor1, cor2;
    HideCursor();
    posicao(45, 13);
    printf("Carregando...");//NEM TA CARREGANDO MAS PARECE MAIS REAL
    imprimir_pong(9);//MUDA A COR Q TA ESCRITO PONG
    Sleep(500);
    imprimir_pong(10);//TB/
    Sleep(500);
    imprimir_pong(11);//TBM
    Sleep(500);
    imprimir_pong(12);//TBM
    Sleep(500);
    imprimir_pong(13);//TBM
    Sleep(500);
    imprimir_pong(14);//TBM
    Sleep(500);
    imprimir_pong(15);//TBM
    Sleep(500);
    system("cls");
    posicao(15,2);
    SetColor(15);
    printf("Bem vindo ao pong!!!");//TELA INICIAL
    posicao(2,5);
    printf("Instrucoes:\n\tJogador 1: W - andar para cima.\n\t           S - andar para baixo.\n\n");
    printf("\tJogador 2: Seta para cima - andar para cima.\n\t           Seta para baixo - andar para baixo.\n\n");
    printf("\t****NAO VALE SEGURAR O BOTAO PARA MOVIMENTAR AS RAQUETES****\n\n");;
    printf("Pressione qualquer tecla para continuar...");
    getch();
    system("cls");
    cores();
    posicao(2,2);
    printf("Escolha a cor do Jogador 1\t");//MENU PARA ESCOLHER AS CORES (JOGADOR 1)
    scanf("%d", &cor1);
    posicao(2,4);
    printf("Escolha a cor do Jogador 2\t");//MENU PARA ESCOLHER AS CORES (JOGADOR 2)
    scanf("%d", &cor2);
    system("cls");
    printf("\n\tEm qual dificuldade voce gostaria de jogar?\n\nDigite: [1] Para facil.\n\n        [2] Para moderado.\n\n        [3] Para dificil.\n\n    Opcao:");
    scanf("%d", &velocidade);//ESCOLHER A VELOCIDADE DA BOLINHA
    system("cls");
    if(velocidade==1)
        velocidade=100;
    if(velocidade==2)
        velocidade=75;
    if(velocidade==3)
        velocidade=50;
    printf("\n\nO primeiro a marcar 7 gols vence, boa sorte aos jogadores!!!\n\nPressione qualquer tecla para comecar...");
    getch();
    imprimir_campo(coluna);//imprime o campo
    jogador1_cima(linha_j1, cor1);//imprime o jogador 1
    jogador2_cima(linha_j2, cor2);//imprime o jogador 2

    while(fim!=0)//COME�O DO JOGO
    {
        system("cls");
        imprimir_campo(coluna);//imprime campo
        linha_j1=9;//coloca o jogador 1 na linha 9
        linha_j2=9;//coloca o jogador 2 na linha 9
        jogador1_cima(linha_j1, cor1);
        jogador2_cima(linha_j2, cor2);
        x=30;
        y = 2 + ( rand() % 17 );           //SEMPRE COME�A DE ALGUMA ALTURA ALEATORIA MAS SEMPRE NO MEIO DO CAMPO
        placar(ponto1, ponto2, cor1, cor2);
        restart=0;
        getch()                                                         ;

        while (restart==0)
       {
            apagabola(x,y);//APAGA A BOLA ANTES DE ATUALIZAR A POSI��O DELA
            y=y+direcaoy;//ATUALIZA Y
            x=x+direcaox;//ATUALIZA X
            bola(x,y);//IMPRIME BOLA COM POSI��O ATUALIZADA

            if(y<=limitesup+1)//PARA REBATER A BOLINHA NA PARTE DE CIMA DO CAMPO
            {
                direcaoy=+1;
            }

            if(y>=limiteinf-1)//REBATER A BOLINHA NA PARTE DE BAIXO DO CAMPO
            {
                direcaoy=-1;
            }

            if(y==linha_j1 && x==2 || y==linha_j1+1 && x==2 || y==linha_j1+2 && x==2)//REBATE BOLINHA NA RAQUETE DO JOGADOR 1
            {
                direcaox=+1;
            }

            if(y==linha_j2 && x==57|| y==linha_j2+1 && x==57|| y==linha_j2+2 && x==57)//REBATE BOLINHA NA RAQUETE DO JOGADOR 2
            {
                direcaox=-1;
            }

            if(x<2)//GOL DO JOGADOR 2
            {
                ponto2=ponto2+1;
                restart=2;
            }

            if(x>58)//GOL DO JOGADOR 1
            {
                ponto1=ponto1+1;
                restart=1;
            }

            if (kbhit())//MOVIMENTO DAS RAQUETES
            {
                tecla = getch();
                if (tecla == 's')//RAQUETE 1 PARA BAIXO
                {
                    linha_j1++;
                    if(linha_j1<limiteinf-2)
                    {
                        jogador1_baixo(linha_j1, cor1);
                    }
                    else
                    {
                        linha_j1--;
                    }
                }

                if (tecla == 'w')//RAQUETE 1 PARA CIMA
                {
                    linha_j1--;
                    if(linha_j1>limitesup)
                    {
                        jogador1_cima(linha_j1, cor1);
                    }
                    else
                    {
                        linha_j1++;
                    }
                }

                if (tecla == ABAIXO)//RAQUETE 2 PARA BAIXO,     ABAIXO � A SETA PARA BAIXO
                {
                    linha_j2++;
                    if(linha_j2<limiteinf-2)
                    {
                        jogador2_baixo(linha_j2, cor2);
                    }
                    else
                    {
                        linha_j2--;
                    }
                }
                if (tecla == ACIMA)// RAQUETE 2 PARA CIMA     ACIMA � A SETA PARA CIMA
                {
                    linha_j2--;
                    if(linha_j2>limitesup)
                    {
                        jogador2_cima(linha_j2, cor2);
                    }
                    else
                    {
                        linha_j2++;
                    }
                }
                if (tecla==ESC)//OP�OES DE BOTOES Q FAZEM ALGUMA COISA- ACABA O JOGO
                {
                    return 0;
                }
                if(tecla=='r')//RECOME�A O JOGO
                {
                    restart=3;
                    ponto1=0;
                    ponto2=0;
                }
            }
            Sleep(velocidade);
        }//apos acontecer algum GOL
        if(restart==1)//GOL DO JOGADOR 1
        {
            imprimir_gol(coluna, linha, cor1);
            direcaox=-1;
        }
        if(restart==2)//GOL DO JOGADOR 2
        {
            imprimir_gol(coluna, linha, cor2);
            direcaox=+1;
        }
        getch();
        if(ponto1==7||ponto2==7)//O JOGO SO VAI ATE 7 PONTOS
            fim=0;//QUANDO FIM =0 SAI DO LOOP WHILE

    }//fim do jogo

        if(ponto1>ponto2)
        {
            system("cls");
            posicao(20,5);
            SetColor(cor1);
            printf("Jogador 1 ganhou!!!");
        }
        else
        {
            system("cls");
            posicao(20,5);
            SetColor(cor2);
            printf("Jogador 2 ganhou!!!");
        }
    getch();
    return 0;
}