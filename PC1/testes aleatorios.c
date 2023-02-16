/*teste*/
/* programa que lê um total de pessoas, pergunta a idade de cada uma delas e vai mostrando a media das idades a partir da segunda pessoa e no final mostre a media final*/
/*#include <stdio.h>
    int main (){
        float contador=1, pessoas, idade, media, idadeSoma=0;
        printf("informe o total de pessoas:\t");
        scanf("%f",&pessoas);
        while (contador<=pessoas){
            printf("\ninforme sua idade:\t");
            scanf("%f",&idade);
            idadeSoma = idadeSoma+idade;
            if (contador>=2){
                media = idadeSoma / contador;
                printf("\na media ate o momento eh de %2.1f anos",media);
            }
            contador++;
        }
        if (media>18){
            printf("\na media das pessoas sao maiores de idade");
        }
        else if( media>60){
            printf("\na medias das pessoas sao idosas");
        }
        else {
            printf("\na medias das pessoas sao menores de idade");
        }
    }*/
/*#include <stdio.h>
    int main (){
        float trabalhoContador=0,rendaContador=0, contador=1, aprendizContador=0;
        float alunos, rendaFamiliar, Prenda, Ptrabalho, bolsa;
        char trabalho[]="sim", aprendiz[]="sim";
        printf("informe o total de alunos:\t");
        scanf("%f",&alunos);
        printf("\niremos iniciar a captura de dados de cada aluno");
        while (contador<=alunos){
            printf("\naluno de numero %2.0f",contador);
            printf("\ninforme a renda familiar per capita do aluno:\t");
            scanf("%f",&rendaFamiliar);
            printf("\no aluno trabalha? sim ou nao:\t");
            scanf("%s",trabalho);
            if (rendaFamiliar<1650){
                rendaContador++;
                
            }
            if (strcmp(trabalho,"sim")==0){
                trabalhoContador++;
                printf("\no aluno se considera aprendiz? sim ou nao:\t");
                scanf("%s",aprendiz);
                if (strcmp(aprendiz,"sim")==0){
                    aprendizContador++;                  
                }
            }
            contador++;
        }
        Prenda = (rendaContador*100)/alunos;
        Ptrabalho = (trabalhoContador*100)/alunos;
        bolsa = rendaContador * 400;
        printf("\n%2.0f alunos tem renda familiar inferior a 1.5 salario minimo",rendaContador);
        printf("\nisso representa %2.1f porcento do total de alunos",Prenda);
        printf("\n\n%2.0f alunos trabalham e %2.0f se declaram aprendizes",trabalhoContador,aprendizContador);
        printf("\nDos alunos que trabalham, representa %2.1f porcento do total de alunos",Ptrabalho);
        printf("\n\nserah necessario um montante de %2.2f reais para cobrir todos alunos com renda inferior ah 1.5 salario minimo",bolsa);
    }*/

/*#include <stdio.h>
    int main(){
       printf("\nisso eh um teste qualquer");
         printf("isso eh apenas um teste");
    }*/
/*#include <stdio.h>
    int main (){   
        int i=1;
        for (i;i<=100;i++){
            printf("\n%d",i);
        }
    }*/
/*#include <stdio.h>
    int main (){
        int n=1;
        while(n<=100){
            printf("\t%d",n);
            n++;
        }
    }*/
/*#include <stdio.h>
#include <stdlib.h> /*blibioteca usada para usar a funcao abs(numero) que tranforma sempre o numero em numeros positivos
#include <time.h> /*blibioteca usada para mexer com tempo
*/
                                /* EXEMPLO DE CODIGO PARA GERAR NUMEROS ALEATORIOS*/
/*#include <stdio.h>
#include <time.h>  
    int main() {

        int segundos = time(0);
        srand(segundos);

        int n1 = rand();
        int n2 = rand();
        int numero1 = n1%11;
        int numero2 = n2%11;

        printf("%d %d\n", numero1, numero2);
}*/ 
/*  teste pra mexer com strings
/*#include <stdio.h>
    int main(){
        char nome[10];
        printf("insira seu nome: \t");
        scanf("%f",&nome);
        printf("\n seu nome eh %s",nome);
    }*/
/*#include <stdio.h>
    int main(){
        char nome[10];
        sprintf(nome,"hiroshi");
        printf("\n%s",nome);
        
    }*/
                                     /*JOGO DA FORCA*/
/*#include <stdio.h>
#include <string.h>

int main() {

	char palavrasecreta[20];
	sprintf(palavrasecreta, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	do {
		
		for(int i = 0; i < strlen(palavrasecreta); i++) {
			int achou = 0;

			for(int j = 0; j < tentativas; j++) {
				if(chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}

			if(achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		char chute;
		printf("Qual letra? ");
		scanf(" %c", &chute);

		chutes[tentativas] = chute;
		tentativas++;


	} while (!acertou && !enforcou);
                /*TESTES COM VOID E FUNÇÕES/*
}*/
/*#include <stdio.h>
void abertura (){
    printf("ola, seja bem vindo");
}

int main(){
    abertura();
}*/
/*#include <stdio.h>
void multiplica( x, y, z) {
    printf("\n\ninforme o valor que sera multiplido\t:");
    scanf("%d",&x);
    printf("\ninforme o valor que ira multiplicar\t:");
    scanf("%d",&y);
    z = x*y;
    printf("\n\no resultado eh %d",z);
}

int main (){
    int x,y,z;
    multiplica(x,y,z);
    multiplica(x,y,z);
}*/
/*	
#include <stdio.h>
#include <string.h>

int main (){
    char sexo;
    printf("informe o seu sexo\t");
    scanf(" %c",&sexo);
    printf("entndi, seu sexo eh do tipo %c",sexo);
            

}*/
/*
#include <stdio.h>
#include <string.h>

int main(){
    char sexo;

    printf("mulher ou homem?\t");
    scanf(" %c",&sexo);
    if(sexo == 'h'){
        printf("\ndeu certo homem");
    }else if (sexo == 'm'){
        printf("\ndeu certo mulher");
    }else{
        printf("\nalguma coisa deu errado");
    }
}
*/
                    /*EXEMPLO DE COMO COMPARAR DUAS STRINGS */
