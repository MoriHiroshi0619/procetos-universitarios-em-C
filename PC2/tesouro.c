#include <stdio.h> /*printf() e scanf()*/
#include <stdlib.h> /* rand()*/
#include "conio_v3.2.4.h" /*background(), textcolor(), gotoxy(), clrscr(), getch()*/
#include <time.h> /*Srand()*/
#include <Windows.h> /*Sleep()*/

#define linha1 35 /*costante para a cordenada linha 1*/
#define coluna1 5 /*costante para a cordenada coluna 1*/
#define linha2 110 /*costante para a cordenada linha 2*/
#define coluna2 30 /*costante para a cordenada coluna 2*/

#define SETA_PARA_DIREITA 77 /*costante para o valor da tecla de direcao direita*/
#define SETA_PARA_BAIXO 80 /*costante para o valor da tecla de direcao para baixo*/
#define SETA_PARA_ESQUERDA 75 /*costante para o valor da tecla de direcao esquerda*/
#define SETA_PARA_CIMA 72 /*costante para o valor da tecla de direcao para cima*/


/*gcc conio_v3.2.4.c tesouro.c -o tesouro.exe -Wall -Werror -pedantic -Wextra*/

/*tipo dos obstaculos, contendo as cordenadas x e y*/
typedef struct
{
    int x, y;
}OBSTACULOS;


/*tipo dos bonecos, contendo as cordenadas x e y + o nome de cada jogador + uma variavel dizendo se ganhou(1) ou perdeu(0)*/
typedef struct
{
	int x, y;
	char nome[20];
	int ganhou;
}BONECO;

/*tipo do tesouro, contendo as cordenadas x e y*/
typedef struct
{
	int x, y;
}TESOURO;


/*prototipo procedimento para criacao da janela principal*/
void janela();

/*prototipo procedimento para o inicio do jogo, mostrando mensagens e pergutando o nome dos jogadores*/
void inicio(BONECO[]);

/*prototipo procedimento para a criacao dos obstaculos e imprimindo ela pela primeira vez na janela definida*/
void criarObstaculo(OBSTACULOS[]);

/*prototipo funcao que retorna valor verdade se as cordenadas geradas aleatoriamente dos obstaculos sao validas ou colidem entre si*/
int validarObstaculos(OBSTACULOS[], int);

/*prototipo procedimento que imprimi os obstaculos nas posicoes salvas. (para evitar do jogador apagar elas no mapa ao passar perto)*/
void imprimirObstaculos(OBSTACULOS[]);

/*prototipo procedimento que imprimi os bonecos nas posicoes salvas. (para evitar do jogador apagar temporariamente ao se encontrarem no mapa)*/
void imprimirBoneco(BONECO[]);

/*prototipo procedimento que imprimi o tesouro(X) na posicao salva.(evita do jogador apagar ele no mapa ao passar perto)*/
void imprimirTesouro(TESOURO *);

/*prototipo procedimento para criacao dos bonecos e imprimindo eles na tela primeira vez*/
void criarBoneco(BONECO[], OBSTACULOS[]);

/*prototipo funcao que retorna valor verdade se as posicoes geradas aleatoriamente sao validar ou se colidem entre si e os obstaculos*/
int validarBoneco(BONECO[], OBSTACULOS[], int);

/*prototipo procedimento para criacao do tesouro e imprimindo ela na tela pela primeira vez*/
void criarTesouro(OBSTACULOS[], BONECO[], TESOURO *);

/*prototipo funcao que retorna valor verdade se a posicao gerada aleatoriamente e valida ou colidem entre os obstaculos e bonecos*/
int validarTesouro(OBSTACULOS[], BONECO[], TESOURO *);

/*prototipo procedimento aonde recebe as teclas de direcao e movimenta os bonecos no mapa,
tambem valida a cada passo se houve vitoria pelo tesouro ou derrota por colisao obstaculos*/
void jogar(BONECO[], OBSTACULOS[],TESOURO *);

/*prototipo funcao que retorna valor verdade se a direcao que o jogador esta apertando e valida.(nao sair de dentro do mapa e limites estabelecidos)*/
int validarMovimento(BONECO[], int, int);

