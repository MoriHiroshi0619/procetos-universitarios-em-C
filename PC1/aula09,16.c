/*
#include <stdio.h>
int fatorial(int ); //prototipo da funcao 
void troca (int *, int *);
// funcao principal 
int main(){
int n,p,C;
printf ("Informe o numero total de eventos: ");
scanf("%d",&n);
printf ("Informe o numero de eventos de cada combinacao : ");
scanf("%d",&p);
if (p > n){
    printf ("Imprime p = %d e n = %d\n", p,n);
	troca(&p,&n); //passa os enderecos de p e de n 
	printf ("Imprime p = %d e n = %d\n", p,n);
}
if (p >= 0&&n >= 0){
	C = fatorial(n)/(fatorial(p)*fatorial(n-p));
	printf("O numero de combinacoes de %d eventos a partir do numero total de %d eventos eh %d \n",p,n,C);
}
}
int fatorial(int x){
printf (" Imprimindo x = %d\n",x);
int fat=1, i;
for (i=x; i > 1; i--)
	fat = fat * i;
return(fat);
}
void troca(int *x, int *y){
   printf (" Imprimindo x = %d e y = %d \n",x,y);
   printf (" Imprimindo *x = %d e *y = %d \n",*x,*y);
   int aux;

   aux = *x;
   printf (" Imprimindo aux = %d\n",aux);
   *x = *y;
   printf (" Imprimindo *x = %d\n",*x);
   *y = aux;
   printf (" Imprimindo *y = %d\n",*y);

}
*/

#include <stdio.h>
void LeVetor (int *, int);
void ImprimeVetor (int *, int );
void TrocaVetores (int *, int *, int );
int main(){
	int vet1[5], vet2[5];
	printf(" Lendo Vetor 1 --------\n");
	LeVetor(vet1,5);
	printf(" ------ Lendo Vetor 2 --------\n");
	LeVetor(vet2,5);
	printf ("Imprimindo os vetores antes da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
	TrocaVetores(vet1,vet2,5);
    printf ("Imprimindo os vetores depois da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);

}
void LeVetor(int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Digite numero:");
        scanf("%d",&vet[i]);
    }
}
void ImprimeVetor (int *vet, int tam){
    int i;
    printf ("[");
    for(i = 0; i < tam; i++)
        printf("%d  ",vet[i]);
    printf ("]\n");
}
void TrocaVetores (int *vet1, int *vet2, int tam){
    int i, aux;
    for(i = 0; i < tam; i++){
        aux=vet1[i];
        vet1[i]=vet2[i];
        vet2[i]=aux;
    }
}
/*
#include <stdio.h>
int raiz(int x){
    int quadrada;
    quadrada = x * x;
    return(quadrada);
}
int hipotenusa(int catA, int catB){
    int hip;
    printf("\ndentro da funccao hipotenusa%d %d",catA,catB);
    //hip = sqrt(catA) + sqrt(catB);
    //hip = (catA*catA)+(catB*catB);
    hip = raiz(catA) + raiz(catB);
    return(hip);
}
void troca(int *x, int *y){
    int aux;
    printf("\n dentro da funcao troca  %d    %d",x,y);
    aux = *x;
    *x = *y;
    *y = aux;
    printf("\n dentro da funcao troca  %d    %d",x,y);
}
int main(){
    int a, b, c,i;
    for(i=0;i<3;i++){
        printf("\ninforme os catetos\t");
        scanf("%d %d", &a, &b);
        printf("\na= %d - b= %d",a,b);
        c = hipotenusa(a,b);
        printf("\nc =  %d",c);
        troca(&a,&b);
        printf("\na= %d - b= %d",a,b);
        printf("\na hipotenusa = %d",c);
    }
}*/