/*
#include <stdio.h>
#include <string.h>

int main(){
    char texto[10],texto2[10];

    printf("digite seu nome:\t");
    scanf(" %s",texto);
    printf("digite seu nome:\t");
    scanf(" %s",texto2);

    printf("\n seu nome eh %s",texto);
    printf("\n seu nome eh %s",texto2);
    
    if(strcmp(texto,texto2)==0){
        printf("\nas strings sao iguais");
    }
}
*/
                                 /*FUNÇÃO FGETS() PARA RECEBER TEXTO POR COMPLETO INCLUNDO NUMEROS*/
/*#include <stdio.h>
int main(){
    int i = 1;
    char nome[30],nome2[30];
    while(i<5){
    printf("informe seu nome :\t");
    //scanf("%s",nome);
    fgets(nome,30,stdin);
    printf("informe outro nome:\t");
    fgets(nome2,30,stdin);
    printf("\no nome armazenado eh %s",nome);
    printf("\no nome armazenado eh %s",nome2);
    if(strcmp(nome,nome2)==0){
        printf("\nos nomes sao iguais !");
    }
    i++;
    }
}*/


                                /*PONTEIROS*/   
/*#include <stdio.h>
int main(){
    int x = 5,i=0;
    int *ponteiro;
    ponteiro = &x;
    while(i<5){
        printf("\nmultiplica 2 ");
        x = i*2;
        printf("eh igual ah %i",x);
        printf("\torigim eh %i",*ponteiro);
        i++;
    }

}*/
                                    /*VETORES*/
/*
#include <stdio.h>

int main(){
    int a=0, b=1, i;
    for(i=1;i<=5;i++){
        a= b * 5;
        printf("\n\nvalor da variavel a = %d na ordem %i",a,i);
        b = b * 2;
    }
    printf("\n\n\nvalor final da variavel fora da estrutura for = %d",a);
    //printf("\nvalor da variavel na ordem x foi de %d",a);
}*/


                    /*EXEMPLO DE CONTINUAR LOOP CASO ENTRADA SEJA INCORRETA*/
/*int main(){
	float altura, maior_a=0, menor_a=2.0, media_a_f=0;
	char sexo;
	int i,cont_f=0;

	for (i=1;i<=5;i++){
        do{
            printf ("Informe o sexo da pessoa %d: ",i);
            scanf(" %c",&sexo);
        }while (sexo!='m' && sexo!='M' && sexo!='f' && sexo!='F');

        printf ("Informe a altura da pessoa %d: ",i);
        scanf("%f",&altura);
        if (altura>maior_a)
           maior_a=altura;
        if (altura<menor_a)
            menor_a=altura;
        if (sexo=='F' || sexo=='f'){
            media_a_f=media_a_f+altura;
            cont_f++;
        }
	}
	printf ("A maior altura do grupo eh: %2.2f\n",maior_a);
	printf ("A menor altura do grupo eh: %2.2f\n",menor_a);
	printf ("A media da altura das mulheres eh: %2.2f\n",media_a_f/cont_f);
	printf ("O numero de homens eh: %d\n",5-cont_f);
}*/     
                /*VETORES, ACHAR O MAIOR E MENOR NUMERO DE UM VETOR*/
/*#include <stdio.h>

int main (){
    int n[6], maior = 0,menor = 0,i,buscaMaior, buscaMenor;
    for(i=1;i<=5;i++){
        printf("\nordem %d - digite um numero\t",i);
        scanf("%d",&n[i]);
        //printf("\t%d",n[i]);
        if(i==1){
            menor = n[i];
        }
        if(n[i]>maior){
            maior = n[i];
            buscaMaior = i;
        }
        if(n[i]<menor) {
            menor = n[i];
            buscaMenor = i;
        }
        //printf("\t%d",i);
    }
    printf("\n\no maior numero foi %d na ordem %d ",maior,buscaMaior);
    printf("\no menor numero foi %d na ordem %d",menor,buscaMenor);     
}*/

/*Escreva um programa que leia um vetor de 10 elementos.
O programa deve informar a quantidade de números pares existentes no vetor.
Os  valores armazenados no vetor serão informados pelo usuário.*/