/*prototipo funcao que retorna valor verdade se o jogador bateu o torco do boneco no obstaculo*/
int bateuObstaculo(BONECO[], OBSTACULOS[], int);

/*prototipo funcao que retorna valor verdade se o jogador bateu o torco no tesouro*/
int bateuTesouro(BONECO[], TESOURO *, int);

/*prototipo procedimento que imprimi na parte superior da tela atualizacoes de turnos para auxiliar o entedimento de turnos*/
void controleJogador(BONECO[], int, int);

/*prototipo procedimento que mostra na tela o nome do jogador que venceu o jogo*/
void fim(BONECO[]);

/*prototipo funcao que pergunta ao usuario se ele quer jogar o jogo novamente*/
int jogarNovamente();



int main(int argc, char *argv[])
{
	OBSTACULOS obstaculos[10]; /*criando um vetor de 10 indices do tipo OBSTACULOS*/
	BONECO boneco[2]; /*criando um vetor de 2 indices do tipo BONECO*/
	TESOURO *tesouro, t; /*criando um ponteiro e uma variavel do tipo TESOURO*/
	tesouro = &t; /*apontando o endeteco de memoria de  t para o ponteiro tesouro*/
	
	/* Artifício para silenciar warning */
	argc = argc;
	argv = argv;
	
	/*laco do while aonde o jogo sera executado no minimo uma vez e entrara em repetcao se o usuario querer jogar multiplas vezes*/
	do{
		clrscr(); /*limpar a janela do console*/
		janela(); /*gera a janela(mapa do jogo)*/
		inicio(&boneco[0]); /*mostra uma mensagem e pergunta os nomes de cada jogador*/
		clrscr(); /*limpa as mensagens*/
		criarObstaculo(&obstaculos[0]); /*gera os obstaculos no mapa*/
		criarBoneco(&boneco[0], &obstaculos[0]); /*gera os bonecos no mapa*/
		criarTesouro(&obstaculos[0], &boneco[0], tesouro); /*gera o tesouro no mapa*/
		jogar(&boneco[0], &obstaculos[0], tesouro); /*inicia a leitura de teclas para o jogador se mover no mapa*/
		clrscr(); /*limpa a tela para mostrar a mensagem final em uma janela limpa*/
		fim(&boneco[0]); /*imprimi o nome do vencedor*/
	}
	while(jogarNovamente()); /*funcao que retorna 1 se o jogador querer jogar novamente e 0 se nao*/
	return 0; /* programa encerrou com sucesso */
}

void janela()
{
	textbackground(WHITE); /*definindo cor de fundo do mapa*/
	window(linha1, coluna1, linha2, coluna2); /*definindo tamanho do mapa*/
}

void inicio(BONECO boneco[])
{
	_setcursortype(_NORMALCURSOR); /*definindo curso para o modo normal (piscar)*/
	textcolor(BLACK); /*definindo cor de texto para o preto*/
	gotoxy(1, (coluna2 - coluna1) + 1); /*definindo cordenadas para impressao de mensagem*/
	printf("aluno: Anderson Hiroshi Mori Correia."); /*mostrando meu nome na tela*/
	gotoxy(((linha2 - linha1) / 2) - 6, (coluna2 - coluna1) / 2); /*definindo cordenadas para impressao de mensagem*/
	printf("seja bem vindo !!");/*mensagem*/
	gotoxy(((linha2 - linha1) / 2) - 28, ((coluna2 - coluna1) / 2) + 1); /*definindo cordenadas para impressao de mensagem*/
	printf("seu objetivo e levar seu bonequinho ao tesouro marcado com 'X'."); /*mensagem*/
	gotoxy(((linha2 - linha1) / 2) - 27, ((coluna2 - coluna1) / 2) + 2); /*definindo cordenadas para impressao de mensagem*/
	printf("cuidado com os '*' eles podem te matar se chegar muito perto."); /*mensagem*/
	gotoxy(((linha2 - linha1) / 2) - 20, ((coluna2 - coluna1) / 2) + 3); /*definindo cordenadas para impressao de mensagem*/
	printf("por favor informe o nome do jogador 1: "); /*mensagem*/
	gotoxy(((linha2 - linha1) / 2) - 20, ((coluna2 - coluna1) / 2) + 4); /*definindo cordenadas para leitura de dados*/
	scanf("%s",boneco[0].nome); /*ler nome jogador 1*/
	gotoxy(((linha2 - linha1) / 2) - 20, ((coluna2 - coluna1) / 2) + 5); /*definindo cordenadas para impressao de mensagem*/
	printf("por favor informe o nome do jogador 2: "); /*mensagem*/
	gotoxy(((linha2 - linha1) / 2) - 20, ((coluna2 - coluna1) / 2) + 6); /*definindo cordenadas para leitura de dados*/
	scanf("%s",boneco[1].nome); /*ler nome jogador 2*/
}


