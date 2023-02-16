

#include<stdio.h>
#include <math.h>
/* 1
int main(){
      float precoAtual, precoAntigo, diferenca, porcentagem;
      char nome[15];

      printf("Qual o nome do produto que voce comprou? :");
      scanf("%s", &nome);
      printf("Quanto voce pagou esse mes? :");
      scanf("%f", &precoAtual);
      printf("Qual era o preco no mes passado? :");
      scanf("%f", &precoAntigo);

      diferenca = precoAtual - precoAntigo;
      porcentagem = (diferenca * 100) / precoAtual;

      printf("O produto %s esta R$ %2.2f mais caro, o que corresponde a um aumento de %2.2f%",nome, diferenca, porcentagem);
}*/
   /* 2
   int main(){
       float precoum, precodois, diferenca, desconto;

       printf("informe o valor pago pelo produto:");
       scanf("%f", &precoum);
       printf("informe o valor original do produto:");
       scanf("%f", &precodois);

       diferenca = precodois - precoum;
       desconto = diferenca * 100 / precodois;

       printf("com base nos dados inseridos podemos dizer que o desconto dado foi de %2.2f porcento",desconto);

   }*/
/* 6
   int main(){
       float a, b, c, d, media;

       printf("informe o valor a:");
       scanf("%f", &a);
       printf("informe o valor b:");
       scanf("%f", &b);
       printf("informe o valor c:");
       scanf("%f", &c);
       printf("informe o valor d:");
       scanf("%f", &d);

       media = ((a*1)+(b*2)+(c*3)+(d*40))/4;

       printf("a media ponderada dos quatros valores sera de %2.2f",media);

   }*/
/* 7
   int main(){
       int a, b, c;
       float hipo;

       printf("informe um dos lados do cateto:");
       scanf("%d", &a);
       printf("informe o outro lado do cateto:");
       scanf("%d", &b);

       c = (a*a)+(b*b);
       hipo = sqrt(c);


       printf("o valor da hipotenusa e %2.2f",hipo);

   }
*/

  /* 8
   int main(){

       float precox, precoy, diferenca;

       printf("informe o valor do produto:");
       scanf("%f", &precox);

       diferenca = precox*0.09;
       precoy = precox - diferenca;

       printf("o produto com desconto de 9 porcento sera de %2.2f reais", precoy);


   }*/

    /*9
    int main(){
        float a, b, c, delt, final1, final2;

        printf("informe o valor de a :");
        scanf("f", &a);
        printf("informe o valor de b :");
        scanf("f", &b);
        printf("informe o valor de c :");
        scanf("f", &c);

        delt = b*b – 4 * a * c;
        final1 = ((-b+delt)/(2*a));
        final2 = ((-b-delt)/(2*a));

        printf("o resultado sera de %f e %f",final1,final2);


    }
*/


/* 10
    int main(){

    float p, taxa, taxaf, n, valorAcumulado, pt1;

    printf("informe o valor de aplicacao mensal:");
    scanf("%f",&p);
    printf("informe o valor da taxa de rendimentos:");
    scanf("%f",&taxa);
    printf("informe o numero de meses que sera aplicado:");
    scanf("%f",&n);

    taxaf = taxa /100;
    pt1 = pow(1+taxaf,n);
    valorAcumulado = p * (pt1-1);

    printf("o valor acumulado de rendimentos sera de %2.2f reais",valorAcumulado);

    }*/

