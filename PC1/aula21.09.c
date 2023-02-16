/*#include <stdio.h>
void LeVetor (int *, int);
void ImprimeVetor (int *, int );
void TrocaVetores (int *, int *, int );
int main(){
	int vet1[5], vet2[5];
	printf(" Lendo Vetor 1 --------\n");
	LeVetor(vet1,5);
	printf(" ------ Lendo Vetor 2 --------\n");
	LeVetor(vet2,5);
	printf ("Imprimindo os vetores antes da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
	TrocaVetores(vet1,vet2,5);
    printf ("Imprimindo os vetores depois da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
}
void LeVetor(int vet[], int tam){
    int i;
    for(i = 0; i < tam; i++){
	printf("Digite numero:");
	scanf("%d",&vet[i]);
    }
}
void ImprimeVetor (int *vet, int tam){
    int i;
    printf ("[");
    for(i = 0; i < tam; i++)
        printf("%d  ",vet[i]);
    printf ("]\n");
}
void TrocaVetores (int *vet1, int *vet2, int tam){
    int i, aux;
    for(i = 0; i < tam; i++){
        aux=vet1[i];
        vet1[i]=vet2[i];
        vet2[i]=aux;
    }
}
*/

#include <stdio.h>
void LeVetor (int *, int);
void ImprimeVetor (int *, int );
void TrocaVetores (int *, int *, int );
int main(){
	int vet1[5], vet2[5];
	printf(" Lendo Vetor 1 --------\n");
	LeVetor(vet1,5);
	printf(" ------ Lendo Vetor 2 --------\n");
	LeVetor(vet2,5);
	printf ("Imprimindo os vetores antes da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
	TrocaVetores(vet1,vet2,5);
    printf ("Imprimindo os vetores depois da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
}
void LeVetor(int vet[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Digite numero:");
        scanf("%d",&vet[i]);
    }
}
void ImprimeVetor (int *vet, int tam){
    int i;
    printf ("[");
    for(i = 0; i < tam; i++)
        printf("%d  ",vet[i]);
    printf ("]\n");
}
void TrocaVetores (int *vet1, int *vet2, int tam){
    int i, aux;
    for(i = 0; i < tam; i++){
        aux=vet1[i];
        vet1[i]=vet2[i];
        vet2[i]=aux;
    }
}

/*
#include <stdio.h>
void LeVetor (int *, int);
void ImprimeVetor (int *, int );
void TrocaVetores (int *, int *, int );
int main(){
	int vet1[5], vet2[5];
    printf("\nendereco de vet1",&vet1);
    printf("\nconteudo de vet1",vet1);
	LeVetor(vet1,5);
    printf("\nnendereco de vet1",&vet1);
    printf("\nconteudo de vet1",vet1);
 
	printf(" \n------ Lendo Vetor 2 --------\n");

    printf("\nendereco de vet2",&vet2);
    printf("\nconteudo de vet2",vet2);
	LeVetor(vet2,5);
    printf("\nendereco de vet2",&vet2);
    printf("\nconteudo de vet2",vet2);

	printf ("\nnImprimindo os vetores antes da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
	TrocaVetores(vet1,vet2,5);
    printf ("\nImprimindo os vetores depois da troca ...\n");
	ImprimeVetor (vet1,5);
	ImprimeVetor (vet2,5);
}
void LeVetor(int vet[], int tam){
    int i;
    printf ("\nConteudo de vet=%d\n", vet);
	for(i = 0; i < tam; i++){
        printf("Digite numero:");
        scanf("%d",&vet[i]);
    }
}
void ImprimeVetor (int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("\nconteudo %d \t ",vet[i]);
        printf("endereco %d  ",&vet[i]);
    }
    printf("\n\n\n");
}
void TrocaVetores (int *vet1, int *vet2, int tam){
    int i, aux;
    for(i = 0; i < tam; i++){
        aux=vet1[i];
        vet1[i]=vet2[i];
        vet2[i]=aux;
    }
}*/
 /*
#include <stdio.h>
void LeMatriz (int mat[5][5], int);
void ImprimeMatriz (int mat[5][5], int );
void TrocaMatrizes (int mat1[5][5], int mat2[5][5], int );
int main(){
	int matriz1[5][5], matriz2[5][5];

	printf(" Lendo Matriz 1 --------\n");
	LeMatriz(matriz1,5);

	printf(" ------ Lendo Matriz 2 --------\n");

	LeMatriz(matriz2,5);

	printf ("Imprimindo as matrizes antes da troca ...\n");
	ImprimeMatriz (matriz1,5);
	ImprimeMatriz (matriz2,5);
	TrocaMatrizes(matriz1,matriz2,5);
    printf ("Imprimindo as matrizes depois da troca ...\n");
	ImprimeMatriz (matriz1,5);
	ImprimeMatriz (matriz2,5);
}
void LeMatriz(int mat[5][5], int tam){
    int i,j;
    for(i = 0; i < tam; i++){
        for (j=0; j< tam; j++){
           printf("Digite numero:");
           scanf("%d",&mat[i][j]);
        }
    }
}
void ImprimeMatriz (int mat[5][5], int tam){
    int i,j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++)
            printf("%d  ",mat[i][j]);
        printf ("\n");
    }
    printf ("\n");
}
void TrocaMatrizes (int mat1[5][5], int mat2[5][5], int tam){
    int i, j, aux;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            aux=mat1[i][j];
            mat1[i][j]=mat2[i][j];
            mat2[i][j]=aux;
        }
    }
}
*/ /*
#include <stdio.h>
int contaVogais (char *);
int main(){
    int i, n;
    char str[20];
    printf ("Informe o numero de strings que serao lidas\n");
    scanf ("%d", &n);
    for (i=0;i<n;i++){
        printf ("Informe a string numero %d\n", i+1);
        scanf ("%s", str);
        printf ("A string %s tem %d vogais\n", str, contaVogais(str));
    }
}

int contaVogais (char s[]) {
	  int numVogais=0, i,j;
	  char vogais[]= "aeiouAEIOU";
	  for (i = 0; s[i] != '\0'; ++i) {
		for (j = 0; vogais[j] != '\0'; ++j) {
			if (vogais[j] == s[i]) {
				numVogais ++;
                     break;
              }
		}
   }
return numVogais;
}*/
/*Ex.Calcular e escrever a área total de um tetraedro, dadas as coordenadas de cada um de seus quatro vértices.
Para tanto, deverão ser utilizados os seguintes módulos:
Que calcula a distância entre dois pontos do espaço;
Que calcula a área de um triângulo em função de seus lados*/

/*
#include <stdio.h>
#include <math.h>

typedef struct{
  float x,y,z;
}Ponto3d;

float distancia (Ponto3d, Ponto3d );
float area_triang( float, float, float);

int main(){
    Ponto3d V[4];
    int i;
    float area, area_total=0.0;

    for (i=0;i<4;i++){
        printf ("Informe as coordenadas do vertice %d ", i);
        scanf ("%f %f %f", &V[i].x, &V[i].y, &V[i].z);
    }
    // Calculando a area do triangulo V[0]V[1]V[2]
    area= area_triang(distancia(V[0],V[1]), distancia(V[1],V[2]), distancia(V[2],V[0]));
    area_total=area_total+area;

    printf ("A area do primeiro triangulo eh %3.2f ", area);


    // Calculando a area do triangulo V[0]V[1]V[3]
    area= area_triang(distancia(V[0],V[1]), distancia(V[1],V[3]), distancia(V[3],V[0]));
    area_total=area_total+area;

    printf ("A area do segundo triangulo eh %3.2f ", area);

    // Calculando a area do triangulo V[1]V[2]V[3]
    area= area_triang(distancia(V[1],V[2]), distancia(V[2],V[3]), distancia(V[3],V[1]));
    area_total=area_total+area;

    printf ("A area do terceiro triangulo eh %3.2f ", area);

    // Calculando a area do triangulo V[0]V[2]V[3]
    area= area_triang(distancia(V[0],V[2]), distancia(V[2],V[3]), distancia(V[3],V[0]));
    area_total=area_total+area;

    printf ("A area do quarto triangulo eh %3.2f ", area);

    printf ("A area total do tetraedro eh %3.2f ", area_total);
}
float distancia (Ponto3d p1, Ponto3d p2){
    float dist;
    dist= sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
    return(dist);
}
float area_triang( float a, float b, float c){
    float semi_perim, area;
    semi_perim=(a+b+c)/2;
    area= sqrt(semi_perim*(semi_perim-a)*(semi_perim-b)*(semi_perim-c));
    return (area);
}
*/
