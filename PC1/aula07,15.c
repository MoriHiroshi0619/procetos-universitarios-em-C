#include <stdio.h>
int main(){
    int i, j, n, matriz[10][10];

    printf ("Informe o numero de linhas e colunas da matriz ");
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf ("Matriz[%d][%d]: ", i, j);
            scanf ("%d", &matriz[i][j]);
        }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf ("%d  ", matriz[i][j]);
        printf ("\n");
    }

}
