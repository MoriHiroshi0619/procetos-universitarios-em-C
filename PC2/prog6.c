/* Código criado para ilustrar como usar a biblioteca graphics */
/* Data da codificação: 02/05/2022                             */
/* Linha que deve ser digitada para executar este código: gcc -o prog6.exe prog6.c graphics_v1.1.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror */
/* Observação: deve usar o "Console herdado" para não ter problemas de desenho decorrentes da alocação do buffer no novo Console */

#include "conio_v3.2.4.h"   /* getch() */
#include "graphics_v1.1.h"  /* linha() */

#define quantidadeQuadrados 3   /* Quantos quadrados serão desenhados na tela */
#define ESC 27					/* Definir que o programa somente deve encerrar ao ser pressionada a tecla ESC */

/* Declaração dos protótipos das funções criadas */
void Quadrado(unsigned int, unsigned int, unsigned int, COLORREF);

/* Início do programa */
int main(int argc, char *argv[])
{
	unsigned int centroColunaQuadrado;
	unsigned int centroLinhaQuadrado;
	unsigned int tamanhoLadoQuadrado; 
	
	/* Artifício para silenciar warning */
	argc = argc;
	argv = argv;
	
    clrscr();
	
	centroColunaQuadrado = 500;
	centroLinhaQuadrado = 300;	
	
	gotoxy(1,2);
	printf("Pressione qualquer tecla para encerrar...");
	
	tamanhoLadoQuadrado = 50;
	do
	{
		Quadrado(centroColunaQuadrado - tamanhoLadoQuadrado/2, centroLinhaQuadrado - tamanhoLadoQuadrado/2,  tamanhoLadoQuadrado, RGB(255, 0, 0));
		tamanhoLadoQuadrado += 50;
		Sleep(1000);  /* pausar o programa 1 segundo */
		if ( kbhit() )
		   break;
	}
	while ( 1 ); /* loop infinito */
	
		
	return 0; /* programa encerrou com sucesso */
	
} /* Fim do programa */

void Quadrado(unsigned int colunaLadoEsquerdo, unsigned int linhaLadoSuperior, unsigned dimensaoLado, COLORREF cor)
{
	/* Lado superior */
	linha(colunaLadoEsquerdo, linhaLadoSuperior, colunaLadoEsquerdo + dimensaoLado, linhaLadoSuperior, cor);
	
	/* Lado inferior */
	linha(colunaLadoEsquerdo, linhaLadoSuperior + dimensaoLado, colunaLadoEsquerdo + dimensaoLado, linhaLadoSuperior + dimensaoLado, cor);
	
	/* Lado esquerdo */
	linha(colunaLadoEsquerdo, linhaLadoSuperior, colunaLadoEsquerdo, linhaLadoSuperior + dimensaoLado, cor);
	
	/* Lado direito */
	linha(colunaLadoEsquerdo + dimensaoLado, linhaLadoSuperior, colunaLadoEsquerdo + dimensaoLado, linhaLadoSuperior + dimensaoLado, cor);		
}

/* Exercício: 
   1) Altere o programa para que ele apague os quadrados, um a um a cada 1 segundo, do mais externo para o mais interno, após ter desenhado 8 quadrados. E depois volte a desenhar os quadrados. E depois a apagá-los. E assim sucessivamente. Em um loop infinito até que o usuário pressione qualquer tecla e encerre o programa.
*/   