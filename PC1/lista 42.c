/*#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *arq;
    char *nome = "fonte.txt";
    typedef struct{
        int chave, data;
        char cond[20];



    }DADOS;

    DADOS dados;
    arq= fopen(nome, "w");
    if(arq == NULL){
        printf("Falha ao criar o arquivo.");
        exit(1);
    }else{
        printf("informe o numero da chave\t");
        scanf("%d",&dados.chave);
        printf("\ninforme o a data\t");
        scanf("%d",&dados.data);
        printf("\ninforme a condicao\t");
        scanf("%s",dados.cond);
        fprintf(arq,"chave %d\ndata %d\ncondicao %s",dados.chave,dados.data,dados.cond);
    }
    afclose(arq);
    nome = "fontenova.txt";
    arq = fopen(nome,"w");
    fprintf(arq,"chave %d\ndata %d\ncondicao %s",dados.chave,dados.data,dados.cond);
    fclose(arq);
}*/
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq;
    char *nome = "dados.txt";
    typedef struct{
        int cep, telefone;
        char nome[30], endereco[30];
    }DADOS;
    DADOS dados;
    arq = fopen(nome,"w");
    if (arq==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1);
    }else{
        printf("informe o nome\t");
        scanf("%s",dados.nome);
        printf("\ninforme o endereco\t");
        scanf("%s",dados.endereco);
        printf("\ninforme o cep\t");
        scanf("%d",&dados.cep);
        printf("\ninforme o telefone\t");
        scanf("%d",&dados.telefone);
    }
    fprintf(arq,"nome = %s\n rua de endereco = %s\n cep =%d\n telefone = %d",dados.nome,dados.endereco,dados.cep,dados.telefone);
    fclose(arq);
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;
    char *nome = "cadastro.txt";
    typedef struct{
        int altura, peso, data;
        char nome[20], sexo[20], cor[20];
    }DADOS;
    int i,total;
    DADOS *dados;
    if (arq==NULL) {
        printf("Falha ao criar o arquivo.");
        exit(1);
    }else{
        arq = fopen(nome,"w");
        printf("informe o numero total de pessoas a serem analisadas\t");
        scanf("%d",&total);
        dados = (DADOS *)malloc(total * sizeof(DADOS));
        for(i=0;i<total;i++){
            printf("\ninforme o nome da pessoa\t");
            scanf("%s",dados[i].nome);
            do{
                printf("\ninforme o sexo da pessoa.  masculino/feminino\t");
                scanf("%s",dados[i].sexo);
            }while(strcmp(dados[i].sexo,"masculino") != 0 && strcmp(dados[i].sexo,"feminino") != 0);
            printf("\ninforme a cor do olho da pessoa\t");
            scanf("%s",dados[i].cor);
            printf("\ninforme a altura da pessoa\t");
            scanf("%d",&dados[i].altura);
            printf("\ninforme o peso da pessoa\t");
            scanf("%d",&dados[i].peso);
            printf("\ninforme o dia de nascimento da pessoa\t");
            scanf("%d",&dados[i].data);
            fprintf(arq,"\n\npessoa de numero %d\nnome = %s\nsexo = %s\n cor de olhos = %s",i+1,dados[i].nome,dados[i].sexo,dados[i].cor);
            fprintf(arq,"\naltura = %d\npeso = %d\ndata = %d",dados[i].altura,dados[i].peso,dados[i].data);
        }
        fclose(arq);
    }


    for(i=0;i<total;i++){
        if(strcmp(dados[i].sexo,"masculino")==0){
            nome = "homens.txt";
            arq = fopen(nome,"w");
            fprintf(arq,"\n\nnome = %s\nsexo = 1\n cor de olhos = %s",dados[i].nome,dados[i].cor);
            fprintf(arq,"\naltura = %d\npeso = %d\ndata = %d",dados[i].altura,dados[i].peso,dados[i].data);
            fclose(arq);
        }else{
            nome = "mulheres.txt";
            arq = fopen(nome,"w");
            fprintf(arq,"\n\nnome = %s\nsexo = 2\n cor de olhos = %s",dados[i].nome,dados[i].cor);
            fprintf(arq,"\naltura = %d\npeso = %d\ndata = %d",dados[i].altura,dados[i].peso,dados[i].data);
            fclose(arq);
        }
    }
}
























