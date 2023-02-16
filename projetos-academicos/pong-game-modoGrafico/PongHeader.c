#include <stdio.h> /*printf() scanf()*/
#include <Windows.h> /*Sleep()*/
#include <time.h> /*srand() */
#include <string.h> /*strlen()*/

#include "conio_v3.2.4.h" /*gotoxy(), clrscr()*/
#include "graphics_v1.1.h" /*linha(), circulo()*/
#include "console_v1.5.4.h" /*setTituloConsole(), setPosicaoJanela(), setDimensaoJanela(), getPosicaoJanela(),
tamanhoJanelaConsole(), MaxDimensaoJanela(), getTamanhoFonteConsole(), setEstadoBarraTarefas(), hit(), Evento(), setCursorStatus()*/
#include "PongHeader.h" /*imprimirRaquete1(), imprimirRaquete2(), imprimirBolinha(), inicio(), jogar(), moveRaquete1Baixo(),
moveRaquete1Cima(), moveRaquete2Baixo(),  moveRaquete2Cima(), moveBolinha(), atualizaCoordenadas(), atualizaSentido(),
validarMovimentoRaquete1Cima(), validarMovimentoRaquete1Baixo(), validarMovimentoRaquete2Cima(), alidarMovimentoRaquete2Baixo(),
colisaoSuperiorRaquete1(), colisaoSuperiorRaquete2(), colisaoCentroRaquete1(), colisaoCentroRaquete2(), colisaoInferiorRaquete1(), colisaoInferiorRaquete2(),
verificaVencedor(), fim(), mostrarInfo()*/

