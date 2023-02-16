#include <stdio.h> /* printf() */
#include <stdlib.h> /* atoi() */

int main(int argc, char **argv)
{
    printf("   --> Dentro de prog2. Valor parametro passado via linha de comando: %c", atoi(argv[1]));
    return(0);
}