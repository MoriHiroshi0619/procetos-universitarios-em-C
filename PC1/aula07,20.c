/*#include <stdio.h>
int main(){
    int i, j, m, n, mat1[10][10], mat2[10][10], mat3[10][10];

    do {
        printf ("Informe o numero de linhas da matriz ");
        scanf ("%d", &m);
    }while (m<1 || m>10);
    do{
        printf ("Informe o numero de colunas da matriz ");
        scanf ("%d", &n);
    }while (n<1 || n>10);

    printf("*** Lendo Matriz 1 ***\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            printf ("Matriz1[%d][%d]: ", i, j);
            scanf ("%d", &mat1[i][j]);
        }
    printf("*** Lendo Matriz 2 ***\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            printf ("Matriz2[%d][%d]: ", i, j);
            scanf ("%d", &mat2[i][j]);
        }

    printf("*** Somando os valores correspondentes das duas matrizes ***\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            mat3[i][j] = mat1[i][j] + mat2[i][j];

    printf("*** Matriz 1 ***\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", mat1[i][j]);
        printf ("\n");
    }
    printf("*** Matriz 2 ***\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", mat2[i][j]);
        printf ("\n");
    }
    printf("*** Matriz 3 - Soma ***\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", mat3[i][j]);
        printf ("\n");
    }

}*//*
#include <stdio.h>
int main(){
    int i,j,n, A[7][7], B[7][7], simetrica=1;

    do{
        printf ("Informe o numero de linhas e colunas da matriz ");
        scanf ("%d", &n);
    }while (n<1 || n>7);

    printf("*** Lendo a Matriz e construindo a transposta***\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf ("Matriz[%d][%d]: ", i, j);
            scanf ("%d", &A[i][j]);
            B[j][i]=A[i][j];
        }

    printf("*** Imprimindo a Matriz Original ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", A[i][j]);
        printf ("\n");
    }
    printf("*** Imprimindo a Matriz Transposta ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", B[i][j]);
        printf ("\n");
    }

}*/
/*
#include <stdio.h>
int main(){
    int i,j,n, A[7][7], B[7][7], simetrica=1;

    do{
        printf ("Informe o numero de linhas e colunas da matriz ");
        scanf ("%d", &n);
    }while (n<1 || n>7);

    printf("*** Lendo a Matriz e construindo a transposta***\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf ("Matriz[%d][%d]: ", i, j);
            scanf ("%d", &A[i][j]);
            B[j][i]=A[i][j];
        }

    printf("*** Imprimindo a Matriz Original ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", A[i][j]);
        printf ("\n");
    }
    printf("*** Imprimindo a Matriz Transposta ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", B[i][j]);
        printf ("\n");
    }
    printf("*** Verificando a Simetria da Matriz A ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (A[i][j]!=B[i][j])
                simetrica=0;
    }
    if (simetrica)
        printf ("A matriz A eh simetrica");
    else
        printf ("A matriz A nao eh simetrica");
}
*/
/*
#include <stdio.h>
int main(){
    int i,j,k, n, A[7][7], B[7][7], C[7][7];

    do{
        printf ("Informe o numero de linhas e colunas da matriz ");
        scanf ("%d", &n);
    }while (n<1 || n>7);

    printf("*** Lendo a Matriz A ***\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf ("A[%d][%d]: ", i, j);
            scanf ("%d", &A[i][j]);
        }
    printf("*** Lendo a Matriz B ***\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf ("B[%d][%d]: ", i, j);
            scanf ("%d", &B[i][j]);
        }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            C[i][j] = 0;
            for (k = 0; k< 3; k++)
                C[i][j] = C[i][j]+A[i][k]* B[k][j];
        }

    printf("*** Imprimindo a Matriz A ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", A[i][j]);
        printf ("\n");
    }
    printf("*** Imprimindo a Matriz B ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", B[i][j]);
        printf ("\n");
    }
    printf("*** Imprimindo a Matriz Produto C ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", C[i][j]);
        printf ("\n");
    }

}
*/
/*
#include<stdio.h>
int main(){
    int A[20][10], i, j, B[20][11],m,n;
    do {
        printf("Informe o numero de linhas de A: ");
        scanf("%d", &m);
    }while (m<1 || m>20);
    do {
        printf ("Informe o numero de colunas de A: ");
        scanf("%d", &n);
    }while (n<1 ||  n>10);
    for (i=0; i<m; i++){
        B[i][n]=1;
        for(j=0; j<n; j++){
            printf(" Informe A[%d][%d] =", i, j);
            scanf("%d", &A[i][j]);
            B[i][j]=A[i][j];
            B[i][n]*=B[i][j];
        }
    }
    printf ("Matriz A");
    for (i=0; i<m; i++){
        printf ("\n");
        for(j=0; j<n; j++){
            printf(" %d",A[i][j]);
        }
    }
    printf ("\n Matriz B");
    for (i=0; i<m; i++){
        printf ("\n");
        for(j=0; j<=n; j++){
            printf(" %d", B[i][j]);
        }
    }
}*/
 /*
#include<stdio.h>
int main(){
    int A[20][10], i, j, B[20][11],m,n;
    do {
        printf("Informe o numero de linhas de A: ");
        scanf("%d", &m);
    }while (m<1 || m>20);
    do {
        printf ("Informe o numero de colunas de A: ");
        scanf("%d", &n);
    }while (n<1 ||  n>10);
    for (i=0; i<m; i++){
        B[i][n]=1;
        for(j=0; j<n; j++){
            printf(" Informe A[%d][%d] =", i, j);
            scanf("%d", &A[i][j]);
            B[i][j]=A[i][j];
            B[i][n]*=B[i][j];
        }
    }
        
    printf ("Matriz A");
    for (i=0; i<m; i++){
        printf ("\n");
        for(j=0; j<n; j++){
            printf(" %d",A[i][j]);
        }
    }
    printf ("\n Matriz B");
    for (i=0; i<m; i++){
        printf ("\n");
        for(j=0; j<=n; j++){
            printf(" %d", B[i][j]);
        }
    }
}*/
/*
#include<stdio.h>
#include <string.h>
int main(){
    int R[10], i, j, O[5], c=0;
    char N[20];
    for(j=0;j<5; j++)
       O[j]=0;
    printf("Digite o nome da pessoa 1: ");
    scanf ("%s",N);
    while (strcmp(N,"vazio")){
        for(j=0;j<10; j++){
            do{
                printf("Digite a resposta da pergunta %d: ", j+1);
                scanf("%d", &R[j]);
            }while (R[j]<1 || R[j]>5);
            O[R[j]-1]++;
        }
        c++;
        printf ("\nRespostas da pessoa %d ===>", c);
        for(j=0;j<10; j++)
            printf("%d  ", R[j]);
        printf("\n\nDigite o nome da pessoa numero %d:", c+1);
        scanf ("%s", N);
    }
    printf ("\nFim dos dados\n");
    for(j=0;j<5; j++)
        printf ("\n O numero de pessoas que responderam a opcao %d foi: %d", j+1, O[j]);
}*/
/*
#include<stdio.h>
#include <string.h>
int main(){
    int R[10], i, j, O[5], c=0, cp=0;
    char N[20];
    for(j=0;j<5; j++)
       O[j]=0;
    printf("Digite o nome da pessoa 1: ");
    scanf ("%s",N);
    while (strcmp(N,"vazio")){
        for(j=0;j<5; j++)
            O[j]=0;
        for(j=0;j<10; j++){
            do{
                printf("Digite a resposta da pergunta %d: ", j+1);
                scanf("%d", &R[j]);
            }while (R[j]<1 || R[j]>5);
            O[R[j]-1]++;
        }
        c++;
        printf ("\nRespostas da pessoa %d ===>", c);
        for(j=0;j<10; j++)
            printf("%d  ", R[j]);
        if (O[0] && O[1] && O[2]&&O[3]&&O[4])
            cp++;
        printf("\n\nDigite o nome da pessoa numero %d:", c+1);
        scanf ("%s", N);
    }
    printf ("\nFim dos dados\n");
    printf ("\n O numero de pessoas que responderam todas as opcoes foi: %d", cp);
}*/
#include <stdio.h>
int main(){
    int M[20][20], i,j,n;
	/* Valida a dimensão da matriz*/
   do{
      printf("Informe o numero de linhas e colunas da matriz quadrada (>0 e <=20)");
      scanf ("%d",&n);
   }while (n>20 || n<1);

    /*Constroi o triangulo de Pascal de ordem n*/

    for (i=0; i<n; i++){
        M[i][0]=M[i][i]=1;
        for (j=1; j<i; j++)
             M[i][j]=M[i-1][j]+M[i-1][j-1];
    }

/* Preenche a matriz triangular superior com zeros (exceto a diagonal principal*/
    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++)
            M[i][j]=0;
        for (j=0;j<n;j++)
            printf ("%d\t",M[i][j]);
        printf ("\n");
  }
}