void inicio (RAQUETE1 *raquete1, RAQUETE2 *raquete2, BOLINHA *bolinha, MONITOR *monitor, BOTAO *botao )
{
	EVENTO clique; /*nomeando evento*/
	int mouseX; /*posicao em x do mouse*/
	int mouseY; /*posicao em y do mouse*/
	
	monitor->PosicaoInicialJanela = getPosicaoJanela(); /*pegando posicao atual do console*/
	monitor->tamanhoInicialJanela = tamanhoJanelaConsole(); /*pegando tamanhoo da janela do console*/
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela(); /*descobrindo tamanho maximo do console*/
	monitor->fonte = getTamanhoFonteConsole(); /*coletando tamanho da fonte do console*/

	setPosicaoJanela(0,0); /*definindo posicao da janela*/
	setDimensaoJanela(monitor->tamanhoMaximoJanela.X, monitor->tamanhoMaximoJanela.Y); /*definidno tamanho da janela*/
	setTituloConsole(TITULO);/*colocando titulo no console*/
	
	/*imprimindo texto descritivo na primeira janela*/
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 10, monitor->tamanhoMaximoJanela.Y / 2 - 4);
	printf("bem vindos !!");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 15, monitor->tamanhoMaximoJanela.Y / 2 - 3);
	printf("esse eh o jogo do pong!!");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 25, monitor->tamanhoMaximoJanela.Y / 2 - 2);
	printf("seu objetivo eh fazer um GOL no seu adversario.");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 22, monitor->tamanhoMaximoJanela.Y / 2 - 1);
	printf("o primeiro que marcar um GOL ganha o jogo !!");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 35, monitor->tamanhoMaximoJanela.Y / 2);
	printf("utilize a tecla shift_direito para mover para cima a raquete da direita");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 35, monitor->tamanhoMaximoJanela.Y / 2 + 1);
	printf("utilize a tecla alt_direito para mover para baixo a raquete da direita");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 35, monitor->tamanhoMaximoJanela.Y / 2 + 2);
	printf("utiliza a tecla shift_esquerdo para mover para cima a raquete da esquerda");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 35, monitor->tamanhoMaximoJanela.Y / 2 + 3);
	printf("utiliza a tecla alt_esquerdo para mover para baixo a raquete da esquerda ");

	/*lendo nome do jogador 1*/
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 20, monitor->tamanhoMaximoJanela.Y / 2 + 4);
	printf("por favor digite o nome do jogador numero 1:");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 20, monitor->tamanhoMaximoJanela.Y / 2 + 5);
	fgets(raquete1->nome, 20, stdin);

	/*lendo nome do jogador 2*/
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 20, monitor->tamanhoMaximoJanela.Y / 2 + 6);
	printf("por favor digite o nome do jogador numero 2");
	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 20, monitor->tamanhoMaximoJanela.Y / 2 + 7);
	fgets(raquete2->nome, 20, stdin);

	gotoxy((monitor->tamanhoMaximoJanela.X / 2) - 10, monitor->tamanhoMaximoJanela.Y / 2 + 8);
	printf("vamos ao jogo!!");

	/*desligando o cursor do console*/
	setCursorStatus(DESLIGAR);

	/*definindo posicoes x e y do botao*/
	botao->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X / 2) - COMPRIMENTO_BOTAO + 20;
	botao->y = (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y / 2) + (monitor->fonte.Y * 10);
	
	/*escrevendo linhas do botao*/
	linha(botao->x, botao->y, botao->x, botao->y + LARGURA_BOTAO, RGB(255, 0, 0));
	linha(botao->x, botao->y, botao->x + COMPRIMENTO_BOTAO, botao->y, RGB(255, 0, 0));
	linha(botao->x, botao->y + LARGURA_BOTAO, botao->x + COMPRIMENTO_BOTAO, botao->y + LARGURA_BOTAO, RGB(255, 0, 0));
	linha(botao->x + COMPRIMENTO_BOTAO, botao->y, botao->x + COMPRIMENTO_BOTAO, botao->y + LARGURA_BOTAO, RGB(255, 0, 0));
	
	/*escrevendo o texto dentro do botao*/
	gotoxy(botao->x / monitor->fonte.X + 2 , botao->y / monitor->fonte.Y + 2);
	printf("%s", MENSANGEM);

	/*laco do while para leitura de evento*/
	do
	{
		/*lendo um evento*/
		clique = Evento();


		/*se for um evento do mouse ira verificar se foi um clique e depois verificar as coordenadas do clique para entao sair do laco*/
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
		/*se for um evento do tipo mouse ira verificar se foi o clique da tecla "enter" para entao sair do laco*/
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
	
	/*apagando tudo na tela e imprimindo mensagem de carregando
	PS: essa parte nao tem nenhum motico logico de eu ter posto no jogo, coloquei apenas porque da um ar diferente  do joguinho kkkk*/
	clrscr();
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 5, monitor->tamanhoInicialJanela.Y / 2);
	printf("carregando...");
	Sleep(300); /*nao ta carregando nada, soh pra o programa ficar mais dahorinha kkkk*/
	
	/*deixando invisivel a barra de tarefas;
	coloquei isso porque essa funcao esta na biblioteca console e eu queria testar*/
	setEstadoBarraTarefas(INVISIVEL);

	/*definindo coordenadas iniciais que ira aparecer na tela da raquete 1*/
	raquete1->x = DISTANCIA_BORDA;
	raquete1->y = DISTANCIA_SUPERIOR_INICIAL;
	
	/*definindo coordenadas iniciais que ira aparecer na tela da raquete 2*/
	raquete2->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X) - DISTANCIA_BORDA;
	raquete2->y = DISTANCIA_SUPERIOR_INICIAL;
	
	/*definindo coordenadaas iniciais que ira aparecer na tela da bolinha*/
	bolinha->x = (monitor->tamanhoMaximoJanela.X * monitor->fonte.X) / 2;
	bolinha->y = (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y) / 2;
	
	/*apagando todo conteudo que esta na console*/
	clrscr();
}


void mostrarInfo(RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor)
{
	
	/*escrevendo nome do primeiro jogador*/
	gotoxy(15, 1);
	printf("jogador %s", raquete1->nome);

	/*escrevendo nome do segundo jogador*/
	gotoxy(monitor->tamanhoMaximoJanela.X - 30, 1);
	printf("jogador %s", raquete2->nome);

	/*escrevendo mensagem de como sair do jogo*/
	gotoxy(monitor->tamanhoMaximoJanela.X / 2 - 9, 1);
	printf("aperte F12 para sair");

}

void imprimirRaquete1(RAQUETE1 *raquete1, COLORREF cor)
{

	/*desenhando a raquete*/
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, cor);
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, cor);
	/*definindo valor falso para a variavel ganhou*/
	raquete1->ganhou = 0; /*assumi que ainda nao venceu o jogo*/

}

void imprimirRaquete2(RAQUETE2 *raquete2, COLORREF cor)
{

	/*desenhando a raquete*/
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, cor);
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, cor);
	/*definindo valor falso para a variavel ganhou*/
	raquete2->ganhou = 0; /*assumi que ainda nao houve vencedor*/

}


