/*1*/
/*#include <stdio.h>

    int main(){
        
        float contador=1,idadeSoma=0;
        float idade,media,pessoas;
        printf("informe o total de gente que sera analisada:\t");
        scanf("%f",&pessoas);
        while (contador<=pessoas){
            printf("\npessoa de numero %2.0f",contador);
            printf("\ninforme sua idade:\t");
            scanf("%f",&idade);
            idadeSoma=idadeSoma+idade;
            contador++;
        }
        media = idadeSoma/pessoas;
        printf("\na media da idade deste grupo eh de %2.1f anos de idade",media);
    }
*/
/*2- */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    int main(){
        int i=1,total=5;
        float altura,maior=0,menor=0,media,homenContador=0,mulherContador=1,somaMulher=0;
        char sexo[10];
        printf("\t\t***iremos iniciar o programa***");
        printf("\ncomece a inserir os dados:\n\n");

        for(i;i<=total;i++){
            printf("\n\n\t\tanalise %d de um total de %d",i,total);
            printf("\n\nEh um homem ou uma mulher? \t\t:");
            scanf(" %s",&sexo);
            printf("\ninforme a altura em cm\t\t:");
            scanf("%f",&altura);

            

            if(strcmp(sexo,"mulher") == 0){
                somaMulher=altura+somaMulher;
                media = somaMulher/mulherContador;
                mulherContador++;
            }else if(strcmp(sexo,"homem") == 0){
                homenContador++;
            }else{
                printf("\no sexo inserido eh invalido!\n digite novamente");
                i--;
                continue;
            }

            if(i == 1){
                maior = altura;
                menor = altura;
            }

            if(altura>maior){
                maior = altura;
            }else if (altura<menor) {
                menor = altura;
            }else{
                printf("\nnessa analise de numero %d nao tivemos um novo maior numero ou menor numero.",i);
            }

            printf("\n:::proxima analise:::");
                                
        }



        printf("\n\n\no maior altura desse grupo foi de %2.0f cm e a menor altura foi de %2.0f cm ",maior,menor);
        printf("\na media de altura das mulheres foi de %2.1f cm",media);
        printf("\no total de homens no grupo foi de %2.0f",homenContador);

    }
*/
/*3- */
/*
#include <stdio.h>
int main (){
    float f=50,centigrado,c=1;
    printf("\n\t\t***Iremos iniciar a construcao da tabela de converscao***");

    for (c;c<=101;c++){
        centigrado = (f-32)*5/9 ;
        if(f<=99){         //usado if apenas para deixar a saida das barras mais alinhadas, não possui nenhuma função funcional de fato
            printf("\n|  %2.0f graus Farenheit| -> | %2.1f centigrados|",f,centigrado);
            f++;
        }else{
            printf("\n| %2.0f graus Farenheit| -> | %2.1f centigrados|",f,centigrado);
            f++;
        }
    }

}*/

/*4-*/

/*#include <stdio.h>
#include <string.h>

int main(){
    char nomeProduto[20],resposta[5];
    float precoCompra, precoVenda,lucro;
    int nao_terminou = 1,lucroMenos10=0,lucroMAis20=0,i=0;

    printf("\t\t******IREMOS REALIZAR A PESQUISA DAS MERCADORIAS.******\n\n\n");

    while(nao_terminou){
        i++;
        printf("\n\n////////////////////////////////////////////");
      
        printf("\n\ninforme o nome da mercadoria:\t\t");
        //fgets( nomeProduto,20,stdin);
        scanf(" %s",nomeProduto);

        printf("\ninforme o valor de compra de %s\t\t:",nomeProduto);
        scanf("%f",&precoCompra);

        printf("\ninforme o valor de venda de %s\t\t:",nomeProduto);
        scanf("%f",&precoVenda);

        //lucro = 100 - ((precoCompra*100)/precoVenda);
        lucro = (precoVenda-precoCompra)/precoCompra*100;
        printf("\no lucro desse produto eh de %2.1f porcento",lucro);

        if(lucro<=10 ){
            lucroMenos10++;
        }
        if(lucro>=20){
            lucroMAis20++;
        }

        printf("\ntem mais produtos a serem analisados o lucro? sim ou nao\t\t:");
        scanf(" %s",resposta);

        if(strcmp(resposta,"nao")==0){
            nao_terminou=0;
        }else if(strcmp(resposta,"sim")==0){
            continue;
        }else{
            printf("\nresposta invalida, iremos continuar com a analise a menos que digite nao");
            

        }

    }

    printf("\n\n////////////////////////////////////////////");
    printf("\n\nterminamos a analise");
    printf("\ntotal de %d produtos analisados:",i);
    printf("\num total de %d produtos possuem lucro menor ou igual a 10 porcento",lucroMenos10);
    printf("\num total de %d produtos possuem lucro maior ou igual a 20 porcento",lucroMAis20);
}*/

