/*#include <stdio.h>
int main(){
    int i, n;
    printf ("Informe um numero inteiro:");
    scanf("%d",&n);
    for (i=1; i<=n;i++)
        printf("\n %d",i);
}
*/
/*#include <stdio.h>
int main(){
    int num;
    printf ("Informe um numero inteiro: ");
    scanf("%d",&num);
    for (; num>0;){
        printf("%d\n",num*num);
        printf ("Informe um numero inteiro: ");
        scanf("%d",&num);
    }
}*/
/*#include <stdio.h>
int main(){
    int i, n;
    printf("Entre com um inteiro positivo: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        if (n % i == 0) // Se o resto for zero, então i é divisor
            printf("%d\n", i);
}*/
/*#include <stdio.h>
int main(){
    int n, i;
    printf("\nDigite um numero natural: ");
    scanf("%d", &n);
    for(i=2; i<=n-1; i++)
        if( n%i == 0 )
            break;
    if( i==n )
        printf("\nO numero eh primo");
    else
        printf("\nO numero nao eh primo");
}*/
/*#include <stdio.h>
int main(){
   int i;
    for (i = 1; i <= 5; i++) {
        if (i == 3)
            continue;
        printf("%d\t", i);
    }
}*/
/*#include <stdio.h>
int main(){
    int a,b,orig_a, orig_b,pro=0;
    printf ("Informe dois inteiros: ");
    scanf ("%d %d", &a,&b);
    orig_a=a;
    orig_b=b;
    while (a>=1) {
        if (a%2!=0)
            pro+=b; 
        a/=2; 
        b*=2;
    }
    printf ("O produto de %d e %d e’ %d",orig_a,orig_b,pro);
}*/

/* Fatorial de um conjunto de inteiros*/
/*#include <stdio.h>
int main(){
		int i , n, fat, quant;
		printf ("Informe a quantidade de inteiros dos quais iremos calcular o fatorial: ");
		scanf ("%d", &quant);
		for (n=1; n<=quant; n++) {
			fat =1; 
			for (i=n; i>= 1;i--){
                printf ("Produto Parcial na iteracao %d = %d x %d = %d\n", i, fat, i, fat*i );
				fat = fat  * i;
            }
			printf ("O fatorial de %d eh %d\n",n,fat);
		}
}*/

#include <stdio.h>
int main(){
		int i , n, fat=1, quant;
		 printf ("Informe a quantidade de inteiros dos quais iremos calcular o fatorial: ");
		scanf ("%d", &quant);
		for (n=1;n<=quant;n++) {
			fat =  fat * n ;
			printf ("O fatorial de %d eh %d\n",n,fat);
		}
}


