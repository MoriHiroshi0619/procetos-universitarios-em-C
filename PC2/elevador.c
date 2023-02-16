
#include <stdio.h>
#include <time.h>

int main(){
    int pessoasElevador[50];// vetor que armazena o elevador mais utilizado de todas as pessoas
    int pessoasPeriodo[50];//vetor que armazena o periodo utilizado de cada pessoa
    int eA = 0, eB = 0, eC = 0;// contadora pra cada elevador
    int m = 0, v = 0, n = 0;// contadora pra cada periodo
    int i, maisUtilizado, menosUtilizado;//elevador mais utilizado de todos e o menos
    int maiorPeriodo, menorPeriodo;//periodo mais utilizado de todos e o menos
    int maiorFluxo, maisUsado; //mairFluxo = o periodo mais utilizado do elevador mais utilizado
    //maisUsado= elevador mais utilizado do periodo mais utilizado/
    int contMais = 0, contMenos = 0; //contador de quantas vezes foi utilizado o elevador mais utilizado e o menos utilizado
    float porMais, porMenos, diferenca;//porcetagem do mais utilizado e o menos utilizado assim como sua diferenca
    int resposta; // guardar a resposta gerada aleatoriamente
    srand(time(NULL)); //necessario para gerar numeros atraves do tempo
    //laço for para leitura dos dados
    for(i=0;i<50;i++){
        resposta = rand()%3 + 1; //sera gerado numeros aleatorios de 0 a 2.. o + 1 serve para tranformar esses numeros de 1 a 3 
        pessoasElevador[i] = resposta;
        //atualizando contagem dos elevadores
        if(pessoasElevador[i] == 1){
            eA++;
        }else if(pessoasElevador[i] == 2){
            eB++;
        }else{
            eC++;
        }
        resposta = rand()%3 + 1;
        pessoasPeriodo[i] = resposta;
        //atualizando contagem dos periodos
        if(pessoasPeriodo[i] == 1){
            m++;
        }else if(pessoasPeriodo[i] == 2){
            v++;
        }else{
            n++;
        }
    }
    //descobrir qual elevado foi o mais utilizado.
    if(eA>eB && eA>eC){
        maisUtilizado = 1;
    }else if(eB > eC){
        maisUtilizado = 2;
    }else{
        maisUtilizado = 3;
    }
    //descobrir qual elevador foi o menos utilizado
    if(eA<eB && eA<eC){
        menosUtilizado = 1;
    }else if(eB < eC){
        menosUtilizado = 2;
    }else{
        menosUtilizado = 3;
    }
    //descobrir qual periodo foi o mais utilizado
    if(m > v && m > n){
        maiorPeriodo = 1;
    }else if(v > n){
        maiorPeriodo = 2;
    }else{
        maiorPeriodo = 3;
    }
    // descobrir qual o periodo foi o menos utilizado
    if(m < v && m < n){
        menorPeriodo = 1;
    }else if(v < n){
        menorPeriodo = 2;
    }else{
        menorPeriodo = 3;
    }

    //zerando variaveis contadoras dos periodos
    m = 0;
    v = 0;
    n = 0;
    //laço for para os periodos do elevador mais utilizado
    for(i=0;i<50;i++){
        //esse primeiro if garante que só sera contado os periodos do elevador mais utilizado
        if(pessoasElevador[i] == maisUtilizado){
            if(pessoasPeriodo[i] == 1){
                m++;
            }else if(pessoasPeriodo[i] == 2){
                v++;
            }else{
                n++;
            }
        }
    }
    //descobrindo o periodo de maior fluxo do elevador mais utilizado
    if(m > v && m > n){
        maiorFluxo = 1;
    }else if(v > n){
        maiorFluxo = 2;
    }else{
        maiorFluxo = 3;
    }
    //zerando as variaveis contadoras do elevador
    eA = 0;
    eB = 0;
    eC = 0;
    //laço for para os elevadores do periodo mais utilizado
    for(i=0;i<50;i++){
        //esse primeiro if garanti que só sera contado os elevadores do periodo mais utiliazado
        if(pessoasPeriodo[i] == maiorPeriodo){
            if(pessoasElevador[i] == 1){
                eA++;
            }else if(pessoasElevador[i] == 2){
                eB++;
            }else{
                eC;
            }
        }
    }
    //descobrindo o elevador mais utilizado do periodo mais utilizado
    if(eA>eB && eA>eC){
        maisUsado = 1;
    }else if(eB > eC){
        maisUsado = 2;
    }else{
        maisUsado = 3;
    }
    //laço for para contar o numero de vezes em que é usado o elevador mais utilizado e o do menos utilizados 
    for(i=0;i<50;i++){
        if(pessoasElevador[i] == maisUtilizado){
            contMais++;
        }
        if(pessoasElevador[i] == menosUtilizado){
            contMenos++;
        }
    }
    //regra de 3 para calcular a porcentagem
    porMais = ((float)contMais * 100) / (float)50;
    porMenos = ((float)contMenos * 100) / (float)50;
    diferenca = porMais - porMenos;
    //cada um dos if a seguir serve para garantir que sera impresso a mensagem correta;
    for(i=0;i<50;i++){
        printf("\npessoa de numero %d elevador mais utilizado = %d",i+1, pessoasElevador[i]);
        printf("\npessoa de numero %d periodo mais utilizado = %d",i+1, pessoasPeriodo[i]);
    }
    if(maisUtilizado == 1){
        printf("\n\no elevador mais utilizado foi A");
    }else if(maisUtilizado == 2){
        printf("\n\no elevador mais utilizado foi B");
    }else{
        printf("\n\no elevador mais utilizado foi C");
    }
    if(menosUtilizado == 1){
        printf("\no elevador menos utilizado foi A");
    }else if(menosUtilizado == 2){
        printf("\no elevador menos utilizado foi B");
    }else{
        printf("\no elevador menos utilizado foi C");
    }
    if(maiorPeriodo == 1){
        printf("\n\no periodo com maior fluxo foi o matutino");
    }else if(menosUtilizado == 2){
        printf("\n\no periodo com maior fluxo foi o vespertino");
    }else{
        printf("\n\no periodo com maior fluxo foi o noturno");
    }
    if(menorPeriodo == 1){
        printf("\n\no periodo com menor fluxo foi o matutino");
    }else if(menorPeriodo == 2){
        printf("\n\no periodo com menor fluxo foi o vespertino");
    }else{
        printf("\n\no periodo com menor fluxo foi o noturno");
    }

    if(maiorFluxo == 1){
        printf("\n\nperiodo com maior fluxo do elevador mais utilizado foi o matutino");
    }else if(maiorFluxo == 2){
        printf("\n\nperiodo com maior fluxo do elevador mais utilizado foi o vespertino");
    }else{
        printf("\n\nperiodo com maior fluxo do elevador mais utilizado foi o noturno");
    }

    if(maisUsado == 1){
        printf("\n\nelevador mais utilizado do maior fluxo foi o A");
    }else if(maisUsado == 2){
        printf("\n\nelevador mais utilizado do maior fluxo foi o B");
    }else{
        printf("\n\nelevador mais utilizado do maior fluxo foi o C");
    }


    printf("\n\ntotal mais utilizado = %d",contMais);
    printf("\ntotal menos utilizado = %d", contMenos);
    printf("\n\nporcentagem do elevador mais utilizado = %.1f", porMais);
    printf("\nporcentagem do elevador menos utilizado = %.1f", porMenos);
    printf("\ndiferenca percentual entre os dois = %.1f",diferenca);
    printf("\n");
}