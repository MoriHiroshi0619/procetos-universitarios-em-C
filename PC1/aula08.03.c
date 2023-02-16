//Faça um programa que leia um ponto do plano cartesiano e escreva em qual quadrante ele se encontra.
/*#include <stdio.h>
typedef struct{
    float x;
    float y;
}Ponto2d;
int main(){
    Ponto2d p;
    int i, n;
    printf ("Informe uma quantidade de pontos para serem classificados: ");
    scanf ("%d", &n);
    for (i=0; i<n; i++){
        printf ("Informe a coordenadas x e y do ponto : ");
        scanf ("%f %f", &(p.x), &(p.y));
        if (p.x>0.0){
            if (p.y>0.0)
                printf ("O ponto p esta no I quadrante\n");
            else if (p.y<0.0)
                printf (" O ponto p esta no IV quadrante\n");
        } else if (p.x<0.0){
            if (p.y>0.0)
                printf ("O ponto p esta no II quadrante\n");
            else if (p.y<0.0)
                printf (" O ponto p esta no III quadrante\n");
        }
    }
}*/
//Faça um programa que leia um ponto do plano cartesiano e escreva em qual quadrante ele se encontra.
//vom vetores
/*
#include <stdio.h>
typedef struct{
    float x;
    float y;
}Ponto2d;
int main(){
    Ponto2d p[10];
    int i, n;
    do {
        printf ("Informe uma quantidade de pontos para serem classificados: ");
        scanf ("%d", &n);
    }while (n<1 || n>10 );

    for (i=0; i<n; i++){
        printf ("Informe a coordenadas x e y do ponto : ");
        scanf ("%f %f", &(p[i].x), &(p[i].y));
        if (p[i].x>0.0){
            if (p[i].y>0.0)
                printf ("O ponto p esta no I quadrante\n");
            else if (p[i].y<0.0)
                printf (" O ponto p esta no IV quadrante\n");
        } else if (p[i].x<0.0){
            if (p[i].y>0.0)
                printf ("O ponto p esta no II quadrante\n");
            else if (p[i].y<0.0)
                printf (" O ponto p esta no III quadrante\n");
        }
    }
}*/

//Faça um programa que leia um ponto do plano cartesiano e escreva em qual quadrante ele se encontra.
//diferentes tipos de dados
/*
#include <stdio.h>
typedef struct //Inicio da definição da estrutura 
{
  char nome[8];
  int nmat; // Número da matrícula 
  float nota[3]; // Notas 
  float media; // Média 
}Cadastro; // Fim da definição 
int main(){
    Cadastro aluno[10];//Declara uma variável do tipo Cadastro 
    int i,j;
    printf ("Informe os dados de 10 alunos\n");
    for (i=0; i<10; i++){
        printf ("Nome do aluno\n");
        scanf ("%s", aluno[i].nome);
        printf ("numero de matricula\n");
        scanf ("%d", &aluno[i].nmat);
        printf ("Informe as tres notas\n");
        for (j=0;j<3; j++)
            scanf ("%f",&aluno[i].nota[j]);

        aluno[i].media= (aluno[i].nota[0] + aluno[i].nota[1]+ aluno[i].nota[2])/3.0;
    }

    printf ("Imprimindo dados dos 10 alunos\n");
    for (i=0; i<10; i++){
        printf ("aluno %d\n", i+1);
        printf ("nome: %s\n",aluno[i].nome);
        printf ("numero de matricula: %d\n",aluno[i].nmat );
        printf ("Nota 1: %2.2f - Nota 2: %2.2f – Nota 3:%2.2f\n", aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2]);
        printf ("media das notas: %2.2f\n",aluno[i].media);
    }

}
*/
//Faça um programa que leia um ponto do plano cartesiano e escreva em qual quadrante ele se encontra.
#include <stdio.h>
typedef struct /*Inicio da definição da estrutura */{
  char nome[8];
  int nmat; /* Número da matrícula */
  float nota[3]; /* Notas */
  float media; /* Média */
}Cadastro; /* Fim da definição */

int main(){
    Cadastro aluno[5];/* Declara uma variável do tipo Cadastro */
    int i,j;
    printf ("Informe os dados de 5 alunos\n");
    for (i=0; i<5; i++){
        printf ("==============================\n");
        printf ("Dados do ALUNO %d\n", i);
        printf ("==============================\n");
        printf ("Nome do aluno\n");
        scanf ("%s", aluno[i].nome);
        printf ("numero de matricula\n");
        scanf ("%d", &aluno[i].nmat);
        printf ("Informe as tres NOTAS\n");
        for (j=0;j<3; j++){
            printf ("NOTA %d do ALUNO %d\n", j, i);
            scanf ("%f",&aluno[i].nota[j]);
        }
        aluno[i].media= (aluno[i].nota[0] + aluno[i].nota[1]+ aluno[i].nota[2])/3.0;
    }
    printf ("===============================\n");
    /* Imprimindo*/
    printf ("Imprimindo dados dos 5 alunos\n");
    for (i=0; i<5; i++){
        printf ("============================\n");
        printf ("Aluno %d\n", i);
        printf ("Nome: %s\n", aluno[i].nome);
        printf ("Numero de Matricula: %d\n",aluno[i].nmat );
        printf ("Nota 1: %2.2f\tNota 2: %2.2f\tNota 3:%2.2f\n", aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2]);
        printf ("Media das notas: %2.2f\n",aluno[i].media);
    }

}


