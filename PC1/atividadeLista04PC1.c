//1
/*
#include <stdio.h>

int main (){
    int temp[10],maior, menor,i,dias = 0,soma = 0;
    float media;
    for(i=0;i<10;i++){
        do{
            printf("\ninforme a temperadura do dia %d\t",i);
            scanf("%d",&temp[i]);
        }while(temp[i]<15 || temp[i]>40);
        if(i==0){
            maior = temp[i];
            menor = temp[i]; 
        }
        if(temp[i]>maior){
            maior = temp[i];
        }
        if(temp[i]<menor){
            menor = temp[i];
        }
        soma += temp[i];
        media = (float)soma/10;
    }
    for(i=0;i<10;i++){
        if(temp[i]<media){
            dias++;
        }
    }
    printf("\na menor temperatura foi %d",menor);
    printf("\na maior temperatura foi %d",maior);
    printf("\na temperatura media foi %.1f",media);
    printf("\nforam um total de %d dias com temperatura a media",dias);
}*/
//2 nao terminado
/*
#include <stdio.h>
#include <string.h>

int main (){
    int tamanho;
    char frase[80];
    printf("digite a frase\n");
    gets(frase);
    tamanho = strlen(frase);
    printf("\nfrase com total de %d caracteres",tamanho);
    if(strcmp(frase,"branco")<0){
        printf("achou");
    }
}*/
//4
/*
#include <stdio.h>
#include <math.h>

int main(){
    int soma,i,j = 100,b[101];
    for(i=1;i<=100;i++){
        printf("\ndigite o valor de numero %d:\t",i);
        scanf("%d",&b[i]);
    }
    for(i=1;i<=50;i++){
        printf("(%d-%d)3 + ",b[i],b[j]);
        soma += pow(b[i] - b[j],3); 
        j--;
    }
    printf("\nsoma = %d",soma);

}*/
//5
/*
#include <stdio.h>
int main(){
    int nota[10],comp[11],i,j,local,count[10];
    for(i=0;i<11;i++){
        comp[i] = i;
    }
    for(i=0;i<10;i++){
        do{
            printf("\ndigite a nota %d:\t",i);
            scanf("%d",&nota[i]);
        }while(nota[i]<0||nota[i]>10);
    }
    for(i=0;i<10;i++){
        count[i] = 0;
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(nota[i] == nota[j]){
                count[i]++;
            }
        }
    }
    for(i=0;i<10;i++){
        printf("\nnota %d frequencia absoluta %d",nota[i],count[i]);
    }

}*/
//7
/*
#include <stdio.h>

int main(){
    int mercadoria[10],quant[10],i;
    float faturamento=0,preco[10];
    for(i=0;i<10;i++){
        mercadoria[i] = i;
        printf("\ninforme o preco da mercadoria %d:\t",i);
        scanf("%f",&preco[i]);
        printf("\ninforme a quantidade de mercadoria vendidas do produto %d:\t",i);
        scanf("%d",&quant[i]);
    }
    for(i=0;i<10;i++){
        faturamento += preco[i]*(float)quant[i];
    }
    printf("\nfaturamento mensal da loja de %.1f reais",faturamento);
}*/
//8
/*
#include <stdio.h>
int main(){
    int empre[10],meses[10],i,menor1 = 0,menor2 = 0, menor3 = 0,loc1,loc2,loc3;
    for(i=0;i<10;i++){
        printf("\ninforme o numero de cadastro do empregado:\t");
        scanf("%d",&empre[i]);
        printf("\ninforme o numero de meses trabalhado do empregado:\t");
        scanf("%d",&meses[i]);
        if(i==0){
            menor1 = meses[i];
            loc1 = i;
        }
        if(meses[i] < menor1){
            menor1 = meses[i];
            loc1 = i;
        }
    }
    for(i=0;i<10;i++){
        if(i == loc1){
            continue;
        }
        if(i==0){
            menor2 = meses[i];
            loc2 = i;
        }
        if(meses[i]<menor2){
            menor2 = meses[i];
            loc2 = i;
        }
    }
    for(i=0;i<10;i++){
        if(i == loc1 || i == loc2){
            continue;
        }
        if(i==0){
            menor3 = meses[i];
            loc3 = i;
        }
        if(meses[i]<menor3){
            menor3 = meses[i];
            loc3 = i;
        }
    }
    printf("\nempregado primeiro mais recente %d. %d meses trabalhados",empre[loc1],menor1);
    printf("\nempregado segundo mais recente %d. %d meses trabalhados",empre[loc2],menor2);
    printf("\nempregado terceiro mais recente %d. %d meses trabalhados",empre[loc3],menor3);
}*/
//9
/*
#include <stdio.h>
int main(){
    int a[10],b[10],x,i,loc;
    printf("\ninforme o valor de x:\t");
    scanf("%d",&x);
    for(i=0;i<10;i++){
        printf("\ninforme o valor de a no elemento %d:\t",i);
        scanf("%d",&a[i]);
        printf("\ninforme o valor de b no elemento %d:\t",i);
        scanf("%d",&b[i]);
    }
    for(i=0;i<10;i++){
        if(x==a[i]){
            loc = i;
        }
    }
    printf("\nelemento a igual a x = %d. elemento b de posicao correspondente de a igual a x = %d",a[loc],b[loc]);
}*/
//22
/*
#include <stdio.h>
int main(){
    int a[100][200],i,j,soma=0;
    srand (time(NULL));
    for(i=0;i<100;i++){
        for(j=0;j<200;j++){
            a[i][j] = rand()%100;
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<200;j++){
            printf("\n[%d],[%d] = %d",i+1,j+1,a[i][j]);
        }
    }
    for(i=0;i<200;i++){
        soma += a[40][i];
    }
    printf("\n\nsomatorio da coluna 40 = %d",soma);
}*/
//23
/*
#include <stdio.h>
int main(){
    int a[100][200],i,j,soma=0;
    srand (time(NULL));
    for(i=0;i<100;i++){
        for(j=0;j<200;j++){
            a[i][j] = rand()%100;
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<200;j++){
            printf("\n[%d],[%d] = %d",i+1,j+1,a[i][j]);
        }
    }
    for(i=0;i<200;i++){
        soma += a[30][i];
    }
    printf("\n\nsomatorio da coluna 30 = %d",soma);
*/
//24
/*
#include <stdio.h> 
int main (){
    int a[2][4],b[2][4],soma=0,i,j;
    srand (time(NULL));
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){   
            a[i][j] = rand()%100;
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            b[i][j] = rand()%100;
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            soma += a[i][j] + b[i][j];
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            printf("\n[%d],[%d] = %d",i+1,j+1,a[i][j]);
        }
    }
    printf("\nsomatorio de todos os elementos = %d",soma);
}*/
//25
/*
#include <stdio.h>
int main (){
    int a[20][30],b[20][30],soma = 0,i,j,x,y;
    srand(time(NULL));
    do{
        printf("informe o numero de linhas da matriz:(limite de ate 20)\t");
        scanf("%d",&x);
    }while(x>20);
    do{
        printf("\ninforme o numero de colunas da matriz:(limmite de ate 30)\t");
        scanf("%d",&y);
    }while(y>30);
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            a[i][j] = rand()%100;
            b[i][j] = rand()%100;
            soma += a[i][j] + b[i][j];
        }
    }
    printf("\n matriz A ");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("\n [%d],[%d] = %d",i+1,j+1,a[i][j]);
        }
    }
    printf("\n matriz B ");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("\n [%d],[%d] = %d",i+1,j+1,b[i][j]);
        }
    }
    printf("\nsomatorio de tudo = %d",soma);
}*/
//26
/*
#include <stdio.h>
int main(){
    srand(time(NULL));
    int a[20][30],b[30][20],i,j,linha,coluna;
    printf("\ninforme o numero de linhas da matriz a (ate 20 linhas):\t");
    scanf("%d",&linha);
    printf("\ninforme o numero de colunas da matriz a (ate 30 colunas):\t");
    scanf("%d",&coluna);
    printf("\nimprimindo matriz a ");
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            a[i][j] = rand()%100;
            printf("\n [%d],[%d] = %d",i+1,j+1,a[i][j]);
        }
    }
    printf("\nimprimindo matriz b ");
    for(i=0;i<coluna;i++){
        for(j=0;j<linha;j++){
            printf("\n [%d],[%d] = %d",i+1,j+1,a[i][j]);
        }
    }
}
*/
                                                        //REGISTROS
