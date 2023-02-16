/*#include <stdio.h>
int main(){
    int i=1, n, num, max; 
    printf("Digite o numero n de elementos : ");
    scanf("%d", &n);
    max = 0;
    while (i<=n){
        printf ("Informe o numero:");
        scanf ("%d",&num);
        if (num > max) 
            max = num;
        i++;
    }
    printf("Maximo = %d\n", max);
}*/
#include <stdio.h>
int main(){
    int num, max; 
    printf("Informe o primeiro numero n da sequencia: ");
    scanf("%d", &num);
    max = 0;
    while (num>0){
        if (num > max) 
            max = num;
        printf ("Informe o proximo numero:");
        scanf ("%d",&num);
    }
    printf("Máximo = %d\n", max);
}
 