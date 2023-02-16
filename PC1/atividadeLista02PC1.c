/*#include <stdio.h> 1
    int main(){
        int a1,m1,d1,a2,m2,d2;
        printf("informe a primeira data seguindo o exemplo abaixo\n ano/mes/dia \n : ");
        scanf("%d",&a1);
        scanf("%d",&m1);
        scanf("%d",&d1);
        printf("informe a segunda data seguindo o exemplo abaixo\n ano/mes/dia \n : ");
        scanf("%d",&a2);
        scanf("%d",&m2);
        scanf("%d",&d2);
        if (a1 < a2){
            printf("a data mais antiga eh %d/%d/%d",a1,m1,d1);  
        }         
        else if (m1 < m2) { 
                printf("a data mais antiga eh %d/%d/%d",a1,m1,d1);
        }
        else if(d1 < d2) {
                    printf("a data mais antiga eh %d/%d/%d",a1,m1,d1);
        }
        else {
            printf("a data mais antiga eh %d/%d/%d",a2,m2,d2);
        }  
 }*/

/*	Escreva um programa que, dado o comprimento de três segmentos de reta,
 determine se eles formam um triângulo 
 e, caso formem, diga se o triângulo é equilátero, isósceles ou escaleno. */
/*#include <stdio.h> 2

    int main(){
        int a,b,c;
        printf("informe os tres lados do triangulo:  ");
        scanf("%d %d %d",&a,&b,&c);
        if (a<b+c &&b<a+c&&c<a+b){
            if (a==b && a==c){
            printf("eh um triangulo equilatero");
            }
            else if (a==b || a==b){
                printf("eh um triangulo isosceles");
            }
            else{
                printf("eh um triangulo escaleno");
            }
        }
        else {
            printf("nao eh um triangulo");
        }
    }*/
/*4.	Escreva um programa que ordene três números.
 Tente encontrar uma versão com apenas 3 comandos if. */
/*#include <stdio.h> 3 
int main() {
	int a, b, c;
	printf("Digite tres numeros: ");
	scanf("%d %d %d", &a, &b, &c);
	if ((a < b) && (a < c)) {
        if (b < c)
            printf("Ordem: %d, %d, %d\n", a, b, c);
        else
            printf("Ordem: %d, %d, %d\n", a, c, b);
   } else if (b < c) {
        if (a < c)
            printf("Ordem: %d, %d, %d\n", b, a, c);
        else
            printf("Ordem: %d, %d, %d\n", b, c, a);
    } else {
        if (a < b)
         	printf("Ordem: %d, %d, %d\n", c, a, b);
        else
            printf("Ordem: %d, %d, %d\n", c, b, a);
    }
}*/
/*Faça um programa que permita a leitura de um numero
 e informe se ele é ou não é divisível por 5. */
/* #include <stdio.h> 5
     int main(){
         int numero, resultado ;
         printf("informe um numero:  ");
         scanf("%d",&numero);
         
         resultado = numero/5;
         if (resultado=0){
             printf("esse numero eh divisil por 5");
         }
         else{
             printf("esse numero nao eh divisil por 5 ");
         }
     }*/
/*	Faça um programa que permita a leitura de um número e informe se ele 
é divisível por 3 e por 7. */
/*#include <stdio.h> 6
     int main (){
         int numero, resu1, resu2;
         printf("informe um numero:    ");
         scanf("%d",&numero);
         resu1 = numero/3;
         resu2 = numero/7;
         if (resu1==0 || resu2==0){
             printf("esse numero eh divisivel por 3 ou 7");
         }
         else{
             printf("esse numero nao eh divisivel por 3 ou 7");
         }
     }*/
/*	Faça um programa que permita a leitura do ano de nascimento de uma pessoa
 e o ano atual e imprima a idade da pessoa.
  Não se esqueça de verificar se o ano de nascimento é um ano válido*/
/*#include <stdio.h> 7
   int main (){
       int anoNascimento, anoAtual, idade;
       printf("informe o seu ano de nascimento:  ");
       scanf("%d",&anoNascimento);
       printf("informe o ano atual:  ");
       scanf("%d",&anoAtual);
       if (anoNascimento>anoAtual||anoNascimento<1921){
           printf("esse ano de nascimento eh invalida");
       }
       else{
           idade = anoAtual - anoNascimento;
           printf("com base nos dados inseridos sua idade eh de ou serah de %d anos",idade);
       }
   }*/
