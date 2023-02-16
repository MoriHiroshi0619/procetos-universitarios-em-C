//                                              lista 31


                        //3.4.3
/*
#include <stdio.h>

int soma (int a, int b, int c, int d){
    int menor=0, i, soma=0;
    int vet[4] = {a,b,c,d};
    for(i=0;i<4;i++){
        if(i==0){
            menor = vet[i];
        }
        if(menor > vet[i]){
            menor = vet[i];
        }
    }
    for(i=0;i<4;i++){
        if(vet[i]==menor){
            continue;
        }
        soma += vet[i];
    }
    return(soma);
}

typedef struct{
    int numero, nota_mes[4], nota_final,soma_nota;
    char  conceito, nome[30];
}dados_alunos;

int main (){
    dados_alunos aluno[3];
    int i,j,total_alunos = 3;
    printf("iniciar leituea de dados dos alunos");
    printf("\n\n\n\n");
    for(i=0;i<total_alunos;i++){
        printf("\ninforme o nome do aluno %d\t",i+1);
        scanf(" %s", aluno[i].nome);
        printf("\ninforme o numero do aluno %s\t",aluno[i].nome);
        scanf("%d",&aluno[i].numero);
        for(j=0;j<4;j++){
            do{
                printf("\ninforme a %d nota mensal do aluno %s\t",j+1,aluno[i].nome);
                scanf("%d",&aluno[i].nota_mes[j]);
            }while(aluno[i].nota_mes[j]>20);
        }
        do{
            printf("\ninforme a nota final\t");
            scanf("%d",&aluno[i].nota_final);
        }while(aluno[i].nota_final>40);
        aluno[i].soma_nota = soma(aluno[i].nota_mes[0],aluno[i].nota_mes[1],aluno[i].nota_mes[2],aluno[i].nota_mes[3]);
        aluno[i].soma_nota += aluno[i].nota_final;
        if(aluno[i].soma_nota<39 && aluno[i].soma_nota>=0){
            aluno[i].conceito = 'F';
        }else if(aluno[i].soma_nota<59 && aluno[i].soma_nota>40){
            aluno[i].conceito = 'E';
        }else if(aluno[i].soma_nota<69 && aluno[i].soma_nota>60){
            aluno[i].conceito = 'D';
        }else if(aluno[i].soma_nota<79 && aluno[i].soma_nota>70){
            aluno[i].conceito = 'C';
        }else if(aluno[i].soma_nota<89 && aluno[i].soma_nota>80){
            aluno[i].conceito = 'B';
        }else{
            aluno[i].conceito = 'A';
        }
    }
    for(i=0;i<total_alunos;i++){
        printf("\n\n\n");
        printf("\naluno = %s",aluno[i].nome);
        printf("\nnumero = %d",aluno[i].numero);
        printf("\nsoma das notas = %d",aluno[i].soma_nota);
        printf("\nconceito = %c",aluno[i].conceito);
    }
}*/

                                //3.4.4