//1
/*
#include <stdio.h>
typedef struct{
    char nome[10];
    float salario;
    int idade,sexo;
}cadastro;
int main(){
    cadastro reg
}*/
//2
/*
#include <stdio.h>
typedef struct{
    char nome[10];
    float salario;
    int idade,sexo;
}cadastro;
int main(){
    cadastro reg;
    reg.salario = 7840212.00
}*/
//3
/*
#include <stdio.h>

typedef struct {
    int incrissao,classe,horasnomal,horasextra;
    float salarioFinal, salarioExtraFinal,salarioLiquido;
    char nome [10]
}cadastro;

int main (){
    cadastro reg[100];
    int i,total,keep;
    float salarionormal,salarioextra,salariobase,basextra;

    printf("informe o salario por horas normais:\t");
    scanf("%f",&salariobase);
    basextra = (salariobase*0.3)+salariobase;
    i=0;
    printf("\n iniciar analise dos funcionarios\n\n\n");
    while(keep){
        printf("\n\n");
        printf("\npasso %d",i+1);
        printf("\ninforme o numero de incrissao do funcionario(a) (caso queira terminar digite 0):\t");
        scanf("%d",&reg[i].incrissao);
        if(reg[i].incrissao == 0){
            break;
        }
        printf("\ninforme o nome do funcionario(a):\t");
        scanf("%s",reg[i].nome);
        printf("\ninforme o numero da classe do funcionario(a):\t");
        scanf("%d",&reg[i].classe);\
        printf("\ninforme quantas horas normais  o(a) %s trabalhou:\t",reg[i].nome);
        scanf("%d",&reg[i].horasnomal);
        reg[i].salarioFinal = reg[i].horasnomal * salariobase;
        printf("\ninforme as horas extras:\t");
        scanf("%d",&reg[i].horasextra);
        reg[i].salarioExtraFinal = reg[i].horasextra * basextra;
        reg[i].salarioLiquido = reg[i].salarioFinal + reg[i].salarioExtraFinal - ((reg[i].salarioFinal + reg[i].salarioExtraFinal)*0.08);
        //total = i;
        i++;
        total = i;
    }
    printf("\n\n\n");
    for(i=0;i<total;i++){
        if(total == 0){
            break;
        }
        printf("\n");
        printf("\nfuncionario: %d",reg[i].incrissao);
        printf("\nnome: %s",reg[i].nome);
        printf("\nclasse: %d",reg[i].classe);
        printf("\nsalario horas normal: %.2f reais",reg[i].salarioFinal);
        printf("\nsalario horas extras: %.2f reais",reg[i].salarioExtraFinal);
        printf("\nsalario final com reducao do inss: %.2f reais",reg[i].salarioLiquido);
    }
}*/
//4

