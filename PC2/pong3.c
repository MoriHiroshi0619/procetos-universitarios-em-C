
/*gcc -o pong3.exe pong3.c PongHeader.c graphics_v1.1.c console_v1.5.4.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/

/*gcc -o pong3.exe pong3.c PongHeader.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror*/


#include "conio_v3.2.4.h"
#include "PongHeader.h"

int main (int argc, char *argv[])
{
	RAQUETE1 *raquete1, r;
	RAQUETE2 *raquete2, r2;
	BOLINHA *bolinha, b;
	MONITOR *monitor, m;
	BOTAO *botao, botton;

	argc = argc;
	argv = argv;
	
	raquete1 = &r;
	raquete2 = &r2;
	bolinha = &b;
	monitor = &m;
	botao = &botton;

	clrscr();
	inicio(raquete1, raquete2, bolinha, monitor, botao);
	imprimirRaquete1(raquete1, RGB(255, 0, 0));
	imprimirRaquete2(raquete2, RGB(255, 0, 0));
	imprimirBolinha(bolinha, RGB(255, 0, 0));
	jogar(raquete1, raquete2, bolinha, RGB(255, 0, 0), RGB(12, 12, 12), monitor);
	fim(monitor, raquete1, raquete2);
	return 0;
}
