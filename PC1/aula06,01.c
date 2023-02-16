/*#include <stdio.h>

int main(){
    int i,n, prod = 1;
    printf("Digite o numero n : ");
    scanf("%d", &n);
    i=n;
    while (i>0){
        printf ("Produto Parcial na iteracao %d = %d x %d = %d\n", i, prod, i, prod*i );
        prod = prod*i;
        i--;
    }
    printf("Fatorial = %d\n", prod);
}*/
/*#include <stdio.h>

int main(){
    int i=1,n, idade;
    float media=0;
    printf("Digite o número n de alunos de SI : ");
    scanf("%d", &n);
    while (i<=n){
        printf ("Informe a idade:");
        scanf ("%d",&idade);
        media += idade; 
        i++;
    }
    printf("Media = %2.1f\n", media/n);
}*/
#include <stdio.h>

int main(){
    int i=1, n, num, max; 
    printf("Digite o numero n de elementos : ");
    scanf("%d", &n);
    max = 0;
    while (i<=n){
        printf ("Informe o numero:");
        scanf ("%d",&num);
        printf ("O maximo parcial era: %d \n",max);
        if (num > max) 
            max = num;
        printf ("O maximo parcial agora eh: %d \n",max);
        i++;
    }
    printf("Maximo = %d\n", max);
}


