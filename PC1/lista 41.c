/*#include <stdio.h>

int fatorial(int x){
    if(x == 1){
        return(1);
    }else{
        return(x*fatorial(x-1));
    }
}

int Sfatorial(int x){
    if(x == 1){
        return(1);
    }else{
        return(fatorial(x-1)*fatorial(x));
    }
} 

int main(){
    int numero, fat;
    printf("digite o numero:\t");
    scanf("%d",&numero);
    fat = Sfatorial(numero);
    printf("superfatorial de %d = %d",numero, fat);
}
*/


/*
#include  <stdio.h>
#include <math.h>

int fatorialX(int numero){
    if(numero == 1){
        return(1);
    }else {
        return(pow(numero,fatorialX(numero-1)));
    }
}

int main(){
    int numero,fatX;
    printf("digite um numero\t");
    scanf("%d",&numero);
    fatX = fatorialX(numero);
    printf("\no fatorial exponencial de %d = %d",numero,fatX);
}*/


#include <stdio.h>

int tribonacci(int x){
    if(x == 0 || x == 1 || x ==2){
        return(0);
    }else if(x == 3){
        return(1);
    }else{
        return(tribonacci(x-1)+tribonacci(x-2)+tribonacci(x-3));
    }
}

int main(){
    int x,numero;
    printf("digite um numero\t");
    scanf("%d",&x);
    numero = tribonacci(x);
    printf("o n-simo numero da seguencia eh %d",numero);
}



/*
#include <stdio.h>

int tretabonacci(int x){
    if(x == 0){
        return(0);
    }else if(x == 1 || x ==2){
        return(1);
    }else if(x == 3){
        return(2);
    }else{
        return(tretabonacci(x-1)+tretabonacci(x-2)+tretabonacci(x-3)+tretabonacci(x-4));
    }
}

int main(){
    int x,numero;
    printf("digite um numero\t");
    scanf("%d",&x);
    numero = tretabonacci(x);
    printf("o n-simo numero da seguencia eh %d",numero);
}*/















