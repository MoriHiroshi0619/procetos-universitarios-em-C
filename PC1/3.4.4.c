#include <stdio.h>
typedef struct {
    int numero, aposta[10],pontos;
    char nome[30];
}dados;
int dezenas_sorteadas(int *vet1, int x, int *vet2, int y)
{
    int pontos = 0, i,j;
    for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                int valorAposta = vet2[j];
                if(vet1[i] == valorAposta){
                    if(pontos == 5){
                        break;
                    }
                    pontos++;
                    break;
                }
            }
    }
    return(pontos);
}
int main ( )
{
    dados loto[30];
    int i, sorteada[5],numero_aposta, keep = 1,j,resposta,total=0,terno=0,quarto=0,quinto=0;
    
    printf("informe as 5 dezenas sorteadas ");
    for(i=0;i<5;i++)
    {
        printf("\n dezena de numero %d \t",i+1);
        scanf("%d", &sorteada[i]);
    }
    i=0;        
    while(keep)
    {
        printf("\ninforme o nome\t");
        scanf("%s", loto[i].nome);
        printf("\ninforme o numero da aposta\t");
        scanf("%d", &loto[i].numero);
        do{
            printf("\n informe a quantidade de dezenas apostadas (max 10)\t");
            scanf("%d",&numero_aposta);
        }while(numero_aposta>10);
        for(j=0;j<numero_aposta;j++){
            do{
                printf("\ninforme a aposta (dezena de numero %d)\t",j+1);
                scanf("%d", &loto[i].aposta[j]);
            }while(loto[i].aposta[j]>99);
        }
        
        loto[i].pontos = dezenas_sorteadas(sorteada, 5, loto[i].aposta, 10);
        
        if(loto[i].pontos == 3){
            terno++;
        }else if(loto[i].pontos == 4){
            quarto++;
        }else if (loto[i].pontos == 5){
            quinto++;
        }     
        i++;
        printf("/n se desejar parar digite 0, senao digite 1\t");
        scanf("%d", &resposta);
        if(resposta==0){
            keep = 0;
            total = i   ;
        }
    }
    printf("\n\nmostrar resultado");
    for(i=0;i<total;i++){
        /*if(loto[i].pontos<=2){
            continue;
        }*/
        printf("\n\nnome = %s",loto[i].nome);
        printf("\nnumero aposta = %d",loto[i].numero);
        printf("\npontos = %d",loto[i].pontos);
    }
    printf("\n\n");
    printf("\ntotal de terno = %d",terno);
    printf("\ntotal de quarto = %d",quarto);
    printf("\ntotal de quinto = %d",quinto);
}