void imprimirBolinha(BOLINHA *bolinha, COLORREF cor)
{

	/*desenhando a bolinha*/
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, cor);
	/*sorteando numero que servira como direcao inicial da bolinha*/
	srand(time(NULL));
	bolinha->direcao = rand()%5 + 1;
	/*definindo velocidade inicial*/
	bolinha->velocidade = VELOCIDADE_BOLINHA_INICIAL;
	/*zerando variavel contadora do tempo do jogo*/
	bolinha->cont = 0;

}

void moveBolinha(BOLINHA *bolinha, MONITOR *monitor, COLORREF vermelho, COLORREF preto, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{

	/*chamando funcao verifica colisao e muda sentido da bolinha*/
	atualizaSentido(bolinha, monitor, raquete1, raquete2);
	/*apaga a bolinha*/
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, preto);
	/*chamando funcao atualiza coordenadas da bolinha*/
	atualizaCoordenadas(bolinha, bolinha->direcao);
	/*desenhando bolinha em sua posicao nova*/
	circulo(bolinha->x, bolinha->y, RAIO_BOLINHA, vermelho);
	/*chamando funcao que verifica se houve um vencedor*/
	verificaVencedor(bolinha, raquete1, raquete2, monitor);

}

void verificaVencedor(BOLINHA *bolinha, RAQUETE1 *raquete1, RAQUETE2 *raquete2, MONITOR *monitor) 
{

	/*se a bola passa do limite da borda esquerda, o jogador da direita venceu*/
	if(bolinha->x < 0)
	{
		raquete2->ganhou = 1;
	}
	/*se a bola passa do limite da borda direita, o jogador da esquerda venceu*/
	if(bolinha->x > (monitor->tamanhoMaximoJanela.X * monitor->fonte.X))
	{
		raquete1->ganhou = 1;
	}

}

void atualizaCoordenadas(BOLINHA *bolinha, int sentido)
{

	/*a denpender do valor que a variavel sentido tiver, as coordenadas da bola sera atualiza*/
	switch ( sentido )
	{
		case RETO_SENTIDO_DIREITO:
			bolinha->x = bolinha->x + MOVIMENTO_BOLINHA;
			break;
		case RETO_SENTIDO_ESQUERDO:
			bolinha->x = bolinha->x - MOVIMENTO_BOLINHA;
			break;
		case DIAG_CIMA_DIREITO:
			bolinha->x = bolinha->x + MOVIMENTO_BOLINHA;
			bolinha->y = bolinha->y - MOVIMENTO_BOLINHA;
			break;
		case DIAG_CIMA_ESQUERDO:
			bolinha->x = bolinha->x - MOVIMENTO_BOLINHA;
			bolinha->y = bolinha->y - MOVIMENTO_BOLINHA;
			break;
		case DIAG_BAIXO_DIREITO:
			bolinha->x = bolinha->x + MOVIMENTO_BOLINHA;
			bolinha->y = bolinha->y + MOVIMENTO_BOLINHA;
			break;
		case DIAG_BAIXO_ESQUERDO:
			bolinha->x = bolinha->x - MOVIMENTO_BOLINHA;
			bolinha->y = bolinha->y + MOVIMENTO_BOLINHA;
			break;
		default:
			break;
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
	
	/*verificando colisao superior da bolinha com a raquete 1*/
	if(colisaoSuperiorRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = DIAG_CIMA_DIREITO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}
	
	/*verificando colisao superior da bolinha com a raquete 2*/
	if(colisaoSuperiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_CIMA_ESQUERDO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}

	/*verificando colisao central da bolinha com a raquete 1*/
	if(colisaoCentroRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = RETO_SENTIDO_DIREITO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}
	
	/*verificando colisao central da bolinha com a raquete 2*/
	if(colisaoCentroRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = RETO_SENTIDO_ESQUERDO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}
	
	/*verificando colisao inferior da bolinha com a raquete 1*/
	if(colisaoInferiorRaquete1(bolinha, raquete1))
	{
		bolinha->direcao = DIAG_BAIXO_DIREITO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}
	
	/*verificando colisao inferior da bolinha com a raquete 2*/
	if(colisaoInferiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_BAIXO_ESQUERDO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}
	
	/*verificando colisao superior da bolinha com a raquete 1*/
	if(colisaoSuperiorRaquete2(bolinha, raquete2))
	{
		bolinha->direcao = DIAG_CIMA_ESQUERDO; /*atualiza sentido da bolinha*/
		if(bolinha->velocidade - 50 > 0) /*verifica se ainda nao atingiu velocidade minima*/
		{
			bolinha->velocidade = bolinha->velocidade - DIMINUICAO_VELOCIDADE; /*diminiu o intervalo de tempo da atualizacao da bolinha, conseguentemente aumentanndo a velocidade dela*/
		}
	}
}

int colisaoSuperiorRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{

	int a = 0; /*criando variavel logica e assumindo valor falso*/
	int i; /*i de for*/
	
	/*verificando para cada pixel da raquete 1 na coordenada y se houve colisao*/
	for( i=0 ; i < COLISAO_BORDAS_RAQUETE ; i++ )
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE * 2) && bolinha->x >= raquete1->x && (bolinha->y == raquete1->y + i))
		{
			a = 1; /*se houver colisao o valor logico muda para verdadeiro*/
		}
	}
	return a;

}

int colisaoSuperiorRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{

	int a = 0; /*criando variavel logica e assumindo valor falso*/
	int i ; /*i de for*/
	
	/*verificando para cada pixel da raquete 1 na coordenada y se houve colisao*/
	for( i=0 ; i < COLISAO_BORDAS_RAQUETE ; i++ )
	{
		if((bolinha->x > raquete2->x - LARGURA_RAQUETE * 2) && bolinha->x < raquete2->x && (bolinha->y == raquete2->y + i))
		{
			a = 1; /*se houver colisao o valor logico muda para verdadeiro*/
		}
	}
	
	return a;

}

int colisaoCentroRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{

	int a = 0; /*criando variavel logica e assumindo valor falso*/
	int i; /*i de for*/

	/*verificando para cada pixel da raquete 1 na coordenada y se houve colisao*/
	for( i=0 ; i <= COLISAO_CENTRO_RAQUETE ; i++)
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE * 2) && bolinha->x >= raquete1->x && (bolinha->y == (raquete1->y + COLISAO_BORDAS_RAQUETE) + i))
		{
			a = 1; /*se houver colisao o valor logico muda para verdadeiro*/
		}
	}
	return a;
	
}

int colisaoCentroRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{

	int a = 0; /*criando variavel logica e assumindo valor falso*/
	int i; /*i de for*/
	
	/*verificando para cada pixel da raquete 1 na coordenada y se houve colisao*/
	for( i=0 ; i <= COLISAO_CENTRO_RAQUETE ; i++ )
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE * 2) && bolinha->x < raquete2->x && (bolinha->y == (raquete2->y + COLISAO_BORDAS_RAQUETE) + i))
		{
			a = 1; /*se houver colisao o valor logico muda para verdadeiro*/
		}
	}
	return a;
	
}

int colisaoInferiorRaquete1(BOLINHA *bolinha, RAQUETE1 *raquete1)
{

	int a = 0; /*criando variavel logica e assumindo valor falso*/
	int i; /*i de for*/
	
	/*verificando para cada pixel da raquete 1 na coordenada y se houve colisao*/
	for( i=0 ; i <= COLISAO_BORDAS_RAQUETE ; i++)
	{
		if((bolinha->x <= raquete1->x + LARGURA_RAQUETE * 2) && bolinha->x >= raquete1->x && (bolinha->y == (raquete1->y + COLISAO_BORDAS_RAQUETE + COLISAO_CENTRO_RAQUETE) + i))
		{
			a = 1; /*se houver colisao o valor logico muda para verdadeiro*/
		}
	}
	return a;
	
}

int colisaoInferiorRaquete2(BOLINHA *bolinha, RAQUETE2 *raquete2)
{

	int a = 0; /*criando variavel logica e assumindo valor falso*/
	int i; /*i de for*/
	
	/*verificando para cada pixel da raquete 1 na coordenada y se houve colisao*/
	for( i = 0 ; i <= COLISAO_BORDAS_RAQUETE ; i++ )
	{
		if((bolinha->x >= raquete2->x - LARGURA_RAQUETE * 2) && bolinha->x < raquete2->x && (bolinha->y == (raquete2->y + COLISAO_BORDAS_RAQUETE + COLISAO_CENTRO_RAQUETE) + i))
		{
			a = 1; /*se houver colisao o valor logico muda para verdadeiro*/
		}
	}
	return a;

}


