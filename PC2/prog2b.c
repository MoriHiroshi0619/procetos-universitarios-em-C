#include <stdio.h> /* printf() */

/* Funcao main: 
Ilustrar que o valor armazenado em argv são caracteres e não numeros.
Como deve ser executado este programa: deve digitar teste2b na linha de comando 
Obs.: note que foi retirada a chamada a função exit(), pois teoricamente este programa só deve ser executado por meio
do arquivo ".bat" correspondente. Como nesse ".bat" já é feita a "guarda" deste programa, isto é, o ".bat" sempre chamará este programa
passando um parâmetro. 
*/
int main(int argc, char **argv)
{
    if (argc > 1)
        printf("Retornando o caracter \'%c\' passado via linha de comando ao programa de volta para o SO...\n", *argv[1]);
	else 
        printf("Digite algum parametro na linha de comando. Exemplo: prog2 1\n"); 
    
	printf("FIM DO PROG2");
	
	return (*argv[1]);
}