/*5-*/

 /*
#include <stdio.h>

int main(){
    int i=0;
    int nao_terminou = 1;
    float a=90000000, b=20000000;
    
    printf("\t\t***iremos iniciar o programa***\n");

    while(nao_terminou){
        i++;
        a = a+(a*0.01);
        b = b+(b*0.03);
        printf("\nano %d\tA = %2.1f \tB= %2.1f",i,a,b);
        if(b>=a){
            nao_terminou = 0;
        }
    }

    printf("\nserah necessario %d anos para que a populacao B ultrapasse a populacao A.",i);
}*/

/*6*/
/*
#include <stdio.h>

int main(){
    double material,result,segundos=0,horas,minutos;
    int continua = 1,i=0;
    printf("\t\tiremos iniciar o programa***\n");
    printf("\ninforme a massa do meterial em gramas \n");
    scanf("%lf",&material);

    while(continua){
        material = material / 2 ;
        segundos = segundos + 50;
        printf("\nmaterial com %2.1lf gramas apos %2.0lf segundos",material,segundos);
        if(material<0.5){
            continua = 0;
        }
        i++;

    }
    minutos = segundos / 60;
    horas = minutos / 60;
    printf("\n\na massa final sera de %2.1f gramas apos %2.1lf horas %2.1lf minutos e %2.0lf segundos.",material,horas,minutos,segundos);
    

}
*/

/*7*/
/*
#include <stdio.h>
#include <string.h>
int main (){
    int turma=1,totalAlunos,aluno=1,a=0,matricula,turmaA=0;
    float ausenciaP;
    char estado[2],turmaNome[2];

    printf("\t\t*****iremos iniciar o programa*****\n\n");

    for(turma;turma<=14;turma++){
        printf("\ninsira a identificacao da turma:\t");
        scanf(" %s",&turmaNome); 
        printf("\ninsira o total de alunos da turma %s :\t",turmaNome);
        scanf("%d",&totalAlunos);
        printf("okay.... iremos iniciar a analise da turma %s",turmaNome);
        printf("\n\n");
        a=0;
        for(aluno=1;aluno<=totalAlunos;aluno++){
            printf("\ninsira a matricula do aluno:\t");
            scanf("%d",&matricula);
            printf("\ninforome se o aluno de matricula %d estava presente ou ausente. p para ausente e a para ausente.:\t\t",matricula);
            scanf("%s",&estado);
            if(strcmp(estado,"a")==0){
                a++;
            }
        }
        ausenciaP=0;
        ausenciaP = (((float)a*100)/(float)totalAlunos);
        if (ausenciaP>=5){
            turmaA++;
        }
        printf("\n\na porcentagem de ausencia da turma %s foi de %2.1f porcento",turmaNome,ausenciaP);
        printf("\n\n");
    }
    
    printf("\n\num total de %d turmas tem ausencia superior ou igual a 5 porcento",turmaA);
    printf("\n\n\t\t*****fim do programa******");
}*/