void criarObstaculo(OBSTACULOS cordenadas[])
{
	int i; /*i para o laco for*/
	textcolor(RED); /*definindo cor de texto para vermelho*/
	srand(time(NULL)); /*gerar numeros aleatorios*/
	for(i=0;i<10;i++) /*10 indices de OBSTACULOS*/
	{
		/*ira gerar numeros aleatorios ate que a condicao seja falsa*/
		do
		{
			cordenadas[i].x = rand()%((linha2 - linha1) - 1) + 1; /*limitando os numeros para o limite horizontal do mapa*/
			cordenadas[i].y = rand()%((coluna2 - coluna1) - 1) + 1; /*limitando os numeros para o limite vertical do mapa*/
		}
		while(validarObstaculos(&cordenadas[0], i)); /*funcao que retorna 1 se as cordenadas forem invalidas*/
		/*imprimindo na tela obstaculo*/
		gotoxy(cordenadas[i].x, cordenadas[i].y);
		printf("***");
		gotoxy(cordenadas[i].x, cordenadas[i].y+1);
		printf("***");
		gotoxy(cordenadas[i].x, cordenadas[i].y+2);
		printf("***");
	}
}

int validarObstaculos(OBSTACULOS cordenadas[], int j)
{
	int i; /*i para o for*/
	int x = 0; /*valor vardade*/
	int difx; /*diferenda entre as cordenadas x das posicoes anteriormente geradas e a que esta sendo gerada*/
	int dify; /*diferenda entre as cordenadas y das posicoes anteriormente geradas e a que esta sendo gerada*/
	for(i=0;i<j;i++) /*j e o indice do obstaculo que esta sendo gerado no laco do while do procedimento criarObstaculo()*/
	{
		difx = 0; /*zerando*/
		dify = 0; /*zerando*/
		if(cordenadas[j].x >= cordenadas[i].x) /*condicao para definir qual x eh o maior, desse modo a diferenca sempre sera valor positivo*/
		{
			difx = cordenadas[j].x - cordenadas[i].x; /*calculando a diferenca*/
		}
		else
		{
			difx = cordenadas[i].x - cordenadas[j].x; /*calculando a diferenca*/
		}
		
		if(cordenadas[j].y >= cordenadas[i].y) /*condicao para definir qual y eh o maior, desse modo a diferenca sempre sera valor positivo*/
		{
			dify = cordenadas[j].y - cordenadas[i].y; /*calculando diferenca*/
		}
		else
		{
			dify = cordenadas[i].y - cordenadas[j].y; /*calculando diferenca*/
		}
		
		/*se a diferenca for menor que 3 isso significa que em um objeto 3x3(obstaculos, boneco) na hora de imprimir na tela,
		eles irao cobrir um ao outro em determinado momento. tentar validar a impressao apenas pela igualdade das posicoes sem calcular
		essa diferenca gera essa brecha para o programa imprimir objeto em cima de objeto*/
		if(difx <= 3 && dify <= 3) 
		{
			x = 1; /*valor verdade 1 se for invalido*/
		}
		
	}	
	
	/*outra condicao para garantir que o a cordenada y(vertival) seja maior que 2 para evitar de cobrir area de auxilio do jogo*/
	if(cordenadas[j].y <= 2)
	{
		x = 1; /*valor verdade 1 se for invalido*/
	}
	return x; /*retornando valor verdade para a condicao do while do procedimento*/
}

