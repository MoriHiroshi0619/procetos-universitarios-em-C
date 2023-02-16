/* Programa para ilustrar a utilização da função window() da conio e permitir ao programador criar múltiplas janelas com cores diferentes na tela */

/* Como compilar: gcc prog2.c conio_v3.2.4.c -o prog2.exe -Wall -pedantic -Wextra -Werror */

#include <stdio.h>			/* printf() */
#include <stdlib.h> 		/* system() */
#include <string.h>			/* strlen() */
#include "conio_v3.2.4.h"   /* textbackground(), window(), gotoxy(), getch(), constantes BLACK, BLUE, LIGHTGRAY, RED */


int main(int argc, char *argv[])
{
	char *mensagem = "Pressione qualquer tecla para encerrar...";
	argc = argc;
	argv = argv;
	
	/* Limpar a janela do console */
	clrscr();
	
	/* Criar uma subjanela e colorir de azul */
	textbackground(BLUE);
	window(20, 20, 40, 25);
	gotoxy(1, 1);  	/* observe que o posicionamento será referente a subjanela */
	printf("Janela 1");
	
	/* Criar uma subjanela e colorir de azul */
	textbackground(RED);
	window(30, 2, 50, 5);
	gotoxy(1, 1); 	/* observe que o posicionamento será referente a subjanela */ 
	printf("Janela 2");

	/* Esperar o usuário pressionar qualquer tecla para encerrar */
	textbackground(LIGHTGRAY);
	textcolor(BLACK);
	window(80 - strlen(mensagem) + 1, 30, 80, 30);
	printf("%s", mensagem);
	getch();

	/* Retornar à cor original da janela do prompt de comando. Assumindo que a cor de fundo é BLACK e a da letra é LIGHTGRAY */
	textbackground(BLACK);
	textcolor(LIGHTGRAY);
	clrscr();

	return 0;
}


/* Exercícios:
   1) Centralize na linha a mensagem "Janela 1" da subjanela 1;
   2) Centralize na linha a mensagem "Janela 2" da subjanela 2;
*/