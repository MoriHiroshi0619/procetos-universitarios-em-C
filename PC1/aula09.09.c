/* Faca um programa que leia um conjunto de n numeros inteiros e
determine o fatorial de cada um deles. Use a funcao fatorial */
/*
#include <stdio.h>
int fatorial(int x){
    int fat=1, i;
    for (i=x; i > 1; i--)
        fat = fat * i;
    return(fat);
}
int main(){
    int i, n, num, fat;
    printf ("Informe uma quantidade de inteiros: ");
    scanf ("%d", &n);
    // Leia um conjunto de n inteiros e calcule o fatorial de cada um deles 
    for (i=1; i<=n; i++){
        printf ("Informe um inteiro: ");
        scanf ("%d", &num);
        fat=fatorial(num);
        printf ("O fatorial de %d eh %d\n", num, fat);
    }
}
*//*
#include <stdio.h>
#include <math.h>
*/
/*
#include <stdio.h>
#include <math.h>

float hipotenusa(float cat1, float cat2){
    float hip;
    hip =sqrt(cat1*cat1+cat2*cat2);
	return(hip);
}
int main(){
    float a,b,c,L,D;
	printf ("Informe os lados a,b e c do paralelepipedo: ");
    scanf ("%f %f %f",&a,&b,&c);
    L=hipotenusa(a,b);
	D=hipotenusa(L,c);
	printf ("O valor da diagonal eh: %.2f",D);
}
*/