/*#include <stdio.h>

int main(){
    int v[11],pares=0,i=1;
    printf("informe os valores do vetor\n");
    for(i;i<=10;i++){
        printf("\nvetor %d de 10 \t",i);
        scanf("%d",&v[i]);
    }          
    for(i=1;i<=10;i++){
        printf("\n%d",v[i]);
    }
    for(i=1;i<=10;i++){
        if(v[i]%2 == 0){
            pares++;
        }
    }
    printf("\nteve um total de %d numeros pares",pares);
}*/
/*
                                                                    var
                                                                    inteiro: I, J, FAT;
                                                                    real: X, E;
                                                                    início
                                                                    E ← 0;
                                                                    leia(X);
                                                                    para I de 1 até 15 faça
                                                                    FAT ← 1;
                                                                    para J de 2 até I – 1 faça
                                                                    FAT ← FAT * J;
                                                                    fim-para
                                                                    E ← E + ( X ** ( I – 1 ) ) / FAT;
                                                                    fim-para
                                                                    imprima("E^",X," = ",E);
                                                                    fim*/
/*#include <stdio.h>

int main(){
    int i, j, fat;
    float x, e;
    e = 0;
    printf("\ndigite x\t");
    scanf("%f",&x);
    for (i=1;i<=15;i++){
        fat = 1;
        printf("\n\n%d**",fat);
        for (j=2;j<=i-1;j++){
            printf("\n\n%d--",fat);
            fat = fat*j;
        }
        printf("\n\n%d++",e);
        e = e+(x*(i-1))/fat;
    }
    printf("\nE^ %d = %d",x,e);
}*/
/*
#include <stdio.h>

int main(){
    int i = 0;
    float x, fatorial = 1,resultado = 0,potencia = 1;
    scanf("%f",&x);
    while (i<15){
        printf("\ni = %f",i);
        printf("\nresultado = %f",resultado);
        resultado = resultado + potencia/fatorial;
        potencia = x * potencia;
        fatorial = fatorial * i;
        i++;
    }
    printf("\n\nresultado = %f",resultado);
}*/
/*
#include <stdio.h>
int main(){
	float x, n, fatorial, resultado, potencia, i;
	resultado = 0;
	fatorial = 1;
	potencia = 1;
	i = 1;
	printf("Informe o valor de x:");
	    scanf("%f", &x);
	while(i <= 15){
	    printf("\n%.1f = %.2f",i,  resultado);
        printf("\n %.1f + %.1f / (%.1f)",resultado,potencia,fatorial);
	    resultado = resultado + potencia / (fatorial);
        printf("\npotencia = %.1f",potencia);
	    potencia = x*potencia;
        printf("\npotencia = %.1f",potencia);
        printf("\nfatorial = %.1f",fatorial);
	    fatorial = fatorial * i;
        printf("\nfatorial = %.1f",fatorial);
	    printf("\n");
	    i++;
	}
}*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numMatricula, frequencia, alunosReprovados, reprovadosFrequencia = 0;
    float nota1, nota2, nota3,aux = 0, maiorNota = 0, menorNota = -1, mediaTurma, auxPorc, porcReprovadoFreque = 0, notaFinal = 0;
    char codigo;

    for(int i = 1; i <= 4; i++){ //depois mudar o 4 para 100;
        printf("Digite o numero da matricula: ");
        scanf("%d", &numMatricula);
        printf("Digite a nota 1: ");
        scanf("%f", &nota1);
        printf("Digite a nota 2: ");
        scanf("%f", &nota2);
        printf("Digite a nota 3: ");
        scanf("%f", &nota3);
        printf("Digite o numero de aulas frequentadas: ");
        scanf("%d", &frequencia);
        notaFinal = (nota1 + nota2 + nota3) / 3;
        printf("Nota final: %.2f\n", notaFinal);
        mediaTurma = mediaTurma + notaFinal;

        if(notaFinal < 6 || frequencia < 40){
            alunosReprovados = alunosReprovados + 1;
            printf("Aluno Reprovado\n");
        }else{
            printf("Aluno Aprovado\n");

        }

        if(frequencia < 40)
            reprovadosFrequencia = reprovadosFrequencia + 1;

        if(menorNota == - 1 || menorNota > notaFinal)
            menorNota = notaFinal;

        if(notaFinal > maiorNota)
            maiorNota = notaFinal;
        }
        porcReprovadoFreque = ((float)reprovadosFrequencia * 100) / alunosReprovados;
        mediaTurma = mediaTurma / 3;


        printf("Media da turma: %.2f\n", mediaTurma);
        printf("Maior nota: %.2f\n", maiorNota);
        printf("Menor nota: %.2f\n", menorNota);
        printf("Quantidade de alunos reprovados: %d\n", alunosReprovados);
        printf("Porcentagem de alunos reprovados por Frequencia: %.2f%%", porcReprovadoFreque);


}*/
/*
#include <stdio.h>

int main(){
    int i,j, m[3][4], maior[3], estado, municipio,p;
    float media=0.0;


    for (p=0; p<3; p++){
        maior[p] = 0;
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++) {
            printf ("Populacao do municipio %d do estado %d: ", j, i);
            scanf ("%d", &m[i][j]);
            if (m[i][j]>maior[i]){
                maior[i]=m[i][j];
                municipio=j;
            }
        }
        media=media+m[i][0];
    }

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf ("%d ", m[i][j]);
        printf ("\n");
    }
    for(p=0;p<3;p++){
        printf ("O municipio mais populoso do estado %d tem %d pessoas\n ",p,maior[p]);
    }
    printf ("A media da populacao das capitais eh : %3.2f ", media/3);
}*/
/*
#include <stdio.h>

int main(){
    int i,j, m[3][4], maior[3], estado, municipio[3],p;
    float media=0.0;

    srand (time(NULL));

    for (p=0; p<3; p++){
        maior[p] = 0;
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++) {

            m[i][j]=rand()%100;
            if (m[i][j]>maior[i]){
                maior[i]=m[i][j];
                municipio[i]=j;
            }
        }
        media=media+m[i][0];
    }


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf ("%d ", m[i][j]);
        printf ("\n");
    }
    for(p=0;p<3;p++){
        printf ("O municipio mais populoso do estado %d eh o %d e tem %d pessoas\n ",p,municipio[p],maior[p]);
    }
    printf ("A media da populacao das capitais eh : %3.2f ", media/3);
}*/
        //lista 21 
