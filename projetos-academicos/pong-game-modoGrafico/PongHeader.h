#ifndef _PONGHEADER_H_
#define _PONGHEADER_H_


#include <Windows.h> /*COLORREF*/


#define TITULO "PONG" /*titulo do console*/
#define DISTANCIA_BORDA 60 /*distancia da raquete com a borda do console*/
#define DISTANCIA_SUPERIOR_INICIAL 20 /*distancia superior do console que a raquete aparece na tela pela primeira vez*/
#define COMPRIMENTO_RAQUETE 160	/*comprimento em pixels da raquete*/
#define LARGURA_RAQUETE 20 /*largura em pixels da raquete*/
#define MOVIMENTO_RAQUETE 20 /*disntancia em pixel que a raquete sera movimentada por tecla*/
#define RAIO_BOLINHA 10 /*raio em pixels da bolinha*/
#define MOVIMENTO_BOLINHA 10 /*distancia em pixels em que a raquete ira se mover na tela*/
#define VELOCIDADE_BOLINHA_INICIAL 50 /*tempo inicial de movimento da bolinha*/
#define DIMINUICAO_VELOCIDADE 50 /*tempo que sera decrementado a cada colisao com as raquetes da bolinha*/
#define COLISAO_BORDAS_RAQUETE 60 /*distancia em pixels para validar colisao da borda tanto superior quanto inferior da bolinha entre as raquetes*/
#define COLISAO_CENTRO_RAQUETE 40 /*distancia em pixels para validar colisao central da bolinha entre as raquetes*/

#define LARGURA_BOTAO 50 /*largura em pixels do botao da tela inicial*/
#define COMPRIMENTO_BOTAO 70 /*comprimento em pixels do botao da tela inicial*/
#define MENSANGEM "jogar" /*texto que aparecera no botao*/

#define RETO_SENTIDO_DIREITO 1 /*numero constante para definir direcao reto sentido direito*/
#define RETO_SENTIDO_ESQUERDO 2 /*numero constante para definir direcao reto sentido esquerdo*/
#define DIAG_CIMA_DIREITO 3 /*numero constante para definir direcao diagonal cima para a direita*/
#define DIAG_CIMA_ESQUERDO 4 /*numero constante para definir direcao diagonal cima para a esquerda*/
#define DIAG_BAIXO_DIREITO 5 /*numero constante para definir direcao diagonal baixo sentido direito*/
#define DIAG_BAIXO_ESQUERDO 6 /*numero constante para definir direcao diagonal baixo sentido esquerdo*/

#define SHIFT 16 /*ASCII da tecla "shift"*/
#define ALT 18 /*ASCII da tecla "alt"*/


/*estrutara definida para a raquete da esquerda*/
typedef struct
{
	int x, y; /*coordenadas em x e y*/
	int ganhou; /*variavel logica para guardar situacao do jogador*/
	char nome[20]; /*string para guardar nome do jogador*/
}RAQUETE1;


/*estrutura definida para a raquete da direita*/
typedef struct
{
	int x, y; /*coordenadas em x e y*/
	int ganhou; /*variavel logica para guardar situacao do jogador*/
	char nome[20]; /*string para guardar nome do jogador*/
}RAQUETE2;


/*estrutura para guardar informacoes importantes do monitor*/
typedef struct
{
	COORD PosicaoInicialJanela; /*guardar a posicao inicial da janela*/
	COORD tamanhoInicialJanela; /*guardar o tamanho inicial da janela*/
	COORD tamanhoMaximoJanela; /*guardar o tamanho maximo possivel para a janela*/
	COORD fonte; /*guardar o tamanho da fonte do console*/
}MONITOR;



/*estrutura para guardar informacoes da bolinha*/
typedef struct
{
	int x, y; /*coordenadas em x e y da bolinha*/
	int direcao; /*guarda a situxao da direcao da bolinha definidas pelas constantes*/
	int velocidade; /*velocidade do tempo da bolinha*/
    int cont; /*conta ate VELOCIDADE da bolinha para validar se pode atualizar o movimento da bolinha*/
}BOLINHA;


/*estrutura para guardar informacoes do botao na tela inicial*/
typedef struct
{
	int x, y; /*coordenadas em x e y da bolinha*/

}BOTAO;

/*imprimir na tela a raquete 1 da esquerda, definir como falso variavel logica vencedora*/
void imprimirRaquete1(RAQUETE1 *, COLORREF);

/*imprimir na tela a raquete 2 da direita, definir como falso variavel logica vencedora*/
void imprimirRaquete2(RAQUETE2 *, COLORREF);

