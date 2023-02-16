#include <stdio.h>
#include <stdlib.h>
#include "conio_v3.2.4.h"
#include <time.h>
#include <Windows.h>


/*gcc conio_v3.2.4.c teste.c -o teste.exe -Wall -Werror -pedantic -Wextra*/
int main(int argc, char *argv[])
{
	/*
	char Boneco[3][3];
	char *boneco;
	boneco = Boneco;
	*/
	int x, y, i;
	int a;
	
	argc = argc;
	argv = argv;
	
	clrscr();
	
	srand(time(NULL));
	
	textbackground(WHITE);
	textcolor(BLACK);
	window(30,5,80,20);
	/*
	x = rand()% 49 + 1;
	y = rand()% 14 + 1;
	gotoxy(x, y);
	printf("%c",a);
	*/
	
	for(i=0;i<100;i++)
	{
		_setcursortype(_NOCURSOR);
		x = rand()% 49 + 1;
		y = rand()% 14 + 1;
		gotoxy(x, y);
		if(i % 2 == 0)
		{
			textcolor(GREEN);
			a = 0;
		}
		else
		{
			textcolor(RED);
			a = 1;
		}
		printf("%d",a);
		Sleep(100);
		clrscr();
	}
	
	return 0;
}