/*
#include <stdio.h>
int main(){
    int voos[5][4], i, j, ident, voo_desej;
    float valor[5];

    printf ("Leitura de dados dos 5 voos ");
    for (i=0;i<5; i++){
        printf ("Informe o numero do voo %d: ", i);
        scanf ("%d", &voos[i][0]);
        do {
            printf ("Informe o tipo de aviao (707, 727, 737): ");
            scanf ("%d", &voos[i][1]);
        }while (voos[i][1]!=707 && voos[i][1]!=727 && voos[i][1]!=737 );

        if (voos[i][1]==707)
            voos[i][2]=voos[i][3]=10;
        else if (voos[i][1]==727)
            voos[i][2]=voos[i][3]=7;
        else
            voos[i][2]=voos[i][3]=5;
        printf ("Informe o preco da passagem do voo %d: ", i);
        scanf ("%f", &valor[i]);
    }
    printf ("Iniciamos as reservas das passagens\n");
    printf ("Informe o numero de identidade do passageiro: ");
    scanf ("%d", &ident);
    while (ident!=0){
        printf ("Informe o numero de voo desejado: ");
        scanf ("%d", &voo_desej);
        for (i=0;i<5;i++){
            if (voo_desej==voos[i][0]){
                if (voos[i][3]>0){
                    voos[i][3]--;
                    printf ("O numero de identidade do passageiro eh %d\n", ident);
                    printf ("O numero de voo desejado eh %d\n", voo_desej);
                    printf ("O preco da passagem eh %3.2f\n", valor[i]);
                    printf ("RESERVA CONFIRMADA\n");
                }else{
                    printf ("O numero de identidade do passageiro eh %d\n", ident);
                    printf ("O numero de voo desejado eh %d\n", voo_desej);
                    printf ("VOO LOTADO\n");
                }
                i=5;
            }else
                printf ("O voo informado nao existe no cadastro de voos\n");
         }
         printf ("Informe o numero de identidade do passageiro: ");
         scanf ("%d", &ident);
    }
    printf ("Determinando lucros ou prejuizos \n");
    for (i=0;i<5; i++){
        if ((voos[i][2]-voos[i][3])>voos[i][2]*0.6)
            printf (" LUCRO NO VOO ");
        else if ((voos[i][2]-voos[i][3])<voos[i][2]*0.6)
            printf (" PREJUIZO NO VOO ");
        else
            printf (" NAO HOUVE NEM LUCRO NEM PREJUIZO NO VOO ");
    }

}*/
/*    0    1    2    3
    0 456  727  170   50
    1 567  707  200   200
    2 732  727  170   170
    3 215  737  120   120
    4 122  707  200   200
    */
   /*
#include <stdio.h>
int main (){
    int v[27],i;
    v[0] = 1;
    v[1] = 1;
    for(i=2;i<27;i++){
        v[i] = v[i-1] + v[i-2];
    }
    printf("%d",v[11]);
}*/
/*
#include <stdio.h>
int main (){
    int a[2] = {3,5,7}, b[4] = {4, 6, 10, 18, 20}, c[7];
    int ia = 1, ib = 1, ic =1, na =3,nb = 5, cont = 0, i;
    while (ia <= na && ib <= nb){
        if(a[ia]<= b[ib]) {
            c[ic] = a[ia];
            ia++;
        }
        else{
            c[ic] = b[ib];
            ib++;
        }
        ic++;
        cont++;
    }
    for(i=ib;i<nb;i++){
        c[ic] = b[i];
        ic++;
    }
    printf("\n mostrando indices vetor C");
    for(i=0;i<7;i++){
        printf("\n%d",c[i]);
    }
    printf("\ncont = %d",cont);
}*/
/*
#include <stdio.h>
int main (){
    int matriz[2][3][4],i,j,k;
    for(i=1;i<=2;i++){
        for(j=1;j<=3;j++){
            for(k=1;k<=4;k++){
                matriz[i][j][k] =  3*i + 2*j + k;
                printf("\n[%d][%d][%d] = %d",i,j,k,matriz[i][j][k]);
            }
        }
    }
    printf("\n%d",matriz[2][2][2]- matriz[1][2][3]);
}*/
/*
#include<stdio.h>
#define LIMITE 10

int main(void)
{
      float matriz[LIMITE][LIMITE],valor;
      int i,j,k,ordem;
      
      printf("Entre com a ordem da matriz:");
      scanf("%d",&ordem);
      
      for(i=0;i<ordem;i++)
      {
        for(j=0;j<ordem;j++)
        {
              printf("Entre com o elemento (%d,%d) da matriz:",i+1,j+1);
              scanf("%f",&matriz[i][j]);
        }
      }    

          
      // Encontrando a determinante
      int fdr = ordem;
      float mult;
      float deter=1;
      for(i=0;i<fdr;i++)
      {
        for(j=0;j<fdr;j++)
        {
              mult=matriz[j][i]/matriz[i][i];
              printf("\n%.3f = %d/%d",mult,matriz[j][i],matriz[i][i]);
              for(k=0;k<fdr;k++)
             {
                if(i==j) break; 
            
                matriz[j][k]=matriz[j][k]-matriz[i][k]*mult;
                printf("\n %d = %d - %d * %.3f",matriz[j][k],matriz[j][k],matriz[i][k],mult);
              }
        }
      }
      for(i=0;i<fdr;i++)
      {
        deter=deter*matriz[i][i];
        printf("%.3f = %.3f * %d",deter,deter,matriz[i][i]);
      }
      
      // Imprimindo a determinante
      printf("O valor da determinante e: %.0f \n",deter);
      system("pause");
      return (0);
}*/ /*
#include <stdio.h>
float media (int n, float *nota){
    int i;
    float soma = 0, m;
    for (i=0;i<n;i++){  
        soma += nota[i];
    }
    m = soma/(float)n;
    return(m);
}
int main (){
    int i, alunos;
    float vnota[100],average;
    printf("\ninforme o numero de alunos\t");
    scanf("%d",&alunos);
    for(i=0;i<alunos;i++){
        printf("informe a nota do aluno %d\t",i+1);
        scanf("%f",&vnota[i]);
    }
    average = media(alunos,vnota);
    printf("\na media final = %.1f",average);
}*/ 
/*
#include <stdio.h>
int fatorial(int x){
int fat=1, i;
for (i=x; i > 1; i--)
	fat = fat * i;
return(fat);
}

int main(){
    int n,p,C;
    scanf("%d %d",&n,&p);
    if (p > 0&&n > 0&&p <= n){ 
        C = fatorial(n)/(fatorial(p)*fatorial(n-p));
        printf("%d \n",C);
    }
}
*/
/*
#include <stdio.h>
int main (){
    int a=10, b=3, c=1, d=7,i,menor=0,soma =0;
    int vet[4] = {a,b,c,d};
    for(i=0;i<4;i++){
        if(i==0){
            menor = vet[i];
        }
        if(menor > vet[i]){
            menor = vet[i];
        }
    }
    printf("\nmenor = %d", menor);
    for(i=0;i<4;i++){
        if(vet[i]==menor){
            continue;
        }
        soma += vet[i];
    }
    printf("\nsoma = %d", soma);
}*/
/*
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
*/
/*
#include <stdio.h>
int main(){
    int result,outro,numero,result2,result3,result4;
    numero = 1357;
    printf("\nnumero original = %d",numero);
    result = numero%10;
    printf("\nresult = %d",result);
    outro = numero/10;
    printf("\noutro = %d",outro);
    result2 = outro%10;
s
    outro = outro/10;
    printf("\noutro = %d",outro);
    result3 = outro%10;
    printf("\nresult3 = %d",result3);
    outro = outro/10;
    printf("\noutro = %d",outro);
    result4 = outro%10;
    printf("\nresult 4 = %d",result4);
    printf("\nnumero quebrado = %d  %d  %d  %d",result4,result3,result2,result);
}*/
/*
#include <stdio.h>
int main(){
    int matriz[3][4][5], contador = 0,result;
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            for(k=0;k<4;k++){
                matriz[i][j][k] = 3 * i + 2 * j + k;
                contador ++;
            }
        }
    }
    result = matriz[1][1][1] - matriz[0][1][2];
    printf("\n%d",result);
    printf("\n%d",contador);
}*//*
#include <stdio.h>

void ler (int *x){
    scanf("%d",&x);
    //printf("n = %d",*x);
}

void mult (int *n){
    *n = *n*45;
}

int main(){
    int n,i,res;
    ler(n);
    printf("\n%d",n);
    for(i=0;i<5;i++){
        res = n*i;
        printf("\n%d",res);
    }
    mult(&res);
    printf("\n%d",res);
}
*/
/*
#include <stdio.h>

int main(){
    int m, n, i,j, **mat;
    printf ("Endereco de mat: %d\n ",&mat );
    printf ("Endereco que mat aponta : %d\n ",mat );

    printf("Informe numero de linhas: \n");
    scanf("%d", &m);
    if ((mat=(int *)malloc(m * sizeof(int)))==NULL) {
        printf("Erro de alocação de memoria !\n");
        exit(1);
    }
    printf ("Endereco que mat aponta : %d\n ",mat );

    for (i=0; i<m; i++)
        printf ("Endereco de mat[%d] : %d\n ",i, &mat[i] );

    printf("Informe numero de colunas: \n");
    scanf("%d", &n);
    for (i=0; i<m; i++)
        if ((mat[i]=(int *)malloc(n * sizeof(int)))==NULL) {
            printf("Erro de alocação de memoria !\n");
            exit(1);
        }

    for (i=0; i<m; i++)
        printf ("Endereco que mat[%d] aponta: %d\n ",i, mat[i] );

    printf ("Lendo matriz\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf ("Endereco de mat[%d][%d] : %d\n ",i,j, &mat[i][j] );
        }
    }
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for (i=0; i<m; i++){
       for (j=0; j<n; j++){
         printf("%d ", mat[i][j]);
       }
       printf ("\n");
    }
    free(mat);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>


int main (){
    int **mat,i,j,coluna,linha,numero;
    printf("\ninforme o numero de coluna\t:");
    scanf("%d",&coluna);

    mat = (int *)malloc(coluna * sizeof(int));

    //printf("\ntamanho de mat = %d",sizeof(mat));
    if(mat == NULL){
        printf("\n erro de alocacao de memoria");
        exit(1);
    }
    printf("\nendereco de memoria de mat = %d",&mat);
    printf("\nendereco de memoria que mat aponta = %d",mat);
    for(i=0;i<coluna;i++){
        printf("\nendereco da coluna %d = %d",i,&mat[i]);
    }

    printf("\n\ninforme o numero de linha\t: ");
    scanf("%d",&linha);
  
    for(i=0;i<coluna;i++){
        mat[i] = (int *)malloc(linha * sizeof(int));
        if(mat[i] == NULL){
            printf("\n erro de alocacao de memoria");
            exit(1);                                                               //TENTATIVA FALHA DE ALOCAR MEMORIA CORRETANMENTE
        }
    }


    for(i=0;i<coluna;i++){
        printf("\nendereco de memoria mat[%d] = %d",i,&mat[i]);
        printf("\nendereco de memoria apontado = %d",mat[i]);
    }

    for(i=0;i<coluna;i++){
        for(j=0;j<linha;j++){
            printf("\n\ninforme o valor da matriz [%d][%d]:",i,j);
            scanf("%d",&numero);
            mat[i][j] = numero;
            printf("endereco do valor = %d : valor = %d",&mat[i][j],mat[i][j]);
        }
    }
    printf("\n\nimprimindo valores da matriz");
    for(i=0;i<coluna;i++){
        printf("\n");
        for(j=0;j<linha;j++){
            printf("%d  ",mat[i][j]);
        }
    }
    printf("\n\nresumo da memoria do programa");
    printf("\nendereco que esta alocado a matriz = %d",&mat);
    printf("\nendereco que a matriz aponta = %d",mat);
    for(i=0;i<coluna;i++){
        printf("\n\nendereco da coluna %d da matriz = %d",i,&mat[i]);
        printf("\nendereco apontado = %d",mat[i]);
        for(j=0;j<linha;j++){
            printf("\nendereco da matriz [%d][%d] = %d",i,j,&mat[i][j]);
        }
    }
}
*/
/*


#include <stdio.h>
void push(int );
int pop(void);
int stack[50], *tos,*pl;
void main(void){
    int value;
    tos = stack;
//Faz tos conter o topo da pilha 
    pl = stack;	//inicializa pl 
    do {
       printf("\nEntre com o valor: (0) Pop, (-1) Sair, Caso contrario Push : ");
       scanf("%d",&value);
       if(value!=0)
          push(value);
       else
          printf("\nTirando valor do topo = %d\n",pop());
     }while(value != -1);
}
void push(int i){
    int *p=tos;
	pl++;
	if(pl==(tos+50)){
	    printf("Estouro da pilha");
	    exit(1);
	}
	*pl = i;
	for ( ;p<=pl ; p++)
        printf ("%d\t", *p);
}
int pop(void){
    int *p=tos;
	if(pl==tos){
	    printf("Pilha vazia");  
	    exit(1);
	}
	pl--;
	for ( ;p<=pl ; p++)
        printf ("%d\t", *p);

	return *(pl+1);

}
*/





