 /* Descrição: Imprimir na tela o tamanho atual da janela de console em quantidade de caracteres */
 /* 14/03/2015 */

/*gcc prog10.c console_v1.5.4.c -o prog10.exe -Wall -Werror -Wextra -pedantic*/

 /* Declaração dos arquivos cabeçalhos */
 #include <stdio.h>            /* função printf() */
 #include "console_v1.5.4.h"   /* função tamanhoJanelaConsole() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Variável que armazenará a resolução atual do monitor */
	COORD dimensionConsoleWindow;
	
	/* Silenciar o warning relativo aos parämetros não usados da função main() */
	argc = argc;
	argv = argv;
	
	/* Armazenar as dimensões da janela de console em quantidade de caracteres */
	dimensionConsoleWindow = tamanhoJanelaConsole();
	
	/* Imprimir na tela as quantidades de caracteres que se pode imprimir nas dimensões atuais da janela de console */
	printf( "\nQuantidade caracteres de largura: %d" , dimensionConsoleWindow.X );
	printf( "\nQuantidade caracteres de altura: %d\n" , dimensionConsoleWindow.Y );	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exercício:
   - Faça um programa que faça com que a janela de console ocupe o tamanho máximo da tela possível. Observação: após o encerramento do seu programa, 
     tudo deve voltar exatamente como era antes da execução de seu programa (tamanho da janela e posição na tela). */