void jogar(RAQUETE1 *raquete1, RAQUETE2 *raquete2, BOLINHA *bolinha, COLORREF vermelho, COLORREF preto, MONITOR *monitor)
{
	EVENTO tecla; /*nomeando evento*/

	

	mostrarInfo(raquete1, raquete2,  monitor); /*chamando funcao de mostrar info pela primeira vez*/
	do
	{	
		timeBeginPeriod ( 1 ) ; /*definindo tempo de prioridade*/
		/*verifico nas variaveis logicas do campo ganhou da raquete se houve um vencedor, se houver eu quebro o laco*/
        if(raquete1->ganhou || raquete2->ganhou)
		{
			break;
		}

		/*se a variavel contadora atingir o tempo de atualizacao eu chamo a funcao de mover a bolinha*/
		if(bolinha->cont == bolinha->velocidade)
		{
			moveBolinha(bolinha, monitor, vermelho, preto, raquete1, raquete2);
			bolinha->cont = 0; /*zero a variavel contadora*/
		}
		
		/*verifico se houve um hit do tipo teclado*/
		if(hit(KEYBOARD_HIT))
        {
        	tecla = Evento(); /*leio o evento*/  
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
					  
                /*raquete2 para cima apenas*/
                if((tecla.teclado.status_teclas_controle & SHIFT_DIREITO_PRESSIONADO)&& validarMovimentoRaquete2Cima(raquete2))
                {
                    moveRaquete2Cima(raquete2, vermelho, preto);
                }                     /*raquete2 para baixo apenas*/
            	else
					if((tecla.teclado.status_teclas_controle & RIGHT_ALT_PRESSED) && validarMovimentoRaquete2Baixo(raquete2, monitor))
					{
						moveRaquete2Baixo(raquete2, vermelho, preto);
					} 
                    
                /*para sair do jogo*/
                if(tecla.teclado.codigo_tecla == F12)
                { 
                    break;
                }                
            }
        }

		Sleep(1); /*intervalo de 1 millisegundo*/
		bolinha->cont++; /*incremento a varivael contadora para o tempo do jogo*/
	}
	while(1);
	timeEndPeriod( 1 ); /*terminando tempo de prioridade*/
}

void moveRaquete1Baixo(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto)
{

	/*aoagando apenas o comprimento de linha referente ao movimento (nesse caso 20 pixels) de forma a reduzir a necessidade grafica de ter que apagar toad a raquete*/
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, preto);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, vermelho);
	
	/*atualizando coordenadas da raquete*/
	raquete1->y = raquete1->y + MOVIMENTO_RAQUETE;
	
	/*imprimindo apenas o comprimento de linha referente ao movimento, agora na cor vermelha para dar a sensacao de animacao*/
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, vermelho);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	
}


void moveRaquete1Cima(RAQUETE1 *raquete1, COLORREF vermelho, COLORREF preto)
{

	/*aoagando apenas o comprimento de linha referente ao movimento (nesse caso 20 pixels) de forma a reduzir a necessidade grafica de ter que apagar toad a raquete*/
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	
	/*atualizando coordenadas da raquete*/
	raquete1->y = raquete1->y - MOVIMENTO_RAQUETE;
	
	/*imprimindo apenas o comprimento de linha referente ao movimento, agora na cor vermelha para dar a sensacao de animacao*/
	linha(raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete1->x, raquete1->y, raquete1->x, raquete1->y + MOVIMENTO_RAQUETE, vermelho);
	linha(raquete1->x, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y, vermelho);
	linha(raquete1->x + LARGURA_RAQUETE, raquete1->y, raquete1->x + LARGURA_RAQUETE, raquete1->y + MOVIMENTO_RAQUETE, vermelho);
	
}


void moveRaquete2Baixo(RAQUETE2 *raquete2, COLORREF vermelho, COLORREF preto)
{

	/*aoagando apenas o comprimento de linha referente ao movimento (nesse caso 20 pixels) de forma a reduzir a necessidade grafica de ter que apagar toad a raquete*/
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, preto);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, vermelho);
	
	/*atualizando coordenadas da raquete*/
	raquete2->y = raquete2->y + MOVIMENTO_RAQUETE;
	
	/*imprimindo apenas o comprimento de linha referente ao movimento, agora na cor vermelha para dar a sensacao de animacao*/
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, vermelho);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);

}


