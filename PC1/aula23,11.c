                        //recustividade
                        /*
#include<stdio.h>
long fat(long n){
   long cham;
   if(n <= 1) //Caso base
       return 1;
   else {
       cham= fat(n-1);
       printf ("Imprimindo a chamada recursiva para %d = %d\n", n , n*cham );
       return (n* cham);
    }
}
int main(){
    int n, i, num;
    printf ("Informe o numero de elementos do conjunto de inteiros:");
    scanf ("%d", &num);
    for (i=1; i<=num; i++){
        printf ("Informe um numero inteiro: ");
        scanf ("%d", &n);
        printf ("O fatorial de %d eh %d\n ", n, fat(n) );
    }
}*/

/*
#include<stdio.h>
int fibonacci (int n){
    int i, fibo, primeiro=1, segundo=1;
    if (n<=2)
        return (1);
    else{
        for (i=3;i<=n;i++){
            fibo=primeiro+segundo;
            primeiro=segundo;
            segundo=fibo;
        }
        return (fibo);
    }
}
int main(){
    int n;
    do {
        printf ("Informe um numero inteiro maior que zero: ");
        scanf ("%d", &n);
    }while (n<1);
    printf ("O termo %d da sequencia de fibonacci eh %d\n", n, fibonacci(n));
}*/



/*
#include<stdio.h>
long fibo(long n){
if(n <= 2)
	return 1;
else
	return (fibo(n-1) + fibo(n-2));
}

int main(){
    int n;
    do {
        printf ("Informe um numero inteiro maior que zero: ");
        scanf ("%d", &n);
    }while (n<1);
    printf ("O termo %d da sequencia de fibonacci eh %d\n", n, fibo(n));
}
*/
/*
#include<stdio.h>
int soma(int n, int v[]){
   if (n == 1)
		return (v[0]);
   else
        //printf("\n%d",v[n-1]);
		return (v[n-1]+soma(n-1, v));
}

int main(){
    int i, n, V[10];
    do {
        printf ("Informe um numero inteiro maior que zero: ");
        scanf ("%d", &n);
    }while (n<1);
    for (i=0;i<n;i++){
        printf ("V[%d]=",i);
        scanf ("%d", &V[i]);
   }
   printf ("\nA soma dos elementos do vetor eh %d\n", soma(n,V));
}
*/

/*
#include<stdio.h>
#include <stdlib.h>
int soma(int n, int v[]){
   if (n == 1)
		return (v[0]);
   else
		return (v[n-1]+soma(n-1, v));
}

int main(){
    int i, n, *V;
    do {
        printf ("Informe um numero inteiro maior que zero: ");
        scanf ("%d", &n);
    }while (n<1);

    if ((V=malloc(n*sizeof(int)))==NULL){
        printf ("Erro na alocacao de memoria\n");
        exit(1);
    }
    for (i=0;i<n;i++){
        printf ("V[%d]=",i);
        scanf ("%d", &V[i]);
   }
   printf ("A soma dos elementos do vetor eh %d\n", soma(n,V));
}*/

/*
#include<stdio.h>
#include<math.h>

float Potencia(float x,int n){
    if  ( n ==0 ) return (1);
else
	if ( n < 0 ) 
        return (1 / (x* Potencia(x, abs(n)-1)));
	else
        return (x * Potencia(x, n -1));
}

int main(){
    int n;
    float X;
    printf ("Informe a base: ");
    scanf ("%f", &X);
    printf ("Informe o expoente: ");
    scanf ("%d", &n);

    printf ("A potencia %2.2f^%d eh %2.2f\n", X,n, Potencia(X,n));
}
*/


/*
#include<stdio.h>
#include<math.h>

float Potencia(float x,int n){
if  ( n ==0 ) return (1);
else
	if ( n <0 )
        return (1/Potencia(x,abs(n)));
	else
        return (x* Potencia(x, n -1));
}

int main(){
    int n;
    float X;
    printf ("Informe a base: ");
    scanf ("%f", &X);
    printf ("Informe o expoente: ");
    scanf ("%d", &n);

    printf ("A potencia %2.2f^%d eh %2.2f\n", X,n, Potencia(X,n));
}*/

/*
#include<stdio.h>
#include<math.h>

int digitos(int n){
   int cont;
   cont=0;
   while (abs(n)>0) {
		n = n/10;
		cont ++;
   }
   return (cont);
}

int main(){
    int n;
    printf ("Informe o numero inteiro, cujos algarismos deseja contar: ");
    scanf ("%d", &n);

    printf ("O numero de algarismos de %d eh %d\n", n, digitos(n));
}
*/
/*
#include<stdio.h>
#include<math.h>

int digitos(int n){
    if (abs( n )<10)
         return (1);
    else
         return (1+ digitos(n/10));
}


int main(){
    int n;
    printf ("Informe o numero inteiro, cujos algarismos deseja contar: ");
    scanf ("%d", &n);

    printf ("O numero de algarismos de %d eh %d\n", n, digitos(n));
}

*/

/*
#include<stdio.h>
#include<math.h>

int somdig(int n){
	  if (n <10)
          return (n);
     else
          return (n%10+ somdig(n/10));
}

 

int main(){
    int n;
    printf ("Informe o numero inteiro, cujos algarismos deseja somar: ");
    scanf ("%d", &n);

    printf ("A soma dos algarismos de %d eh %d\n", n, somdig(n));
}*/



#include <stdio.h>

int pot (int exp){
    int i, b=1;

    for (i=0; i<exp; i++)
        b*=10;
    return (b);
}

int capicua(int n, int ndig){
	if (n <10)
		return (1);
	else
		if ((n%10)!=n/pot(ndig-1)){
	         return (0);
		}
		printf ("\n%d %d", n, n%pot(ndig-1)/10);
		capicua((n%(int)pot(ndig-1))/10,ndig-2);



}
int digitos(int n){
    if (abs( n )<10)
         return (1);
    else
         return (1+ digitos(n/10));
}
int main(){
    int n, ndig, i;
    printf ("\nInforme um numero inteiro positivo: ");
    scanf ("%d", &n);
    ndig=digitos(n);
    printf ("\nnumero de digitos: %d", ndig);
    if (capicua(n, ndig)==1)
        printf ("\nO numero %d eh Capicua\n", n);
    else
        printf ("\nO numero %d nao eh Capicua\n", n);
}