/*
#include <stdio.h>
typedef struct {
    int numero, aposta[10],pontos;
    char nome[30];
}dados;

int dezenas_sorteadas(int *vet1, int x, int *vet2, int y)
{
    int pontos = 0, i,j;
    for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                int valorAposta = vet2[j];
                if(vet1[i] == valorAposta){
                    if(pontos == 5){
                        break;
                    }
                    pontos++;
                }
            }
    }
    return(pontos);
}

int main ( )
{
    dados loto[30];
    int i, sorteada[5],numero_aposta, keep = 1,j,resposta,total,terno=0,quarto=0,quinto=0;
    
    printf("informe as 5 dezenas sorteadas ");
    for(i=0;i<5;i++)
    {
        printf("\n dezena de numero %d \t",i+1);
        scanf("%d", &sorteada[i]);
    }
    i=0;
    while(keep)
    {
        printf("\ninforme o nome\t");
        scanf("%s", loto[i].nome);
        printf("\ninforme o numero da aposta\t");
        scanf("%d", &loto[i].numero);
        do{
            printf("\n informe a quantidade de dezenas apostadas (max 10)\t");
            scanf("%d",&numero_aposta);
        }while(numero_aposta>10);
        for(j=0;j<numero_aposta;j++){
            do{
                printf("\ninforme a aposta (dezena de numero %d)\t",j+1);
                scanf("%d", &loto[i].aposta[j]);
            }while(loto[i].aposta[j]>99);
        }
        
        loto[i].pontos = dezenas_sorteadas(sorteada, 5, loto[i].aposta, 10);
        
        if(loto[i].pontos == 3){
            terno++;
        }else if(loto[i].pontos == 4){
            quarto++;
        }else if (loto[i].pontos == 5){
            quinto++;
        }
        
        i++;
        printf("/n se desejar parar digite 0, senao digite 1\t");
        scanf("%d", &resposta);
        if(resposta==0){
            keep = 0;
            total = i;
        }
    }

    printf("\n\nmostrar resultado");
    
    for(i=0;i<total;i++){
        if(loto[i].pontos<=2){
            continue;
        }
        printf("\n\nnome = %s",loto[i].nome);
        printf("\nnumero aposta = %d",loto[i].numero);
        printf("\npontos = %d",loto[i].pontos);
    }
    printf("\n\n");
    printf("\ntotal de terno = %d",terno);
    printf("\ntotal de quarto = %d",quarto);
    printf("\ntotal de quinto = %d",quinto);
}*/

                //questao de sorteio de dados     3.4.6
/*
#include <stdio.h>

int result (int dados[], int total){
    int i,numero[5],resultado = 0, maior = 0;
    for(i=0;i<6;i++){
        numero[i] = 0;
    }
    for(i=0;i<total;i++){
        if(dados[i]==1){
            numero[0]++;
        }
        if(dados[i]==2){
            numero[1]++;
        }
        if(dados[i]==3){
            numero[2]++;
        }
        if(dados[i]==4){
            numero[3]++;
        }
        if(dados[i]==5){
            numero[4]++;
        }
        if(dados[i]==6){
            numero[5]++;
        }
    }
    for(i=0;i<6;i++){
        if(numero[i]>maior){
            maior = numero[i];
            resultado = i+1;
        }
    }
    return(resultado);
}

int main(){
    int dados_dia[30],dados_result[6];
    int ganhador_mes,i,j;
    printf("iremos comecar a analise dos jogos");
    srand (time(NULL));
    do{
        for(i=0;i<30;i++){
            do{
                printf("\n\n\n\njogadas do dia %d",i+1);
                for(j=0;j<6;j++){
                    do{
                        //printf("\ninforme o numero obtido pelo dado(jogada %d)\t",j+1);                
                        dados_result[j] = rand ()%6+1;
                        printf("\nnumero obtido dia %d/jogada%d = %d",i+1,j+1,dados_result[j]);
                        //scanf("%d",&dados_result[j]);
                    }while(dados_result[j]>6);
                }
                dados_dia[i] = result(dados_result,6);
                printf("\n\nganhador do dia %d = %d",i+1,dados_dia[i]);
            }while(dados_dia[i]==0);
        }
        ganhador_mes = result(dados_dia,5);
    }while(ganhador_mes==0);
    printf("\n\n\t\tganhador mensal = %d\n\n",ganhador_mes);
    for(i=0;i<30;i++){
        printf("\nganhador dia %d = %d",i+1,dados_dia[i]);
    }
}
*/

                    //questao de horarios de entrada e saida de funcionarios   AED