void moveRaquete2Cima(RAQUETE2 *raquete2, COLORREF vermelho, COLORREF preto)
{

	/*aoagando apenas o comprimento de linha referente ao movimento (nesse caso 20 pixels) de forma a reduzir a necessidade grafica de ter que apagar toad a raquete*/
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + COMPRIMENTO_RAQUETE - MOVIMENTO_RAQUETE, vermelho);
	
	/*atualizando coordenadas da raquete*/
	raquete2->y = raquete2->y - MOVIMENTO_RAQUETE;
	
	/*imprimindo apenas o comprimento de linha referente ao movimento, agora na cor vermelha para dar a sensacao de animacao*/
	linha(raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, preto);
	linha(raquete2->x, raquete2->y, raquete2->x, raquete2->y + MOVIMENTO_RAQUETE, vermelho);
	linha(raquete2->x, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y, vermelho);
	linha(raquete2->x - LARGURA_RAQUETE, raquete2->y, raquete2->x - LARGURA_RAQUETE, raquete2->y + MOVIMENTO_RAQUETE, vermelho);

}


int validarMovimentoRaquete1Cima(RAQUETE1 *raquete1)
{

	int a = 1; /*valor verdade*/
	/*se a coordenada X da bola for superior a disntancia incial de 20 pixels que dizer que ela vai comer a borda*/
	if(raquete1->y < DISTANCIA_SUPERIOR_INICIAL)
	{
		a = 0;
	} 
	return a;

}


int validarMovimentoRaquete1Baixo(RAQUETE1 *raquete1, MONITOR *monitor)
{

	int a = 1;
	/*declarandoo variavel inteira auxiliar para compracao*/
	unsigned int proxRaquete1 = raquete1->y + MOVIMENTO_RAQUETE;
	/*se a coordenada Y for maior que o limite em pixels do console - o comprimento dela que dizer que vai estar comendo a borda*/
	if(proxRaquete1 >= (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y - (unsigned int)COMPRIMENTO_RAQUETE))
	{
		a = 0;
	}

	return a;

}


int validarMovimentoRaquete2Cima(RAQUETE2 *raquete2)
{
	int a = 1; /*valor verdade*/
	/*se a coordenada X da bola for superior a disntancia incial de 20 pixels que dizer que ela vai comer a borda*/
	if(raquete2->y < DISTANCIA_SUPERIOR_INICIAL)
	{
		a = 0;
	} 
	return a;
}


int validarMovimentoRaquete2Baixo(RAQUETE2 *raquete2, MONITOR *monitor)
{

	int a = 1;
	/*declarandoo variavel inteira auxiliar para compracao que eh a cordenada do proximo movimento*/
	unsigned int proxRaquete2 = raquete2->y + MOVIMENTO_RAQUETE;
	/*se a coordenada Y for maior que o limite em pixels do console - o comprimento dela que dizer que vai estar comendo a borda*/
	if(proxRaquete2 >= (monitor->tamanhoMaximoJanela.Y * monitor->fonte.Y - (unsigned int)COMPRIMENTO_RAQUETE))
	{
		a = 0;
	}

	return a;

}


void fim(MONITOR *monitor, RAQUETE1 *raquete1, RAQUETE2 *raquete2)
{
	/*apagando tudo pra imprimir conteudo da ultima tela*/
	clrscr();
	/*deixando barra de tarefas visivel novamente*/
	setEstadoBarraTarefas(VISIVEL);
	/*dimenisondo console para tamanho e posicoes original*/
	setDimensaoJanela(monitor->tamanhoInicialJanela.X, monitor->tamanhoInicialJanela.Y);
	setPosicaoJanela(monitor->PosicaoInicialJanela.X, monitor->PosicaoInicialJanela.Y);
	/*lendo o maximo de caracteres possivel no console*/
	monitor->tamanhoMaximoJanela = MaxDimensaoJanela();
	/*imprinido mensagem de fim de jogo*/
	gotoxy((monitor->tamanhoInicialJanela.X / 2) - 8, monitor->tamanhoInicialJanela.Y / 2);
	printf("o jogo terminou");
	/*a depender do vencedor ira imprimir seu nome*/
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
	/*esperar 3 segundos antes de encerrar o programa*/
	Sleep(3000);
	/*ligar o cursor do console*/
	setCursorStatus(LIGAR);

}