/*  11
    int main (){

    float real, dolar, cambio;

    printf("informe a quantidade de dolares que voce tem:");
    scanf("%f", &dolar);

    cambio = 5.50;
    real = dolar * cambio;
    printf("voce tem %f reais ",real);

}*/
/* 12
    int main(){

    int  kmh, tempoMedio;
    float km, mh ;

    printf("informe a distancia em kilometros do percurso:");
    scanf("%f",&km);
    printf("informe a velocidade em km/h que sera percorrida:");
    scanf("%d", &kmh);

    tempoMedio = km/kmh;
    mh = kmh/3.6;

    printf("o tempo medio de chegada sera de aproximadamente %d hora(s)\nvelocidade em metros por segundo sera de %2.1f",tempoMedio,mh);
    }
*/
/*  14
    int main(){
        float f, c;

        printf("informe a temperatura em graus celsius: ");
        scanf("%f",&c);
        
        f = (9*c+160)/5;

        printf("a temperatura em graus Fahrenheit eh de %2.1f graus",f);

    }

*/ 
/* 15
int main(){
    float produto, pres;

    printf("informe o valor integral do produto: ");
    scanf("%f",&produto);

    pres = produto/5;

    printf("o valor da parcela dividida em 5 vezes sera de %2.2f reais",pres);
}

*/
/* 16
int main (){
    float porcen, custo, valorVenda;
    printf("informe o custo de producao: ");
    scanf("%f",&custo);
    printf("informe a porcentangem de lucro: ");
    scanf("%f",&porcen);

    porcen = porcen/100;
    valorVenda = (custo*porcen)+custo;

    printf("o valor de venda aplicado um lucro de %2.1f porcentos serah de %2.2f reais",porcen*100, valorVenda);
}
*/
/* 17
int main (){
    float custoFabrica, porcenDis=0.28, porcenImp=0.45,custoIntermediario, custoFinal;
    
    printf("informe o custo de fabricar o carro: ");
    scanf("%f",&custoFabrica);
    custoIntermediario = (custoFabrica*porcenDis)+custoFabrica;
    custoFinal = (custoIntermediario*porcenImp)+custoIntermediario;
    printf("o valor final do carro com base no custo inicial de %2.2f reais serah de %2.2f reais ",custoFabrica,custoFinal);

}
*/
/* 18
int main (){
    int lado, perimetro, area;

    printf("informe o lado do quadrado: ");
    scanf("%d",&lado);

    perimetro = lado*4;
    area = lado*lado;

    printf("o perimetro do quadrado serah %d e a area serah de %d",perimetro,area);
}
*/
/*19
int main(){
    float salario, salarioNovo;

    printf("informe o seu salario atual: ");
    scanf("%f",&salario);
    
    salarioNovo=(salario*0,370)+salario;

    printf("o seu novo salario com um aumento de 37 porcento serah de %2.2f reais",salarioNovo);
}
*/
/* 20
int main(){
    float segundo, minuto,hora,dias;

    printf("informe uma quantidade de segundos:     ");
    scanf("%f",&segundo);

    minuto=segundo/60;
    hora=minuto/60;
    dias=hora/24;
    printf("isso equivale ah %2.1f minutos %2.1f horas e %2.1f dias",minuto,hora,dias);

}
*/
/*#include <stdio.h> 21
     int main(){
         int anoAtual, anoNascimento, idadeAtual, idadeFutura;
         printf("informe seu ano de nascimento:     ");
         scanf("%d",&anoNascimento);
         printf("informe o ano atual:    ");
         scanf("%d",&anoAtual);
         idadeAtual = anoAtual - anoNascimento;
         idadeFutura = idadeAtual+(2028-anoAtual);
         printf("a sua idade atual eh ou serah de %d anos",idadeAtual);
         printf("\nsua idade em 2028 serah de %d anos",idadeFutura);
     }*/