/*
#include <stdio.h>

typedef struct{
    int inscricao, cargo, total_minuto;
    int hora_entra[5], hora_sai[5];
    int minuto_entra[5], minuto_sai[5];
    int horas_totais, minutos_totais;
    float salario;
    char nome[50]; 
}funcionario;

int conversao_minuto(int a, int b){
    return((a*60)+b);
}

int horas_totais(int a){
    return(a/60);
}

int minutos_totais(int a){
    return(a%60);
}

int main(){
    funcionario func[100];
    int i=1,j,hora1,hora2,total,ref1,ref2;
    int keep = 1;
    while(keep){
        printf("\ninforme a inscricao do funcionario\t");
        scanf("%d",&func[i].inscricao);
        printf("\ninforme o nome do funcionario\t");
        scanf("%s", func[i].nome);
        for(j=0;j<5;j++){
            printf("\ndia %d da semana",j+1);
            do{
                printf("\ninforme a hora de entrada\t");
                scanf("%d",&func[i].hora_entra[j]);
            }while(func[i].hora_entra[j]>24);
            do{
                printf("\ninforme o minuto de entrada\t");
                scanf("%d",&func[i].minuto_entra[j]);
            }while(func[i].minuto_entra[j]>60);
            ref1 = func[i].hora_entra[j];
            ref2 = func[i].minuto_entra[j];
            hora1 = conversao_minuto(ref1, ref2);

            do{
                printf("\ninforme a hora de sainda\t");
                scanf("%d",&func[i].hora_sai[j]);
            }while(func[i].hora_sai[j]>24);
            do{
                printf("\ninforme o minuto de saida\t");
                scanf("%d",&func[i].minuto_sai[j]);
            }while(func[i].minuto_sai[j]>60);
            ref1 = func[i].hora_sai[j];
            ref2 = func[i].minuto_sai[j];
            hora2 = conversao_minuto(ref1, ref2);

            func[i].total_minuto += hora2 - hora1;
        }
        ref1 = func[i].total_minuto;
        func[i].horas_totais = horas_totais(ref1);
        ref2 = func[i].total_minuto;
        func[i].minutos_totais = minutos_totais(ref2);

        do{
            printf("\ninforme o cargo do funcionario(1 2 3)\t");
            printf("\ndigite 0 caso queira terminar\t");
            scanf("%d", &func[i].cargo);
        }while(func[i].cargo>3);
        i++;
        if(func[i].cargo == 0){
            keep = 1;
            total = i;
        }
    }                   
    for(i=0;i<total;i++){
        if(func[i].cargo == 1){
            int salario_hora = 300;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
        if(func[i].cargo == 2){
            int salario_hora = 400;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
        if(func[i].cargo == 3){
            int salario_hora = 1000;
            printf("\ninscricao = %d",func[i].inscricao);
            printf("\nnome = %s ",func[i].nome);
            printf("\ncargo = %d",func[i].cargo);
            printf("\nhoras totais = %d\t",func[i].horas_totais);
            printf("minutos totais = %d",func[i].minutos_totais);
            if(func[i].horas_totais < 40){
                func[i].salario = ((float)salario_hora * func[i].horas_totais)/(float)2;
            }
            if(func[i].horas_totais>= 40){
                int horas;
                float hora_extra;
                horas = func[i].horas_totais-40;
                hora_extra = (horas * salario_hora)/2;
                func[i].salario = (salario_hora * 40)+ hora_extra;
            }
            printf("\nsalario = %2.1f",func[i].salario);
        }
    }
}
*/
                                    // 3.4.10
