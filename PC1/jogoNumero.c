#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("\n\n***bem vindo ao jogo da adivinhacao***");
    printf("\nnesse jogo voce tera que adivinhar um numero aleatorio de 0 ah 50");
    printf("\nvoce tera tentativas e conforme voce for usando suas tentativas voce perdera pontos");
    printf("\nvoce irah iniciar o jogo com 1000 pontos");
    
    int segundos = time(0);
    srand(segundos);

    int numero1 = rand();
    int n = numero1%51;
    int nUsuario;

    int contador=1;

    while (contador<=50){
        printf("\n\n\ntentativa de numero %d",contador);
        printf("\ninsira um numero da sorte de 0 a 50:\t");
        scanf("%d",&nUsuario);
        if (nUsuario<0){
            printf("\nnao vale usar numeros negativos");
            contador--;
        }
        else if (nUsuario == n){
            printf("\n\nparabens !!!!!  \nvoce acertou o numero da sorte com %d tentativas",contador);;
            int pontoerro = 25, ponto;
            ponto = 1000-(pontoerro*contador);
            printf("\nos seus pontos finais eh de %d",ponto);
            break;
        }
        else if (nUsuario < n){
            printf("voce errou!!!");
            printf("\n\no numero da sorte eh maior");
        }
        else {
            printf("voce errou!!!");
            printf("\n\no numero da sorte eh menor");
        }
        contador++;
    }

    printf("\n\nobrigado por jogar o jogo\n\n");
}