#include <stdio.h>
typedef struct {
    int numero,lugar;
    float preco;
    int tipo;
} ingresso;
int main (){
    ingresso voo[10];
    int keep = 1, i, passageiro[100],vooWish;
    float total[10] ,somatotal = 0,vendido[10],ref[10];
    printf("informe os dados dos 10 voos\n\n\n\n");
    for(i=0;i<10;i++){
        printf("\n passo %d",i+1);
        printf("\ninforme o numero de voo:\t");
        scanf("%d",&voo[i].numero);
        do{
        printf("\ninforme o tipo de aviao (707,727,737):\t");
        scanf("%d",&voo[i].tipo);
        }while(voo[i].tipo != 707 && voo[i].tipo != 727 && voo[i].tipo != 737);
        printf("\ninforme a quantidade de lugares para o aviao:\t");
        scanf("%d",&voo[i].lugar);
        printf("\ninforme o preco de cada passagem:\t");
        scanf("%f",&voo[i].preco);
    }
    printf("\n\nagora iremos iniciar as RESERVAS\n\n");
    for(i=0;i<10;i++){
        vendido[i] = 0;
        ref[i] = voo[i].lugar - (voo[i].lugar * 0.6);
    }
    i=0;
    while(keep){
        printf("\n\n");
        printf("\ninforme o numero de identidade do passageiro (flag = 0):\t");
        scanf("%d",&passageiro[i]);
        if (passageiro[i] == 0){
            break;
        }
        do{
        printf("\ninforme o numero de voo desejado. (1 a 10):\t");
        scanf("%d",&vooWish);
        vooWish--;
        }while(vooWish > 10);
        if(voo[vooWish].lugar != 0 ){
            voo[vooWish].lugar--;
            vendido[vooWish]++;
            printf("\n\npassageiro  de identidade %d",passageiro[i]);
            printf("\nvoo %d desejado.",vooWish);
            printf("\npreco da passagem %.2f reais.",voo[vooWish].preco);
            printf("\nRESERVA CONFIRMADA");
        }else{
            printf("\n\npassageiro  de identidade %d",passageiro[i]);
            printf("\nvoo %d desejado.",vooWish);
            printf("\nVOO LOTADO");
        }
        i++;
    }
    for(i=0;i<10;i++){
        total[i] = vendido[i] * voo[i].preco;
        somatotal += total[i];
    }
    for(i=0;i<10;i++){
        if (voo[i].lugar>=ref[i]){
            printf("\nvoo %d, faturamento de %.2f reais. estado PREJUIZO",i+1,total[i]);
        }else{
            printf("\nvoo %d, faturamento de %.2f reais. estado LUCRO",i+1,total[i]);
        }
    }
    printf("\n\n faturamento total de %.2f reais.",somatotal);
    
}
/*
#include <stdio.h>
int main (){
    int sim=0, nao=0, indife = 0, p[100],i;
    srand(time(NULL));
    for(i=0;i<100,i++){
        printf("pergunta numero %i",i);
        p[i] = rand()%2;
        if (p[i]==0){
            sim++;
        }
        else if (p[i] == 1){
            nao++;
        }
        else{
            indife++;
        }
    }
}/*