//exemplo de codigo dinamico com malloc e realloc


#include <stdio.h>

typedef struct {
    char nome[10];
    int rgm;
}cad_aluno;

int main(){
    cad_aluno *v;
    int i;
    v = malloc (3 * sizeof (cad_aluno));
    for (i = 0; i < 3; i++){
         printf ("v[%d].nome=",i);
         scanf ("%s", v[i].nome);
         printf ("v[%d].rgm=",i);
         scanf ("%d", &(v[i].rgm));
    }
    printf ("Realocando memoria\n");
    v = realloc (v, 6 * sizeof (cad_aluno));
    for (i = 3; i < 6; i++){
         printf ("v[%d].nome=",i);
         scanf ("%s", v[i].nome);
         printf ("v[%d].rgm=",i);
         scanf ("%d", &(v[i].rgm));    }
}


/*
#include <stdio.h>

void leitura (int *x){
    printf("\informe o nemero fatorial\t");
    scanf("%d",&x);
    printf("\nx = %d",x);
}

void fatorial (int *x){
    printf("\nx = %d",*x);
    int n = *x;
    int i;
    for(i=0;i<n;i++){
        *x = *x * i; 
    }
}

void imprime (int *x){
    printf("\nfatorial = %d",x);
}

int main (){
    int fat;
    leitura(&fat);
    fatorial(&fat);
    imprime(&fat);
}
*/
/*
#include <stdio.h>

int main(){
    char string[40];
    int tam=0,i;
    printf("digite a string\t");
    scanf("%s",string);
    for(i=0;string[i] != '\0';i++){
        tam++;
    }
    printf("tamanho da string = %d",tam);
}*/
                                                                        //alocação dinamica com registros dendro de registros
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct {
 float pontox;
 float pontoy;
} ponto2d;

