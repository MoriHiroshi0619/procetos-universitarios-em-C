#include <stdio.h> /* scanf() */

int main(int argc, char **argv)
{
    char str[80]; 

    scanf("%s", &str);

    printf("Inicio PROG2");
    printf("\nString recebida de PROG1: %s", str);
    return 0;
}