 /* Descrição: Identificar a resolução atual do monitor */
 /* 14/03/2015 */
/*gcc prog9.c console_v1.5.4.c -o prog9.exe -Wall -Werror -Wextra -pedantic*/
 /* Declaração dos arquivos cabeçalhos */
 #include <stdio.h>            /* função printf() */
 #include "console_v1.5.4.h"   /* função getResolucaoMonitor() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Variável que armazenará a resolução atual do monitor */
	COORD resolution;
	int maxCubo;
	int maxCaracter, maxX, maxY;
	int i;
	/* Silenciar o warning relativo aos parämetros não usados da função main() */
	argc = argc;
	argv = argv;
	
	/* Armazenar a resolução atual da tela */
	resolution = getResolucaoMonitor();
	
	/* Imprimir na tela a resolução atual do monitor */
	printf( "\nQuantidade pixels de largura: %d" , resolution.X );
	printf( "\nQuantidade pixels de altura: %d\n" , resolution.Y );	
	
	maxCubo = resolution.X * resolution.Y;
	maxCaracter = maxCubo / 128; 
	maxX = resolution.X / 8;
	maxY = resolution.Y / 16;
	
	printf("maximo de caracteres na tela = %d\n", maxCaracter);
	printf("maximno caracter X = %d\n", maxX);
	printf("maximo caracter Y = %d\n", maxY);
	system("pause");
	system("cls");
	/*
	for(i=0;i<maxCaracter;i++)
	{
		printf("a");
	}*/
	
	for(i=0;i<maxX;i++)
	{
		printf("a");
	}
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exercício:
   - Faça um programa que imprima na tela a quantidade de pixels de largura e de altura da fonte atual definida para a janela de console */