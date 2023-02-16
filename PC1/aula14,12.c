                            // ARQUIVOS 

                        //lendo texto direto do ARQUIVO
/*
#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *ptr;
	char nomeArquivo[20];
	int total=0;
	printf ("Informe o nome do arquivo a ser lido: ");
	scanf("%s", nomeArquivo);
	ptr = fopen(nomeArquivo, "rt");
	if (ptr==NULL) {
		printf("Arquivo nao existe.");
		exit(1);
	}
	while (getc(ptr)!=EOF)  
    total++;
	printf("O numero de caracteres lidos no arquivo %s eh %d", nomeArquivo, total);
 }*/




                //lendo texto indiretamente do arquivo 

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() { 
	FILE *ptr;
	char nomeArquivo[20],linha[102];
	int total=0;
	printf ("Informe o nome do arquivo a ser lido: ");
	scanf("%s", nomeArquivo);
	ptr = fopen(nomeArquivo, "rt");
	if (ptr==NULL) {
		printf("Arquivo não existe.");
		exit(1);
	}
	fgets(linha, 100, ptr);
	printf ("A string eh : %s\n", linha);
	total=strlen(linha);
	printf("O numero de caracteres lidos no arquivo %s eh %d", nomeArquivo, total);
 }
*/
                                    //lendo caractere por caractere e imrpimindo ele indiretamente 
/*
 #include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *ptr; char nomeArquivo[20], caracter;
	printf ("Informe o nome do arquivo a ser lido: ");
	scanf("%s", nomeArquivo);
	ptr = fopen(nomeArquivo, "rt");
	if (ptr==NULL) {
		printf("Arquivo não existe.");
		exit(1); }
	caracter=getc(ptr);
 	while (caracter!=EOF){
		printf("%c", caracter);
 		caracter=getc(ptr); 
    }
}*/

// criar e modificar um numero

/*
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	FILE *arquivo;
	char nome[10];
	int quantidade, i;
	printf("Digite o nome do arquivo:");
	scanf("%s", nome);
	printf("Digite a quantidade de numeros:");
	scanf("%d", &quantidade);
    arquivo = fopen(nome, "w");
    if (arquivo==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1); }
    else {
        for (i=1;i<=quantidade;i++)
            fprintf(arquivo, "%d\n", rand()%100);
    }
    fclose(arquivo);
}

*/


                                //utilizando struct

#include<stdio.h>
#include<stdlib.h>
int main(){
   FILE *arq;
   char *nome = "alunos.txt";
   int i, num;
   typedef struct{
        char nome[10];
        int matricula;
        float nota;
    }cadaluno;

    cadaluno aluno;
    
    arq= fopen(nome, "w");
    if (arq==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1); }
    else {
        printf ("Informe o numero de alunos: ");
        scanf ("%d", &num);
        printf ("Entrada dos dados dos %d alunos da faculdade\n", num);
        for(i = 0; i < num; i++){
            printf ("Aluno No %d\n", i+1);
            printf ("Nome do aluno: ");
            scanf ("%s", aluno.nome);
            printf ("Numero de matricula: ");
            scanf ("%d", &aluno.matricula);
            printf ("Nota: ");
            scanf ("%f", &aluno.nota);
            fprintf (arq, "%s %d %2.1f\n", aluno.nome, aluno.matricula, aluno.nota);
        }
    }

   fclose(arq);
}



/*
#include<stdio.h>
#include<stdlib.h>
int main(){
   FILE *arq;
   char *nome = "alunos.txt";
   int i, num;
   typedef struct{
        char nome[10];
        int matricula;
        float nota;
    }cadaluno;

    cadaluno aluno;

    arq= fopen(nome, "w");
    if (arq==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1); }
    else {
        printf ("Informe o numero de alunos: ");
        scanf ("%d", &num);
        printf ("Entrada dos dados dos %d alunos da faculdade\n", num);
        fprintf (arq, "Nome\t\t Matricula\t\t Nota\n");
        for(i = 0; i < num; i++){
            printf ("Aluno No %d\n", i+1);
            printf ("Nome do aluno: ");
            scanf ("%s", aluno.nome);
            printf ("Numero de matricula: ");
            scanf ("%d", &aluno.matricula);
            printf ("Nota: ");
            scanf ("%f", &aluno.nota);
            fprintf (arq, "%s\t\t %d\t\t %2.1f\n", aluno.nome, aluno.matricula, aluno.nota);
        }
    }

   fclose(arq);
}*/




                        //programa para gerar numeros no arquivo DADOS
