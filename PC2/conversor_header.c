#include <stdio.h>
#include "conversor_header.h"
#include "conio_v3.2.4.h"

int perguntar()
{
    int opcao;
    clrscr();
    printf("favor digitar uma opcao.");
    printf("\n1 - Converter expressao de notacao infixa para pos-fixa");
    printf("\n2 - Converter expressao de notacao infixa para pos-fixa");
    printf("\n3 - Converter expressao de notacao pre-fixa para infixa");
    printf("\n4 - Converter expressao de notacao pre-fixa para pos-fixa");
    printf("\n5 - Converter expressao de notacao pos-fixa para pre-fixa");
    printf("\n6 - Converter expressao de notacao pos-fixa para infixa");
    scanf("%d", &opcao);

    return opcao;
}