void imprimirObstaculos (OBSTACULOS cordenadas[])
{
	textcolor(RED); /*definindo cor de texro para vermelho*/
	int i; /*i de for */
	for(i=0;i<10;i++)
	{
		/*imprimindo obstaculos*/
		gotoxy(cordenadas[i].x, cordenadas[i].y);
		printf("***");
		gotoxy(cordenadas[i].x, cordenadas[i].y+1);
		printf("***");
		gotoxy(cordenadas[i].x, cordenadas[i].y+2);
		printf("***");
	}
	/*voltando cor de texto para preto*/
	textcolor(BLACK);
}


void criarBoneco(BONECO boneco[], OBSTACULOS obstaculos[])
{
	textcolor(MAGENTA);/*definindo cor de texto para mangenta*/
	int i; /*i de for*/
	int j; /*j de for*/
	for(i=0;i<2;i++) /*doid indices de boneco*/
	{
		/*desse modo garantindo que o segundo boneco tera outra cor*/
		if(i == 1) /*segundo boneco*/
		{
			textcolor(GREEN);/*definindo cor de texto para green*/
		}
		Sleep(100); /*pausa o programa por 1 segundo*/
		/*laco do while para garantir que cordenadas geradas seja validas*/
		do
		{
			boneco[i].x = rand()%((linha2 - linha1) - 1) + 1; /*limitando o numero para o limite horizontal(x) do mapa*/
			boneco[i].y = rand()%((coluna2 - coluna1) - 1) + 1; /*limitando o numero para o limeto vertical(y) do mapa*/
		}
		while(validarBoneco(&boneco[0], &obstaculos[0], i)); /*funcao que retorna 1 se posicoes de boneco e obstaculos forem validas*/
		for(j=0;j<3;j++) /*repete ciclo 3 vezes para gerar uma pequena animacao de pisca do boneco na tela*/
		{
			/*apagando boneco*/
			gotoxy(boneco[i].x, boneco[i].y);
			printf("   ");
			gotoxy(boneco[i].x, boneco[i].y + 1);
			printf("   ");
			gotoxy(boneco[i].x, boneco[i].y + 2);
			printf("   ");
			Sleep(100);/*pausando o programa por 1 segundo */
			/*imprimindo o boneco*/
			gotoxy(boneco[i].x, boneco[i].y);
			printf(" O ");
			gotoxy(boneco[i].x, boneco[i].y + 1);
			printf("-|-");
			gotoxy(boneco[i].x, boneco[i].y + 2);
			printf("/ \\");
			Sleep(100); /*pausando o programa por 1 minuto*/
		}
	}
}


void imprimirBoneco(BONECO boneco[])
{
	int i; /*i de for */
	textcolor(MAGENTA); /*definindo cor de texto para mangenta*/
	for(i=0;i<2;i++)
	{
		/*garantindo que o boneco tenha a cor diferente*/
		if(i == 1) /*segundo boneco*/
		{
			textcolor(GREEN); /*definindo cor de texto para green*/
		}
		/*imprimindo boneco*/
		gotoxy(boneco[i].x, boneco[i].y);
		printf(" O ");
		gotoxy(boneco[i].x, boneco[i].y + 1);
		printf("-|-");
		gotoxy(boneco[i].x, boneco[i].y + 2);
		printf("/ \\");
	}
}