/*
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	FILE *arquivo;
	char *nome="dados.txt";
	int quantidade, i;
	printf("Digite a quantidade de numeros:");
	scanf("%d", &quantidade);
    arquivo = fopen(nome, "w");
    if (arquivo==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1); }
    else {
        for (i=1;i<=quantidade;i++)
            fprintf(arquivo, "%d ", rand()%100);
    }
    fclose(arquivo);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
int main (void) {
    int x, n, k; 
    double soma;
    FILE *entrada;
    entrada = fopen ("dados.txt", "r");
    if (entrada == NULL){
       printf ("\nNao encontrei arquivo\n");
       exit (EXIT_FAILURE);
    }
   soma = n = 0;
   while (TRUE) {
        k = fscanf (entrada, "%d", &x);
        if (k != 1){
            break;
        }
        soma += x;
        n ++;
    }
    fclose (entrada);
    printf ("A media dos numeros eh %f\n", soma/n);
}
*/



                    // mesmo programa porem juntos em um so

/*
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
int main (void) {
	FILE *arquivo;
	char *nome="dados.txt";
	int quantidade, i;
	int x, n, k; double soma = 0;

	printf("Digite a quantidade de numeros:");
	scanf("%d", &quantidade);
    arquivo = fopen(nome, "w+");
    if (arquivo==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1); }
    else {
        for (i=1;i<=quantidade;i++)
            fprintf(arquivo, "%d ", rand()%100);

        rewind (arquivo);
        soma = n = 0;
        while (TRUE) {
         k = fscanf (arquivo, "%d", &x);
         if (k != 1) break;
         soma += x; n ++;
        }
        fclose (arquivo);
        printf ("A media dos numeros eh %f\n", soma/n);
    }
}*/




                    //
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int main () {
	char palavra[MAX];
	int i; float f; FILE *pa;
	char *nome = "format.txt";
	// Abre o arquivo para leitura e escrita 
	if (( pa = fopen(nome, "w+")) == NULL) {
		printf("\n\nNao foi possivel abrir o arquivo.\n"); exit(1);
	}
	puts ("Entre com uma palavra."); scanf ("%s", palavra);
	puts ("Entre com um numero inteiro."); scanf("%d", &i);
	puts ("Entre com um numero flutuante."); scanf("%f", &f);
	// Escreve os dados no arquivo 
	fprintf(pa, "%s %d %f", palavra, i, f);
	rewind(pa); // volta ao inicio do arquivo 
	printf("\nTerminei de escrever, agora vou ler.\n");
       fscanf(pa, "%s %d %f", palavra, &i, &f);
	printf("Palavra lida: %s\n", palavra);
	printf("Inteiro lido: %d\n", i);
	printf("Float lido: %f\n", f);
	fclose(pa); getchar(); // Espera o usuario digitar alguma coisa 
}*/


                    //
/*
#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *parq;
	char *nome = "dados.dat";
	char c; int i, j;
	//Abre o arquivo
	if((parq = fopen(nome, "w+")) == NULL){
		printf("\n\nO arquivo nao pode ser aberto."); exit	(1);
	}
//Grava os caracteres
	for(i = 0; i < 10; i++){
		c = getche();
		for(j = 0; j < 10; j++)
			fputc(c, parq);
	}
	rewind(parq);
	//Volta ao inicio do arquivo
	//Exibe o conteudo do arquivo
	while(!feof(parq)) printf("%c", fgetc(parq));
	fclose(parq);
	getche();
}
*/






