/* Código criado para ilustrar como usar a biblioteca graphics */
/* Data da codificação: 15/06/2020                          */
/* Linha que deve ser digitada para executar este código: gcc -o prog5.exe prog5.c graphics_v1.1.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror */
/* Observação: deve usar o "Console herdado" para não ter problemas de desenho decorrentes da alocação do buffer no novo Console */

#include "conio_v3.2.4.h"   /* getch() */
#include "graphics_v1.1.h"  /* linha() */

#define quantidadeQuadrados 5   /* Quantos quadrados serão desenhados na tela */
#define ESC 27					/* Definir que o programa somente deve encerrar ao ser pressionada a tecla ESC */

/* Declaração dos protótipos das funções criadas */
void Quadrado(unsigned int, unsigned int, unsigned int, COLORREF);

/* Início do programa */
int main(int argc, char *argv[])
{
	int i; /* variável contadora */
	unsigned int colunaLadoEsquerdo;
	unsigned int linhaLadoSuperior;
	unsigned int ladoQuadrado = 100; /* Dimensão do lado do quadrado */
	
	/* Artíficio para silenciar warning */
	argc = argc;
	argv = argv;
	
    clrscr();
	
	colunaLadoEsquerdo = 100;
	linhaLadoSuperior = 100;	
	for (i = 0; i < quantidadeQuadrados; i++)
	{
		Quadrado(colunaLadoEsquerdo, linhaLadoSuperior, ladoQuadrado, RGB(255, 0, 0));
		colunaLadoEsquerdo = colunaLadoEsquerdo + ladoQuadrado;
		linhaLadoSuperior = linhaLadoSuperior + ladoQuadrado;
		Sleep(100);  /* pausar o programa 1/10 de segundo */
	}
	gotoxy(1,2);
	printf("Pressione a tecla ESC para encerrar...");
	while(getch() != ESC);
	
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