int validarBoneco(BONECO boneco[], OBSTACULOS obstaculos[], int x)
{
	int i; /*i de for */
	int a = 0; /*valor verdade*/
	int difx; /*diferenca de cordenadas x geradas de objetos anteriores e atual*/
	int dify; /*diferenca de cordenadas y geradas de objetos anteriores e atual*/
	int outro; /*variavel que guardara o indice do outro boneco*/
	/*condicao if ira garantir que o indice do "outro boneco" seja diferente do que foi passado pelo parametro da funcao*/
	if(x == 0)
	{
		outro = 1;
	}
	else
	{
		outro = 0;
	}
	
	for(i=0;i<10;i++) /*analisando todos os 10 obstaculos*/
	{
		/*segue mesma logica para validar cordenadas de obstaculos visto anteriormente*/
		difx = 0; 
		dify = 0;
		if(boneco[x].x >= obstaculos[i].x)
		{
			difx = boneco[x].x - obstaculos[i].x;
		}
		else
		{
			difx = obstaculos[i].x - boneco[x].x;
		}
		
		if(boneco[x].y >= obstaculos[i].y)
		{
			dify = boneco[x].y - obstaculos[i].y;
		}
		else
		{
			dify = obstaculos[i].y - boneco[x].y;
		}
		
		if(difx <= 3 && dify <= 3)
		{
			a = 1; /*valor verdade vardadeiro*/
		}
	}	
	/*repetindo processo. agora para validar que um boneco nao imprima um em cima do outro*/
	difx = 0;
	dify = 0;
	if(boneco[x].x >= boneco[outro].x)
	{
		difx = boneco[x].x - boneco[outro].x;
	}
	else
	{
		difx = boneco[outro].x - boneco[x].x;
	}
	
	if(boneco[x].y >= boneco[outro].y)
	{
		dify = boneco[x].y - boneco[outro].y;
	}
	else
	{
		dify = boneco[outro].y - boneco[x].y;
	}
	
	if(difx <= 3 && dify <= 3)
	{
		a = 1; /*valor vardade verdadeiro*/
	}
	
	/*ultima condicao para garantir que cordenada y(vertical) nao seja maior que 2 para evitar de cobrir area auxiliar para o jogador*/
	if(boneco[x].y <= 2)
	{
		a = 1; /*valor verdade verdadeiro*/
	}
	/*se qualquer das condicoes anteriores for verdade o programa tera brecha para falhas
	por isso varias condicoes aonde posiveis retorno verdadeiro de modos diferentes(a = 1) */
	return a; /*retornando valor verdade*/
}


void criarTesouro(OBSTACULOS obstaculos[], BONECO boneco[], TESOURO *tesouro)
{
	textcolor(BLUE); /*definindo cor de texto para azul*/
	/*laco do while para garantir que cordenadas seja validas*/
	do
	{
		tesouro->x = rand()%((linha2 - linha1) - 5) + 3; /*limitando numero para limite horizontal(x) do mapa
		e um pouco mais para garantir que torco do boneco possa ter colisao*/
		tesouro->y = rand()%((coluna2 - coluna1) - 5) + 3; /*limitando numero para limite vertical(y) do mapa
		e um pouco mais para garantir que torco do boneco possa ter colisao*/
	}
	while(validarTesouro(&obstaculos[0], &boneco[0], tesouro)); /*funcao que retorna 1 se posicao do tesouro for invalido*/
	/*imprimindo tesouro*/
	gotoxy(tesouro->x, tesouro->y);
	printf("X");
}


void imprimirTesouro(TESOURO *tesouro)
{
	textcolor(BLUE); /*definindo cor de texto para azul*/
	/*imprimindo tesouro*/
	gotoxy(tesouro->x, tesouro->y);
	printf("X");
}