/*8-*/
/*
#include <stdio.h>
#include <string.h>

int main(){

    int s=0,n=0,h=0,m=0,i;
    float Psim,Pnao;
    char respota[5],sexo[9];

    printf("\t\t***iremos iniciar a pesquisa***\n");

    for(i=1 ;i<=5;i++){

        printf("\ncontador -> %i/5",i);
        printf("\ninforme seu sexo\t");
        scanf("%s",sexo);
        printf("\ninforme se gostou do produto, sim ou nao.\t");
        scanf("%s",respota);
        //printf("%s,%s",sexo,respota);

        if(strcmp(sexo,"mulher")==0 && strcmp(respota,"sim")==0){
            m++;
        }
        if(strcmp(sexo,"homem")==0 && strcmp(respota,"nao")==0){
            h++;
        }
        if(strcmp(respota,"sim")==0){
            s++;
        }
        if(strcmp(respota,"nao")==0){
            n++;
        }
    }

    Psim = (m*100)/5;
    Pnao = (h*100)/5;

    printf("\n\ntotal de pessoas que respoderam sim eh de %i",s);
    printf("\ntotal de pessoas que respoderam nao eh de %i",n);
    printf("\nporcetam de mulheres que gostaram eh de %2.1f",Psim);
    printf("\nporcetagem de homens que nao gostaram eh de %2.1f",Pnao);

}*/

/*9*/

/*#include <stdio.h>
#include <string.h>

int main (){
    int vazio = 1,i = 0,b=0, more24 =  0;
    float born, meses, pMortos, pMasculinos,p24;
    char sexo[10],respota[5];
    //sprintf(nao,"nao");
    //sprintf(sim,"sim");
    printf("\t\t\n ***iremos iniciar o programa***");
    printf("\ninforme o numero de criacas nascidas no periodo\t:");
    scanf("%f",&born);
    do{
        printf("\n\nhouve pelo menos uma crianca morta? sim ou nao\t:");
        scanf("%s",respota);
        if(strcmp(respota,"nao")==0){
        vazio = 0;
        }
    }while (strcmp(respota,"nao") !=0 && strcmp(respota,"sim")!=0);
    while(vazio){
        printf("\ncaso tenha terminado a analise digite vazio no sexo da crianca");
        do{
            printf("\ninforme o sexo da crianca. masculino ou feminino\t\t:");
            scanf("%s",sexo);
            if(strcmp(sexo,"masculino")==0){
            b++;
            }
        }while(strcmp(sexo,"masculino")!=0 && strcmp(sexo,"vazio")!=0 && strcmp(sexo,"feminino")!=0);
        if(strcmp(sexo,"vazio")==0){
            break;
        }
        printf("\ninforme quanto meses a crianca viveu\t:");
        scanf("%f",&meses);
        i++;
        if(meses<=22){
            more24++;
        }
    }
    pMortos = ((float)i*100)/born;
    pMasculinos = ((float)b*100)/born;
    p24 = ((float)more24*100)/born;
    printf("\n\no total de criancas mortas nesse periodo foram de %2.1f criancas",pMortos);
    printf("\no total de criancas do sexo masculino mortos nesse periodo foram de %2.1f criancas",pMasculinos);
    printf("\no total de criancas mortas com menos de 24 meses nesse periodo foram de %2.1f criancas",p24);
}*/