/*
#include <stdio.h>
#include <string.h>

//função para calcular o numero de algarismos do numero
int quanti_algarismo(int n){
    char numero[5];
    int n_alga;
    sprintf (numero,"%d",n);
    n_alga = strlen(numero);
    return(n_alga);
}

//função que valida se o numero é uma capicua, se sim devolve 1(verdade) se nao devolve 0(falso)
int validar_capicua (int algarismos, char numero[5]){
    int ref = 1, i, j;
    j = algarismos-1;
    for(i=0;i<algarismos;i++){
        if(numero[i] != numero[j]){
            ref = 0;
            break;
        }
        j--;
    }
    return(ref);
}

int main(){
    int n_algarismos, i, j, ref,n,quadrado[100],cont = 0,result = 0;
    char numero[5];
    
    for(i=1;i<5000;i++){
        if(quadrado[i-1]>=5000){
            break;
        }
        quadrado[i] = i*i;
        cont++;
    }    
        
        
    for(n=0;n<5000;n++){
        ref = 1;
        sprintf (numero,"%d",n);
        n_algarismos = quanti_algarismo(n);
        ref = validar_capicua(n_algarismos,numero);
        
        
        
        
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
                            //.3.4.9
/*
#include <stdio.h>

int calculo(int x, int y){
    int y1 ,resu=0;
    y1 = y;
    while(x != 1){
        x = x/2;
        y = y*2;
    }
    resu = y + y1;
    return(resu);
}

int main (){
    int numero1[10], numero2[10], soma[10],i;
    for(i=0;i<10;i++){
        printf("\n\npar de numero %d",i+1);
        printf("\ninforme o primeiro numero\t");
        scanf("%d",&numero1[i]);
        printf("\ninformw o segundo numero\t");
        scanf("%d",&numero2[i]);
        soma[i] = calculo(numero1[i],numero2[i]);
        printf("\nresultado = %d",soma[i]);

    }

}*/
                        //3.4.12
/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void distancia(int *x, int *y, int *dif){;

    if(*x>*y){
        *dif = *x-*y;
    }else{
        *dif = *y-*x;
    }

}

void prencher(int *x,int tam){
    srand(time(NULL));
    int i;
    for(i=0;i<tam;i++){
        x[i] = rand()%100;
    }
}

void imprimir(int *x,int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("\n%d valor = %d",i+1,x[i]);
    }
}

int main (){
    int m,i;
    int *v1,*v2;
    printf("informe os pares de vetores a serem analisados\t");
    scanf("%d",&m);
    for(i=0;i<=m;i++){
        int tam,tam2,*dif;
        printf("\npares de vetores numero %d",i+1);
        printf("\ninforme o numero de posicoes do primeiro vetor\t");
        scanf("%d",&tam);
        v1 = (int *)malloc(tam * sizeof(int));
        prencher(&v1,tam);
        imprimir(&v1,tam);
        printf("\ninforme o numero de posicoes do segundo vetor\t");
        scanf("%d",&tam2);
        prencher(&v2,tam2);
        imprimir(&v2,tam2);
        v2 = (int *)malloc(tam * sizeof(int));
        distancia(&tam,&tam2,&dif);
        printf("\ndiferenca de posicoes =%d",dif);
        free(v1);
        free(v2);
    }
}
*/


                        //3,4,15
/*

#include <stdio.h>

float fatorial(int numero){
    int i;
	int resultado = 1;
	if(numero > 1)
	{
		for (i = 2; i <= numero; i++)
		{
			resultado *= i;
		}
	}

	return resultado;
}


int main()
{
    double sequencia = 1; //sequencia e
	int nTermos = 1;
	int i = 2;


    while(abs(exp(1) - sequencia) <= 0,0001 && nTermos < 100){
		sequencia += 1 / fatorial(i);
		nTermos++;
		i++;
		printf("Termos: %d   Sequencia: %d\n", nTermos, sequencia);
    }
}
*/

                //3,4,18

/*
#include <stdio.h>

int qtdDeMDC(int mdc, int numero)
{
  int i;
  int resto;
  scanf ("%d", &mdc);
  for (i = 1; i < 2; i++)
    {
      //printf("Entre com o %do. numero da sequencia: ", i+1);
      scanf ("%d", &numero);

          while (numero != 0){
          resto = mdc % numero;
          mdc   = numero;
          numero = resto;
        }
        printf("Maximo divisor comum: %d\n", mdc);
    }

  return 0;
}

int main()
{

    int numA, numB, maxDivisor;
    for(int i = 0; i < 30; i++){
        printf("Conjunto %d: ", i + 1);
        //scanf("%d %d", &numA, &numB);
        qtdDeMDC(numA, numB);
    }

}
*/




                                //lista 32

