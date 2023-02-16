/*Capicuas são números que têm o mesmo valor, se lidos da esquerda para a direita ou da direita para a esquerda. 
Ex.: 44, 232, etc. Escrever um algoritmo que determine e escreva todos os números inteiros menores que 5000 que são capicuas.
O algoritmo deverá conter PELO MENOS UM dos módulos a seguir: 

- uma função que calcule quantos algarismos tem um determinado número inteiro;

- um procedimento para separar um número em n algarismos;

- um procedimento para formar o número na ordem inversa.*/

                                            //prototipo
/*
#include <stdio.h>
#include <string.h>
int main(){
    int algarismos,i,j,ref = 1 ;
    char numero[10];
    printf("insira numero\t");
    scanf("%s",&numero);
    printf("\n%s",numero);
    algarismos = strlen(numero);
    printf("\n%d\n",algarismos);
    for(i=0;i<algarismos;i++){
        printf(" %c",numero[i]);
    }
    j = algarismos - 1;
    printf("\n\n");
    for(i=0;i<algarismos;i++){
        printf(" %c",numero[j]);
        j--;
    }
    j = algarismos-1;
    for(i=0;i<algarismos;i++){
        //if(numero[i] != numero[j])
        char a,b;
        a = numero[i];
        b = numero[j];
        printf("\n a = %c   b = %c",a,b);
        //if(strcmp(a,b) != 0)
        if(numero[i] != numero[j]){
            ref = 0;
            break;
        }
        j--;
    }
    if(ref){
        printf("\nnumero e uma capicua");
    }else{
        printf("\nnumero nao e uma capicua");
    }
    int teste;
    teste = strtol (numero, NULL,10);     //fun��o que transforma string em um inteiro;
    printf("\ninteiro %d",teste+1);
    sprintf (numero,"%d",teste);           //fun��o que transforma um inteiro em uma string;
    printf("\nstring %s",numero);
}
*/ 
#include <stdio.h>
#include <string.h>
int main(){
    int n_algarismos, i, j, ref,n;
    char numero[5];
    for(n=0;n<5000;n++){
        ref = 1;
        sprintf (numero,"%d",n);
        n_algarismos = strlen(numero);
        j = n_algarismos-1;
        for(i=0;i<n_algarismos;i++){
            if(numero[i] != numero[j]){
                ref = 0;
                break;
            }
            j--;
        }
        if(ref){
            printf("\n\n\nnumero %d e  uma cupicua",n);
            printf("\npossui %d algarismos",n_algarismos);
            printf("\nnumero ordenado por algarismos");
            for(i=0;i<n_algarismos;i++){
                printf("  %c",numero[i]);
            }
            printf("\nnumero na ordem invertida");
            j = n_algarismos-1;
            for(i=0;i<n_algarismos;i++){
                printf("  %c",numero[j]);
                j--;
            }
        }
    }
}

/*
#include <stdio.h>
#include <math.h>

int main(){
    
    int a, j, Num_inv, Val_cada_alg, N1, N2, N3, N4, i=1, capicua[1000];
    
    
    i = 1;
    
    for(a=1; a <= 100; a++){
        //inverte os numeros
        if(a < 10){
            N1=a%10;//mostra o valor do primeiro algarismo
            Num_inv = N1; //mostra o numero invertido
                
            //determina se é capicua
            if(a == Num_inv){
                capicua[i] = a;
                i++;
            }
        }else if( a >= 10 && a < 100 ){
            N2=a%10;//mostra o valor do segundo algarismo
            printf("\nn2 = %d",N2);
            Val_cada_alg=a/10;//transforma o numero de 2 algarismos em um numero de 1 algarismo
            printf("\nval cada alg = %d",Val_cada_alg);
            N1=Val_cada_alg%10;//mostra o valor do primeiro algarismo
            printf("\nn1 = %d",N1);
            Num_inv = (N2*10) + N1; //mostra o numero de 2 algarismos, invertido
                
            if(a == Num_inv){
                capicua[i] = a;
                i++;
            }
        }else if( a >= 100 && a < 1000){
            N3=a%10;//mostra o valor do terceiro algarismo
            Val_cada_alg= a/10;//transforma o numero de 3 algarismos em um numero de 2 algarismo
            N2=Val_cada_alg%10;//mostra o valor do segundo algarismo
            Val_cada_alg=Val_cada_alg/10;//transforma o numero de 2 algarismos em um numero de 1 algarismo
            N1=Val_cada_alg%10;//mostra o valor do primeiro algarismo
            Num_inv = (N3 * 100) + (N2*10) + N1; //mostra o numero de 3 algarismos, invertido
                
            //determina se é capicua
            if(a == Num_inv){
                capicua[i] = a;
                i++;
            }
        }else if( a >= 1000 && a < 5000){
            N4=a%10; //mostra o valor do quarto algarismos   
            Val_cada_alg=a/10;//transforma o numero de 4 algarismos em um numero de 3 algarismo      
            N3=Val_cada_alg%10;//mostra o valor do terceiro algarismo
            Val_cada_alg=Val_cada_alg/10;//transforma o numero de 3 algarismos em um numero de 2 algarismo
            N2=Val_cada_alg%10;//mostra o valor do segundo algarismo
            Val_cada_alg=Val_cada_alg/10;//transforma o numero de 2 algarismos em um numero de 1 algarismo
            N1=Val_cada_alg%10;//mostra o valor do primeiro algarismo
            Num_inv = (N4*1000)+(N3 * 100) + (N2*10) + N1; //mostra o numero de 4 algarismos, invertido
                
            //determina se é capicua
            if(a == Num_inv){
                capicua[i] = a;
                i++;
            }
        }
    }
    //imprime na tela os numeros que sao capicuas e quadrados perfeitos
    printf("Numeros entre 1 e 5000 que sao capicuas e quadrados perfeitos simultaneamente: \n");
    for(j = 1; j < i; j++){
        printf("%d\n", capicua[j]);
    }
    return 0;
}*/