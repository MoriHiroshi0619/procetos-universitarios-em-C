/*#include<stdio.h>
int main(){
    char st[80], st2[80];
    int a;
    printf("\nEntre com nome sem espacos:");
    scanf("%s",st);
    printf("\nEntre com nome com espacos:");
    scanf(" %[^\n]",st2);
    printf("\nEntre com idade:");
    scanf("%d",&a);
    printf("\n Digitado: %s, %s e %d\n",st, st2 ,a);
}
*/
/*
#include<stdio.h>
int main(){
    char st[13], stInv[13];
    int tam, i, j;
	printf("Entre com o string: ");
	scanf("%s",st);
	tam = 0;
	printf ("Tam=%d\n",tam);
	while(st[tam] != '\0' && tam < 13){
		tam++;
		printf ("Tam=%d\n",tam);
	}

    stInv[tam] = '\0';
    j = tam-1;
    i = 0;
    while(i<tam){
        stInv[j] = st[i];
        printf ("stInv=%s\t i=%d\t j=%d \n", stInv,i,j);
        i++;
        j--;

    }
    printf("A inversa e: %s\n",stInv);
}*/