/*Dada uma letra, escreva na tela
 se essa letra é ou não uma vogal pode considerar apenas letras minúsculas  */
/*#include <stdio.h>  10
   int main (){
       char letra;
       printf("digite uma letra:   ");
       scanf("%c",&letra);
       if (letra == 'a'|| letra == 'e'|| letra == 'i'|| letra == 'o'|| letra == 'u'){
           printf("%c eh uma vogal",letra);
       }
       else {
           printf("%c nao eh uma vogal",letra);
       }
   }*/
/*Rigorosamente falando, há anos múltiplos de quatro que não sao bissextos. 
São aqueles múltiplos de 100 que não são múltiplos de 400. 
Por exemplo, o ano 2000 foi um ano bissexto, mas o ano de 2100 não será. 
Para que o programa detecte estas exceções, a expressão logica que controla o comando if 
deve ser ampliada e talvez seja mais fácil considerar a condição para que
 um ano não seja bissexto: não deve ser múltiplo de quatro ou se for múltiplo de 100
 não deve ser múltiplo de 400. Faça um programa que,
  optando por uma expressão lógica, garanta o fato de que o ano dado não é bissexto. */
/*#include <stdio.h> 9
       int main(){
           int anoInformado, ano400, ano100, ano4;
           printf("informe o ano:      ");
           scanf("%d",&anoInformado);
           
           ano400 = anoInformado/400;
           ano100 = anoInformado/100;
           ano4 = anoInformado/4;

           if (ano400 ==0 || ano100 == 0 || ano4 == 0){
               printf("esse ano e bissexto");
           }
           else {
               printf("esse ano nao eh bissexto");
           }
       }*/
/*Escreva um programa que recebe um operador aritmético e dois operandos e calcule 
a operação indicada. As operações possíveis são 
soma(+), subtração(−), multiplicação(*) e divisão(/). Ex: + 10 2 imprime 12 na tela.*/
/*#include <stdio.h> 11
       int main(){
           char operador;
           int n1, n2, resultado;
           printf("informe o operador que voce quer utilizar:     ");
           scanf("%s",&operador);
           printf("informe dois numeros para o calculo:    ");
           scanf("%d %d",&n1,&n2);
           if (operador== '+'){
               resultado = n1+n2;
               printf("o resultado serah de %d",resultado);
           }
           else if (operador=='-'){
                resultado = n1-n2;
               printf("o resultado serah de %d",resultado);
           }
           else if (operador=='*'){
               resultado = n1*n2;
               printf("o resultado serah de %d",resultado);
           }
           else if (operador=='/'){
                resultado = n1/n2;
               printf("o resultado serah de %d",resultado);
           }
           else {
               printf("o caracter inserido eh invalido");
           }
       }*/
/*Uma escola adota no seu processo de avaliação a realização de duas avaliações bimestrais e o regime de aprovação dos alunos seguinte:  
i)	Se a média das avaliações bimestrais for superior ou igual a 7,0, o aluno esta aprovado, com média final igual a media das avaliações bimestrais. 
ii)	Se a media das avaliações bimestrais for inferior a 5,0, o aluno esta reprovado, com media final igual a media das avaliações bimestrais. 
iii)	Não ocorrendo nenhum dos casos anteriores, o aluno se submete a uma prova final e a sua média final 
será a média ponderada desta prova final (com peso 4) e a média das avaliações bimestrais (com peso 6). Neste caso, o aluno estará aprovado se a sua média final for superior ou igual a 5,5. */
/*#include <stdio.h>  12
       int main(){
           float prova1, prova2, prova3, media, mediaPonderada;
           printf("informe a nota da primeira prova bimestral e da segunda:     ");
           scanf("%f %f",&prova1,&prova2);
           media = (prova1+prova2)/2;
           if (media>=7 && media<=10){
               printf("o aluno esta aprovado com media final igual a %2.1f",media);
           }
           else if (media<5 && media>=0){
               printf("o alino esta reprovado com media final igual a %2.1f",media);
           }
           else if (media == 5 || media == 6){
               printf("voce tera que fazer uma terceira prova\ninforme a nota dessa terceira prova:    ");
               scanf("%f",&prova3);
               mediaPonderada = ((prova3*4)+(prova1*6)+(prova2*6))/16;
               if (mediaPonderada>= 5.5){
                   printf("o aluno esta aprovado com media final igual a %2.1f",mediaPonderada);
               }
               else{
                   printf("o aluno esta reprovado com media final igual a %2.1f",mediaPonderada);
               }
           }
           else{
               printf("ocorreu um erro, tente novamente");
           }/
       }*/
