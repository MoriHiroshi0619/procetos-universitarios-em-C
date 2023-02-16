#include <stdio.h>
#include <string.h>

int main (){
    char palavra[10];
    sprintf(palavra,"mao");
    int acertou=0, enforco =0;

    printf("***BEM VINDO AO JOGO DA FORCA***");
    
    do{
        char chute;
        printf("\ndigite uma letra\t");
        scanf(" %c",&chute);
        for(int i=0; i<strlen(palavra); i++ ){
            if (chute=palavra[i]){
                printf("\nletra %c na posisao %d",palavra[i],i+1);
            }
        }
    }while(!acertou && !enforco);
}