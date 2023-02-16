                    /*minimo multiplo comum*/

/*#include <stdio.h>
int main(){
	int x, y, resto;
	printf ("Informe dois numeros inteiros para calcular o MDC: ");
   	scanf("%d %d",&x,&y);
	if (x!=0 && y!=0){
		resto = x%y;
 		while (resto!=0){
            printf ("x=%d, y=%d, resto=%d\n",x,y,resto);
			x =y;
			y =resto ;
			resto =x%y;
		}
		printf ("mdc = %d", y);
	}else
		printf ("Nao funciona para entradas nulas.");
}
*/
#include <stdio.h>
/*Tem-se um conjunto de dados contendo a altura e o sexo (masculino, feminino) de 50 pessoas,
Fazer um algoritmo que calcule e escreva:
o a maior e a menor altura do grupo;
o a média de altura das mulheres:
o o número de homens.
*/

                    /*EXEMPLO DE CONTINUAR LOOP CASO ENTRADA SEJA INCORRETA*/
int main(){
	float altura, maior_a=0, menor_a=2.0, media_a_f=0;
	char sexo;
	int i,cont_f=0;

	for (i=1;i<=5;i++){
        do{
            printf ("Informe o sexo da pessoa %d: ",i);
            scanf(" %c",&sexo);
        }while (sexo!='m' && sexo!='M' && sexo!='f' && sexo!='F');

        printf ("Informe a altura da pessoa %d: ",i);
        scanf("%f",&altura);
        if (altura>maior_a)
           maior_a=altura;
        if (altura<menor_a)
            menor_a=altura;
        if (sexo=='F' || sexo=='f'){
            media_a_f=media_a_f+altura;
            cont_f++;
        }
	}
	printf ("A maior altura do grupo eh: %2.2f\n",maior_a);
	printf ("A menor altura do grupo eh: %2.2f\n",menor_a);
	printf ("A media da altura das mulheres eh: %2.2f\n",media_a_f/cont_f);
	printf ("O numero de homens eh: %d\n",5-cont_f);
}