/*imprimir na tela a bolinha, sortear um direcao inicial aleatoria, definir velocidade, zera contador da bolinha*/
void imprimirBolinha(BOLINHA *,  COLORREF);

/*mostrar a tela inicial, definir tamanho do console, ler informacoes, mostrar texto inicial, ler nomes dos jogadoes, ler clique, definir posicoes das raquetes e da bolinha, desliga o cursor e deixa invisivel a barra de tarefas*/
void inicio(RAQUETE1 *, RAQUETE2 *, BOLINHA *, MONITOR *, BOTAO *);

/*mostrar informacoes durante o jogo, verificar vencedor, verificar se a bola pode se mover na tela, verificar leituras de teclas*/
void jogar(RAQUETE1 *, RAQUETE2 *, BOLINHA *,  COLORREF, COLORREF, MONITOR *);

/*move raquete 1 para baixo*/
void moveRaquete1Baixo(RAQUETE1 *, COLORREF, COLORREF);

/*move raquete 1 para cima*/
void moveRaquete1Cima(RAQUETE1 *, COLORREF, COLORREF);

/*move raquete 2 para baixo*/
void moveRaquete2Baixo(RAQUETE2 *, COLORREF, COLORREF);

/*move raquete 2 para cima*/
void moveRaquete2Cima(RAQUETE2 *, COLORREF, COLORREF);

/*move a bolinha, verifica colisao com borda ou raquete, verifica se ha vencedor*/
void moveBolinha(BOLINHA *,  MONITOR *, COLORREF, COLORREF, RAQUETE1 *, RAQUETE2 *);

/*atualiza x e y da bolinha a depender da direcao que ele tiver seguindo */
void atualizaCoordenadas(BOLINHA *, int);

/*verifica colisao com borda superior e inferior, verifica colisao com as duas raquetes tanto na parte cetral como nas bordas*/
void atualizaSentido(BOLINHA *, MONITOR *, RAQUETE1 *, RAQUETE2 *);

/*funcao que retorna valor verdade para verificar se a raquete 1 nao ira sair do mapa por cima*/
int validarMovimentoRaquete1Cima(RAQUETE1 *);

/*funcao que retorna valor verdade para verificar se a raquete 1 nao ira sair do mapa por baixo*/
int validarMovimentoRaquete1Baixo(RAQUETE1 *, MONITOR *);

/*funcao que retorna valor verdade para verificar se a raquete 2 nao ira sair do mapa por cima*/
int validarMovimentoRaquete2Cima(RAQUETE2 *);

/*funcao que retorna valor verdade para verificar se a raquete 2 nao ira sair do mapa por baixo*/
int validarMovimentoRaquete2Baixo(RAQUETE2 *, MONITOR *);

/*funcao que retorna valor verdade para verificar se a bolinha colidiu com a borda superior da raquete 1*/
int colisaoSuperiorRaquete1(BOLINHA *, RAQUETE1 *);

/*funcao que retorna valor verdade para verificar se a bolinha colidiu com a borda superior da raquete 2*/
int colisaoSuperiorRaquete2(BOLINHA *, RAQUETE2 *);

/*funcao que retorna valor verdade para verificar se a bolinha colidiu com a parte central da raquete 1*/
int colisaoCentroRaquete1(BOLINHA *, RAQUETE1 *);

/*funcao que retorna valor verdade para verificar se a bolinha colidiu com a parte central da raquete 2*/
int colisaoCentroRaquete2(BOLINHA *, RAQUETE2 *);

/*funcao que retorna valor verdade para verificar se a bolinha colidiu com a borda inferior da raquete 1*/
int colisaoInferiorRaquete1(BOLINHA *, RAQUETE1 *);

/*funcao que retorna valor verdade para verificar se a bolinha colidiu coma borda inferior da raquete 2*/
int colisaoInferiorRaquete2(BOLINHA *, RAQUETE2 *);

/*verifica se a bolinha nao saiu do mapa e atualiza variavel ligica da raquete vencedora*/
void verificaVencedor(BOLINHA *, RAQUETE1 *, RAQUETE2 *, MONITOR *);

/*tela final do jogo que mostra qual jogador venceu, liga o cursor de volta e deixa visivel a barra de tarefas*/
void fim(MONITOR *, RAQUETE1 *, RAQUETE2 *);

/*mostra os nomes do jogador na tela e a mensagem de como sair do jogo*/
void mostrarInfo(RAQUETE1 *, RAQUETE2 *, MONITOR *);



#endif