typedef struct {
    ponto2d p1, p2; 
    float pmX, pmY;
}segmento;


int main(){
    segmento *reta;
    segmento *raiz;
    int count = 1;
        reta = malloc(sizeof(segmento));
        raiz = reta;
        printf("%d\n",sizeof(segmento));
        printf("Primeiro Seguimento: ");
        scanf("%f", &(reta->p1.pontox));
        scanf("%f", &(reta->p1.pontoy));

        printf("Segundo Seguimento: ");
        scanf("%f", &(reta->p2.pontox));
        scanf("%f", &(reta->p2.pontoy));

        while(reta->p1.pontox != 0 || reta->p1.pontoy != 0 || reta->p2.pontox != 0 || reta->p2.pontoy){
                reta->pmX = (reta->p1.pontox + reta->p2.pontox) / 2;
                reta->pmY = (reta->p1.pontoy + reta->p2.pontoy) / 2;
                printf("Ponto medio (%.2f, %.2f)\n", reta->pmX, reta->pmY);

                count++;
                raiz = (segmento *)realloc(raiz,count * sizeof(segmento));
                reta = raiz + (count - 1);

                printf("Primeiro Seguimento: ");
                scanf("%f", &reta->p1.pontox);
                scanf("%f", &reta->p1.pontoy);

                printf("Segundo Seguimento: ");
                scanf("%f", &reta->p2.pontox);
                scanf("%f", &reta->p2.pontoy);

        }
        reta = raiz;
        for(int i = 0; i < count - 1; i++){
            printf("Ponto medio (%.2f, %.2f)\n", reta->pmX, reta->pmY);
            reta++;


        }

}*/
                                //teste recursa//
