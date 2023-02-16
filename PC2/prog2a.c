#include <stdio.h> /* printf() */
#include <stdlib.h> /* exit() */

/* Funcao main: 
Ilustrar que o valor armazenado em argv são caracteres e não numeros.
Como deve ser executado este programa: deve digitar teste2a na linha de comando */
int main(int argc, char **argv)
{
    if (argc > 1)
        printf("Retornando o caracter \'%c\' passado via linha de comando ao programa de volta para o SO...\n", *argv[1]);
	else /* caso não coloque exit() aqui, dará erro no return final, nas situações em que não for digitado algum parâmetro */
        printf("Digite algum parametro na linha de comando. Exemplo: prog2 1\n"), exit(1); 
    
	printf("FIM DO PROG2");
	
	return (*argv[1]);
}