
/*include <stdio.h>

int main(){
    int *p;
    printf ("Endereco de p: %d\n", &p);
    printf ("Valor de p: %d\n", p);
    p = (int*)malloc(4);
    printf ("Valor de p: %d\n", p);
    printf ("Valor do endereco apontado por p: %d\n", *p);
    *p = 5;
    printf ("Valor do endereco apontado por p: %d\n", *p);

}*/ 
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, *vet;
    printf("Informe numero de elementos: \n");
    scanf("%d", &n);
    if ((vet=(int *)malloc(n * sizeof(int)))==NULL){
        printf("Erro de alocação de memoria !\n");
        exit(1);
    }
    for (i=0; i<n; i++)
        scanf("%d", &vet[i]);
    for (i=0; i<n; i++)
        printf("%d ", vet[i]);
    free(vet);
}*/
/*
#include <stdio.h>
#include <string.h>

void main(void) {
    char sir1[40];
    char *sir2;
    printf("Informe uma string: \n");
    scanf("%40s", sir1);
    if ((sir2=(char *)malloc(strlen(sir1)+1))==NULL) {
        printf("Erro na alocação de memória !\n");
        exit(1);
    }
    strcpy(sir2, sir1);
    printf("A copia e: %s \n", sir2);

}
*/ /*
#include <stdio.h>

int main(){
    int *p,i;
    printf ("Endereco de p: %d\n", &p);
    printf ("Valor de p: %d\n", *p);
    p = (int*)malloc(5 * (sizeof *p));
    printf ("Valor de p: %d\n", p);
    printf ("Valor do endereco apontado por p: %d\n", *p);
    *p = 5;
    printf ("Valor do endereco apontado por p: %d\n", *p);
    *p += 5;
    printf ("Valor do endereco apontado por p: %d\n", *p);
    printf ("Endereco de p: %d\n\n\n", &p);
    for(i=0;i<5;i++){
        p[i] = i*5;
        printf("\ni = %d:",i);
        printf ("Valor do endereco apontado por p: %d\n", p[i]);
        printf ("Endereco de p com pocisao de vetor: %d\n", &p[i]);
        printf ("Endereco de p: %d\n\n", &p);
    }
    printf ("Valor de p: %d\n", p);
    printf ("Endereco de p: %d\n\n", &p);
    printf ("Endereco de p com pocisao de vetor: %d\n", &p[4]);
    printf ("Valor do endereco apontado por p: %d\n", p[4]);
    printf ("Valor de p: %d\n", p);
}*/
/*                        nao funciona
#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n, i,j, **mat;
    printf("Informe numero de linhas: \n");
    scanf("%d", &m);
    if ((mat=(int *)malloc(m * sizeof(int)))==NULL) {
        printf("Erro de alocação de memoria !\n");
        exit(1);
    }
    printf("\nendereco de mat %d\n\n",&mat);
    for(i=0;i<m;i++){
        printf("\n %d",mat[i]);
        printf("\n *%d",*mat[i]);
        printf("\nendereco de mat %d\n",&mat);
    }
    printf("\nInforme numero de colunas: \n");
    scanf("%d", &n);
    printf("\nendereco de mat %d\n\n",&mat);
    for(i=0;i<m;i++){
        printf("\n coluna%d",mat[i]);
        printf("\n coluna*%d",*mat[i]);
        for(i=0; i<n; i++){
            printf("\nlinhas %d",mat[i][j]);
            printf("\nlinhas *%d",*mat[i][j]);
            printf("\nendereco de mat %d\n",&mat);
        }
    }
    for (i=0; i<m; i++)
        if ((mat[i]=(int *)malloc(n * sizeof(int)))==NULL) {
            printf("Erro de alocação de memoria !\n");
            exit(1);
        }
    printf ("Lendo matriz\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++)
            scanf("%d", &mat[i][j]);
    }
    for (i=0; i<m; i++){
       for (j=0; j<n; j++){
         printf("%d ", mat[i][j]);
       }
       printf ("\n");
    }
    free(mat);
}
*/
#include <stdio.h>

int main(){
    int m, n, i,j, **mat,tam;
    printf ("Endereco de mat: %d\n ",&mat );
    printf ("Endereco que mat aponta : %d\n ",mat );
    tam = sizeof(mat);
    printf("\ntamanho de mat = %d\n",tam);
    printf("Informe numero de linhas: \n");
    scanf("%d", &m);
    if ((mat=(int *)malloc(m * sizeof(int)))==NULL) {
        printf("Erro de alocação de memoria !\n");
        exit(1);
    }
    printf ("Endereco que mat aponta : %d\n ",mat );

    for (i=0; i<m; i++)
        printf ("Endereco de mat[%d] : %d\n ",i, &mat[i] );

    printf("Informe numero de colunas: \n");
    scanf("%d", &n);
    for (i=0; i<m; i++)
        if ((mat[i]=(int *)malloc(n * sizeof(int)))==NULL) {
            printf("Erro de alocação de memoria !\n");
            exit(1);
        }

    for (i=0; i<m; i++)
        printf ("Endereco que mat[%d] aponta: %d\n ",i, mat[i] );

    printf ("Lendo matriz\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf ("Endereco de mat[%d][%d] : %d\n ",i,j, &mat[i][j] );
        }
    }
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for (i=0; i<m; i++){
       for (j=0; j<n; j++){
         printf("%d ", mat[i][j]);
       }
       printf ("\n");
    }
    tam = sizeof(mat);
    printf("\ntamanho de mat = %d",tam);

    free(mat);
}




/*
#include <stdio.h>

int main(){
    int *v, n = 5, i;
    v = calloc(n,sizeof (int));
    if(v == NULL){
        printf("Espaço Insuficiente para alocar \n"); exit(1);
    }else{
        for(i = 0; i < n; i++)
            printf("\n vet[%d]=%d ",i, v[i]);
    }

}*/



#include <stdio.h>
int *soma_vetor4(int *a, int *b, int n) {
    int * r;
    r=(int *) malloc(sizeof (int) * n);
    if (r==NULL) exit(1);
     int i;
     for (i=0; i<n; i++, a++, b++)
             r[i]=*a+*b;
      return r;
}
int main(){
    int i;
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    int * rr;
    rr=soma_vetor4(a,b,3);
    for (i=0;i<3;i++)
        printf ("%d ", rr[i]);
}