/*
#include <stdio.h>

int resto(int x,int y){
    if(y>x){
        return(x);
    }else{
        return(resto(x-y,y));
    }
}
  
int main (){
    int x,y,result;
    printf("digite x\t");
    scanf("%d",&x);
    printf("\ndigite y\t");
    scanf("%d",&y);
    result  = resto(x,y);
    printf("\nresto = %d",result);
}*/

/*
#include <stdio.h>
#include <math.h>

int main(){
    int x,y;
    scanf("%d",&x);
    y = pow(x,3);
    printf("\n%d",y);
} char =
*/

/*

#include <stdio.h>
#include <stdlib.h>


void iniciarJogo(char jogo[][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            jogo[i][j] = ' ';
        }
    }
}

void imprimir(char jogo[][3]){
    int i,j;
    printf("\n\n\t COLUNAS\n");
    printf("\t 0   1   2\n\n");
    for(i=0;i<3;i++){
        printf("\t");
        for(j=0;j<3;j++){
            printf(" %c ",jogo[i][j]);
            if(j<2){
                printf("|");
            }
            if(j == 2){
                printf("  %d LINHAS",i);
            }
        }
        printf("\n");
        if(i<2){
            printf("\t-----------\n");
        }
    }
}

int ehvalida(char jogo[][3], int i, int j){
    if(i>= 0 && i<3 && j>=0 && j<3 && jogo[i][j] == ' '){
        return 1;
    }else{
        return 0;
    }
}


void perguntaCordenadas(char jogo[][3], char x){
    int i,j;
    printf("informe as cordenadas a ser preenchida");
    printf("\ninforme a linha   ");
    scanf("%d",&i);
    printf("informe a coluna    ");
    scanf("%d",&j);

    while(ehvalida(jogo, i, j) == 0){
        printf("informe as cordenadas a ser preenchida");
        printf("\ninforme a linha   ");
        scanf("%d",&i);
        printf("informe a coluna    ");
        scanf("%d",&j);
    }

    jogo[i][j] = x;
}

int quantDisponivel(char jogo[][3]){
    int i,j;
    int disponivel = 0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(jogo[i][j] == ' '){
                disponivel++;
            }
        }
    }
    return disponivel;
}

int ganhouLinha(char jogo[][3], char x, int i){
    
    if(jogo[i][0] == x && jogo[i][1] == x && jogo[i][2] == x){
        return 1;
    }else{
        return 0;
    }
}

int ganhouLinhas(char jogo[][3], char x){
    int i;
    int ganhou = 0;
    for(i=0;i<3;i++){
        ganhou += ganhouLinha(jogo, x, i);
    }
    return ganhou;
}


int main(){
    char *jogo;
    char matriz [3][3];
    char jogadorX = 'x', jogador0 = '0';
    jogo = matriz;
    int vitoriaX = 0;
    int vitoria0 = 0;
    int jogador = 1;
    iniciarJogo(jogo);
    int disponivel;
    do{
        imprimir(jogo);
        if(jogador == 1){
            perguntaCordenadas(jogo, jogadorX);
            jogador++;
            vitoriaX += ganhouLinhas(jogo, jogadorX);
        }else{
            perguntaCordenadas(jogo, jogador0);
            jogador = 1;
            vitoria0 += ganhouLinhas(jogo, jogador0);
        }
    }while(vitoria0 == 0 && vitoriaX == 0 && quantDisponivel(jogo)>0);
}
*/


