#include <stdio.h>
#include <string.h>
    int main(){
    char palavra[15];
    sprintf(palavra,"mao");
    int acertou=0,enforca=0;
    char chutes[26];
    int tentativas = 0;
    printf("*** BEM VINDO AO JOGO DA FORCA***");
    
    do{
        for(int i=0; i<strlen(palavra); i++){
            int achou = 1;

            for(int k=0; k<tentativas; k++){
                if(chutes[k] == palavra){
                    achou = 1;
                    break;
                }
            }
            if (achou){
                printf("%c ",palavra[i]);
                break;
            }else{
                printf("_ ");
            }
        }
        char chute;
        printf("\ndigite uma letra:\t");
        scanf(" %c",&chute);
        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforca);
    
    }
    