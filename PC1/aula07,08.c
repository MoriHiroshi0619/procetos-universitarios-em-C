/*#include<stdio.h>
int main(){
    int v[10], x,i, busca= -1;

    //Leitura de dados
    printf ("Informe os elementos do vetor:\n");
    for (i=0; i<10; i++){
        printf ("v[%d] = ",i);
        scanf ("%d", &v[i]);
    }
    printf ("Informe o numero a ser procurado no vetor: ");
    scanf ("%d",&x);

    // Busca atraves da comparacao

    for (i=0; i<10; i++){
        if (v[i]==x)
            busca=i;
    }
    // Verifica se a busca deu certo

    if (busca>=0)
        printf ("O numero procurado foi achado na posicao %d", busca);
    else
        printf ("O numero procurado nao foi achado");
}*/
/* Programa que realiza a busca basica de um numero dentro de um vetor */
/*#include<stdio.h>
int main(){
    int v[10], x,i, achou=0;
    printf ("Informe os elementos do vetor:\n");
    for (i=0; i<10; i++){
        printf ("v[%d] = ",i);
        scanf ("%d", &v[i]);
    }
    printf ("Informe o numero a ser procurado no vetor: ");
    scanf ("%d",&x);
    for (i=0; i<10 && !achou; i++){
        if (v[i]==x)
            achou=1;
    }
    if (achou)
        printf ("O numero procurado foi achado na posicao %d", i-1);
    else
        printf ("O numero procurado nao foi achado");
}*/
#include <stdio.h>
int main(){
    int v[10], i, meio, inicio=0, fim, x,n;

    do{
        printf ("Informe o tamanho do vetor entre 2 e 10:\n");
        scanf ("%d",&n);
    }while (n<2 || n>10);
    fim=n-1;

    printf ("Informe os elementos do vetor na ordem crescente:\n");
    for (i=0; i<n; i++){
        printf ("v[%d]=", i);
        scanf ("%d",&v[i]);
    }
    printf ("Informe o elemento a ser procurado no vetor:\n");
    scanf ("%d",&x);

    meio=(inicio + fim)/2; /* meio do vetor */
    printf ("Inicio= %d\t Fim=%d\t Meio=%d\n",inicio, fim, meio);
    /*termina quando achou ou quando o fim ficou antes do inicio */

    while (v[meio] !=x && inicio<=fim  ){
        if (x < v[meio])  //joga uma das duas metades fora
            fim=meio-1;   /* metade superior foi jogada fora */
        else
            inicio=meio+1; /* metade inferior foi jogada fora */
        meio=(inicio + fim)/2; /* recalcula meio */
        printf ("Inicio= %d\t Fim=%d\t Meio=%d\n",inicio, fim, meio);
    }
    if (v[meio] == x)
        printf ("Achou na posicao %d",meio);
    else
        printf ("O elemento x nao foi achado no vetor");
}