// comenta uma linha 
/* comenta
mais de uma linha
*/
/*

#include <stdio.h>

int main(){
    int numero, n, somapar = 0, totalImpar = 0, i;

    printf("ïnforme a quantidade de numeros para analisar.\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\ninforme numero de posicao %d", i+1);
        scanf("%d", numero);
        if(numero % 2 == 0){
            somapar += numero;
        }else{
            totalImpar++;
        }
    }
    printf("soma total dos numeros par = %d",somapar);
    printf("total de numeros impar digitados", totalImpar);
    return 0;
}*/







/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void iniciarJogo(char jogo[][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            jogo[i][j] = ' ';
        }
    }
    system("cls");
}

void imprimir(char jogo[][3]){
    int i,j;
    printf("\n\n\t colunas\n");
    printf("\t 0   1   2\n\n");
    for(i=0;i<3;i++){
        printf("\t");
        for(j=0;j<3;j++){
            printf(" %c ",jogo[i][j]);
            if(j<2){
                printf("|");
            }
            if(j == 2){
                printf("  %d linhas",i);
            }
        }
        printf("\n");
        if(i<2){
            printf("\t-----------\n");
        }
    }
}

int ganhouLinha(char jogo[][3], char x, int i){
    if(jogo[i][0] == x && jogo[i][1] == x && jogo[i][2] == x){
        return 1;
    }else{
        return 0;
    }
}

int ganhouLinhas(char jogo[][3], char x){
    int i;
    int ganhou = 0;
    for(i=0;i<3;i++){
        ganhou += ganhouLinha(jogo, x, i);
    }
    return ganhou;
}

int ganhouColuna(char jogo[][3], char x, int j){
    if(jogo[0][j] == x && jogo[1][j] == x && jogo[2][j] == x){
        return 1;
    }else{
        return 0;
    }
}

int ganhouColunas(char jogo[][3], char x){
    int j;
    int ganhou = 0;
    for(j=0;j<3;j++){
        ganhou += ganhouColuna(jogo, x, j);
    }
    return ganhou;
}

int ganhouDiagDescendo(char jogo[][3], char x){
    if(jogo[0][0] == x && jogo[1][1] == x && jogo[2][2] == x){
        return 1;
    }else{
        return 0;
    }
}

int ganhouDiagCrescendo(char jogo[][3], char x){
    if(jogo[0][2] == x && jogo[1][1] == x && jogo[2][0] == x){
        return 1;
    }else{
        return 0;
    }   
}

int ehvalida(char jogo[][3], int i, int j){
    if(i>= 0 && i<3 && j>=0 && j<3 && jogo[i][j] == ' '){
        return 1;
    }else{
        return 0;
    }
}

void perguntaCordenadas(char jogo[][3], char x){
    int i,j;
    printf("informe as cordenadas a ser preenchida");
    printf("\ninforme a linha   ");
    scanf("%d",&i);
    printf("informe a coluna    ");
    scanf("%d",&j);

    while(ehvalida(jogo, i, j) == 0){
        printf("informe as cordenadas a ser preenchida");
        printf("\ninforme a linha   ");
        scanf("%d",&i);
        printf("informe a coluna    ");
        scanf("%d",&j);
    }
    jogo[i][j] = x;
}

int quantDisponivel(char jogo[][3]){
    int i,j;
    int disponivel = 0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(jogo[i][j] == ' '){
                disponivel++;
            }
        }
    }
    return disponivel;
}

void jogar (char jogo[][3]){
    int vitoriaX = 0, vitoria0 = 0, player = 1;
    char jogadorX = 'X', jogador0 = '0';
    do{
        imprimir(jogo);

        if(player == 1){
            perguntaCordenadas(jogo, jogadorX);
            player++;
            vitoriaX += ganhouColunas(jogo, jogadorX);
            vitoriaX += ganhouLinhas(jogo, jogadorX);
            vitoriaX += ganhouDiagCrescendo(jogo, jogadorX);
            vitoriaX += ganhouDiagDescendo(jogo, jogadorX);
    
        }else{
            perguntaCordenadas(jogo, jogador0);
            player = 1;
            vitoria0 += ganhouColunas(jogo, jogador0);
            vitoria0 += ganhouLinhas(jogo, jogador0);
            vitoria0 += ganhouDiagCrescendo(jogo, jogador0);
            vitoria0 += ganhouDiagDescendo(jogo, jogador0);
        }

        system("cls");
    }while(vitoria0 == 0 && vitoriaX == 0 && quantDisponivel(jogo) > 0);
    
    imprimir(jogo);

    if(vitoria0 == 1){
        printf("\nparabens!! jogador 0 ganhou\n");
    }else if( vitoriaX == 1){
        printf("\nparabens!! jogador X ganhou\n");
    }else{
        printf("\nnao houve vencedor, que pena\n");
    }

}

int main(){
    char *jogo;
    char matriz [3][3];
    jogo = matriz;
    int opcao;
    do{
        iniciarJogo(jogo);
        jogar(jogo);
        printf("\n\ngostaria de jogor novamente?? digite 1 para sim, 0 para nao.     ");
        scanf("%d", &opcao);
    }while(opcao = 1);
    return 0;
}
*/