int validarTesouro(OBSTACULOS obstaculos[], BONECO boneco[], TESOURO *tesouro)
{
	int i; /*i de for*/
	int a = 0; /*valor verdade*/
	int difx; /*diferenca de cordenadas entre x geradas anteriormente e atual*/
	int dify; /*diferenda de cordenadas entre y geradas anteriormente e atual*/
	for(i=0;i<10;i++)/* 10 obstaculos*/
	{
		/*segue mesma logica mostrada anteriormente para validar cordenadas*/
		difx = 0;
		dify = 0;
		if(tesouro->x >= obstaculos[i].x)
		{
			difx = tesouro->x - obstaculos[i].x;
		}
		else
		{
			difx = obstaculos[i].x - tesouro->x;
		}
		
		if(tesouro->y >= obstaculos[i].y)
		{
			dify = tesouro->y - obstaculos[i].y;
		}
		else
		{
			dify = obstaculos[i].y - tesouro->y;
		}
		if(difx <= 3 && dify <= 3)
		{
			a = 1; /*valor vardade verdadeiro*/
		}
		
		difx = 0;
		dify = 0;
	}	
	
	for(i=0;i<2;i++) /*dois bonecos*/
	{
		/*segue mesma logica anterior agora para validar que nao caira em cima do boneco*/
		if(tesouro->x >= boneco[i].x)
		{	
			difx = tesouro->x - boneco[i].x;
		}
		else
		{
			difx = boneco[i].x - tesouro->x;
		}
	
		if(tesouro->y >= boneco[i].y)
		{
			dify = tesouro->y - boneco[i].y;
		}
		else
		{
			dify = boneco[i].y - tesouro->y;
		}
		if(difx <= 3 && dify <= 3)
		{
			a = 1; /*valor verdade verdadeiro*/
		}
	}
	
	/*ultima condicao para garantir que cordenada y(vertical) nao seja maior que 4 para evitar de cobrir area auxiliar para o jogador
	e um pouco mais para garantir que torco do boneco posssa ter colisao*/
	if(tesouro->y <= 4)
	{
		a = 1; /*valor verdade verdadeiro*/
	}
	/*se qualquer das condicoes anteriores for verdade o programa tera brecha para falhas
	por isso varias condicoes aonde posiveis retorno verdadeiro de modos diferentes(a = 1) */
	return a; /* retornando valor verdade para condicao do while do */
}

