//programa nao roda com void leitura()



#include <stdio.h>
/*
void leitura(float *massa){
    printf("\ninforme a massa do produto\t");
    scanf("%f", &massa);
}
*/
void decaimento(float *massa, float *segundos){
    float massa_alvo = 0.5;
    while(*massa>massa_alvo){
        printf("\nmassa = %f",*massa);
        *massa = *massa/2;
        *segundos = *segundos + 50;
    }
}

float conversao (float x){
    return(x/60);
}

int main(){
    float massa, hora, minutos, segundo = 0;
    // leitura(&massa);
    float massa_inicial = 0.5;
    printf("\ninforme a massa inicial\t");
    scanf("%f",&massa);
    printf("\nmassa inicial = %f",massa);
    decaimento(&massa,&segundo);
    minutos = conversao(segundo);
    hora = conversao(minutos);
    printf("\nmassa final = %f",massa);
    printf("\nsegundos = %f",segundo);
    printf("\nminuto = %f",minutos);
    printf("\nhora = %f",hora);
}