/*10*/
/*
#include <stdio.h>
#include <string.h>
int main (){
    int canal,casa=1,pessoas,totalPessoas=0,continua = 1,pessoasC[4],i,j;
    float audieciaP[4];
    char resposta1[5],resposta2[5];
    printf("\t\t\t***iremos iniciar o programa***\n");
    for(i=0;i<=4;i++){
        audieciaP[i] = i;
    }
    for (j=0;j<=4;j++){
        pessoasC[j] = j;
    }
    pessoasC[0] = 0;
    pessoasC[1] = 0;
    pessoasC[2] = 0;
    pessoasC[3] = 0;
    audieciaP[1] = 0;
    audieciaP[2] = 0;
    audieciaP[3] = 0;
    do{
        if(casa>1){
            do{
                printf("\ndeseja continuar com a pesquisa? sim ou nao\t:");
                scanf(" %s",resposta1);
            }while(strcmp(resposta1,"sim")!=0 && strcmp(resposta1,"nao")!=0);
            if(strcmp(resposta1,"nao")==0){
                break;
            }
        }
        printf("\ncasa de numero %d",casa);
        do{
            printf("\na televisao na casa %d estava ligada? sim ou nao:\t",casa);
            scanf(" %s", resposta2);
        }while(strcmp(resposta2,"sim")!=0 && strcmp(resposta2,"nao")!=0);
        if(strcmp(resposta2,"nao")==0){
            casa++;
            continue;
        }
        do{
        printf("\ninforme o canal de tv assistido 4, 5, 7 ou 12\t");
        scanf("%d",&canal);
        }while(canal!=4&&canal!=5&&canal!=7&&canal!=12);
        printf("\ninforme o numero de pessoas que assistiu ao canal %d\t",canal);
        scanf("%d",&pessoas);
        totalPessoas += pessoas;
        if(canal==4){
            pessoasC[0] += pessoas;
        }else if(canal==5){
            pessoasC[1] += pessoas;
        }else if(canal==7){
            pessoasC[2] += pessoas;
        }else{
            pessoasC[3] += pessoas;
        }
        casa++;
    }while(continua);
    audieciaP[0] = ((float)pessoasC[0]*100)/(float)totalPessoas;
    audieciaP[1] = ((float)pessoasC[1]*100)/(float)totalPessoas;
    audieciaP[2] = ((float)pessoasC[2]*100)/(float)totalPessoas;
    audieciaP[3] = ((float)pessoasC[3]*100)/(float)totalPessoas;
    printf("\n o canal 4 teve %.1f porcentos de audiencia.",audieciaP[0]);
    printf("\n o canal 5 teve %.1f porcentos de audiencia.",audieciaP[1]);
    printf("\n o canal 7 teve %.1f porcentos de audiencia.",audieciaP[2]);
    printf("\n o canal 12 teve %.1f porcentos de audiencia.",audieciaP[3]);
}
*/
/*
#include <stdio.h>
int main(){
    int alunos[6], codigo[6],frequencia[6],reprovados=0,reprovadoF=0,i,z,j;
    int matirucla,regularidade,totalAlunos = 3;
    float notaFinal[6],mediaSoma=0,reprovadosP,reproFP,maior=0,menor=0,prova1, prova2, prova3;
    for(i=0;i<=totalAlunos;i++){
        alunos[i] = i;
        codigo[i] = i;
        codigo[i] = 0;    
        frequencia[i] = i;      
        notaFinal[i] = i;
    }
    for(z=0;z<totalAlunos;z++){
        printf("\n\n\ninforme o numero da matricula do aluno\t%d   ",z+1);
        scanf("%d",&matirucla);
        alunos[z] = matirucla;
        do{
            printf("\ninforme a nota 1 do aluno\t  ");
            scanf("%f",&prova1);
        }while(prova1>10);
        do{
            printf("\ninforme a nota 2 do aluno\t  ");
            scanf("%f",&prova2);
        }while(prova2 > 10);
        do{
            printf("\ninforme a nota 3 do aluno\t  ");
            scanf("%f",&prova3);
        }while(prova3 > 10);
        do{
            printf("\ninforme a frequencia do aluno dentre 100 aulas\t  ");
            scanf("%d",&regularidade);
        }while(regularidade > 100);
        frequencia[z] = regularidade;
        notaFinal[z] = (prova1 + prova2 + prova3) /3;
        if(z==0){
            maior = notaFinal[z];
            menor = notaFinal[z];
        }
        if(notaFinal[z]>maior){
            maior = notaFinal[z];
        }
        if(notaFinal[z]<menor){
            menor = notaFinal[z];
        }
        if(notaFinal[z] <=6 || frequencia[z] <=40){
            codigo[z] = 1; //1 = reprovado
            reprovados++;
        }
        if(notaFinal[z]>=6 && frequencia[z]<=40){
            reprovadoF++;
        }
        mediaSoma += notaFinal[z];
    }
    reprovadosP = (reprovados*100)/totalAlunos;
    reproFP = (reprovadoF*100)/totalAlunos;
    printf("\n\n\nteve um total de %d alunos reprovados",reprovados);
    printf("\n %.1f porcentos dos alunos reprovados",reprovadosP);
    printf("\n %.1f porcentos reprovados por falta",reproFP);
    printf("\na maior nota media foi de %.1f ",maior);
    printf("\na menor nota media foi de %.1f",menor);
    printf("\n***importante -> \t codigo 1 = reprovado \t codigo 0 = aprovado");
    for(j=0;j<totalAlunos;j++){
        if(codigo[j]== 1){
            printf("\naluno de matricula %d, teve frequencia de %d, nota final de %.1f e esta REPROVADO",alunos[j],frequencia[j],notaFinal[j]);
        }else{
            printf("\naluno de matricula %d, teve frequencia de %d, nota final de %.1f e esta APROVADO   ",alunos[j],frequencia[j],notaFinal[j]);
        }
    }
}
*/
//15
/*
#include <stdio.h>
#include <string.h>
int main(){
    int n,numeroConta[10],numero,i,j=0,operacao,x,z;
    float taxa, saldo[10],minimoSaldo,valorOperacao,saqueValido;
    char tipoOperacao[15];
    printf("\ninforme o total de contas a serem analisadas\t");
    scanf("%d", &n);
    printf("\ninforme o saldo minimo para uma conta\t");
    scanf("%f",&minimoSaldo);
    printf("\ninforme o valor da taxa \t");
    scanf("%f",&taxa);
    for(i=0;i<n;i++){
        numeroConta[i]=0;
        saldo[i] = 0;
    }
    printf("\n\n");
    while(j<n){
        printf("\ninforme o numero da conta\t");
        scanf("%d",&numero);
        numeroConta[j] = numero;
        printf("\ninforme o numero de oporacoes realizas pela conta\t");
        scanf("%d",&operacao);
            for(x=0;x<operacao;x++){
                do{
                    printf("\ninforme o tipo de operacao. deposito ou saque\t\t");
                    scanf("%s",tipoOperacao);
                }while(strcmp(tipoOperacao,"deposito")!=0 && strcmp(tipoOperacao,"saque")!=0);
                if(strcmp(tipoOperacao,"saque")==0){
                    if(saldo[j] == 0){
                        printf("saldo atual de %.2f reais, nao fundos para ser sacado. favor inserir 'deposito' ",saldo[j]);
                        x--;
                        continue;
                    }
                    saqueValido = saldo[j];
                    do{
                        printf("saldo atual de %.2f reais",saldo[j]);
                        printf("\ninforme o valor do saque\t");
                        scanf("%f",&valorOperacao);
                    }while(valorOperacao>saqueValido);
                    saldo[j] = saldo[j] - valorOperacao ;
                }
                if(strcmp(tipoOperacao,"deposito")==0){
                    printf("saldo atual de %.2f reais",saldo[j]);
                    printf("\ninforme o valor do deposito\t");
                    scanf("%f",&valorOperacao);
                    saldo[j] = saldo[j] + valorOperacao ;
                }
            }
        j++;
    }
    printf("\n\n");
    for(z=0;z<n;z++){
        if(saldo[z]==0){
            printf("\nconta de numero %d, nao ha fundos",numeroConta[z]);
        }else if(saldo[z]>0 && saldo[z]<minimoSaldo){
            printf("\nconta de numero %d, saldo no final do dia de %.2f reais devera pagar taxa de %.2f. saldo final de %.2f reais",numeroConta[z],saldo[z],taxa,saldo[z]-taxa);
        }else{
            printf("\nconta de nuemro%d, saldo no final do dia de %.2f reais",numeroConta[z],saldo[z]);
        }
    }
}*/
//18
/*
#include <stdio.h>
int main (){
    int i=0,equipe[100],inscricao,keep = 1,totalPar,vencedor;
    float padrao[3],tempo,etapa1[100],etapa2[100],etapa3[100],a1[100],a2[100],a3[100],somapontos[100],pontos1[100],pontos2[100],pontos3[100],maior=0;
    printf("\ninforme o tempo padrao para cada um das tres fases\t");
    for(i=0;i<3;i++){
        printf("\nfase %d\t",i);
        scanf("%f",&tempo);
        padrao[i] = tempo;
    }
    printf("\n");
    i=0;
    while(keep){
        printf("\n se desejar terminar a analise difite 9999 no numero de inscricao");
        printf("\ninforme o numero de inscricao de cada equipe\t");
        scanf("%d",&inscricao);
        if (inscricao == 9999){
            break;
        }
        equipe[i] = inscricao;
        printf("\ninforme o tempo descorrido da equipe %d para cada uma das tres fases",equipe[i]);        
        printf("\ntempo na fase 1\t");
        scanf("%f",&tempo);
        etapa1[i] = tempo;
        printf("\ntempo na fase 2\t");
        scanf("%f",&tempo);
        etapa2[i] = tempo;
        printf("\ntempo na fase 3\t");
        scanf("%f",&tempo);
        etapa3[i] = tempo;
        i++;       
        totalPar = i; 
    }
    for(i=0;i<totalPar;i++){
        a1[i] = etapa1[i] - padrao[0];
        if(a1[i]<3){
            pontos1[i] = 100;
        }else if (a1[i]>=3 && a1[i]<=5){
            pontos1[i] = 80;
        }else{
            pontos1[i] = 80-(a1[i]-5)/5;
        }
        somapontos[i] += pontos1[i];
        a2[i] = etapa2[i] - padrao[1];
        if(a2[i]<3){
            pontos2[i] = 100;
        }else if (a2[i]>=3 && a2[i]<=5){
            pontos2[i] = 80;
        }else{
            pontos2[i] = 80-(a2[i]-5)/5;
        }
        somapontos[i] += pontos2[i];
        a3[i] = etapa3[i] - padrao[2];
        if(a3[i]<3){
            pontos3[i] = 100;
        }else if (a3[i]>=3 && a3[i]<=5){
            pontos3[i] = 80;
        }else{
            pontos3[i] = 80-(a3[i]-5)/5;
        }
        somapontos[i] += pontos3[i];
    }
    for(i=0;i<totalPar;i++){
        if(somapontos[i] > maior){
            maior = somapontos[i];
            vencedor = i;
        }
    }
    printf("\n\n\na equipe vencedora eh a %d com %.1f pontos\n\n\n",equipe[vencedor],maior);
    for(i=0;i<totalPar;i++){
        printf("\nequipe %d / %.1f pontos primeira etapa / %.1f pontos segunda etapa / %.1f pontos terceira etapa / total de pontos %.1f\n",equipe[i],pontos1[i],pontos2[i],pontos3[i],somapontos[i]);
    }

}*/
//21
/*
#include <stdio.h>
#include <string.h>

int main (){
    int keep = 1,i,operario[100], operapeca[100], boy = 0,girl = 0,totalPecas = 0,totalHa=0,totalHb=0,tototalHc=0,totalMa=0,totalMb=0,tototalMc=0;
    int boyA=0, boyB=0, boyC=0,girlA=0,girlB=0,girlC=0,totalOp,maiorOP;
    float mediaboyA=0,mediaboyB=0,mediaboyC=0, mediagirlA=0,mediagirlB=0,mediagirlC=0,salarioOP[100],folhaPag = 0,salarioMinimo =1100,maior = 0;
    char sexo[10]; 
    printf("\niremos iniciar a analise:");
    i=0;
    while(keep){
        printf("\ninforme o numero do operario. se desejar terminar com a contagem digite 0\t");
        scanf("%d",&operario[i]);
        if(operario[i] == 0){
            break;
        }
        do{
        printf("\ninforme o sexo do operario. homem ou mulher\t");
        scanf("%s",sexo);
        }while(strcmp("homem",sexo)!= 0 && strcmp("mulher",sexo)!=0);
        if(strcmp("homem",sexo)==0){
            boy++;
            printf("\ninforme o numero de pacas fabricadas por esse operario nesse mes\t");
            scanf("%d",&operapeca[i]);
            if(operapeca[i]<=30){                             
                salarioOP[i] = salarioMinimo;
                totalHa += operapeca[i];
                boyA++;
                mediaboyA = (float)totalHa/(float)boyA;
            }else if(operapeca[i]>30&&operapeca[i]<=35){                
                salarioOP[i] = (salarioMinimo*(((float)operapeca[i] - 30)*3) /100) + salarioMinimo;
                totalHb += operapeca[i];
                boyB++;
                mediaboyB = (float)totalHb/(float)boyB;
            }else{                
                salarioOP[i] = (salarioMinimo*(((float)operapeca[i] - 30)*5) /100) + salarioMinimo;
                tototalHc += operapeca[i];
                boyC++;
                mediaboyC = (float)tototalHc/(float)boyC;
            }  
        }
        if(strcmp("mulher",sexo)==0){
            girl++;
            printf("\ninforme o numero de pacas fabricadas por esse operario nesse mes\t");
            scanf("%d",&operapeca[i]);
            if(operapeca[i]<=30){                          
                salarioOP[i] = salarioMinimo;
                totalMa += operapeca[i];
                girlA++;
                mediagirlA = (float)totalMa/(float)girlA;
            }else if(operapeca[i]>30&&operapeca[i]<=35){               
                salarioOP[i] = (salarioMinimo*(((float)operapeca[i] - 30)*3) /100) + salarioMinimo;
                totalMb += operapeca[i];
                girlB++;
                mediagirlB = (float)totalMb/(float)girlB;
            }else{               
                salarioOP[i] = (salarioMinimo*(((float)operapeca[i] - 30)*5) /100) + salarioMinimo;
                tototalMc += operapeca;
                girlC++;
                mediagirlC = (float)tototalMc/(float)girlC;
            }  
        }
        folhaPag += salarioOP[i];
        totalPecas += operapeca[i];
        i++;   
        totalOp = i;
    }
    for(i=0;i<totalOp;i++){
        if(salarioOP[i]>maior){
            maior = salarioOP[i]; 
            maiorOP = i;
        }
    }
    for(i=0;i<totalOp;i++){
        printf("\noperario de numero %d, salario de %.2f reais",operario[i],salarioOP[i]);
    }
    printf("\ntotal de operarios %d",totalOp);
    printf("\no total da folha de pagamento da fabrica sera de %.2f reais",folhaPag);
    printf("\no numero total de pecas fabricadas eh de %d",totalPecas);
    printf("\na media de pecas fabricadas pelos homens na classe A eh de %.1f",mediaboyA);
    printf("\na media de pecas fabricadas pelos homens na classe B eh de %.1f",mediaboyB);
    printf("\na media de pecas fabricadas pelos homens na classe C eh de %.1f",mediaboyC);
    printf("\na media de pecas fabricadas pelas nulheres na classe A eh de %.1f",mediagirlA);
    printf("\na media de pecas fabricadas pelas nulheres na classe B eh de %.1f",mediagirlB);
    printf("\na media de pecas fabricadas pelas nulheres na classe C eh de %.1f",mediagirlC);
    printf("\no operario de numero %d possui o maior salario com %.2f reais ",operario[maiorOP],maior);
    printf("\n");
}*/
//24
/*
#include <stdio.h>

int main (){
    int N=1,M=1;
    float soma=0, R;
    while(N<99){
        R = (float)N/(float)M;
        printf("\nR = %.1f",R);
        soma+= R;
        printf("\nsoma = %.1f",soma);
        N++;
        N++;
        M++;
    }
    printf("\n\nsoma final igual a %.1f",soma);
}*/
//27

#include <stdio.h>

int main (){
    int soma=0,numero=1,deno=1,termo,aux;
    while(numero>=10){
        termo = numero/deno;
        aux = deno % 2;
        if(aux!=0){
            soma+=termo;
        }else{
            soma-=termo;
        }
        numero++;
        deno++;
        deno++;
    }
    printf("\na soma final eh de %d",soma);
}
//30
/*
#include <stdio.h>
#include <math.h>
int main (){
    float senoA, A=0;
    while(A<=6.3){
        senoA = A - ((pow(A,3)) / 6) + ((pow(A,5)) / 120) - ((pow(A,7)) / 5040);
        printf("\nangulo %.1f senoA %.1f",A,senoA);
        A = A+0.1;
    }
}*/
