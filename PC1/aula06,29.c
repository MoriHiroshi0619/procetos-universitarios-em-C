
                        //atividade lista 13
/*#include <stdio.h>
int main(){
    int i, num_conta, quant_trans;
    float sald_atual, sald_min, taxa, valor;
    char cod_trans;

    printf ("Informe numero de conta: ");
    scanf ("%d", &num_conta);
    while (num_conta!=0){
        printf ("Informe o valor do saldo atual: ");
        scanf ("%f", &sald_atual);
        printf ("Informe o valor do saldo minimo: ");
        scanf ("%f", &sald_min);
        printf ("Informe a quantidade de transacoes: ");
        scanf ("%d", &quant_trans);
        printf ("Informe o valor da taxa de servico: ");
        scanf ("%f", &taxa);
        for (i=1;i<=quant_trans;i++){
            printf ("Informe o codigo da transacao <D/R>: ");
            scanf (" %c", &cod_trans);
            printf ("Informe o valor da transacao: ");
            scanf ("%f", &valor);
            if (cod_trans=='D')
                sald_atual=sald_atual+valor;
            else
                sald_atual=sald_atual-valor;
            if (sald_atual<sald_min)
                sald_atual=sald_atual-taxa;
        }
        printf ("Numero de Conta: %d\n", num_conta);
        printf ("Saldo Calculado: %3.2f\n", sald_atual);
        if (sald_atual<=0)
            printf ("NAO HA FUNDOS\n");

        printf ("Informe numero de conta: ");
        scanf ("%d", &num_conta);
    }
}*/
                            //vetores de dados
                            //Ler 10 notas, calcular a média das 10 notas e imprimir as notas maiores ou iguais a média.
/*#include <stdio.h>
int main(){
    int i;
    float notas[10], media=0;
    for (i=0;i<10;i++){
        printf ("Informe a nota[%d]: ",i+1 );
        scanf ("%f",&notas[i]);
        media=media+notas[i];
    }
    media=media/10;
    printf ("A media eh = %2.1f\n", media);

    for (i=0;i<10;i++){
        if (notas[i]>=media)
            printf ("A nota = %2.1f eh maior do que a media\n", notas[i]);


    }

}*/
//Ler 10 notas, calcular a média das 10 notas e imprimir as notas maiores ou iguais a média.
/*#include <stdio.h>
int main(){
    int i, n;
    float notas[10], media=0;
    printf ("Informe o numero de notas: ");
    scanf ("%d", &n);


    for (i=0;i<n;i++){
        printf ("Informe a nota[%d]: ",i+1 );
        scanf ("%f",&notas[i]);
        media=media+notas[i];
    }
    media=media/n;
    printf ("A media eh = %2.1f\n", media);

    for (i=0;i<n;i++){
        if (notas[i]>=media)
            printf ("A nota = %2.1f eh maior do que a media\n", notas[i]);


    }

}*/
/*
#include<stdio.h>
int main(){
    int vetor1[5], vetor2[5], soma[5],i;
    for (i = 0; i < 5; i++) {
        printf("Entre com valor %d para vetor 1: ", i + 1);
        scanf("%d", &vetor1[i]);
    }
    for (i = 0; i < 5; i++) {
        printf("Entre com valor %d para vetor 2: ", i + 1);
        scanf("%d", &vetor2[i]);
    }
    for (i = 0; i < 5; i++){
        soma[i] = vetor1[i] + vetor2[i];
        printf("soma[%d]: %d\n", i, soma[i]);
    }
}
*/
/* Programa que calcula o produto escalar de dois vetores */
/*#include<stdio.h>
int main(){
    int vetor1[4], vetor2[4], produto=0 ,i;
    for (i = 0; i < 4; i++) {
        printf("Entre com valor %d para vetor 1: ", i + 1);
        scanf("%d", &vetor1[i]);
    }
    for (i = 0; i < 4; i++) {
        printf("Entre com valor %d para vetor 2: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    for (i = 0; i < 4; i++)
        produto = produto + vetor1[i] * vetor2[i];

    printf("Produto Escalar : %d\n", produto);

}*/

/*int main(){
    int v[10], x,i, busca= -1;

    printf ("Informe o numero a ser procurado no vetor: ");
    scanf ("%d",&x);
    for (i=0; i<10; i++){
        printf ("v[%d] = ",i);
        scanf ("%d", &v[i]);
        if (v[i]==x)
            busca=i;
    }
    if (busca>=0)
        printf ("O numero procurado foi achado na posicao %d", busca);
    else
        printf ("O numero procurado nao foi achado");
}*/