/*int main(){ 22
    float valor,taxa,rendimento,rendimentoTotal;
    printf("informe o valor que sera depositado:\t");
    scanf("%f",&valor);
    printf("informe a porcentagem da taxa de juros:\t");
    scanf("%f",&taxa);
    rendimento=valor*(taxa/100);
    rendimentoTotal=rendimento+valor;
    printf("o seu rendimento total sera de %2.2f reais",rendimentoTotal);
}*/
/*int main (){ 23
    float alturadesejada,altura,totalDegrau;
    printf("informe a altura de cada degrau em metros:\t");
    scanf("%f",&altura);
    printf("informe a altura que voce que subir em metros:\t");
    scanf("%f",&alturadesejada);
    totalDegrau=alturadesejada/altura;
    printf("o total de degraus que subira serah de %2.0f degrais",totalDegrau);
}*/
/*int main (){ 24
    float peso,altura,imc;
    printf("informe sua altura:\t");
    scanf("%f",&altura);
    printf("informe seu peso:\t");
    scanf("%f",&peso);
    imc = peso/(altura*altura);
    printf("\nseu imc eh de %2.1f",imc);
}*/
/*int main (){ 25
    int x,y,potencia;
    printf("informe de dois numeros para elevarmos a potencia do primeiro pelo segundo:\t");
    scanf("%d %d",&x,&y);
    potencia = pow(x,y);
    printf("o resultado dessa operacao serah %d",potencia);
}*/
/*int main(){ 26
    float totalApe,valorDiaria,valorDesconto,lucroTotal,ocupa100,ocupa70,perdaLucro;
    printf("informe o total de quartos do hotel:\t");
    scanf("%f",&totalApe);
    printf("informe o valor da diaria do hotel:\t");
    scanf("%f",&valorDiaria);
    valorDesconto = valorDiaria - (valorDiaria*0.25);
    ocupa100 = valorDesconto * totalApe;
    lucroTotal = valorDiaria * totalApe;
    ocupa70 = (totalApe - (totalApe*0.3))*valorDesconto;
    perdaLucro = lucroTotal - ocupa100;
    printf("\no valor de promocao serah de %2.2f reais\no valor total a ser arregadado caso a ocupacao atinja 100 porcento eh de %2.2f reais\no valor total a ser arregadado caso a ocupacao atinja 70 porcento eh de %2.2f reais\no valor que o hotel deixara de arregadar em virtude da promocao eh de %2.2f",valorDesconto,ocupa100,ocupa70,perdaLucro);
}*/
/*int main (){ 27
    float consumo, salario, valorQuilowatt, valorTotal, valorComDesconto;
    printf("informe o consumo de quilowatt da casa:\t");
    scanf("%f",&consumo);
    printf("informe o salario minimo:\t");
    scanf("%f",&salario);
    valorQuilowatt = salario*0.2;
    valorTotal = consumo*valorQuilowatt;
    valorComDesconto = valorTotal - (valorTotal*0.15);
    printf("\no valor de cada quilowatts eh de %2.2f reais\n",valorQuilowatt);
    printf("o valor a ser pago pela residencia eh de %2.2f reais\n",valorTotal);
    printf("o valor a ser pago com 15 porcento de desconto eh de %2.2f reais",valorComDesconto);
}*/
/*int main (){  28
    float custoEspetaculo, precoConvite, nConviteE,nConvite23;
    printf("informe o custo do show:\t");
    scanf("%f",&custoEspetaculo);
    printf("informe o preco do convite:\t");
    scanf("%f",&precoConvite);
    nConviteE = custoEspetaculo / precoConvite;
    nConvite23 = ((custoEspetaculo*0.23)+custoEspetaculo) / precoConvite;
    printf("a quantidade de convites que voce deve vender para cobrir o custo eh de %2.0f convites\n",nConviteE);
    printf("a quantidade de convites que voce deve vender para atingir 23 porcento de lucro eh de no minimo %2.0f convites",nConvite23);
}*/
/*int main (){ 29
    float distancia, tempo, velocidadeMedia, combustivel;
    printf("informe a velocidade media percorrida na viagem:\t");
    scanf("%f",&velocidadeMedia);
    printf("informe o tempo gasto na viagem:\t");
    scanf("%f",&tempo);
    distancia = tempo * velocidadeMedia;
    combustivel = distancia / 12;
    printf("o carro terah gasto %2.1f litros de gasolina",combustivel);
}*/
/*
int main (){
    float eleitores, candidato1, candidato2, nulo, p1, p2;
    printf("informe o total de eleitores:\t");
    scanf("%f",&eleitores);
    printf("informe o total de votos no candidato 1:\t");
    scanf("%f",&candidato1);
    printf("informe o total de votos no candidato 2:\t");
    scanf("%f",&candidato2);
    p1 = (candidato1*100)/eleitores;
    p2 = (candidato2*100)/eleitores;
    nulo = 100 - p1 - p2;
    printf("a porcentagem de votos do candidato 1 eh de %2.1f porcentos\n",p1);
    printf("a porcentagem de votos do candidato 2 eh de %2.1f porcentos\n",p2);
    printf("a porcentagem de votos nulos eh de %2.1f porcentos:",nulo);
    }
*/
