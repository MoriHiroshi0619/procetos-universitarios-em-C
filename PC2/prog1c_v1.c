#include <stdio.h> /* printf() */
#include <limits.h> /* constante INT_MAX*/

/* Funcao main:
-  recebe dois parametros. Notar que o parametro env não foi colocado pois não é standard C.
- retorna um valor inteiro que estoure o limite do valor passível de ser retornado. 
 - o inteiro retornado será impresso pelo arquivo  teste1.bat    
*/
int main(int argc, char **argv)
{
    int i;

    i = INT_MAX + 1; /* Notar que esta linha emitirá um warning pois a variável i não consegue armazenar o valor INT_MAX + 1 */
    printf("Retornando o valor %d + 1 para o SO...\n", INT_MAX);	
    printf("FIM DO PROG1C");
    return i; /* forçar o estouro do tipo int */
}

/* O que acontece quando se soma uma unidade ao valor máximo que uma variável do tipo int consegue armazenar? 
     Vamos analisar a situação...
      No caso de i = INT_MAX significa que os bits armazenados em "i" são os seguintes:
      i = 0111 1111 1111 1111 1111 1111 1111 1111
      ou seja, 31 bits com o valor "1" e o bit mais significativo com o valor "0" para indicar que é um número positivo (lembrar que é utilizada a notação complemento de 2 para o armazenamento dos números inteiros)
      ao se somar +1 a i, o valor armazenado em i passa a ser o seguinte:
      i = 1000 0000 0000 0000 0000 0000 0000 0000
      ou seja, o bit mais significativo passou a ter o valor "1" e, portanto, o número passa a ser um número negativo na notação complemento de 2 utilizada.
      Se for feita a transformação de complemento de 2 do número para se saber qual é o número, temos as seguintes operações:
      - Inverter todos os bits: 0111 1111 1111 1111 1111 1111 1111 1111 	  
      - Somando 1: 1000 0000 0000 0000 0000 0000 0000 0000
      - Esse valor corresponde ao valor: 2147483648
       Mas como inicialmente o bit mais significativo tinha o valor "1", então esse número é de fato um valor negativo, portanto, o valor armazenado é de fato o número -2147483648
*/
	   