void jogar (BONECO boneco[], OBSTACULOS obstaculos[], TESOURO *tesouro)
{
	textcolor(BLACK); /*definindo cor de texto para preto*/
	_setcursortype(_NOCURSOR); /*defindo cursor para sem cursor(nao aparecer na tela)*/
	int tecla; /*guarda valor da tecla digitado pelo jogador*/
	int i; /*i de for*/
	int x = 1; /*jogador 1 que inicia o jogo*/
	int bateuObs = 0; /*guarda valor verdade se o jogador bateu no obstaculo*/
	int bateuTes = 0; /*guarda valor verdade se o jogador encontrou o tesouro*/
	int z = 1; /*valor verdade para manter o loop while ate que o jogo termine*/
	int outro; /*guarda o indice do jogador adversario*/
	while(z) /*loop do jogo aonde o boneca ira se movimentar pelo mapa ate que ele bata no obstaculo ou encontre o tesouro*/
	{
		/*logica para garantir a cada inicio do while alterne entre o jogador, assim lendo a tecla e movendo boneco por turnos*/
		if(x == 0)
		{
			x = 1;
			outro = 0;
		}
		else
		{
			x = 0;
			outro = 1;
		} 
		
		for(i=0;i<3;i++)/*tres passos por turno*/
		{
			/*procedimento que imprimi na tela informacoes para auxiliar o jogodor dutante o jogo */
			controleJogador(&boneco[0], x, i);
			/*logica para garantir que a impressao do boneco para cada passo seja de acordo com a cor de seu jogador*/
			if(x == 0)
			{
				textcolor(MAGENTA);
			}
			else
			{
				textcolor(GREEN);
			}
			
			tecla = getch(); /*ler tecla do usuario*/
			switch(tecla)
			{
				case 0:	 /* tecla estendida */
					case 224: /* tecla estendida */
						/*ciclo while para garantir que entrada do teclado do usuario seja setas de direcao*/
						do
						{		
							tecla = getch(); /*ler tecla do usuario*/
							/*valida direcao e valida movimento com funcao validadora*/
							if(tecla == SETA_PARA_DIREITA && validarMovimento(&boneco[0], x, tecla))
							{
								/*apaga boneco no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("   ");
								/*atualiza posicao do boneco*/
								boneco[x].x = boneco[x].x + 1;
								/*imprimi boneco em posicao atualizada*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf(" O ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("-|-");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("/ \\");	
							}
							else 
								/*valida direcao e valida movimento com funcao validadora*/
								if(tecla == SETA_PARA_BAIXO && validarMovimento(&boneco[0], x, tecla))
							{						
								/*apaga boneco no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("   ");
								/*atualiza posicao do boneco*/
								boneco[x].y = boneco[x].y + 1;
								/*imprimi boneco em posicao atualizada no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf(" O ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("-|-");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("/ \\");							 
							}
							else 
								/*valida direcao e valida movimento com funcao validadora*/
								if(tecla == SETA_PARA_ESQUERDA && validarMovimento(&boneco[0], x, tecla))
							{
								/*apaga boneco no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("   ");
								/*atualiza posicao do boneco*/
								boneco[x].x = boneco[x].x - 1;
								/*imprimi boneco em posicao atualizada no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf(" O ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("-|-");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("/ \\");							
							}
							else 
								/*valida direcao e valida movimento com funcao validadora*/
								if(tecla == SETA_PARA_CIMA && validarMovimento(&boneco[0], x, tecla))
							{
								/*apaga boneco no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("   ");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("   ");
								/*atualiza posicao do boneco*/
								boneco[x].y = boneco[x].y - 1;
								/*imprimi boneco em posicao atualizada no mapa*/
								gotoxy(boneco[x].x, boneco[x].y);
								printf(" O ");
								gotoxy(boneco[x].x, boneco[x].y + 1);
								printf("-|-");
								gotoxy(boneco[x].x, boneco[x].y + 2);
								printf("/ \\");							
							}
							/*caso tecla seja diferente da direcao diminui um "i" para quando voltar no do while o "i" esteja correto*/
							else
							{
								i--;
							}
							/*chama funcao para verificar se boneco bateu no obstaculo*/
							bateuObs = bateuObstaculo(&boneco[0], &obstaculos[0], x);
							/*chama funcao para verificar se boneco bateu no tesouro*/
							bateuTes = bateuTesouro(&boneco[0], tesouro, x);
							/*se bateu no obstaculo entra no if*/
							if(bateuObs)
							{
								boneco[x].ganhou = 0; /*turno do boneco indice x, campo ganhou do tipo BONECO ganha valor 0*/
								boneco[outro].ganhou =1;/*turno do boneco indice outro, campo ganhou do tipo BONECO ganha valor 1*/
								/*garantir que saira do loop while*/
								z = 0;
								break;
							}	
							if(bateuTes)
							{
								boneco[x].ganhou = 1; /*turno do boneco indice x, campo ganhou do tipo BONECO ganha valor 1*/
								boneco[outro].ganhou = 0; /*turno do boneco indice outro, campo ganhou do tipo BONECO ganha valor 0*/
								/*garantir que saira do loop while*/
								z = 0;
								break;
							}
							break;
						}while(tecla == SETA_PARA_BAIXO && tecla == SETA_PARA_CIMA && tecla == SETA_PARA_DIREITA && tecla == SETA_PARA_ESQUERDA);
			}	
			/*imprimi a cada passo do boneco os obstaculos, boneco e tesouro para evitar que jogador apague esses objeto ao passar por perto*/
			imprimirObstaculos(&obstaculos[0]);	
			imprimirTesouro(tesouro);
			imprimirBoneco(&boneco[0]);
			/*garantir que saira do loop while*/
			if(!z)
			{
				break;
			}
		/*garantir que saira do loop while*/
		}
		if(!z)
		{
			break;
		}
	}
}


int validarMovimento(BONECO boneco[], int x, int tecla)
{
	int a = 1; /*valor verdade*/
	/*para cada tecla digitada sera verificado se ainda ha espaco para incremetar ou decremetar cordenada x, y
	atribuindo valor falso(0) para a.*/
	if( tecla == SETA_PARA_DIREITA )
	{
		if(boneco[x].x > 73)
		{
			a = 0;
		}
	}
	if( tecla == SETA_PARA_ESQUERDA )
	{
		if(boneco[x].x < 2)
		{
			a = 0;
		}
	}
	if( tecla == SETA_PARA_CIMA )
	{
		if(boneco[x].y < 4)
		{
			a = 0;
		}
	}
	if( tecla == SETA_PARA_BAIXO )
	{
		if(boneco[x].y > 23)
		{
			a = 0;
		}
	}
	return a; /*retorna valor falso para condicao if do procedimento loop*/ 
}




int bateuObstaculo(BONECO boneco[], OBSTACULOS obstaculos[], int x)
{
	int a = 0; /*valor verdade*/
	int i; /*i de for*/
	for(i=0;i<10;i++) /*verifica todos os 10 obstaculos*/
	{
		/*compara torco do boneco com o meio do obstaculo*/
		if(boneco[x].x + 1 == obstaculos[i].x + 1 && boneco[x].y + 1 == obstaculos[i].y + 1)
		{
			a = 1; /*valor verdade verdadeiro*/
		}
	}
	return a; /*retorna valor verdade verdadeiro para atribuicao da variavel bateuObs procedimento jogar()*/
}

int bateuTesouro (BONECO boneco[], TESOURO *tesouro, int x)
{
	int a = 0; /*valor verdade*/
	/*compara torco do boneco com posicao do tesouro */
	if(boneco[x].x + 1 == tesouro->x && boneco[x].y + 1 == tesouro->y)
	{
		a = 1; /*valor verdade verdadeiro*/
	}
	return a; /*retorna valor verdade verdadeiro para atribuicao da variavel bateTes procedimento jogar()*/
}

void controleJogador(BONECO boneco[], int x, int i)
{
	int j; /*j de for*/
	int restantes; /*restantes dos passos do turno de cada jogador*/
	/*if para comparar parametro i para calcular restantes*/
	if(i == 0)
	{
		restantes = 3;
	}
	else
		if(i == 1)
	{
		restantes = 2;
	}
	else
	{
		restantes = 1;
	}
	
	/*usar parametro x para definir cor do texto de auxilio de acordo com a cor do boneco*/
	if(x == 0)
	{
		textcolor(MAGENTA); /*definindo cor de texto para magenta*/
	}
	else
	{
		textcolor(GREEN); /*definindo cor de texto para green*/
	}
	/*para cada atualizacao apagar texto da linha 1*/
	gotoxy(1, 1);
	for(j=0;j<(linha2 - linha1);j++)
	{
		printf(" ");
	}
	/*imprimindo informacoes na linha 1*/
	gotoxy(20, 1);
	printf("jogador %s - passos restantes %d ",boneco[x].nome , restantes);
	/*definindo barreira da linha de informacao e area jogavel*/
	textcolor(RED); /*definindo cor de texto para vermelho*/
	gotoxy(1, 2);
	for(j=0;j<(linha2 - linha1);j++)
	{
		printf("-");
	}
}

void fim(BONECO boneco[])
{
	textcolor(BLACK);/*definindo cor de texto para preto*/
	/*campo do BONECO que tiver valor verdade foi o vencedor*/
	if(boneco[0].ganhou)
	{
		gotoxy(((linha2 - linha1) / 2) - 10, ((coluna2 - coluna1) / 2) + 2);
		printf("jogador %s ganhou !!",boneco[0].nome);
	}
	else
	{
		gotoxy(((linha2 - linha1) / 2) - 10, ((coluna2 - coluna1) / 2) + 2);
		printf("jogador %s ganhou !!",boneco[1].nome);	
	}		
}

int jogarNovamente()
{
	_setcursortype(_NORMALCURSOR); /*definir cursor para normal(poscar)*/
	int resposta; /*guarda valor da resposta*/
	/*ciclo while para garantir que resposta seja sempre 1 ou 0*/
	do
	{
	/*pergunta para o usuario se ele quer jogar de novo*/
	gotoxy(((linha2 - linha1) / 2) - 30, ((coluna2 - coluna1) / 2) + 4);
	printf("deseja jogar novamente? digite '1' par sim ou '0' para encerrar:");
	gotoxy(((linha2 - linha1) / 2) - 30, ((coluna2 - coluna1) / 2) + 5);
	scanf("%d",&resposta); /*ler resposta*/ 
	}
	while(resposta != 0 && resposta != 1);
	
	return resposta; /*retorna valor 1 ou 0 para ciclo do while da main()*/
}