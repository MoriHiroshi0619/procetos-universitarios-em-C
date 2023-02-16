/*#include <stdio.h>
int main (){
    int sim=0, nao=0, indife = 0, p[100],i;
    srand(time(NULL));
    for(i=0;i<100;i++){
        printf("\npergunta numero %i",i);
        p[i] = rand()%3;
        printf("resposta = %d",p[i]);
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
    printf("\nsim = %d",sim);
    printf("\nnao = %d",nao);
    printf("\nindiferente = %d",indife);
}*/
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