/*Uma empresa decidiu dar um aumento escalonado a seus funcionários de acordo com a seguinte regra:
13% para os salários inferiores ou iguais a R$ 900,00;
11% para os salários situados entre R$ 900,0 e R$ 1100,00 (inclusive);
9 % para os salários entre R$ 1100,00 e R$ 1500,00 (inclusive) e 
7% para os demais salários. Faça um programa que receba o salario atual de um funcionário e forneça o valor do seu novo salario. */
/*include <stdio.h> 13
      int main(){
          float salario, salarioNovo;
          printf("informe seu salario:     ");
          scanf("%f",&salario);
          if (salario<=900){
              salarioNovo = (salario*0.13)+salario;
              printf("seu novo salario serah de %2.2f reais",salarioNovo);
          }
          else if(salario>900 && salario<=1100){
              salarioNovo = (salario*0.11)+salario;
              printf("seu novo salario serah de %2.2f reais",salarioNovo);
          }
          else if (salario>1100 && salario<1500){
              salarioNovo = (salario*0.09)+salario;
              printf("seu novo salario serah de %2.2f reais",salarioNovo);
          }
          else{
              salarioNovo = (salario*0.07)+salario;
              printf("seu novo salario serah de %2.2f reais",salarioNovo);
          }
      }*/
/*Faça um programa que determine o numero de dias de um mês 
(um programa como este seria parte integrante de um programa que manipulasse datas).
Considere que os meses de trinta dias são quatro e os de trinta e um dias são sete. */
/*include <stdio.h> 14
      int main (){
          int mes;
          printf("informe o mes:      ");
          scanf("%d",&mes);
          if (mes ==2){
              printf("esse mes terah 29 dias");
          }
          else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
              printf("esse mes terah 31 dias");
          }
          else{
              printf("esse mes terah 30 dias");
          }
      }*/
/*Escreva um programa que mostre na tela um menú de pratos (pelo menos 5), cada um associado a um número.  
Prato 1 – Miojo 	 
Prato 2 – Ensopado 
Quando um número é selecionado, o programa deve exibir uma breve descrição do prato.
 Por exemplo, ao digitar 1, o programa mostra: “Macarrão instantâneo”. */
 /*#include <stdio.h> 15
       int main(){
           int prato;
           printf("escolha o numero do prato\n");
           printf("1- miojo\n2- lamem\n3- yakisoba\n4- oden\n5- Spaghetti\n     :");
           scanf("%d",&prato);
           if (prato == 1){
               printf("macarrao instantaneo com canceriginos");
           }
           else if (prato == 2){
               printf("parece miojo porem eh japones");
           }
           else if (prato == 3){
               printf("outro tipo de miojo japones so que agora frito");
           }
           else if (prato == 4){
               printf("mais um miojo japones so que diferente");
           }
           else if (prato == 5){
               printf("miojo italiano pra variar um pouco");
           }
           else{
               printf("esse prato nao esta disponivel");
           }
       }
 */
/*Sejam dois intervalos fechados [a,b] e [c,d], onde a,b,c e d são números inteiros fornecidos pelo usuário com as seguintes condições: a<b, c<d e a<c. Seja também um inteiro n fornecido pelo usuário. 
Faça um programa que determine se n pertence somente ao intervalo [a,b] ou somente ao intervalo [c,d] ou, se n pertence a ambos ou se n não pertence a nenhum dos dois. */
 /*#include <stdio.h>
          int main (){
              int a, b ,c, d, n;
              printf("informe quatros numeros inteiros a b c d em uma ordem crescente:\t");
              scanf("%d %d %d %d",&a,&b,&c,&d);
              printf("informe um numero n:\t");
              scanf("%d",&n);
              if (n>a&&n<b){
                  printf("%d pertence ao intervalo %d,%d",n,a,b);
              }
              else if (n>c&&n<d){
                  printf("%d pertence ao intervalo %d,%d",n,c,d);
              }
              else if (n>a&&n<b&&n>c&&n<d){
                  printf("%d pertece aos dois grupos %d,%d e %d,%d",n,a,b,c,d);
              }
              else{
                  printf("esse numero nao pertence a nenhum intervalo");
              }
          }
*/


#include <stdio.h>
int main("\n")