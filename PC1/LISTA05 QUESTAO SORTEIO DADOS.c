#include <stdio.h>

int result (int dados[], int total){
    int i,numero[5],resultado = 0, maior = 0;
    for(i=0;i<6;i++){
        numero[i] = 0;
    }
    for(i=0;i<total;i++){
        if(dados[i]==1){
            numero[0]++;
        }
        if(dados[i]==2){
            numero[1]++;
        }
        if(dados[i]==3){
            numero[2]++;
        }
        if(dados[i]==4){
            numero[3]++;
        }
        if(dados[i]==5){
            numero[4]++;
        }
        if(dados[i]==6){
            numero[5]++;
        }
    }
    for(i=0;i<6;i++){
        if(numero[i]>maior){
            maior = numero[i];
            resultado = i+1;
        }
    }
    return(resultado);
}

int main(){
    int dados_dia[5],dados_result[6];
    int ganhador_mes,i,j;
    printf("iremos comecar a analise dos jogos");
    srand (time(NULL));
    do{
        for(i=0;i<5;i++){
            do{
                printf("\n\n\n\njogadas do dia %d",i+1);
                for(j=0;j<6;j++){
                    do{
                        //printf("\ninforme o numero obtido pelo dado(jogada %d)\t",j+1);                
                        dados_result[j] = rand ()%6+1;
                        printf("\nnumero obtido dia %d/jogada%d = %d",i+1,j+1,dados_result[j]);
                        //scanf("%d",&dados_result[j]);
                    }while(dados_result[j]>6);
                }
                dados_dia[i] = result(dados_result,6);
                printf("\n\nganhador do dia %d = %d",i+1,dados_dia[i]);
            }while(dados_dia[i]==0);
        }
        ganhador_mes = result(dados_dia,5);
    }while(ganhador_mes==0);
    printf("\n\n\t\tganhador mensal = %d\n\n",ganhador_mes);
    for(i=0;i<5;i++){
        printf("\nganhador dia %d = %d",i+1,dados_dia[i]);
    }
}
/*
#include <stdio.h>

int result (int dados[][], int total){
    int i,numero[5],resultado = 0, maior = 0;
    for(i=0;i<5;i++){
        numero[i] = 0;
    }
    for(i=0;i<total;i++){
        if(dados[i]==1){
            numero[0]++;
        }
        if(dados[i]==2){
            numero[1]++;
        }
        if(dados[i]==3){
            numero[2]++;
        }
        if(dados[i]==4){
            numero[3]++;
        }
        if(dados[i]==5){
            numero[4]++;
        }
        if(dados[i]==6){
            numero[5]++;
        }
    }
    for(i=0;i<5;i++){
        if(numero[i]>maior){
            maior = numero[i];
            resultado = i+1;
        }
    }
    return(resultado);
}

int main(){
    int dados[30][41];//matriz contendo para cada dia o dado de cada uma das 40 rodadas
    int ganhador_mes,i,j;
    printf("iremos comecar a analise dos jogos");
    srand (time(NULL));
    for(i=0;i<30;i++){
        printf("\njogadas do dia %d",i+1);
        for(j=0;j<41;j++){
            if(j==41){
                continue;
            }
            printf("\ninforme o numero obtido pelo dado\t");
            dados[i][j] = rand ()%6+1;
            printf("\nnumero obtido = %d",dados[i][j]);
        }
        dados[i][41] = result(dados[i][],40);
        printf("\n\nganhador do dia %d = %d",i+1,dados[i][41]);
    }
    ganhador_mes = result(dados[][41],30);
    printf("\nganhador mensal = %d",ganhador_mes);
}*/